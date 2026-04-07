#include "Hook.h"
#include "memory.h"

namespace Hook
{
	uintptr_t vtbale_hook_address = NULL;
	uintptr_t vtbale_parry_address = NULL;
	uintptr_t vtbale_old_address = NULL;
	uintptr_t vtbale_break_address = NULL;
	uintptr_t vtbale_jmp_address = NULL;
	uintptr_t vtbale_switch_address = NULL;

	VOID InitVtbaleHook() {
		do {
			Sleep(100);
			Offset::NarakaBladepoint = Memory::get_module_handle(DmaData::vmm_handle, DmaData::PID, "NarakaBladepoint.exe");;
			if (Offset::NarakaBladepoint) {
				// printf("[+] GameAddrBase = %llx\n", Offset::GameAssembly);
				break;
			}
		} while (!Offset::NarakaBladepoint);

		vtbale_jmp_address = Offset::NarakaBladepoint + 0x565F4;

		//Kernel::VirtualAlloc(&Parry::vtbale_jmp_address, 1024, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		vtbale_hook_address = Offset::GameAssembly + 0x967F1A0;
		vtbale_break_address = Offset::GameAssembly + 0x157C40D;
		vtbale_jmp_address = vtbale_jmp_address + 0x300;
		vtbale_switch_address = vtbale_jmp_address + 0x200;
		BYTE  code[] = {
			0x48,0xB8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//mov rax,00007FFB19EFC1AD
			0x48,0x39,0x84,0x24,0xC0,0x00,0x00,0x00,//cmp [rsp+000000C0],rax
			0x75,0x20,//jne 29E65A70334
			0x48,0xB8,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//mov rax,0000000000000004
			0x48,0x01,0x84,0x24,0xC0,0x00,0x00,0x00,//add [rsp+000000C0],rax
			0xFF,0x25,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//jmp 7FFB1BE254D0
			0x48,0xB8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//mov rax,0000029E65A70500
			0x83,0x38,0x01,//cmp dword ptr [rax],01
			0x75,0x1A,//jne 29E65A7035D
			0xC7,0x00,0x00,0x00,0x00,0x00,//mov [rax],00000000
			0x48,0xB8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//mov rax,00007FFB1BE254D0
			0x48,0xA3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//mov [29E6C5CA890],rax
			0xFF,0x25,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00//jmp 7FFB1BE254D0
		};
		*(uintptr_t*)&code[2] = vtbale_break_address;
		vtbale_parry_address = Memory::RAM<uintptr_t>(vtbale_hook_address);
		vtbale_parry_address = Memory::RAM<uintptr_t>(vtbale_parry_address + 0x18);
		vtbale_parry_address = Memory::RAM<uintptr_t>(vtbale_parry_address + 0xC0);
		vtbale_parry_address = Memory::RAM<uintptr_t>(vtbale_parry_address + 0x90);
		if (!vtbale_parry_address) {
			return;
		}
		vtbale_old_address = Memory::RAM<uintptr_t>(vtbale_parry_address);
		if (!vtbale_old_address) {
			return;
		}
		*(uintptr_t*)&code[44] = vtbale_old_address;
		*(uintptr_t*)&code[54] = vtbale_switch_address;
		*(uintptr_t*)&code[75] = vtbale_old_address;
		*(uintptr_t*)&code[85] = vtbale_parry_address;
		*(uintptr_t*)&code[99] = vtbale_old_address;
		Memory::WPM_BYTE(vtbale_jmp_address, code, sizeof(code));
		cout << "内存振加载成功！" << endl;
		//cout << hex << vtbale_parry_address << " | " << vtbale_jmp_address << " | " << vtbale_old_address << endl;
		//Kernel::RtlCopyMemoryEx((PBYTE)vtbale_jmp_address, code, sizeof(code));
		//Dedbg("%llX", Parry::vtbale_jmp_address);
	}

	VOID enable_vtbale(bool enable) {
		Memory::WPM<uintptr_t>(vtbale_parry_address, enable ? vtbale_jmp_address : vtbale_old_address);
	}
}
