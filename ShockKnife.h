#pragma once
#include <stdint.h>
#include "HidTable.h"
#include "Hook.h"
#include "Data.h"

namespace 振刀逻辑
{
	//振刀
	void BlueToRed();
	//跳振
	void JumpShock();
	//天海F2振刀
	void TianhaiF2();
	//拼刀
	void CollideKnife();
	//短闪
	void ShortDodge(uint32_t Key);
	//长闪
	void LongDodge(uint32_t Key);
	//中闪
	void ZhongDodge();
	//随机左右短闪
	void ShortDodgeEx();
	//内存振A
	void MemShock();
	//武田随机F
	void WuTianF();
	//腾云式右键抓振刀后摇
	void 腾云式B();
}