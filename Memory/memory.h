#pragma once
#include"..\pak.h"
#include <cstdint>
namespace DmaData
{
	inline HWND Hwnd;
	inline VMMDLL_SCATTER_HANDLE hS;
	inline VMMDLL_SCATTER_HANDLE hS1;
	inline VMM_HANDLE vmm_handle;
	inline HANDLE hProcess;
	inline int PID;
}
namespace Memory
{
	int get_process_id(const char* process_name);
	uint64_t get_module_handle(VMM_HANDLE Hvmm, int PID, const char* module_name);

	VMM_HANDLE DMA_Initialize();
	void scatterClear(VMMDLL_SCATTER_HANDLE h);
	void scatterExec(VMMDLL_SCATTER_HANDLE h);
	VMMDLL_SCATTER_HANDLE scatterInit();
	void scatterDestroy(VMMDLL_SCATTER_HANDLE h);
	void scatterPrep(VMMDLL_SCATTER_HANDLE h, uint64_t address, int size);
	void RefreshConfigSet();
	void RefreshConfigSetALL();

	std::string RegistryQueryValue(std::string path, DWORD type);
	std::vector<int> GetPidList(std::string name);
	bool InitRemoteKeyDetection();
	void UpdateKeyInputBitmap();
	bool IsKeyDown(uint32_t virtual_key_code);
	bool WasKeyPressed(uint32_t virtual_key_code);
	inline bool ReadMemory(uint64_t ptr, void* buff, size_t size)
	{
		return VMMDLL_MemReadEx(DmaData::vmm_handle, DmaData::PID, ptr, (PBYTE)buff, size, 0, VMMDLL_FLAG_NOCACHE | VMMDLL_FLAG_NOCACHEPUT);
	}
	inline bool ReadMemoryEx(uint64_t ptr, void* buff, size_t size)
	{
		return VMMDLL_MemRead(DmaData::vmm_handle, DmaData::PID, ptr, (PBYTE)buff, size);
	}

	template <typename T> T RAM(uint64_t addr)
	{
		T Novalue = {};

		VMMDLL_MemReadEx(DmaData::vmm_handle, DmaData::PID, addr,(PBYTE)&Novalue, sizeof(T), 0, VMMDLL_FLAG_NOCACHE);

		//Novalue = *(T*)(addr);

		return Novalue;
	}

	template <typename T> T ReadEx(uint64_t addr)
	{
		T Novalue = {};

		VMMDLL_MemRead(DmaData::vmm_handle, DmaData::PID, addr, (PBYTE)&Novalue, sizeof(T));

		//Novalue = *(T*)(addr);

		return Novalue;
	}

	inline std::byte* ReadByteEx(uint64_t addr, DWORD size)
	{
		std::byte* p = new std::byte[size];
		memset(p, 0, size);//Çå¿ÕÉêÇëµÄ»º´æÇø
		VMMDLL_MemRead(DmaData::vmm_handle, DmaData::PID, addr, (PBYTE)p, size);
		//Novalue = *(T*)(addr);
		return p;
	}
	template <typename T> T WPM(uint64_t addr, T buffer)
	{
		return VMMDLL_MemWrite(DmaData::vmm_handle, DmaData::PID, addr, (PBYTE)&buffer, sizeof(T));
	}
	inline bool WPM_BYTE(uint64_t addr, PBYTE dest, size_t sz)
	{
		return VMMDLL_MemWrite(DmaData::vmm_handle, DmaData::PID, addr, dest, sz);
	}


	template <typename TV>
	static TV scatterRead(VMMDLL_SCATTER_HANDLE h, uint64_t address, size_t size) {
		TV buffer;
		DWORD bytesRead = 0;
		return VMMDLL_Scatter_Read(h, address, size, (PBYTE)&buffer, &bytesRead) ? buffer : TV();

	};

	inline bool ScatterReadMemory(VMMDLL_SCATTER_HANDLE h,uint64_t ptr, void* buff, size_t size)
	{
		DWORD bytesRead = 0;
		return VMMDLL_Scatter_Read(h, ptr, size, (PBYTE)buff, &bytesRead);
	}

}