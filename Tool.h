#include "stdio.h"
#include "Memory/memory.h"

namespace Tool
{
	uintptr_t GetMatrixAddr(uintptr_t temp)
	{
		temp = Memory::ReadEx<uint64_t>(temp + 0x40);
		temp = Memory::ReadEx<uint64_t>(temp + 0x38);
		temp = Memory::ReadEx<uint64_t>(temp + 0x10);
		return temp + 0xdc;
	}

	//是否手持武器
	bool IsMeleeWeapon(WeaponType ObjWeaponType)
	{
		if (ObjWeaponType == WeaponType::Blade || ObjWeaponType == WeaponType::Dagge ||
			ObjWeaponType == WeaponType::Katana || ObjWeaponType == WeaponType::nunchucks ||
			ObjWeaponType == WeaponType::Spear || ObjWeaponType == WeaponType::Sw ||
			ObjWeaponType == WeaponType::twinblades || ObjWeaponType == WeaponType::rod ||
			ObjWeaponType == WeaponType::saber || ObjWeaponType == WeaponType::tiebian ||
			ObjWeaponType == WeaponType::dualhalberd || ObjWeaponType == WeaponType::fan ||
			ObjWeaponType == WeaponType::hengdao)
		{
			return true;
		}
		return false;
	}
	//是否手持远程武器
	bool IsMeleeWeaponY(WeaponType ObjWeaponType)
	{
		if (ObjWeaponType == WeaponType::鸟铳 || ObjWeaponType == WeaponType::连弩 ||
			ObjWeaponType == WeaponType::神妙机甲 ||
			ObjWeaponType == WeaponType::弓箭 || ObjWeaponType == WeaponType::大佛手 ||
			ObjWeaponType == WeaponType::喷火筒1 || ObjWeaponType == WeaponType::五眼铳 ||
			ObjWeaponType == WeaponType::三娘水矛 || ObjWeaponType == WeaponType::一窝蜂)
		{
			return true;
		}
		return false;
	}
}