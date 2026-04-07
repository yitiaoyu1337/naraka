#include <stdio.h>
#include "SDK.h"
#include "Vector.h"
#include<map>
#pragma once

namespace Global
{
	struct
	{
		CharacterManager* Character = new CharacterManager;
		UserDataManager* UserData = new UserDataManager;
		CharactorSyncManager* Sync = new CharactorSyncManager;
		uintptr_t MatrixAddr = NULL;

		float ping = 0.f;
		double GlobalTime = 0.f;
		int 敌人数量5M内 = 0;

		time_t t = time(nullptr);
		struct tm* now = localtime(&t);
	}WorldPtr;

	struct
	{
		ActorModel* L_ActorModel = nullptr;
		ActorModelPropertyData* L_PropertyData = nullptr;
		ActorKit* L_ActorKit = nullptr;
		RuntimePropertyData* L_RuntimeProperty = nullptr;
		ObjectMessenger* L_ObjectMessenger = nullptr;
		ActionHitSimulateData* L_HitSimulate = nullptr;

		uintptr_t Cache_EventTracksForLayerPtr = NULL;
		uintptr_t Cache_PosPtr = NULL;
		uintptr_t Cache_ActorRootPtr = NULL;
		uintptr_t Cache_GetGlobalTime_PTR = NULL;
		uintptr_t Cache_GetCurTimeForLogicState_PTR = NULL;
		uintptr_t Cache_GetNameHash_PTR = NULL;
		uintptr_t Cache_ActorPhysics_PTR = NULL;
		uintptr_t Cache_Bluetime_PTR = NULL;
		uintptr_t Cache_PropertData_PTR = NULL;
		PropertyDataID Cache_PropertyDataID = { 0 };

	}Cache_LocalPlayer;

	//struct
	//{
	//	ActorModel* Min_ActorModel = nullptr;
	//	ActorModelPropertyData* Min_PropertyData = nullptr;
	//	ActorKit* Min_ActorKit = nullptr;
	//	RuntimePropertyData* Min_RuntimeProperty = nullptr;
	//	ObjectMessenger* Min_ObjectMessenger = nullptr;
	//	ActionHitSimulateData* Min_HitSimulate = nullptr;

	//	uintptr_t Cache_EventTracksForLayerPtr = NULL;
	//	uintptr_t Cache_PosPtr = NULL;
	//	uintptr_t Cache_ActorRootPtr = NULL;
	//	uintptr_t Cache_GetGlobalTime_PTR = NULL;
	//	uintptr_t Cache_GetCurTimeForLogicState_PTR = NULL;
	//	uintptr_t Cache_GetNameHash_PTR = NULL;
	//	uintptr_t Cache_Bluetime_PTR = NULL;
	//	uintptr_t Cache_PropertData_PTR = NULL;
	//	PropertyDataID Cache_PropertyDataID = { 0 };

	//}Cache_MinObj;

	struct 
	{
		AllSkillData* L_LocalSkillData = nullptr;
		uintptr_t Cache_Skill_PTR = NULL;
	}MySkillData;
}
struct ObjData
{
	ActorModel* O_ActorModel = nullptr;
	ActorModelPropertyData* O_PropertyData = nullptr;
	ActorKit* O_ActorKit = nullptr;
	RuntimePropertyData* O_RuntimeProperty = nullptr;
	ObjectMessenger* O_ObjectMessenger = nullptr;
	ActionHitSimulateData* O_HitSimulate = nullptr;

	uintptr_t Cache_EventTracksForLayerPtr = NULL;
	uintptr_t Cache_PosPtr = NULL;
	uintptr_t Cache_ActorRootPtr = NULL;
	uintptr_t Cache_GetGlobalTime_PTR = NULL;
	uintptr_t Cache_GetCurTimeForLogicState_PTR = NULL;
	uintptr_t Cache_GetNameHash_PTR = NULL;
	uintptr_t Cache_Bluetime_PTR = NULL;
	uintptr_t Cache_PropertData_PTR = NULL;
	PropertyDataID Cache_PropertyDataID = { 0 };

	bool ISRobot = false;
	int Team = 0;
	int HeroId = 0;
	string PlayerName = "";

};

struct PlayerData
{
	bool ISRobot = false;
	int Team = 0;
	int HeroId = 0;
	string PlayerName = "";
	//double ObjCurTime;

	string HeroName = "";
	
	wstring O_ActionName = L"";
	bool O_Visible = false;
	int O_WeaponID = 0;
	//int O_RangeReactionType;
	//unsigned int O_NameHash;
	WeaponType O_ActorWeapon;
	ActionType O_EndureLevel;
	Vector3 O_Pos = Vector3{0,0,0};
	float O_Dis = 0.f;
	int O_CurHp = 0;
	int O_MaxHp = 0;
	int O_Curshield = 0;
	int O_Maxshield = 0;
	int O_CurAnger =0;
	int O_MaxAnger = 0;

	uintptr_t Cache_GetCurTimeForLogicState_PTR = 0;
	uintptr_t Cache_ActorRootPtr = 0;
	uintptr_t Cache_HitSimulate = 0;
	uintptr_t Cache_NameHash = 0;
	uintptr_t O_ActorModel= 0;
};

struct 
{
	PlayerData MinObj;
	float RecentValue = 0.f;
	bool m_Lock = false;
	int speed = 100;
	int fov = 500;

}AimObj;

typedef struct
{
	ActionType MyEndureLevel;
	HeroType MyHero;
	wstring MyActionName;
	WeaponType MyWeaponType;
	int MyReactionType;
	int MyTeam;
	int MySkillID;
	int MySkillState;
	int MyCurrentCollisionFlags;
	float MyLeftContinueTime;
	float MyActionDuration;
	float MyCurTime;
	float MyBlueTime;
	Vector3 MyPos;
}LocalPlayer_Data1;

extern LocalPlayer_Data1 LocalPlayer_Data;

//struct
//{
//	ActionType Min_EndureLevel;
//	wstring Min_ActionName;
//	WeaponType Min_WeaponType;
//	bool Min_IsVisible = false;
//	unsigned int Min_NameHash = 0;
//	float Min_CurTime = 0.f;
//	float Min_BlueTime = 0.f;
//	float Min_Dis = 0.f;
//	Vector3 Min_Pos;
//}MinObj_Data;

namespace Function
{
	namespace ESP
	{
		extern bool 菜单;
		extern bool 菜单_2;
		extern bool 方框;
		extern bool 信息;
		extern bool 血条;
		extern bool 预警;
		extern bool 手持;
		extern bool 名字;

		extern bool 近战;
		extern bool 远程;
		extern bool 道具;
		extern bool 扩容;
		extern bool 金魂;
		extern bool 夺魂;
		extern bool 属性;
		extern bool 盒子;

		extern bool 护甲Lv1;
		extern bool 护甲Lv2;
		extern bool 护甲Lv3;
		extern bool 护甲Lv4;
		extern bool 护甲Lv5;

		extern bool 果实;
		extern bool 萤火虫;
		extern bool 金堆;
		extern bool 蓝堆;
		extern bool 绿堆;
		extern bool 任务;

		extern bool 堆堆Debug;

		extern int 血条样式;
		extern int 预警样式;
		extern ImColor 人机颜色;
		extern ImColor 玩家颜色;
		extern ImColor 名字颜色;
		extern ImColor 信息颜色;
	}
	namespace Kmbox
	{
		namespace Net
		{
			extern char IP[0XFF], Port[0XFF], mac[0XFF];
			extern int NetState;
		}
		namespace B_Pro
		{
			extern bool BproState;
			extern char PorttextBuffer[0XFF];
			extern char SpeedBuffer[0XFF];
		}
	}
	namespace Shock
	{
		extern bool F_ShockKnife;		//振刀功能开关
		extern bool F_MemShock;		//内存振
		extern bool 预判振刀;				//预判振噬魂斩 龙虎乱舞等等
		extern int Shock_Delay;				//振刀时机精度调整
		extern bool Flag_ShockKnife;	//振刀判断到需要振刀时，是否执行振刀
		extern bool Flag_CollideKnife;	//振刀判断到需要拼刀时，是否执行拼刀
		extern bool Flag_ShortDodge;	//振刀判断到需要闪避时，是否执行闪避
		extern bool 扬鞭劲振刀;
		extern bool 横栏振刀;
		extern bool 横刀左蓄振刀;
	}
	namespace LogicKnife
	{
		extern bool BlueAttackShock;	//出蓄抓振刀功能开关
		extern bool BlueAttackWrite;	//出蓄抓白刀功能开关
	}
	namespace HeroActivation
	{
		extern bool IsDodge;		//闪避功能开关
		extern bool 躲避火男F;
		extern bool 躲避火男冲拳;
		extern bool 躲避妖刀大招;
		extern bool 躲避顾清寒V1V2;
		extern bool 躲避武田F;
		extern bool 躲避胡为;
		extern bool 躲避宁红叶F;
		extern bool 躲避狐狸大招;
		extern bool 躲避三娘V2;
		extern bool 躲避哈迪大招;
		extern bool 躲避魏轻F1;
		extern bool 躲避魏轻V;

		extern bool 武田自动毛刀;
		extern bool 和尚自动F2;

		namespace 特殊处理
		{
			extern bool 永远躲避顾倾寒V1;
		}
	}
	namespace Flag
	{
		extern bool IsMyManage;					//自身是否可以振刀的FLAG
		extern bool IsBlueToRed;					//自身是否可以续转
		extern bool ISAtoG;							//判断招式是否可以G震
		extern bool HeroTianHaiF2;				//天海是否可以使用F2
	}
}

struct ItemInfoData
{
	uint32_t ID = 0;
	uint32_t  ItemType = 0;
	Vector3 Pos = { 0.f,0.f,0.f };
	string Name = {};
	ImColor Color = {};
};
struct InteractiveInfoData
{
	uint32_t ID = 0;
	uint32_t status = 0;//是否被打开
	Vector3 Pos = { 0.f,0.f,0.f };
	string Name = {};
	ImColor Color = {};
	uint32_t  ItemType = 0;
};
inline float MATRIX[4][4];
inline vector<ObjData> 全_游戏数据;
inline vector<PlayerData> 全_玩家数据;
inline vector<ItemInfoData> 全_物品数据;
inline vector<InteractiveInfoData> 全_金堆数据;

inline bool 全_玩家交互 = false;

namespace Color
{
	inline ImColor 大理石灰 = ImColor(196, 203, 207, 255);
	inline ImColor 润红 = ImColor(221, 68, 68, 255);
	inline ImColor 竹篁绿 = ImColor(119, 252, 119, 255);
	inline ImColor 星蓝 = ImColor(85, 117, 209, 255);
	inline ImColor 向日葵黄 = ImColor(239, 221, 53, 255);
	inline ImColor 美人焦橙 = ImColor(205, 149, 12, 255);
	inline ImColor 淡牵牛紫 = ImColor(193, 82, 254, 255);
}
struct ItemData
{
	string Name;
	ImColor color;
	uint32_t itemType;
};
struct InteraData
{
	string Name;
	ImColor color;
	uint32_t itemType;
};
inline map<uint32_t, ItemData> itemTable = {

	{3040002,{"魂冢",Color::向日葵黄,1}},
	//果实
	{3010008,{"[果实]-刺梨",Color::大理石灰,2}},
	{3010009,{"[果实]-沙叻",Color::润红,2}},
	{3010050,{"[果实]-沙梨",Color::美人焦橙,2}},
	{3010007,{"[状态]-蒲公英",Color::大理石灰,2}},
	{3010005,{"[怒气]-萤火虫",Color::美人焦橙,14}},
	//护甲
	{3005001 ,{"护甲Lv1",Color::大理石灰,10}},
	{3005002 ,{"护甲Lv2",Color::星蓝,11}},
	{3005003 ,{"护甲Lv3",Color::淡牵牛紫,12}},
	{3005004 ,{"护甲Lv4",Color::美人焦橙,13}},
	{3005005 ,{"护甲Lv5",Color::美人焦橙,15}},
	//道具
	{3040001 , {"[道具]-暗潮币",Color::美人焦橙,4}},
	{3010004 , {"[道具]-凝血丸",Color::大理石灰,4}},
	{3010006 , {"[道具]-大包凝血丸",Color::润红,4}},
	{3010023 , {"[道具]-护甲粉末",Color::大理石灰,4}},
	{3010024 , {"[道具]-高级护甲粉末",Color::淡牵牛紫,4}},
	{3010018 , {"[道具]-武备匣",Color::大理石灰,4}},
	{3010020 , {"[道具]-飞索线轴",Color::星蓝,4}},

	{3010001 , {"[扩容]-魂玉扩容",Color::星蓝,16}},
	{3010002 , {"[扩容]-武器扩容",Color::星蓝,16}},
	{3010003 , {"[扩容]-道具扩容",Color::星蓝,16}},
	//近战
	{3000100 , {"[近战]-匕首",Color::大理石灰,5}},
	{3000110 , {"[近战]-匕首",Color::星蓝,5}},
	{3000120 , {"[近战]-匕首",Color::淡牵牛紫,5}},
	{3000130 , {"[近战]-匕首",Color::美人焦橙,5}},
	{3001500 , {"[近战]-双截棍",Color::大理石灰,5}},
	{3001510 , {"[近战]-双截棍",Color::星蓝,5}},
	{3001520 , {"[近战]-双截棍",Color::淡牵牛紫,5}},
	{3001530 , {"[近战]-双截棍",Color::美人焦橙,5}},
	{3000001 , {"[近战]-长剑",Color::大理石灰,5}},
	{3000011 , {"[近战]-长剑",Color::星蓝,5}},
	{3000021 , {"[近战]-长剑",Color::淡牵牛紫,5}},
	{3000031 , {"[近战]-长剑",Color::美人焦橙,5}},
	{3000300 , {"[近战]-太刀",Color::大理石灰,5}},
	{3000310 , {"[近战]-太刀",Color::星蓝,5}},
	{3000320 , {"[近战]-太刀",Color::淡牵牛紫,5}},
	{3000330 , {"[近战]-太刀",Color::美人焦橙,5}},
	{3000400 , {"[近战]-阔刀",Color::大理石灰,5}},
	{3000410 , {"[近战]-阔刀",Color::星蓝,5}},
	{3000420 , {"[近战]-阔刀",Color::淡牵牛紫,5}},
	{3000430 , {"[近战]-阔刀",Color::美人焦橙,5}},
	{3000200 , {"[近战]-枪",Color::大理石灰,5}},
	{3000210 , {"[近战]-枪",Color::星蓝,5}},
	{3000220 , {"[近战]-枪",Color::淡牵牛紫,5}},
	{3000230 , {"[近战]-枪",Color::美人焦橙,5}},
	{3001600 , {"[近战]-双刀",Color::大理石灰,5}},
	{3001610 , {"[近战]-双刀",Color::星蓝,5}},
	{3001620 , {"[近战]-双刀",Color::淡牵牛紫,5}},
	{3001630 , {"[近战]-双刀",Color::美人焦橙,5}},
	{3001700 , {"[近战]-斩马刀",Color::大理石灰,5}},
	{3001710 , {"[近战]-斩马刀",Color::星蓝,5}},
	{3001720 , {"[近战]-斩马刀",Color::淡牵牛紫,5}},
	{3001730 , {"[近战]-斩马刀",Color::美人焦橙,5}},
	{3001900 , {"[近战]-双戟",Color::大理石灰,5}},
	{3001910 , {"[近战]-双戟",Color::星蓝,5}},
	{3001920 , {"[近战]-双戟",Color::淡牵牛紫,5}},
	{3001930 , {"[近战]-双戟",Color::美人焦橙,5}},
	{3002000 , {"[近战]-扇子",Color::大理石灰,5}},
	{3002010 , {"[近战]-扇子",Color::星蓝,5}},
	{3002020 , {"[近战]-扇子",Color::淡牵牛紫,5}},
	{3002030 , {"[近战]-扇子",Color::美人焦橙,5}},
	{3001800 , {"[近战]-长棍",Color::大理石灰,5}},
	{3001810 , {"[近战]-长棍",Color::星蓝,5}},
	{3001820 , {"[近战]-长棍",Color::淡牵牛紫,5}},
	{3001830 , {"[近战]-长棍",Color::美人焦橙,5}},
	//远程
	{ 3001200,{"[远程]-鸟铳",Color::大理石灰,6}},
	{ 3001210,{"[远程]-鸟铳",Color::星蓝,6}},
	{ 3001220,{"[远程]-鸟铳",Color::淡牵牛紫,6}},
	{ 3001230,{"[远程]-鸟铳",Color::美人焦橙,6}},
	{ 3000501,{"[远程]-弓箭",Color::大理石灰,6}},
	{ 3000511,{"[远程]-弓箭",Color::星蓝,6}},
	{ 3000521,{"[远程]-弓箭",Color::淡牵牛紫,6}},
	{ 3000531,{"[远程]-弓箭",Color::美人焦橙,6}},
	{ 3000800,{"[远程]-火炮",Color::大理石灰,6}},
	{ 3000810,{"[远程]-火炮",Color::星蓝,6}},
	{ 3000820,{"[远程]-火炮",Color::淡牵牛紫,6}},
	{ 3000830,{"[远程]-火炮",Color::美人焦橙,6}},
	{ 3001000,{"[远程]-一窝蜂",Color::大理石灰,6}},
	{ 3001010,{"[远程]-一窝蜂",Color::星蓝,6}},
	{ 3001020,{"[远程]-一窝蜂",Color::淡牵牛紫,6}},
	{ 3001030,{"[远程]-一窝蜂",Color::美人焦橙,6}},
	{ 3001100,{"[远程]-五眼铳",Color::大理石灰,6}},
	{ 3001110,{"[远程]-五眼铳",Color::星蓝,6}},
	{ 3001120,{"[远程]-五眼铳",Color::淡牵牛紫,6}},
	{ 3001130,{"[远程]-五眼铳",Color::美人焦橙,6}},
	{ 3000700,{"[远程]-连弩",Color::大理石灰,6}},
	{ 3000710,{"[远程]-连弩",Color::星蓝,6}},
	{ 3000720,{"[远程]-连弩",Color::淡牵牛紫,6}},
	{ 3000730,{"[远程]-连弩",Color::美人焦橙,6}},
	{ 3000900,{"[远程]-喷火筒",Color::大理石灰,6}},
	{ 3000910,{"[远程]-喷火筒",Color::大理石灰,6}},
	{ 3000920,{"[远程]-喷火筒",Color::淡牵牛紫,6}},
	{ 3000930,{"[远程]-喷火筒",Color::美人焦橙,6}},
	//夺魂
	{ 3020094,{"[魂玉]-夺魂·太刀",Color::淡牵牛紫,7}},
	{ 3020096,{"[魂玉]-夺魂·长剑",Color::淡牵牛紫,7}},
	{ 3020095,{"[魂玉]-夺魂·重刃",Color::淡牵牛紫,7}},
	{ 3020135,{"[魂玉]-夺魂·长兵器",Color::淡牵牛紫,7}},
	{ 3020159,{"[魂玉]-夺魂·短兵器",Color::淡牵牛紫,7}},
	{ 3020161,{"[魂玉]-夺魂·双截棍",Color::淡牵牛紫,7}},
	{ 3020180,{"[魂玉]-夺魂·双持",Color::淡牵牛紫,7}},
	//金魂玉
	{ 3020084,{"[魂玉]-噬魂斩",Color::美人焦橙,8} },
	{ 3020127,{"[魂玉]-惊雷十劫",Color::美人焦橙,8} },
	{ 3020132,{"[魂玉]-巽风震雷刀",Color::美人焦橙,8} },
	{ 3020193,{"[魂玉]-过关斩将",Color::美人焦橙,8} },
	{ 3020185,{"[魂玉]-七星夺窍",Color::美人焦橙,8} },
	{ 3020091,{"[魂玉]-凤凰羽",Color::美人焦橙,8} },
	{ 3020145,{"[魂玉]-风火穿心脚",Color::美人焦橙,8} },
	{ 3020188,{"[魂玉]-五情七灭阵",Color::美人焦橙,8} },
	{ 3020138,{"[魂玉]-狂浪怒涛",Color::美人焦橙,8} },
	{ 3020195,{"[魂玉]-定海针·镇地撑天",Color::美人焦橙,8} },
	{ 3020142,{"[魂玉]-鬼哭神嚎",Color::美人焦橙,8} },
	{ 3020211,{"[魂玉]-缠龙奔野",Color::美人焦橙,8} },
	{ 3020158,{"[魂玉]-虎啸龙咆",Color::美人焦橙,8} },
	{ 3020183,{"[魂玉]-乾坤日月斩",Color::美人焦橙,8} },
	{ 3020206,{"[魂玉]-战龙在天",Color::美人焦橙,8} },
	{ 3020177,{"[魂玉]-亢龙有悔",Color::美人焦橙,8} },
	{ 3020101,{"[魂玉]-爆裂箭",Color::美人焦橙,8} },
	{ 3020122,{"[魂玉]-火龙炮",Color::美人焦橙,8} },
	{ 3020121,{"[魂玉]-御地雷",Color::美人焦橙,8} },
	{ 3020110,{"[魂玉]-穿甲弹",Color::美人焦橙,8} },
	{ 3020156,{"[魂玉]-续命术",Color::美人焦橙,8} },
	{ 3020116,{"[魂玉]-魂燃一线",Color::美人焦橙,8} },
	{ 3020124,{"[魂玉]-抽芯补天",Color::美人焦橙,8} },
	{ 3020151,{"[魂玉]-灵光一现",Color::美人焦橙,8} },
	{ 3020079,{"[魂玉]-毕工淌",Color::美人焦橙,8} },
	{ 3020164,{"[魂玉]-召雷术",Color::美人焦橙,8} },
	//属性
	{ 3020001,{"[魂玉]-大魂玉·体力",Color::美人焦橙,9}},
	{ 3020011,{"[魂玉]-大魂玉·攻击",Color::美人焦橙,9}},
	{ 3020051,{"[魂玉]-大魂玉·近抗",Color::美人焦橙,9}},
	{ 3020061,{"[魂玉]-大魂玉·远抗",Color::美人焦橙,9}},
};
inline map<uint32_t, InteraData > InteractiveTable =
{
	{ 4000003 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4000007 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4000016 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4000019 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4000305 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002004 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002012 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002105 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002112 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002200 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002203 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002208 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002211 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002900 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002901 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002920 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002923 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002928 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002931 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002932 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002935 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002937 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002940 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002942 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002943 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002946 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002949 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002954 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002957 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002958 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002964 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002961 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002958 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002979 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002976 , {"[落物堆]-绿",Color::竹篁绿,1}},
    { 4002973 , {"[落物堆]-绿",Color::竹篁绿,1}},

	{ 4000005 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4000008 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4000014 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4000017 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002002 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002010 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002106 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002113 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002201 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002204 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002206 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002209 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002921 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002924 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002926 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002929 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002933 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002947 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002950 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002952 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002955 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002959 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002965 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002962 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002959 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002980 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002977 , {"[落物堆]-蓝",Color::星蓝,2}},
    { 4002974 , {"[落物堆]-蓝",Color::星蓝,2}},

	{ 4000006 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4000009 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4000015 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4000018 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4000203 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4000204 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002003 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002011 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002107 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002114 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002202 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002205 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002207 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002210 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002902 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002903 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002922 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002925 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002927 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002930 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002934 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002936 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002938 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002939 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002941 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002944 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002948 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002951 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002953 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002956 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002966 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002963 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002960 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002981 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002978 , {"[落物堆]-金",Color::向日葵黄,3}},
    { 4002975 , {"[落物堆]-金",Color::向日葵黄,3}},

	{ 4000999 , {"[任务]-普通",Color::向日葵黄,4}},
	{ 4000998 , {"[任务]-追击",Color::淡牵牛紫,4}},
	{ 4000997 , {"[任务]-叫阵",Color::润红,4}},
};

namespace BlueAttackFront
{
	inline float 长剑剑气 = 0.232f;
	inline float 长剑凤凰羽 = 0.222f;
	inline float 太刀百裂 = 0.202f;
	inline float 太刀噬魂斩 = 0.f;
	inline float 阔刀站走右蓄 = 0.212f;
	inline float 阔刀滑步右蓄 = 0.303f;
	inline float 阔刀左蓄1段 = 0.492f;
	inline float 阔刀左蓄2段 = 0.522f;
	inline float 阔刀左蓄3段 = 0.463f;
	inline float 阔刀左右 = 0.243f;
	inline float 阔刀左右捏蓄 = 0.303f;
	inline float 阔刀右右 = 0.496f;
	inline float 长枪左蓄 = 0.402f;
	inline float 长枪右蓄 = 0.342f;
	inline float 匕首左蓄 = 0.234f;
	inline float 匕首右蓄 = 0.202f;
	inline float 匕首亢龙有悔 = 0.204f;
	inline float 双节棍左蓄 = 0.283f;
	inline float 双节棍右蓄 = 0.213f;
	inline float 双节棍扬鞭劲 = 0.148f;
	inline float 双节棍虎啸龙咆 = 0.123f;
	inline float 双刀铁马残红 = 0.202f;
	inline float 双刀右蓄 = 0.203f;
	inline float 长棍左蓄 = 0.254f;
	inline float 长棍右蓄 = 0.248f;
	inline float 长棍桶劲 = 0.201f;
	inline float 长棍腾云式 = 0.27f;
	inline float 斩马刀左蓄 = 0.232f;
	inline float 斩马刀左右 = 0.247f;
	inline float 斩马刀右右 = 0.497f;
	inline float 斩马刀右蓄 = 0.402f;
	inline float 斩马刀炽焰斩 = 0.252f;
	inline float 斩马刀过关斩将 = 0.452f;
	inline float 横刀左蓄 = 0.485f;
	inline float 横刀右蓄 = 0.225f;
	inline float 横刀极光碎云闪 = 0.248f;
}


typedef struct 
{
	float 左3;
	float 右3;
	float 左剑气;
	float 右剑气;
	float 凤凰羽;
	float 蓝月;
	float 七星夺窍;
}长剑1;		//0-13米
typedef struct
{
	float 左3;
	float 右3;
	float 左蓄;
	float 右蓄;
	float 左惊雷;
	float 右惊雷;	//惊雷十劫和此参数一样
	float 左青鬼;
	float 右青鬼;
	float 噬魂斩;
}太刀1;			//0-11M;
typedef struct
{
	float 左左;
	float 左右;
	float 右右;
	float 右左;
	float 左蓄一段;
	float 左蓄二段;
	float 左蓄三段;
	float 右蓄;
	float 右右蓄;
	float 雷刀;
	float 雷刀下劈;
}阔刀1;			//0-9.5M
typedef struct
{
	float 左3;
	float 右3;
	float 左蓄;
	float 六合枪;
	float 右蓄;
	float 大圣游;
	float 风卷云残;
	float 双环扫;
	float 龙王破;
	float 穿心脚;
}长枪1;			//0-11M
typedef struct
{
	float 左3;
	float 右3;
	float 左蓄;
	float 右蓄;
	float 鬼反;
	float 荆轲献匕;
	float 鬼刃暗扎;
	float 鬼哭神嚎;
	float 亢龙有悔;
}匕首1;			//0-10M
typedef struct
{
	float 左右3;
	float 左蓄;
	float 右蓄;
	float 飞踢;
	float 扬鞭劲;
	float 横栏;
	float 龙虎乱舞;
}双截棍1;			//0-8M
typedef struct
{
	float 左右3;
	float 左蓄;
	float 右蓄;
	float 铁马残红;
	float 乾坤日月斩;
	float 惊雷;
	float 八斩刀;
	float 分水斩;
}双刀1;		//0-10M
typedef struct
{
	float 左3;
	float 右3;
	float 少林棍;
	float 左蓄;
	float 右蓄;
	float 腾云式;
	float 乱点天宫;
	float 桶劲;
	float 五情七灭镇;
	float 双环扫;
	float 倒海棍;
	float 镇地撑天;
}长棍1;		//0-14M
typedef struct
{
	float 左左;
	float 左右;
	float 右右;
	float 右左;
	float 左蓄;
	float 右蓄;
	float 柄击;
	float 惊雷;
	float 炽焰斩;
	float 过关斩将;
}斩马刀1;		//0-9M
typedef struct
{
	float 左右3;
	float 左蓄;
	float 右蓄;
	float 勾旋斩;
	float 探海蛟;
	float 钩挂;
	float 战龙在天;
	float 形意钩;
}双戟1;		//0-8M
typedef struct
{
	float 左3;
	float 右3;
	float 左蓄;
	float 右蓄;
	float 双开圆;
	float 三风摆;
	float 鬼反;
	float 惊雷;
	float 缠龙奔野;
}扇子1;		//0-12.5M
typedef struct
{
	float 左3;
	float 右3;
	float 左蓄;
	float 右蓄;
	float 破千军;
	float 极光破云闪;
}横刀1;		//0-7M

typedef struct
{
	float 左3;
	float 右3;
	float 左剑气2M;
	float 左剑气4M;
	float 左剑气6M;
	float 左剑气9M;
	float 左剑气9M外;
	float 右剑气2M;
	float 右剑气4M;
	float 右剑气6M;
	float 右剑气9M;
	float 右剑气9M外;
	float 凤凰羽2M;
	float 凤凰羽5M;
	float 凤凰羽8M;
	float 凤凰羽8M外;
	float 蓝月2M;
	float 蓝月6M;
	float 蓝月6M外;
	float 七星夺窍;
}长剑2;
typedef struct
{
	float 左3;
	float 右3;
	float 左蓄2M;
	float 左蓄2M外;
	float 右蓄2M;
	float 右蓄2M外;
	float 左惊雷;
	float 右惊雷5M;//惊雷十劫和此参数一样
	float 右惊雷5M外;	//惊雷十劫和此参数一样
	float 左青鬼;
	float 右青鬼;
}太刀2;
typedef struct
{
	float 左左;
	float 左右2M;
	float 左右2M外;
	float 右右;
	float 右左;
	float 左蓄一段2M;
	float 左蓄一段2M外;
	float 右蓄2M;
	float 右蓄2M外;
	float 右右蓄2M;
	float 右右蓄2M外;
}阔刀2;
typedef struct
{
	float 左3;
	float 右3;
	float 左蓄;
	float 六合枪2M;
	float 六合枪2M外;
	float 右蓄;
	float 大圣游;
	float 风卷云残;
	float 龙王破2M;
	float 龙王破2M外;
	float 穿心脚2M;
	float 穿心脚2M外;
}长枪2;
typedef struct
{
	float 左3;
	float 右3;
	float 左蓄2M;
	float 左蓄2M外;
	float 右蓄2M;
	float 右蓄2M外;
	float 鬼反;
	float 荆轲献匕2M;
	float 荆轲献匕2M外;
	float 鬼刃暗扎2M;
	float 鬼刃暗扎2M外;
	float 亢龙有悔2M;
	float 亢龙有悔4M;
	float 亢龙有悔4M外;
}匕首2;
typedef struct
{
	float 左右3;
	float 左蓄2M;
	float 左蓄2M外;
	float 右蓄2M;
	float 右蓄2M外;
	float 飞踢;
	float 扬鞭劲;
	float 横栏;
}双截棍2;
typedef struct
{
	float 左右3;
	float 左蓄;
	float 右蓄;
	float 铁马残红3M;
	float 铁马残红3M外;
	float 乾坤日月斩;
	float 惊雷;
	float 八斩刀;
	float 分水斩;
}双刀2;
typedef struct
{
	float 左3;
	float 右3;
	float 少林棍;
	float 左蓄2M;
	float 左蓄2M外;
	float 腾云式2M;
	float 腾云式2M外;
	float 乱点天宫;
	float 桶劲;
	float 五情七灭镇8M;
	float 五情七灭镇8M外;
	float 双环扫;
	float 倒海棍;
	float 镇地撑天;
}长棍2;
typedef struct
{
	float 左左;
	float 左右2M;
	float 左右2M外;
	float 右右;
	float 右左;
	float 左蓄2M;
	float 左蓄2M外;
	float 右蓄;
	float 柄击;
	float 惊雷;
	float 炽焰斩;
	float 过关斩将;
}斩马刀2;
typedef struct
{
	float 左右3;
	float 左蓄3M;
	float 左蓄3M外;
	float 右蓄3M;
	float 右蓄3M外;
	float 勾旋斩;
	float 探海蛟;
	float 钩挂;
	float 战龙在天;
	float 形意钩;
}双戟2;
typedef struct
{
	float 左3;
	float 右3;
	float 左蓄;
	float 右蓄2M;
	float 右蓄2M外;
	float 双开圆;
	float 三风摆3M;
	float 三风摆3M外;
	float 鬼反;
	float 惊雷;
	float 缠龙奔野3M;
	float 缠龙奔野3M外;
}扇子2;
typedef struct
{
	float 左3;
	float 右3;
	float 左蓄;
	float 右蓄;
	float 破千军;
	float 极光破云闪;
}横刀2;

namespace 振刀参数
{
	namespace 距离
	{
		extern 长剑1 长剑;
		extern 太刀1 太刀;
		extern 阔刀1 阔刀;
		extern 长枪1 长枪;
		extern 匕首1 匕首;
		extern 双截棍1 双截棍;
		extern 双刀1 双刀;
		extern 长棍1 长棍;
		extern 斩马刀1 斩马刀;
		extern 双戟1 双戟;
		extern 扇子1 扇子;
		extern 横刀1 横刀;
	}

	namespace 角度
	{
		extern 长剑2 长剑;
		extern 太刀2 太刀;
		extern 阔刀2 阔刀;
		extern 长枪2 长枪;
		extern 匕首2 匕首;
		extern 双截棍2 双截棍;
		extern 双刀2 双刀;
		extern 长棍2 长棍;
		extern 斩马刀2 斩马刀;
		extern 双戟2 双戟;
		extern 扇子2 扇子;
		extern 横刀2 横刀;
	}
	namespace 特殊处理
	{
		extern bool 阔刀右蓄是否短闪振;
		extern bool 双截棍左蓄是否短闪振;
		extern bool 斩马刀左蓄是否长闪振;
		extern bool 扇子左蓄是否中闪振;
		extern bool 扇子右蓄是否中闪振;
		extern bool 横刀左蓄是否只短闪;
	}
}

namespace 活化参数
{
	namespace 距离
	{
		extern float 火男冲拳;
		extern float 妖刀大招;
		extern float 顾倾寒大招;
		extern float 武田F2;
		extern float 武田F3;
		extern float 胡为F1;
		extern float 胡为F2;
		extern float 胡为跃击;
		extern float 胡为V1V2;
		extern float 宁红叶F1;
		extern float 宁红叶F2;
		extern float 宁红叶F3;
		extern float 狐狸大招;
		extern float 火男F;
		extern float 三娘V2;
		extern float 哈迪大招2段;
		extern float 哈迪大招3段;
		extern float 魏轻F1;
		extern float 魏轻V1;
		extern float 魏轻V2;
	}

	namespace 角度
	{
		extern float 火男冲拳;
		extern float 妖刀大招3M;
		extern float 妖刀大招3M外;
		extern float 顾倾寒大招3M;
		extern float 顾倾寒大招3M外;
		extern float 武田F21M;
		extern float 武田F21M外;
		extern float 武田F31M;
		extern float 武田F31M外;
		extern float 胡为F2;
		extern float 胡为跃击;
		extern float 胡为V1V2;
		extern float 宁红叶F1;
		extern float 宁红叶F2;
		extern float 宁红叶F3;
		extern float 狐狸大招4M;
		extern float 狐狸大招8M;
		extern float 狐狸大招12M;
		extern float 狐狸大招12M外;
		extern float 火男F;
		extern float 三娘V24M;
		extern float 三娘V210M;
		extern float 三娘V210M外;
		extern float 哈迪大招;
		extern float 魏轻V1;
		extern float 魏轻V2;
	}

	extern int 出蓄抓振延迟;
}

typedef struct
{
	string 敌人类型;
	string 敌人动作;
	string 执行动作;
	float 判断角度;
	float 执行角度;
	float 执行距离;
}逻辑执行1;		//这个结构体无需加在菜单，随动的

namespace 调试
{
	extern 逻辑执行1 逻辑执行;
	extern bool 输出逻辑执行;
	extern bool 输出逻辑执行Flag;		//这个不用加在菜单，随动的。
	extern bool 输出调试执行;
}