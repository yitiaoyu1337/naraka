#include "pak.h"

namespace Hook
{
	extern uintptr_t vtbale_hook_address;
	extern uintptr_t vtbale_parry_address;
	extern uintptr_t vtbale_old_address;
	extern uintptr_t vtbale_break_address;
	extern uintptr_t vtbale_jmp_address;
	extern uintptr_t vtbale_switch_address;

	VOID InitVtbaleHook();
	VOID enable_vtbale(bool enable);
}
