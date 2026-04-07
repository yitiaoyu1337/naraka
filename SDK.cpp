#include "Memory/memory.h"
#include "Data.h"
#define PI 3.14159265358979323846
bool WorldToScreen(float MATRI[4][4], Vector3 Pos, Vec2& PM, Vec4& RW)
{
	float SightX = Gui.Window.Size.x / 2, SightY = Gui.Window.Size.y / 2;

	float fViewW = MATRI[0][3] * Pos.x + MATRI[1][3] * Pos.y + MATRI[2][3] * Pos.z + MATRI[3][3];

	if (fViewW < 0.01f) { return false; }
	fViewW = 1 / fViewW;
	PM.x = SightX + (MATRI[0][0] * Pos.x + MATRI[1][0] * Pos.y + MATRI[2][0] * Pos.z + MATRI[3][0]) * fViewW * SightX;
	PM.y = SightY - (MATRI[0][1] * Pos.x + MATRI[1][1] * Pos.y + MATRI[2][1] * Pos.z + MATRI[3][1]) * fViewW * SightY;
	float ViewY = SightY - (MATRI[0][1] * Pos.x + MATRI[1][1] * Pos.y + MATRI[2][1] * Pos.z + MATRI[3][1]) * fViewW * SightY;

	RW.y = SightY - (MATRI[0][1] * Pos.x + MATRI[1][1] * (Pos.y + 1.8) + MATRI[2][1] * Pos.z + MATRI[3][1]) * fViewW * SightY;
	RW.z = ViewY - RW.y;
	RW.w = RW.z / 2;
	RW.x = PM.x - RW.z / 4;

	return true;
}
bool WorldToScreen_AIM(float MATRI[4][4], Vector3 Pos, Vector2& PM)
{
	float SightX = Gui.Window.Size.x / 2, SightY = Gui.Window.Size.y / 2;

	float fViewW = MATRI[0][3] * Pos.x + MATRI[1][3] * Pos.y + MATRI[2][3] * Pos.z + MATRI[3][3];

	if (fViewW < 0.01f) { return false; }
	fViewW = 1 / fViewW;
	PM.x = SightX + (MATRI[0][0] * Pos.x + MATRI[1][0] * Pos.y + MATRI[2][0] * Pos.z + MATRI[3][0]) * fViewW * SightX;
	PM.y = SightY - (MATRI[0][1] * Pos.x + MATRI[1][1] * (Pos.y+1.1) + MATRI[2][1] * Pos.z + MATRI[3][1]) * fViewW * SightY;


	return true;
}
WeaponData GetWeaponData(uint32_t WeaponID)
{
	WeaponData Temp;
	if (WeaponID == 3201510)
	{
		Temp.WeaponName = "双截棍";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3201520)
	{
		Temp.WeaponName = "双截棍";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3201530)
	{
		Temp.WeaponName = "双截棍";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3201540)
	{
		Temp.WeaponName = "双截棍";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3200001)
	{
		Temp.WeaponName = "长剑";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3200011)
	{
		Temp.WeaponName = "长剑";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3200021)
	{
		Temp.WeaponName = "长剑";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3200031)
	{
		Temp.WeaponName = "长剑";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3200300)
	{
		Temp.WeaponName = "太刀";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3200310)
	{
		Temp.WeaponName = "太刀";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3200320)
	{
		Temp.WeaponName = "太刀";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3200330)
	{
		Temp.WeaponName = "太刀";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3200400)
	{
		Temp.WeaponName = "阔刀";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3200410)
	{
		Temp.WeaponName = "阔刀";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3200420)
	{
		Temp.WeaponName = "阔刀";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3200430)
	{
		Temp.WeaponName = "阔刀";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3200200)
	{
		Temp.WeaponName = "长枪";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3200210)
	{
		Temp.WeaponName = "长枪";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3200220)
	{
		Temp.WeaponName = "长枪";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3200230)
	{
		Temp.WeaponName = "长枪";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3200101)
	{
		Temp.WeaponName = "匕首";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3200111)
	{
		Temp.WeaponName = "匕首";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3200121)
	{
		Temp.WeaponName = "匕首";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3200131)
	{
		Temp.WeaponName = "匕首";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3201610)
	{
		Temp.WeaponName = "双刀";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3201620)
	{
		Temp.WeaponName = "双刀";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3201630)
	{
		Temp.WeaponName = "双刀";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3201640)
	{
		Temp.WeaponName = "双刀";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3201810)
	{
		Temp.WeaponName = "长棍";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3201820)
	{
		Temp.WeaponName = "长棍";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3201830)
	{
		Temp.WeaponName = "长棍";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3201840)
	{
		Temp.WeaponName = "长棍";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3201710)
	{
		Temp.WeaponName = "斩马刀";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3201720)
	{
		Temp.WeaponName = "斩马刀";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3201730)
	{
		Temp.WeaponName = "斩马刀";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3201740)
	{
		Temp.WeaponName = "斩马刀";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3201910)
	{
		Temp.WeaponName = "双戟";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3201920)
	{
		Temp.WeaponName = "双戟";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3201930)
	{
		Temp.WeaponName = "双戟";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3201940)
	{
		Temp.WeaponName = "双戟";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3202010)
	{
		Temp.WeaponName = "扇子";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3202020)
	{
		Temp.WeaponName = "扇子";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3202030)
	{
		Temp.WeaponName = "扇子";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3202040)
	{
		Temp.WeaponName = "扇子";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3202210)
	{
		Temp.WeaponName = "横刀";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3202220)
	{
		Temp.WeaponName = "横刀";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3202230)
	{
		Temp.WeaponName = "横刀";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3202240)
	{
		Temp.WeaponName = "横刀";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3201300)
	{
		Temp.WeaponName = "戮魂伞";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3201310)
	{
		Temp.WeaponName = "戮魂伞";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3201320)
	{
		Temp.WeaponName = "戮魂伞";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3201330)
	{
		Temp.WeaponName = "戮魂伞";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3201000)
	{
		Temp.WeaponName = "一窝蜂";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3201010)
	{
		Temp.WeaponName = "一窝蜂";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3201020)
	{
		Temp.WeaponName = "一窝蜂";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3201030)
	{
		Temp.WeaponName = "一窝蜂";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3200700)
	{
		Temp.WeaponName = "连弩";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3200710)
	{
		Temp.WeaponName = "连弩";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3200720)
	{
		Temp.WeaponName = "连弩";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3200730)
	{
		Temp.WeaponName = "连弩";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3201200)
	{
		Temp.WeaponName = "鸟铳";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3201210)
	{
		Temp.WeaponName = "鸟铳";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3201220)
	{
		Temp.WeaponName = "鸟铳";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3201230)
	{
		Temp.WeaponName = "鸟铳";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3201100)
	{
		Temp.WeaponName = "五眼铳";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3201110)
	{
		Temp.WeaponName = "五眼铳";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3201120)
	{
		Temp.WeaponName = "五眼铳";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3201130)
	{
		Temp.WeaponName = "五眼铳";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3200900)
	{
		Temp.WeaponName = "喷火筒";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3200910)
	{
		Temp.WeaponName = "喷火筒";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3200920)
	{
		Temp.WeaponName = "喷火筒";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3200930)
	{
		Temp.WeaponName = "喷火筒";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3200800)
	{
		Temp.WeaponName = "火炮";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3200810)
	{
		Temp.WeaponName = "火炮";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3200820)
	{
		Temp.WeaponName = "火炮";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3200830)
	{
		Temp.WeaponName = "火炮";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}

	if (WeaponID == 3200501)
	{
		Temp.WeaponName = "弓箭";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3200511)
	{
		Temp.WeaponName = "弓箭";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3200521)
	{
		Temp.WeaponName = "弓箭";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3200531)
	{
		Temp.WeaponName = "弓箭";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3209904)
	{
		Temp.WeaponName = "白大佛";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3209905)
	{
		Temp.WeaponName = "蓝大佛";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3209906)
	{
		Temp.WeaponName = "紫大佛";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3209907)
	{
		Temp.WeaponName = "金大佛";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3208002)
	{
		Temp.WeaponName = "白岳山";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3208003)
	{
		Temp.WeaponName = "蓝岳山";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3208004)
	{
		Temp.WeaponName = "紫岳山";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3208005)
	{
		Temp.WeaponName = "金岳山";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3209002)
	{
		Temp.WeaponName = "白沈妙";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3209003)
	{
		Temp.WeaponName = "蓝沈妙";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3209004)
	{
		Temp.WeaponName = "紫沈妙";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3209005)
	{
		Temp.WeaponName = "金沈妙";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3207006)
	{
		Temp.WeaponName = "白三娘";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3207005)
	{
		Temp.WeaponName = "蓝三娘";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3207004)
	{
		Temp.WeaponName = "紫三娘";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3207001)
	{
		Temp.WeaponName = "金三娘";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3209102)
	{
		Temp.WeaponName = "白莹莹";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3209103)
	{
		Temp.WeaponName = "蓝莹莹";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3209104)
	{
		Temp.WeaponName = "紫莹莹";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3209105)
	{
		Temp.WeaponName = "金莹莹";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3209201)
	{
		Temp.WeaponName = "白哈迪";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	if (WeaponID == 3209202)
	{
		Temp.WeaponName = "蓝哈迪";
		Temp.WeaponColor = ImColor{ 82,136,255 };//天蓝
	}
	if (WeaponID == 3209203)
	{
		Temp.WeaponName = "紫哈迪";
		Temp.WeaponColor = ImColor{ 189,66,248 };//暗紫
	}
	if (WeaponID == 3209204)
	{
		Temp.WeaponName = "金哈迪";
		Temp.WeaponColor = ImColor{ 237,221,5 };//金色
	}
	if (WeaponID == 3209901)
	{
		Temp.WeaponName = "拳头";
		Temp.WeaponColor = ImColor{ 202,202,202 };//银白
	}
	return Temp;
}
string GetHeroType(int ID)
{
	if (ID == 1000001) { return  "胡桃"; }
	if (ID == 1000003) { return  "宁红夜"; }
	if (ID == 1000004) { return  "迦南"; }
	if (ID == 1000005) { return  "特木尔"; }
	if (ID == 1000006) { return  "季沧海"; }
	if (ID == 1000007) { return  "天海"; }
	if (ID == 1000008) { return  "大佛"; }
	if (ID == 1000009) { return  "妖刀姬"; }
	if (ID == 1000010) { return  "崔三娘"; }
	if (ID == 1000011) { return  "岳山"; }
	if (ID == 1000012) { return  "神将"; }
	if (ID == 1000013) { return  "无尘"; }
	if (ID == 1000015) { return  "顾清寒"; }
	if (ID == 1000016) { return  "武田信忠"; }
	if (ID == 1000017) { return  "殷紫萍"; }
	if (ID == 1000018) { return  "沈妙"; }
	if (ID == 1000019) { return  "铁卫"; }
	if (ID == 1000020) { return  "胡为"; }
	if (ID == 1000021) { return  "季莹莹"; }
	if (ID == 1000022) { return  "玉玲珑"; }
	if (ID == 1000023) { return  "哈迪"; }
	if (ID == 1000024) { return  "魏轻"; }

	return"";
}

void CharacterManager::GetCharacterManagerPtr()
{
	auto Manager = Memory::ReadEx<uintptr_t>(Offset::GameAssembly + Offset::m_CharacterManager);
	Manager = Memory::ReadEx<uintptr_t>(Manager + 0xB8);
	CharacterManagerPtr = Memory::ReadEx<uintptr_t>(Manager + 0x8);
}

void CharacterManager::Cache_PlayerCount_ActorModelList()
{
	auto Addr = Memory::ReadEx<uintptr_t>(CharacterManagerPtr + Offset::Character.AllAliveCharList);
	Cache_PlayerCount_ActorModelList_Ptr = Memory::ReadEx<uintptr_t>(Addr + 0x18);
}

int CharacterManager::GetPlayerCount()
{
	return Memory::ReadEx<int>(Cache_PlayerCount_ActorModelList_Ptr + 0x18);
}

ActorModel* CharacterManager::GetLocalActorModel()
{
	return Memory::ReadEx<ActorModel*>(CharacterManagerPtr + 0x18);
}

ActorModel* CharacterManager::GetActorModelList(int index)
{
	return Memory::RAM<ActorModel*>(Cache_PlayerCount_ActorModelList_Ptr + Offset::Character.ArrayStart + index * 0x18ull);
}

bool ActorModel::IsVisible()
{
	return Memory::RAM<bool>(reinterpret_cast<uintptr_t>(this) + 0x6C);
}

bool ActorModel::IsAlive()
{
	return Memory::ReadEx<int>(reinterpret_cast<uintptr_t>(this) + 0x38) == 0x101;
}

uintptr_t ActorModel::Cache_GetEventTracksForLayer()
{
	auto temp = Memory::ReadEx<uintptr_t>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ObjectMsg);
	return Memory::ReadEx<uintptr_t>(temp + Offset::ActorModel.EventTracksForLayer);
}

std::wstring ActorModel::GetActorName(uintptr_t EventTracksForLayerPtr)
{
	uint64_t temp = Memory::scatterRead<uint64_t>(DmaData::hS1, EventTracksForLayerPtr + 0x20, sizeof(uint64_t));
	temp = Memory::ReadEx<uint64_t>(temp + 0x10);

	//auto NameLen = Memory::ReadEx<int>(temp + 0x10);
	//cout << NameLen << endl;
	wchar_t Name[0xFF] = { '\0' };
	Memory::ReadMemory(temp + 0x14, &Name, /*NameLen * 2*/140);

	return Name;
}

uintptr_t ActorModel::Cache_GetPosPtr()
{
	auto temp = Memory::ReadEx<uintptr_t>(reinterpret_cast<uintptr_t>(this) + 0x60);
	temp = Memory::ReadEx<uintptr_t>(temp + 0x10);
	temp = Memory::ReadEx<uintptr_t>(temp + 0x30);
	temp = Memory::ReadEx<uintptr_t>(temp + 0x30);
	temp = Memory::ReadEx<uintptr_t>(temp + 0x08);
	return Memory::ReadEx<uintptr_t>(temp + 0x38);
}

Vector3 ActorModel::GetPos(uintptr_t PosPtr)
{
	return Memory::RAM<Vector3>(PosPtr + 0x90);
}

uintptr_t ActorModel::Cache_GetActorRootPtr()
{
	auto BackingField = Memory::ReadEx<uintptr_t>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.Transform);
	auto CachedPtr = Memory::ReadEx<uintptr_t>(BackingField + 0x10);
	return Memory::ReadEx<uintptr_t>(CachedPtr + 0x38);
}

//BOOL ActorModel::CheckPlayerAngle(uintptr_t ActorRootPtr, Vector3 ObjPos, float NewAngle)
//{
	//Vector3 Direction = Memory::RAM<Vector3>(ActorRootPtr + 0xA4);
	//float Yaw = atan2f(fabs(Direction.x), fabs(Direction.z)) * 360.0f / (float)PI;
	//if (!(Direction.x > 0.0f && Direction.z > 0.0f || Direction.x < 0.0f && Direction.z < 0.0f))
	//{
	//	Yaw = 360.0f - Yaw;
	//}
	//Yaw = Yaw + 180.0f;
	//if (Yaw > 360.0f)
	//{
	//	Yaw = Yaw - 360.0f;
	//}
	//float War = atan2f(Enitiy->GetPos().x - LocalPlayer->GetPos().x, Enitiy->GetPos().z - LocalPlayer->GetPos().z) * 180.0f / (float)PI;
	//if (War <= 0.0f)
	//{
	//	War = War + 360.0f;
	//}
	//float Phi = fmodf(fabs(War - Yaw), 360.0f);
	//float Angle = Phi > 180.0f ? 360.0f - Phi : Phi;
	//if (Angle > 0.0f && Angle <= NewAngle)
	//{
	//	return TRUE;
	//}

//}

//BOOL ActorModel::CheckPlayerAngle(uintptr_t ActorRootPtr, Vector3 ObjPos, float NewAngle)
//{
//	Vector3 Direction = Memory::ReadEx<Vector3>(ActorRootPtr + 0xA4);
//
//	float Yaw = atan2f(fabs(Direction.x), fabs(Direction.z)) * 360.0f / (float)PI;
//	if (!(Direction.x > 0.0f && Direction.z > 0.0f || Direction.x < 0.0f && Direction.z < 0.0f))
//	{
//		Yaw = 360.0f - Yaw;
//	}
//	Yaw = Yaw + 180.0f;
//	if (Yaw > 360.0f)
//	{
//		Yaw = Yaw - 360.0f;
//	}
//	float War = atan2f(ObjPos.x - LocalPlayer_Data.MyPos.x, ObjPos.z - LocalPlayer_Data.MyPos.z) * 180.0f / (float)PI;
//	if (War <= 0.0f)
//	{
//		War = War + 360.0f;
//	}
//	float Phi = fmodf(fabs(War - Yaw), 360.0f);
//	float Angle = Phi > 180.0f ? 360.0f - Phi : Phi;
//	if (Angle > 0.0f && Angle <= NewAngle)
//	{
//		return TRUE;
//	}
//	return FALSE;
//}

WeaponType ActorModel::GetActorWeapon()
{
	auto temp = Memory::RAM<uintptr_t>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ActorWeapon);
	return Memory::RAM<WeaponType>(temp + 0x68); 
}

ActorModelPropertyData* ActorModel::GetActorModelPropertyData()
{
	return Memory::ReadEx<ActorModelPropertyData*>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.PropertyData);
}

ActorKit* ActorModel::GetActorKit()
{
	return Memory::ReadEx<ActorKit*>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ActorKit);
}

RuntimePropertyData* ActorModel::GetRuntimePropertyData()
{
	return Memory::ReadEx<RuntimePropertyData*>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.RuntimePropertyData);
}

ObjectMessenger* ActorModel::GetObjectMessenger()
{
	return Memory::ReadEx<ObjectMessenger*>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ObjectMsg);
}

bool ActorModelPropertyData::GetISRobotId()
{
	return Memory::ReadEx<int>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ProPerty.RobotId) != NULL;
}

int ActorModelPropertyData::GetTeam()
{
	return Memory::ReadEx<int>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ProPerty.Group);
}

HeroType ActorModelPropertyData::GetHeroTID()
{
	return Memory::RAM<HeroType>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ProPerty.Heroid);
}

int ActorModelPropertyData::GetWeaponID()
{
	return Memory::RAM<int>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ProPerty.WeaponId);
}
std::string UnicodeToAscii(CONST std::wstring& wstr) {
	// 预算-缓冲区中多字节的长度    
	int ansiiLen = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	// 给指向缓冲区的指针变量分配内存    
	char* pAssii = (char*)malloc(sizeof(char) * ansiiLen);
	// 开始向缓冲区转换字节    
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, pAssii, ansiiLen, nullptr, nullptr);
	std::string ret_str = pAssii;
	free(pAssii);
	return ret_str;
}
std::string ActorModelPropertyData::GetPlayerName()
{
	auto temp = Memory::ReadEx<uintptr_t>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ProPerty.PlayerName);
	//auto NameLen = Memory::ReadEx<int>(temp + 0x10);
	wchar_t Name[0xFF] = { '\0' };
	Memory::ReadMemoryEx(temp + 0x14, &Name, 128);
	return UnicodeToAscii(Name).c_str();
}

uintptr_t ActorKit::Cache_BlueTime()
{
	auto temp = Memory::ReadEx<uintptr_t>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ActorKitS.BackingField);
	temp = Memory::ReadEx<uintptr_t>(temp + 0x18);
	temp = Memory::ReadEx<uintptr_t>(temp + 0x20);
	return Memory::ReadEx<uintptr_t>(temp + 0x10);
}

uintptr_t ActorKit::Cache_ActorPhysics()
{
	return Memory::ReadEx<uintptr_t>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ActorKitS.ActorPhysics);
}

float ActorKit::BlueTime(uintptr_t Cache_Bluetime_PTR)
{
	return Memory::RAM<float>(Cache_Bluetime_PTR + 0x24 + 3 * 0xC);
}

ActionHitSimulateData* ActorKit::GetActionHitSimulateData()
{
	return Memory::ReadEx<ActionHitSimulateData*>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ActorKitS.HitSimulateData);
}

ActionType ActionHitSimulateData::GetEndureLevel()
{
	return Memory::RAM<ActionType>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ActorKitS.HitSimulate.endureLevel);
}

int ActionHitSimulateData::GetReactionType()
{
	return Memory::RAM<int>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ActorKitS.HitSimulate.ReactionType);
}

int ActionHitSimulateData::GetRangeReactionType()
{
	return Memory::RAM<int>(reinterpret_cast<uintptr_t>(this) + Offset::ActorModel.ActorKitS.HitSimulate.RangeReactionType);
}

float ActionHitSimulateData::GetActionDuration()
{
	return Memory::ReadEx<float>(reinterpret_cast<uintptr_t>(this) + 0x2C);
}

PropertyDataID RuntimePropertyData::GetPropertyDataID()
{
	auto Data = Memory::ReadEx<uintptr_t>(reinterpret_cast<uintptr_t>(this) + 0x10);
	Data = Memory::ReadEx<uintptr_t>(Data + 0x10);
	Data = Memory::ReadEx<uintptr_t>(Data + 0x18);
	auto DictCount = Memory::ReadEx<int>(Data + 0x18);
	int Index = 0;
	PropertyDataID temp = { 0 };
	for (size_t i = 0; i < DictCount; i++)
	{
		uintptr_t ID1 = Data + 0x28 + i * 0x10;

		uintptr_t ID2 = ID1 + 4;

		auto DataID = Memory::ReadEx<int>(ID1);

		auto TempID = Memory::ReadEx<int>(ID2);

		if (DataID == 11001) { temp.CurHpID = TempID; Index += 1; }
		if (DataID == 10001) { temp.HpMaxID = TempID; Index += 1; }
		if (DataID == 11024) { temp.CurshieldID = TempID; Index += 1; }
		if (DataID == 10107) { temp.shieldMaxID = TempID; Index += 1; }
		if (DataID == 11002) { temp.CurEnergyID = TempID; Index += 1; }
		if (DataID == 10006) { temp.EnergyMaxID = TempID; Index += 1; }

		if (Index >= 6) { break; }
	}
	return temp;
}

uintptr_t RuntimePropertyData::Cache_PropertData()
{
	auto Data = Memory::ReadEx<uintptr_t>(reinterpret_cast<uintptr_t>(this) + 0x10);
	Data = Memory::ReadEx<uintptr_t>(Data + 0x28);
	return Memory::ReadEx<uintptr_t>(Data + 0x10);
}

int RuntimePropertyData::GetCurHp(uintptr_t Cache_PropertData_PTR, PropertyDataID Cache_PropertyDataID)
{
	return Memory::RAM<int>(Cache_PropertData_PTR + 0x20 + Cache_PropertyDataID.CurHpID * 4ull);
}

int RuntimePropertyData::GetHpMax(uintptr_t Cache_PropertData_PTR, PropertyDataID Cache_PropertyDataID)
{
	return Memory::ReadEx<int>(Cache_PropertData_PTR + 0x20 + Cache_PropertyDataID.HpMaxID * 4ull);
}

int RuntimePropertyData::GetCurshield(uintptr_t Cache_PropertData_PTR, PropertyDataID Cache_PropertyDataID)
{
	return Memory::RAM<int>(Cache_PropertData_PTR + 0x20 + Cache_PropertyDataID.CurshieldID * 4ull);
}

int RuntimePropertyData::GetshieldMax(uintptr_t Cache_PropertData_PTR, PropertyDataID Cache_PropertyDataID)
{
	return Memory::ReadEx<int>(Cache_PropertData_PTR + 0x20 + Cache_PropertyDataID.shieldMaxID * 4ull);
}

int RuntimePropertyData::GetCurEnergy(uintptr_t Cache_PropertData_PTR, PropertyDataID Cache_PropertyDataID)
{
	return Memory::ReadEx<int>(Cache_PropertData_PTR + 0x20 + Cache_PropertyDataID.CurEnergyID * 4ull);
}

int RuntimePropertyData::GetEnergyMax(uintptr_t Cache_PropertData_PTR, PropertyDataID Cache_PropertyDataID)
{
	return Memory::ReadEx<int>(Cache_PropertData_PTR + 0x20 + Cache_PropertyDataID.EnergyMaxID * 4ull);
}

int RuntimePropertyData::GetCurAnger(uintptr_t Cache_PropertData_PTR)
{
	return Memory::RAM<int>(Cache_PropertData_PTR + 0x30);
}

int RuntimePropertyData::GetAngerMax(uintptr_t Cache_PropertData_PTR)
{
	return Memory::ReadEx<int>(Cache_PropertData_PTR + 0x38);
}

uintptr_t ObjectMessenger::Cache_GetGlobalTime()
{
	auto Manager = Memory::ReadEx<uintptr_t>(Offset::GameAssembly + Offset::m_GlobalTime);
	return Memory::ReadEx<uintptr_t>(Manager + 0xB8);
}

uintptr_t ObjectMessenger::Cache_GetCurTimeForLogicState()
{
	auto temp = Memory::ReadEx<uintptr_t>(reinterpret_cast<uintptr_t>(this) + 0x68);
	temp = Memory::ReadEx<uintptr_t>(temp + 0x48);
	return Memory::ReadEx<uintptr_t>(temp + 0x20);
}

float ObjectMessenger::GetCurTimeForLogicStateA(uintptr_t Cache_GetGlobalTime_PTR, uintptr_t Cache_GetCurTimeForLogicState_PTR)
{
	auto v2 = Memory::RAM<double>(Cache_GetGlobalTime_PTR + 0x28);
	return (float)(v2 - Memory::RAM<double>(Cache_GetCurTimeForLogicState_PTR + 0x58));
}

uintptr_t ObjectMessenger::Cache_GetNameHash()
{
	auto temp = Memory::ReadEx<uintptr_t>(reinterpret_cast<uintptr_t>(this) + 0x68);
	temp = Memory::ReadEx<uintptr_t>(temp + 0x48);
	return Memory::ReadEx<uintptr_t>(temp + 0x20);
	//return Memory::RAM<uintptr_t>(temp + 0x48);
}

unsigned int ObjectMessenger::GetNameHash(uintptr_t Cache_GetNameHash_PTR)
{
	auto temp = Memory::ReadEx<uintptr_t>(Cache_GetNameHash_PTR + 0x48);
	return  Memory::RAM<unsigned int>(temp + 0x18);
}

void UserDataManager::GetUserDataManager()
{
	auto Manager = Memory::ReadEx<uintptr_t>(Offset::GameAssembly + Offset::m_UserDataManager);
	Manager = Memory::ReadEx<uintptr_t>(Manager + 0xB8);
	UserDataManagerPtr = Memory::ReadEx<uintptr_t>(Manager);
}

AllSkillData* UserDataManager::GetAllSkillDataList()
{
	auto UserBattleData = Memory::ReadEx<uintptr_t>(UserDataManagerPtr + 0x30);
	auto skillData = Memory::ReadEx<uintptr_t>(UserBattleData + 0xE8);
	auto characterSkillDataDict = Memory::ReadEx<uintptr_t>(skillData + 0x10);
	auto AllSkillDataList = Memory::ReadEx<uintptr_t>(characterSkillDataDict + 0x18);
	return  Memory::ReadEx<AllSkillData*>(AllSkillDataList + 0x30);
}

bool UserDataManager::IsSpectator()
{
	auto SpectatorData = Memory::ReadEx<uintptr_t>(UserDataManagerPtr + Offset::UserData.SpectatorData);
	return  !Memory::ReadEx<bool>(SpectatorData + 36);
}

int AllSkillData::GetCount()
{
	auto temp = Memory::ReadEx<uintptr_t>(reinterpret_cast<uintptr_t>(this) + 0x18);
	return Memory::ReadEx<int>(temp + 0x18);
}

uintptr_t AllSkillData::Cache_Skill()
{
	auto SkillId = Memory::ReadEx<uintptr_t>(reinterpret_cast<uintptr_t>(this) + 0x18);
	SkillId = Memory::ReadEx<uintptr_t>(SkillId + 0x10);
	return Memory::ReadEx<uintptr_t>(SkillId + 0x20 + 0 * 0x08);
}

int AllSkillData::GetSkillID(uintptr_t Cache_Skill_PTR)
{
	auto SkillId = Memory::ReadEx<uintptr_t>(Cache_Skill_PTR + 0x60);
	return Memory::ReadEx<int>(SkillId + Offset::UserData.Skill_ID);
}

int AllSkillData::GetSkillState(uintptr_t Cache_Skill_PTR)
{
	return Memory::RAM<int>(Cache_Skill_PTR + Offset::UserData.skillState);
}

float AllSkillData::Get_LeftCdTime(uintptr_t Cache_Skill_PTR)
{
	return Memory::RAM<float>(Cache_Skill_PTR + Offset::UserData.ClientLeftCdTime);
}

float AllSkillData::Get_LeftContinueTime(uintptr_t Cache_Skill_PTR)
{
	return Memory::ReadEx<float>(Cache_Skill_PTR + Offset::UserData.ClientLeftContinueTime);
}

void CharactorSyncManager::GetCharactorSyncManager()
{
	auto Manager = Memory::ReadEx<uintptr_t>(Offset::GameAssembly + Offset::m_CharactorSync);
	Manager = Memory::ReadEx<uintptr_t>(Manager + 0xB8);
	CharactorSyncManagerPtr = Memory::ReadEx<uintptr_t>(Manager);
}

float CharactorSyncManager::GamePing()
{
	float shrtt = Memory::ReadEx<float>(CharactorSyncManagerPtr + 0x40);//shrtt
	if (shrtt > 0.0f)
	{
		shrtt = (shrtt * 2.0f) * 1000.0f;
		return shrtt;
	}
	return 0.f;
}

BOOL CheckPlayerAngle(uintptr_t ActorRootPtr, Vector3 ObjPos, Vector3 MyPos, float NewAngle)
{
	Vector3 Direction = Memory::RAM<Vector3>(ActorRootPtr + 0xA4);

	float Yaw = atan2f(fabs(Direction.x), fabs(Direction.z)) * 360.0f / (float)PI;
	if (!(Direction.x > 0.0f && Direction.z > 0.0f || Direction.x < 0.0f && Direction.z < 0.0f))
	{
		Yaw = 360.0f - Yaw;
	}
	Yaw = Yaw + 180.0f;
	if (Yaw > 360.0f)
	{
		Yaw = Yaw - 360.0f;
	}
	float War = atan2f(ObjPos.x - MyPos.x, ObjPos.z - MyPos.z) * 180.0f / (float)PI;
	if (War <= 0.0f)
	{
		War = War + 360.0f;
	}
	float Phi = fmodf(fabs(War - Yaw), 360.0f);
	float Angle = Phi > 180.0f ? 360.0f - Phi : Phi;
	//cout << Angle << endl;
	调试::逻辑执行.判断角度 = Angle;
	if (Angle > 0.0f && Angle <= NewAngle)
	{
		return TRUE;
	}
	return FALSE;
}
float GetAngle(uintptr_t ActorRootPtr, Vector3 ObjPos, Vector3 MyPos)
{
	Vector3 Direction = Memory::RAM<Vector3>(ActorRootPtr + 0xA4);

	float Yaw = atan2f(fabs(Direction.x), fabs(Direction.z)) * 360.0f / (float)PI;
	if (!(Direction.x > 0.0f && Direction.z > 0.0f || Direction.x < 0.0f && Direction.z < 0.0f))
	{
		Yaw = 360.0f - Yaw;
	}
	Yaw = Yaw + 180.0f;
	if (Yaw > 360.0f)
	{
		Yaw = Yaw - 360.0f;
	}
	float War = atan2f(ObjPos.x - MyPos.x, ObjPos.z - MyPos.z) * 180.0f / (float)PI;
	if (War <= 0.0f)
	{
		War = War + 360.0f;
	}
	float Phi = fmodf(fabs(War - Yaw), 360.0f);
	float Angle = Phi > 180.0f ? 360.0f - Phi : Phi;
	return Angle;
	//cout << Angle << endl;
	//if (Angle > 0.0f && Angle <= NewAngle)
	//{
	//	return TRUE;
	//}
	//return FALSE;
}


int GetRangeReactionType(uintptr_t HitSimulateData_PTR)
{
	return Memory::RAM<int>(HitSimulateData_PTR + Offset::ActorModel.ActorKitS.HitSimulate.RangeReactionType);
}

int GetReactionType(uintptr_t HitSimulateData_PTR)
{
	return Memory::RAM<int>(HitSimulateData_PTR + Offset::ActorModel.ActorKitS.HitSimulate.ReactionType);
}

uint64_t GetItemPosAddr(uint64_t Ptr)
{
	uint64_t TEMP;
	TEMP = Memory::ReadEx<uint64_t>(Ptr + 0x30);
	TEMP = Memory::ReadEx<uint64_t>(TEMP + 0x18);
	TEMP = Memory::ReadEx<uint64_t>(TEMP + 0x28);
	TEMP = Memory::ReadEx<uint64_t>(TEMP + 0x10);
	TEMP = Memory::ReadEx<uint64_t>(TEMP + 0x30);
	TEMP = Memory::ReadEx<uint64_t>(TEMP + 0x8);
	return TEMP;
}

//bool IsHokeyEx(int Key)
//{
//	return Memory::IsKeyDown(Key);
//}

float GetAimDis(float x, float y, float ObjeX, float ObjeY)
{

	float _x = x - ObjeX;
	float _Y = y - ObjeY;
	return sqrt(_x * _x + _Y * _Y);
}
float GetPlayerDis(Vector3 Obj, Vector3 Local)
{

	float _x = Obj.x - Local.x;
	float _Y = Obj.y - Local.y;
	float _Z = Obj.z - Local.z;
	return sqrt(_x * _x + _Y * _Y + _Z * _Z);
}
//bool KmboxIsHokeyMouse(int Key)
//{
//	if (Key == 1)
//		return kmNet_monitor_mouse_left();
//	else if (Key == 2)
//		return kmNet_monitor_mouse_right();
//	else if (Key == 5)
//		return kmNet_monitor_mouse_side1();
//	else if (Key == 6)
//		return kmNet_monitor_mouse_side2();
//	else
//		return 0;
//}

//bool KmboxIsHokeyKey(short vk_key)
//{
//	return kmNet_monitor_keyboard(vk_key);
//}

void SendKeyPressEx(uint32_t Key)
{
	kmNet_keyup(Key);
	kmNet_keydown(Key);
}

void SendKeyUpEx(uint32_t Key)
{
	kmNet_keyup(Key);
}

void MouseLeftEx(int key)
{
	kmNet_mouse_left(key);
}

void MouseRightEx(int key)
{
	kmNet_mouse_right(key);
}

void MouseLeftUp(int key)
{
	kmNet_mask_mouse_left(true);
	kmNet_mouse_move(1, 1);
	kmNet_mask_mouse_left(false);
}

void MouseRightUp(int key)
{
	kmNet_mask_mouse_right(true);
	kmNet_mouse_move(1, 1);
	kmNet_mask_mouse_right(false);
}

void Kmbox_Move(int x, int y)
{
	char buff[1024];
	sprintf_s(buff, "km.move(%d,%d)\r\n", x, y);
	myserial.write(buff);
	Sleep(10);//等待10ms(串口传输是需要时间，kmbox内部代码执行也需要时间。)
	myserial.read(buff, 20);    //接收串口数据，超时时间为20ms（有的函数不需要回码，可以不需要接收。如果想精确收发请自定义串口协议）
}
void Move_mouse(int x, int y)
{
	if (按键方式 == 0)
	{
		kmNet_mouse_move(x, y);
	}
	else if (按键方式 == 1)
	{
		Kmbox_Move(x, y);
	}

}
void 按下键盘(int vk)
{
	char buff[1024];
	sprintf_s(buff, "km.down(%d)\r\n", vk);
	myserial.write(buff);
	//Sleep(1);//等待10ms(串口传输是需要时间，kmbox内部代码执行也需要时间。)
	//myserial.read(buff, 20);    //接收串口数据，超时时间为20ms（有的函数不需要回码，可以不需要接收。如果想精确收发请自定义串口协议）
}
void 弹起键盘(int vk)
{
	char buff[1024];
	sprintf(buff, "km.up(%d)\r\n", vk);
	myserial.write(buff);
	//Sleep(1);//等待10ms(串口传输是需要时间，kmbox内部代码执行也需要时间。)
	//myserial.read(buff, 20);    //接收串口数据，超时时间为20ms（有的函数不需要回码，可以不需要接收。如果想精确收发请自定义串口协议）
}
void 左键按下()
{
	char buff[1024];
	sprintf(buff, "%s", "km.left(1)\r\n");
	myserial.write(buff);
	//Sleep(1);				          //等待10ms(串口传输是需要时间，kmbox内部代码执行也需要时间。)
	//myserial.read(buff, 20);    //接收串口数据，超时时间为20ms（有的函数不需要回码，可以不需要接收。如果想精确收发请自定义串口协议）
}
void 左键弹起()
{
	char buff[1024];
	sprintf(buff, "%s", "km.left(0)\r\n");
	myserial.write(buff);
	//Sleep(1);				          //等待10ms(串口传输是需要时间，kmbox内部代码执行也需要时间。)
	//myserial.read(buff, 20);    //接收串口数据，超时时间为20ms（有的函数不需要回码，可以不需要接收。如果想精确收发请自定义串口协议）
}
void 右键按下()
{
	char buff[1024];
	sprintf(buff, "%s", "km.right(1)\r\n");
	myserial.write(buff);
	//Sleep(1);				          //等待10ms(串口传输是需要时间，kmbox内部代码执行也需要时间。)
	//myserial.read(buff, 20);    //接收串口数据，超时时间为20ms（有的函数不需要回码，可以不需要接收。如果想精确收发请自定义串口协议）
}
void 右键弹起()
{
	char buff[1024];
	sprintf(buff, "%s", "km.right(0)\r\n");
	myserial.write(buff);
	//Sleep(1);				          //等待10ms(串口传输是需要时间，kmbox内部代码执行也需要时间。)
	//myserial.read(buff, 20);    //接收串口数据，超时时间为20ms（有的函数不需要回码，可以不需要接收。如果想精确收发请自定义串口协议）
}

int 左键状态()
{
	char buff[1024];
	sprintf(buff, "%s", "km.left()\r\n");
	myserial.write(buff);
	//Sleep(1);			          //等待10ms(串口传输是需要时间，kmbox内部代码执行也需要时间。)
	myserial.read(buff, 20);
	if (strstr(buff, "1") != NULL)return 1;

}
int 右键状态()
{
	char buff[1024];
	sprintf(buff, "%s", "km.right()\r\n");
	myserial.write(buff);
	//Sleep(1);			          //等待10ms(串口传输是需要时间，kmbox内部代码执行也需要时间。)
	myserial.read(buff, 20);
	if (strstr(buff, "1") != NULL)return 1;

}

//void MouseMove(int pos_x, int pos_y, int speed)
//{
//	int x = pos_x - Gui.Window.Size.x / 2;
//	int y = pos_y - Gui.Window.Size.y / 2;
//
//	if ((x > 3 || x < -3) || (y > 3 || y < -3))
//	{
//		int x_move = 0, y_move = 0;
//
//		if (x > 5 + speed / 2)
//			x_move = speed;
//		else if (x < -5 - speed / 2)
//			x_move = -speed;
//		else if (x <= 5 + speed / 2 && x >= 3)
//			x_move = 1;
//		else if (x >= -5 - speed / 2 && x <= -3)
//			x_move = -1;
//		if (y > 5 + speed / 2)
//			y_move = speed;
//		else if (y < -5 - speed / 2)
//			y_move = -speed;
//		else if (y <= 5 + speed / 2 && y >= 3)
//			y_move = 1;
//		else if (y >= -5 - speed / 2 && y <= -3)
//			y_move = -1;
//
//		if (!按键::鼠标移动)
//		{
//			按键::Move_X = x_move;
//			按键::Move_Y = y_move;
//			按键::鼠标移动 = true;
//		}
//		//if (按键方式 == 0)
//		//{
//		//	kmNet_mouse_move(x_move, y_move);
//		//}
//		//else if (按键方式 == 1)
//		//{
//		//	Kmbox_Move(x_move, y_move);
//		//}
//	}
//
//	std::this_thread::sleep_for(std::chrono::milliseconds(5));
//}

void MouseLeftorRightUp()
{
	if (按键方式 == 0)
	{
		MouseLeftUp(false);
		MouseRightUp(false);
	}
	else if (按键方式 == 1)
	{
		左键弹起();
		Sleep(1);
		右键弹起();
	}
}