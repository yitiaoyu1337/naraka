#include <stdio.h>
#include "Offset.h"
#include "Vector.h"
#include "Kmbox.cpp"
inline _com myserial;
//存放武器类型
enum WeaponType :int
{
	Node = 100,				//空手
	Sw = 101,					//长剑
	Katana = 102,			//太刀
	Blade = 103,				//阔刀
	Spear = 105,				//长枪
	Dagge = 106,				//匕首
	喷火筒 = 110,
	nunchucks = 116,		//双节棍	
	twinblades = 118,		//双刀
	saber = 119,				//斩马刀
	rod = 120,					//棍
	dualhalberd = 121,	//双戟
	fan = 122,				//扇子
	hengdao = 123,		//横刀
	tiebian = 207,			//季莹莹大招
	hadidazhao = 208,	//哈迪大招

	//远程
	弓箭 = 104,
	连弩 = 108,
	火炮 = 109,
	喷火筒1 = 110,
	一窝蜂 = 111,
	五眼铳 = 112,
	鸟铳 = 113,
	三娘水矛 = 203,
	大佛手 = 204,
	神妙机甲 = 206
};
//英雄ID
enum HeroType :int
{
	hutao = 1000001,
	ninghongye = 1000003,
	jianan = 1000004,
	shanan = 1000005,
	jicanghai = 1000006,
	tianhai = 1000007,
	dafo = 1000008,
	yaodaoji = 1000009,
	cuisanniang = 1000010,
	yueshan = 1000011,
	shenjiang = 1000012,
	wuchen = 1000013,
	guqinghan = 1000015,
	wutian = 1000016,
	yinziping = 1000017,
	shenmiao = 1000018,
	tiewei = 1000019,
	huwei = 1000020,
	jiyingying = 1000021,
	yulinglong = 1000022,
	hadi = 1000023,
	weiqing = 1000024
};
//人物状态
enum ActionType :int
{
	Normal = 5,					//空手
	Hurt = 6,						//英雄挨打
	WhithAttack = 11,			//白
	BuleAttack = 20,			//蓝
	PurpleAttack = 21,			//紫霸体
	BuleAttack2 = 22,			//蓝
	ShockKnife = 30,			//金霸体出刀
	GoldState = 31,				//金霸体
	TianhaiF = 50,				//和尚放F的霸体
	AwakenGole = 51,			//奥义金霸体(90减伤)
	NinghongyeAwaken = 52,	//宁红夜大招
	AwakenIng = 53,		//奥义金霸体后续(超高减伤)
	GuqinghanF = 59,		//顾清寒被自己F冻住时
};
//血、甲、精等等
struct PropertyDataID
{
	int CurHpID;						//当前血量
	int HpMaxID;						//最大血量
	int CurshieldID;					//当前护甲
	int shieldMaxID;					//最大护甲
	int CurEnergyID;					//当前精力
	int EnergyMaxID;					//最大精力
};
struct WeaponData
{
	ImColor WeaponColor = { 0,0,0 };
	string WeaponName = "";
};
//ActorModel->ActorModelPropertyData结构体数据 人物属性相关数据
class ActorModelPropertyData
{
public:
	bool GetISRobotId();						//ActorModel->ActorModelPropertyData->ISRobotId判断数据 判断是否是人机
	int GetTeam();								//ActorModel->ActorModelPropertyData->Group整形数据 判断人物在哪个组里面
	HeroType GetHeroTID();					//ActorModel->ActorModelPropertyData->HeroTid整形数据 判断人物英雄ID
	int GetWeaponID();						//ActorModel->ActorModelPropertyData->WeaponID整形数据 判断人物手持武器具体ID
	std::string GetPlayerName();			//获取玩家名称
};

//ActorModel->ActorKit->GetActionHitSimulateData结构 人物出招时的状态
class ActionHitSimulateData
{
public:
	ActionType GetEndureLevel();						//ActorModel->ActorKit->GetActionHitSimulateData->EndureLevel枚举数据 人物当前出招状态
	int GetReactionType();								//ActorModel->ActorKit->GetActionHitSimulateData->ReactionType整形数据 为2则是可以拼刀状态，1是磐石
	int GetRangeReactionType();						//为12则是攻击状态
	float GetActionDuration();							//人物僵直
};

//ActorModel->ActorKit结构体数据 人物招式相关数据
class ActorKit
{
public:
	uintptr_t Cache_BlueTime();
	uintptr_t Cache_ActorPhysics();
	float BlueTime(uintptr_t Cache_Bluetime_PTR);														//ActorModel->ActorKit->BlueTime浮点型数据 人物进蓝的时间
	ActionHitSimulateData* GetActionHitSimulateData();	//ActorModel->ActorKit->GetActionHitSimulateData指针数据 指向ActionHitSimulateData结构
};

//获取当前血甲精等等
class RuntimePropertyData
{
public:
	PropertyDataID GetPropertyDataID();
	uintptr_t Cache_PropertData();
	int GetCurHp(uintptr_t Cache_PropertData_PTR, PropertyDataID Cache_PropertyDataID);					//当前血量
	int GetHpMax(uintptr_t Cache_PropertData_PTR, PropertyDataID Cache_PropertyDataID);					//最大血量
	int GetCurshield(uintptr_t Cache_PropertData_PTR, PropertyDataID Cache_PropertyDataID);				//当前护甲
	int GetshieldMax(uintptr_t Cache_PropertData_PTR, PropertyDataID Cache_PropertyDataID);				//最大护甲
	int GetCurEnergy(uintptr_t Cache_PropertData_PTR, PropertyDataID Cache_PropertyDataID);				//当前精力
	int GetEnergyMax(uintptr_t Cache_PropertData_PTR, PropertyDataID Cache_PropertyDataID);				//最大精力
	int GetCurAnger(uintptr_t Cache_PropertData_PTR);				//当前怒气
	int GetAngerMax(uintptr_t Cache_PropertData_PTR);				//最大怒气
};

//ActorModel->ObjectMessenger结构体数据，人物动画相关
class ObjectMessenger
{
public:
	uintptr_t Cache_GetGlobalTime();
	uintptr_t Cache_GetCurTimeForLogicState();
	float GetCurTimeForLogicStateA(uintptr_t Cache_GetGlobalTime_PTR, uintptr_t Cache_GetCurTimeForLogicState_PTR);				//当前动画执行时间
	uintptr_t Cache_GetNameHash();
	unsigned int GetNameHash(uintptr_t Cache_GetNameHash_PTR);				//动画hash
};

//ActorModel结构体数据（是一个数组 周围有多名玩家）
class ActorModel
{
public:
	//int GetType();																												//ActorModel->Type整形数据 人物类型数据如果是35FD则为人物
	bool IsVisible();																												//ActorModel->IsVisible判断数据 判断自身视野内是否有敌人如果为1则有反之没有
	bool IsAlive();																												//ActorModel->IsVisibleAlive 判断人物是否存活，如果为101则存活
	//以下为获取动画名称缓存写法:在调用GetActorName之前一定要先调用过GetEventTracksForLayer获取到缓存
	uintptr_t Cache_GetEventTracksForLayer();			
	std::wstring  GetActorName(uintptr_t EventTracksForLayerPtr);
	//以下为获取Pos缓存写法:先调用GetPosPtr之前一定要先调用过GetPosPtr确保获取到缓存
	uintptr_t Cache_GetPosPtr();																										//ActorModel->Vector指针数据 人物坐标数据
	Vector3 GetPos(uintptr_t PosPtr);
	//以下是角度获取
	uintptr_t Cache_GetActorRootPtr();
	//BOOL CheckPlayerAngle(uintptr_t ActorRootPtr, Vector3 ObjPos, float NewAngle);		//ActorModel->Actor角度检查

	WeaponType GetActorWeapon();																					//ActorModel->ActorWeapon指针数据	指向ActorWeapon武器结构
	ActorModelPropertyData* GetActorModelPropertyData();													//ActorModel->ActorModelPropertyData指针数据 指向ActorModelPropertyData结构
	ActorKit* GetActorKit();																									//ActorModel->ActorKit指针数据 指向ActorKit结构
	RuntimePropertyData* GetRuntimePropertyData();															//ActorModel->RuntimePropertyData指针数据	指向RuntimePropertyData结构
	ObjectMessenger* GetObjectMessenger();
};

class CharacterManager
{
public:
	uintptr_t CharacterManagerPtr = NULL;
	uintptr_t Cache_PlayerCount_ActorModelList_Ptr = NULL;
	void GetCharacterManagerPtr();							//CharacterManager 人物管理器
	void Cache_PlayerCount_ActorModelList();				//Count与List的缓存
	int GetPlayerCount();										//CharacterCount整形数据 周围多少人数据
	ActorModel* GetLocalActorModel();					//LocalActorModel指针数据 本人数据	指针指向本人地址
	ActorModel* GetActorModelList(int index);			//ActorModel指针数据 指针指向周围人物地址（以上面数量形式进行遍历，包括本人，敌人）
};

//获取技能CD等结构
class AllSkillData
{
public:
	int GetCount();
	uintptr_t Cache_Skill();
	int GetSkillID(uintptr_t Cache_Skill_PTR);								//获取本人技能ID
	int GetSkillState(uintptr_t Cache_Skill_PTR);							//获取本人技能状态
	float Get_LeftCdTime(uintptr_t Cache_Skill_PTR);					//当前技能CD
	float Get_LeftContinueTime(uintptr_t Cache_Skill_PTR);			//当前技能持续时间
};

class UserDataManager
{
public:
	uintptr_t UserDataManagerPtr = NULL;
	void GetUserDataManager();
	AllSkillData* GetAllSkillDataList();
	bool IsSpectator();												//是否是观战
};

//获取ping结构
class CharactorSyncManager
{
public:
	uintptr_t CharactorSyncManagerPtr = NULL;
	void GetCharactorSyncManager();
	float GamePing();
};

bool WorldToScreen(float MATRI[4][4], Vector3 Pos, Vec2& PM, Vec4& RW);

bool WorldToScreen_AIM(float MATRI[4][4], Vector3 Pos, Vector2& PM);

WeaponData GetWeaponData(uint32_t WeaponID);
string GetHeroType(int ID);
BOOL CheckPlayerAngle(uintptr_t ActorRootPtr, Vector3 ObjPos, Vector3 MyPos, float NewAngle);		//ActorModel->Actor角度检查
float GetAngle(uintptr_t ActorRootPtr, Vector3 ObjPos, Vector3 MyPos);
int GetRangeReactionType(uintptr_t HitSimulateData_PTR);
int GetReactionType(uintptr_t HitSimulateData_PTR);


uint64_t GetItemPosAddr(uint64_t Ptr);
inline int 按键方式 = 0;
//// 鼠标是否按下
//bool IsHokeyEx(int Key);
////物理监控鼠标按下
//bool KmboxIsHokeyMouse(int Key);
////物理监控键盘按下
//bool KmboxIsHokeyKey(short  vk_key);

//模拟键盘按下(kmbox)
void SendKeyPressEx(uint32_t Key);

//模拟键盘弹起(kmbox)
void SendKeyUpEx(uint32_t Key);

//左键按下弹起(物理)
void MouseLeftEx(int key);

//右键按下弹起(物理)
void MouseRightEx(int key);

//左右键弹起(物理)
void MouseLeftorRightUp();
//物理左键弹起
float GetAmmoFlySpeed(WeaponType ID, float LoaclBlueTime);
//获取敌人到准星距离
float GetAimDis(float x, float y, float ObjeX, float ObjeY);

void Kmbox_Move(int x, int y);

void Move_mouse(int x, int y);

void 按下键盘(int vk);

void 弹起键盘(int vk);

void 左键按下();

void 左键弹起();

void 右键按下();

void 右键弹起();

int 左键状态();

int 右键状态();

void MouseMove(int pos_x, int pos_y, int speed);