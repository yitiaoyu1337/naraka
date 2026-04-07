#include"memory.h"
#include <thread>
using namespace std;

int win_logon_pid = 0;
uint64_t win32kbase = 0;
uint64_t gafAsyncKeyStateExport = 0;
uint8_t state_bitmap[64]{ };
uint8_t previous_state_bitmap[256 / 8]{ };

//DMA获取进程ID
int Memory::get_process_id(const char* process_name)
{
	DWORD buffer;
	bool ret = VMMDLL_PidGetFromName(DmaData::vmm_handle, (LPSTR)process_name, &buffer);

	if (ret)
	{
		return buffer;
	}

	return 0;
}

//DMA获取模块基址
uint64_t Memory::get_module_handle(VMM_HANDLE Hvmm, int PID, const char* module_name)
{
	uint64_t address = VMMDLL_ProcessGetModuleBaseU(Hvmm, PID, (LPSTR)module_name);
	return address;
}

//初始化DMA
VMM_HANDLE Memory::DMA_Initialize()
{

	vector<LPSTR> _局部1 = { (LPSTR)"-norefresh", (LPSTR)"-device", (LPSTR)"FPGA" };
	VMM_HANDLE _局部2 = VMMDLL_Initialize(3, _局部1.data());
	
	return _局部2;

}

void Memory::scatterClear(VMMDLL_SCATTER_HANDLE h) {
	VMMDLL_Scatter_Clear(h, DmaData::PID, VMMDLL_FLAG_NOCACHE | VMMDLL_FLAG_ZEROPAD_ON_FAIL);
}

void Memory::scatterExec(VMMDLL_SCATTER_HANDLE h) {
	VMMDLL_Scatter_ExecuteRead(h);
}

VMMDLL_SCATTER_HANDLE Memory::scatterInit() {

	return VMMDLL_Scatter_Initialize(DmaData::vmm_handle, DmaData::PID, VMMDLL_FLAG_NOCACHE | VMMDLL_FLAG_ZEROPAD_ON_FAIL);

}

void Memory::scatterDestroy(VMMDLL_SCATTER_HANDLE h) {
	VMMDLL_Scatter_CloseHandle(h);
}

void Memory::scatterPrep(VMMDLL_SCATTER_HANDLE h, uint64_t address,  int size) {
	//if (h == NULL) scatterInit(h);
	VMMDLL_Scatter_Prepare(h, address, size);
}
void Memory::RefreshConfigSet()
{
	VMMDLL_ConfigSet(DmaData::vmm_handle, VMMDLL_OPT_REFRESH_FREQ_MEM_PARTIAL, 1);
	VMMDLL_ConfigSet(DmaData::vmm_handle, VMMDLL_OPT_REFRESH_FREQ_TLB_PARTIAL, 1);
}
void Memory::RefreshConfigSetALL()
{
	VMMDLL_ConfigSet(DmaData::vmm_handle, VMMDLL_OPT_REFRESH_ALL, 1);
}
std::string Memory::RegistryQueryValue(std::string path, DWORD type) {
	BYTE buffer[0x128];
	DWORD _type = (DWORD)type;
	DWORD size = sizeof(buffer);

	if (!VMMDLL_WinReg_QueryValueExU(DmaData::vmm_handle, (LPSTR)path.c_str(), &_type, buffer, &size))
	{
		return std::string();
	}

	std::wstring wstr = std::wstring((wchar_t*)buffer);
	return std::string(wstr.begin(), wstr.end());
}
std::vector<int> Memory::GetPidList(std::string name)
{
	PVMMDLL_PROCESS_INFORMATION process_info = NULL;
	DWORD total_processes = 0;
	std::vector<int> list = { };

	if (!VMMDLL_ProcessGetInformationAll(DmaData::vmm_handle, &process_info, &total_processes))
	{
		return list;
	}

	for (size_t i = 0; i < total_processes; i++)
	{
		auto process = process_info[i];
		if (strstr(process.szNameLong, name.c_str()))
			list.push_back(process.dwPID);
	}

	return list;
}
bool Memory::InitRemoteKeyDetection() {
	std::string win = RegistryQueryValue("HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\CurrentBuild", REG_SZ);
	int Winver = 0;
	if (win.empty()) {
		return false;
	}
	Winver = stoi(win);
	win_logon_pid = get_process_id("winlogon.exe");
	if (Winver > 22000) {
		auto pids = GetPidList("csrss.exe");
		for (size_t i = 0; i < pids.size(); i++)
		{
			auto pid = pids[i];
			uintptr_t tmp = VMMDLL_ProcessGetModuleBaseU(DmaData::vmm_handle, pid, (LPSTR)"win32ksgd.sys");
			uintptr_t g_session_global_slots = tmp + 0x3110;
			uintptr_t user_session_state = RAM<uintptr_t>(RAM<uintptr_t>(RAM<uintptr_t>(g_session_global_slots)));
			gafAsyncKeyStateExport = user_session_state + 0x3690;
			if (gafAsyncKeyStateExport > 0x7FFFFFFFFFFF)
				break;
		}
		if (gafAsyncKeyStateExport > 0x7FFFFFFFFFFF)
			return true;
		return false;
	}
	else
	{
		PVMMDLL_MAP_EAT eat_map = NULL;
		PVMMDLL_MAP_EATENTRY eat_map_entry;
		bool result = VMMDLL_Map_GetEATU(DmaData::vmm_handle, get_process_id("winlogon.exe") | VMMDLL_PID_PROCESS_WITH_KERNELMEMORY, (LPSTR)"win32kbase.sys", &eat_map);
		if (!result)
			return false;

		if (eat_map->dwVersion != VMMDLL_MAP_EAT_VERSION)
		{
			VMMDLL_MemFree(eat_map);
			eat_map_entry = NULL;
			return false;
		}

		for (int i = 0; i < eat_map->cMap; i++)
		{
			eat_map_entry = eat_map->pMap + i;
			if (strcmp(eat_map_entry->uszFunction, "gafAsyncKeyState") == 0)
			{
				gafAsyncKeyStateExport = eat_map_entry->vaFunction;
				break;
			}
		}

		VMMDLL_MemFree(eat_map);
		eat_map = NULL;
		if (gafAsyncKeyStateExport > 0x7FFFFFFFFFFF)
			return true;
		return false;
	}
}

void Memory::UpdateKeyInputBitmap()
{
	uint8_t previous_key_state_bitmap[64] = { 0 };
	memcpy(previous_key_state_bitmap, state_bitmap, 64);

	VMMDLL_MemReadEx(DmaData::vmm_handle, win_logon_pid | VMMDLL_PID_PROCESS_WITH_KERNELMEMORY, gafAsyncKeyStateExport, (PBYTE)&state_bitmap, 64, NULL, VMMDLL_FLAG_NOCACHE);
	for (int vk = 0; vk < 256; ++vk)
		if ((state_bitmap[(vk * 2 / 8)] & 1 << vk % 4 * 2) && !(previous_key_state_bitmap[(vk * 2 / 8)] & 1 << vk % 4 * 2))
			previous_state_bitmap[vk / 8] |= 1 << vk % 8;
}

bool Memory::IsKeyDown(uint32_t virtual_key_code) {
	UpdateKeyInputBitmap();
	return state_bitmap[(virtual_key_code * 2 / 8)] & 1 << virtual_key_code % 4 * 2;
}

bool Memory::WasKeyPressed(uint32_t virtual_key_code) {
	bool const result = previous_state_bitmap[virtual_key_code / 8] & 1 << virtual_key_code % 8;
	previous_state_bitmap[virtual_key_code / 8] &= ~(1 << virtual_key_code % 8);
	return result;
}