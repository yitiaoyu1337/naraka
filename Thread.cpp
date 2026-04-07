#include "Thread.h"
#include "pak.h"
#include "Data.h"
#include "Menu.h"
#include "Tool.h"
#include "ShockKnifeLogic.h"
#include "HeroActivation.h"
#include "AttackShockKnife.h"
#include "AttackWrite.h"

static bool 是否连接Net = false;
static bool 是否HOOK = false;
BOOL WINAPI HandlerRoutine(DWORD dwCtrlType) {
	switch (dwCtrlType)
	{
	case CTRL_C_EVENT: //CTRL + C
		break;
	case CTRL_BREAK_EVENT: //CTRL + BREAK
		break;
	case CTRL_CLOSE_EVENT: //关闭
		if (Function::Shock::F_MemShock)
		{
			保存内存振配置();
			//此处保存内存振配置
		}
		else if (Function::Shock::F_ShockKnife)
		{
			//此处保存模拟振配置
			保存模拟振配置();
		}
		保存活化配置();
		保存其他参数();
		MouseLeftorRightUp();
		SendKeyUpEx(KEY_W);
		SendKeyUpEx(KEY_S);
		SendKeyUpEx(KEY_A);
		SendKeyUpEx(KEY_D);
		SendKeyUpEx(KEY_F);
		SendKeyUpEx(KEY_G);
		SendKeyUpEx(KEY_LEFTSHIFT);
		SendKeyUpEx(KEY_SPACEBAR);
		break;
	case CTRL_LOGOFF_EVENT: //用户退出
		break;
	case CTRL_SHUTDOWN_EVENT: //系统被关闭时.
		break;
	}

	return 0;
}

void 初始化振刀距离参数数据()
{
	振刀参数::距离::长剑.左3 = 4.2f;
	振刀参数::距离::长剑.右3 = 4.5f;
	振刀参数::距离::长剑.左剑气 = 12.f;
	振刀参数::距离::长剑.右剑气 = 12.f;
	振刀参数::距离::长剑.凤凰羽 = 12.f;
	振刀参数::距离::长剑.蓝月 = 12.f;
	振刀参数::距离::长剑.七星夺窍 = 10.5f;

	振刀参数::距离::太刀.左3 = 4.5f;
	振刀参数::距离::太刀.右3 = 4.8f;
	振刀参数::距离::太刀.左蓄 = 5.2f;
	振刀参数::距离::太刀.右蓄 = 5.2f;
	振刀参数::距离::太刀.左惊雷 = 8.f;
	振刀参数::距离::太刀.右惊雷 = 9.5f;	//惊雷十劫和此参数一样
	振刀参数::距离::太刀.左青鬼 = 6.f;
	振刀参数::距离::太刀.右青鬼 = 4.2f;
	振刀参数::距离::太刀.噬魂斩 = 10.f;

	振刀参数::距离::阔刀.左左 = 5.6f;
	振刀参数::距离::阔刀.左右 = 5.5f;
	振刀参数::距离::阔刀.右右 = 4.2f;
	振刀参数::距离::阔刀.右左 = 4.3f;
	振刀参数::距离::阔刀.左蓄一段 = 7.5f;
	振刀参数::距离::阔刀.左蓄二段 = 4.5f;
	振刀参数::距离::阔刀.左蓄三段 = 8.5f;
	振刀参数::距离::阔刀.右蓄 = 4.8f;
	振刀参数::距离::阔刀.右右蓄 = 8.5f;
	振刀参数::距离::阔刀.雷刀 = 7.6f;
	振刀参数::距离::阔刀.雷刀下劈 = 4.5f;

	振刀参数::距离::长枪.左3 = 4.5f;
	振刀参数::距离::长枪.右3 = 4.5f;
	振刀参数::距离::长枪.左蓄 = 5.2f;
	振刀参数::距离::长枪.六合枪 = 8.5f;
	振刀参数::距离::长枪.右蓄 = 8.3f;
	振刀参数::距离::长枪.大圣游 = 6.2f;
	振刀参数::距离::长枪.风卷云残 = 5.f;
	振刀参数::距离::长枪.双环扫 = 4.5f;
	振刀参数::距离::长枪.龙王破 = 10.f;
	振刀参数::距离::长枪.穿心脚 = 10.f;

	振刀参数::距离::匕首.左3 = 4.5f;
	振刀参数::距离::匕首.右3 = 4.f;
	振刀参数::距离::匕首.左蓄 = 5.8f;
	振刀参数::距离::匕首.右蓄 = 4.f;
	振刀参数::距离::匕首.鬼反 = 5.5f;
	振刀参数::距离::匕首.荆轲献匕 = 8.f;
	振刀参数::距离::匕首.鬼刃暗扎 = 6.5f;
	振刀参数::距离::匕首.鬼哭神嚎 = 6.f;
	振刀参数::距离::匕首.亢龙有悔 = 9.f;

	振刀参数::距离::双截棍.左右3 = 4.5f;
	振刀参数::距离::双截棍.左蓄 = 6.f;
	振刀参数::距离::双截棍.右蓄 = 4.5f;
	振刀参数::距离::双截棍.飞踢 = 4.5f;
	振刀参数::距离::双截棍.扬鞭劲 = 4.5f;
	振刀参数::距离::双截棍.横栏 = 3.5f;
	振刀参数::距离::双截棍.龙虎乱舞 = 6.f;

	振刀参数::距离::双刀.左右3 = 4.5f;
	振刀参数::距离::双刀.左蓄 = 5.f;
	振刀参数::距离::双刀.右蓄 = 4.8f;
	振刀参数::距离::双刀.铁马残红 = 5.f;
	振刀参数::距离::双刀.乾坤日月斩 = 9.f;
	振刀参数::距离::双刀.惊雷 = 4.5f;
	振刀参数::距离::双刀.八斩刀 = 6.f;
	振刀参数::距离::双刀.分水斩 = 4.5f;

	振刀参数::距离::长棍.左3 = 4.5f;
	振刀参数::距离::长棍.右3 = 4.5f;
	振刀参数::距离::长棍.少林棍 = 4.5f;
	振刀参数::距离::长棍.左蓄 = 6.7f;
	振刀参数::距离::长棍.右蓄 = 5.2f;
	振刀参数::距离::长棍.腾云式 = 9.f;
	振刀参数::距离::长棍.乱点天宫 = 5.f;
	振刀参数::距离::长棍.桶劲 = 8.f;
	振刀参数::距离::长棍.五情七灭镇 = 13.f;
	振刀参数::距离::长棍.双环扫 = 4.5f;
	振刀参数::距离::长棍.倒海棍 = 6.3f;
	振刀参数::距离::长棍.镇地撑天 = 5.5f;

	振刀参数::距离::斩马刀.左左 = 6.f;
	振刀参数::距离::斩马刀.左右 = 5.5f;
	振刀参数::距离::斩马刀.右右 = 4.f;
	振刀参数::距离::斩马刀.右左 = 4.5f;
	振刀参数::距离::斩马刀.左蓄 = 5.f;
	振刀参数::距离::斩马刀.右蓄 = 5.8f;
	振刀参数::距离::斩马刀.柄击 = 6.5f;
	振刀参数::距离::斩马刀.惊雷 = 5.f;
	振刀参数::距离::斩马刀.炽焰斩 = 7.f;
	振刀参数::距离::斩马刀.过关斩将 = 8.3f;

	振刀参数::距离::双戟.左右3 = 4.5f;
	振刀参数::距离::双戟.左蓄 = 5.f;
	振刀参数::距离::双戟.右蓄 = 6.f;
	振刀参数::距离::双戟.勾旋斩 = 5.f;
	振刀参数::距离::双戟.探海蛟 = 7.f;
	振刀参数::距离::双戟.钩挂 = 6.f;
	振刀参数::距离::双戟.战龙在天 = 6.4f;
	振刀参数::距离::双戟.形意钩 = 11.f;

	振刀参数::距离::扇子.左3 = 4.5f;
	振刀参数::距离::扇子.右3 = 4.f;
	振刀参数::距离::扇子.左蓄 = 7.f;
	振刀参数::距离::扇子.右蓄 = 7.f;
	振刀参数::距离::扇子.双开圆 = 6.f;
	振刀参数::距离::扇子.三风摆 = 9.5f;
	振刀参数::距离::扇子.鬼反 = 6.f;
	振刀参数::距离::扇子.惊雷 = 5.5f;
	振刀参数::距离::扇子.缠龙奔野 = 11.5f;

	振刀参数::距离::横刀.左3 = 4.5f;
	振刀参数::距离::横刀.右3 = 4.8;
	振刀参数::距离::横刀.左蓄 = 5.f;
	振刀参数::距离::横刀.右蓄 = 6.f;
	振刀参数::距离::横刀.破千军 = 5.f;
	振刀参数::距离::横刀.极光破云闪 = 6.1f;
}
void 初始化振刀角度参数数据()
{
	振刀参数::角度::长剑.左3 = 25.f;
	振刀参数::角度::长剑.右3 = 25.f;
	振刀参数::角度::长剑.左剑气2M = 180.f;
	振刀参数::角度::长剑.左剑气4M = 25.f;
	振刀参数::角度::长剑.左剑气6M = 25.f;
	振刀参数::角度::长剑.左剑气9M = 11.f;
	振刀参数::角度::长剑.左剑气9M外 = 11.f;
	振刀参数::角度::长剑.右剑气2M = 60.f;
	振刀参数::角度::长剑.右剑气4M = 30.f;
	振刀参数::角度::长剑.右剑气6M = 25.f;
	振刀参数::角度::长剑.右剑气9M = 12.f;
	振刀参数::角度::长剑.右剑气9M外 = 12.f;
	振刀参数::角度::长剑.凤凰羽2M = 90.f;
	振刀参数::角度::长剑.凤凰羽5M = 30.f;
	振刀参数::角度::长剑.凤凰羽8M = 25.f;
	振刀参数::角度::长剑.凤凰羽8M外 = 15.f;
	振刀参数::角度::长剑.蓝月2M = 12.f;
	振刀参数::角度::长剑.蓝月6M = 12.f;
	振刀参数::角度::长剑.蓝月6M外 = 12.f;
	振刀参数::角度::长剑.七星夺窍 = 45.f;

	振刀参数::角度::太刀.左3 = 25.f;
	振刀参数::角度::太刀.右3 = 25.f;
	振刀参数::角度::太刀.左蓄2M = 60.f;
	振刀参数::角度::太刀.左蓄2M外 = 30.f;
	振刀参数::角度::太刀.右蓄2M = 45.f;
	振刀参数::角度::太刀.右蓄2M外 = 25.f;
	振刀参数::角度::太刀.左惊雷 = 25.f;
	振刀参数::角度::太刀.右惊雷5M = 25.f;	//惊雷十劫和此参数一样
	振刀参数::角度::太刀.右惊雷5M外 = 13.f;	//惊雷十劫和此参数一样
	振刀参数::角度::太刀.左青鬼 = 25.f;
	振刀参数::角度::太刀.右青鬼 = 25.f;

	振刀参数::角度::阔刀.左左 = 25.f;
	振刀参数::角度::阔刀.左右2M = 60.f;
	振刀参数::角度::阔刀.左右2M外 = 30.f;
	振刀参数::角度::阔刀.右右 = 30.f;
	振刀参数::角度::阔刀.右左 = 45.f;
	振刀参数::角度::阔刀.左蓄一段2M = 60.f;
	振刀参数::角度::阔刀.左蓄一段2M外 = 45.f;
	振刀参数::角度::阔刀.右蓄2M = 60.f;
	振刀参数::角度::阔刀.右蓄2M外 = 45.f;
	振刀参数::角度::阔刀.右右蓄2M = 45.f;
	振刀参数::角度::阔刀.右右蓄2M外 = 15.f;

	振刀参数::角度::长枪.左3 = 45.f;
	振刀参数::角度::长枪.右3 = 45.f;
	振刀参数::角度::长枪.左蓄 = 45.f;
	振刀参数::角度::长枪.六合枪2M = 60.f;
	振刀参数::角度::长枪.六合枪2M外 = 25.f;
	振刀参数::角度::长枪.右蓄 = 45.f;
	振刀参数::角度::长枪.大圣游 = 60.f;
	振刀参数::角度::长枪.风卷云残 = 45.f;
	振刀参数::角度::长枪.龙王破2M = 45.f;
	振刀参数::角度::长枪.龙王破2M外 = 25.f;
	振刀参数::角度::长枪.穿心脚2M = 45.f;
	振刀参数::角度::长枪.穿心脚2M外 = 25.f;

	振刀参数::角度::匕首.左3 = 45.f;
	振刀参数::角度::匕首.右3 = 45.f;
	振刀参数::角度::匕首.左蓄2M = 90.f;
	振刀参数::角度::匕首.左蓄2M外 = 60.f;
	振刀参数::角度::匕首.右蓄2M = 180.f;
	振刀参数::角度::匕首.右蓄2M外 = 90.f;
	振刀参数::角度::匕首.鬼反 = 45.f;
	振刀参数::角度::匕首.荆轲献匕2M = 90.f;
	振刀参数::角度::匕首.荆轲献匕2M外 = 45.f;
	振刀参数::角度::匕首.鬼刃暗扎2M = 180.f;
	振刀参数::角度::匕首.鬼刃暗扎2M外 = 45.f;
	振刀参数::角度::匕首.亢龙有悔2M = 180.f;
	振刀参数::角度::匕首.亢龙有悔4M = 45.f;
	振刀参数::角度::匕首.亢龙有悔4M外 = 20.f;

	振刀参数::角度::双截棍.左右3 = 45.f;
	振刀参数::角度::双截棍.左蓄2M = 60.f;
	振刀参数::角度::双截棍.左蓄2M外 = 306.f;
	振刀参数::角度::双截棍.右蓄2M = 60.f;
	振刀参数::角度::双截棍.右蓄2M外 = 30.f;
	振刀参数::角度::双截棍.飞踢 = 45.f;
	振刀参数::角度::双截棍.扬鞭劲 = 30.f;
	振刀参数::角度::双截棍.横栏 = 30.f;

	振刀参数::角度::双刀.左右3 = 45.f;
	振刀参数::角度::双刀.左蓄 = 60.f;
	振刀参数::角度::双刀.右蓄 = 60.f;
	振刀参数::角度::双刀.分水斩 = 45.f;
	振刀参数::角度::双刀.铁马残红3M = 120.f;
	振刀参数::角度::双刀.铁马残红3M外 = 60.f;
	振刀参数::角度::双刀.乾坤日月斩 = 60.f;
	振刀参数::角度::双刀.惊雷 = 45.f;
	振刀参数::角度::双刀.八斩刀 = 60.f;

	振刀参数::角度::长棍.左3 = 45.f;
	振刀参数::角度::长棍.右3 = 45.f;
	振刀参数::角度::长棍.少林棍 = 45.f;
	振刀参数::角度::长棍.左蓄2M = 180.f;
	振刀参数::角度::长棍.左蓄2M外 = 90.f;
	振刀参数::角度::长棍.腾云式2M = 45.f;
	振刀参数::角度::长棍.腾云式2M外 = 30.f;
	振刀参数::角度::长棍.乱点天宫 = 60.f;
	振刀参数::角度::长棍.桶劲 = 45.f;
	振刀参数::角度::长棍.五情七灭镇8M = 90.f;
	振刀参数::角度::长棍.五情七灭镇8M外 = 60.f;
	振刀参数::角度::长棍.双环扫 = 45.f;
	振刀参数::角度::长棍.倒海棍 = 75.f;
	振刀参数::角度::长棍.镇地撑天 = 120.f;

	振刀参数::角度::斩马刀.左左 = 25.f;
	振刀参数::角度::斩马刀.左右2M = 60.f;
	振刀参数::角度::斩马刀.左右2M外 = 30.f;
	振刀参数::角度::斩马刀.右右 = 30.f;
	振刀参数::角度::斩马刀.右左 = 45.f;
	振刀参数::角度::斩马刀.左蓄2M = 180.f;
	振刀参数::角度::斩马刀.左蓄2M外 = 45.f;
	振刀参数::角度::斩马刀.右蓄 = 45.f;
	振刀参数::角度::斩马刀.柄击 = 45.f;
	振刀参数::角度::斩马刀.惊雷 = 60.f;
	振刀参数::角度::斩马刀.炽焰斩 = 60.f;
	振刀参数::角度::斩马刀.过关斩将 = 25.f;

	振刀参数::角度::双戟.左右3 = 45.f;
	振刀参数::角度::双戟.左蓄3M = 90.f;
	振刀参数::角度::双戟.左蓄3M外 = 60.f;
	振刀参数::角度::双戟.右蓄3M = 90.f;
	振刀参数::角度::双戟.右蓄3M外 = 60.f;
	振刀参数::角度::双戟.勾旋斩 = 45.f;
	振刀参数::角度::双戟.探海蛟 = 45.f;
	振刀参数::角度::双戟.钩挂 = 45.f;
	振刀参数::角度::双戟.战龙在天 = 45.f;
	振刀参数::角度::双戟.形意钩 = 45.f;

	振刀参数::角度::扇子.左3 = 45.f;
	振刀参数::角度::扇子.右3 = 45.f;
	振刀参数::角度::扇子.左蓄 = 60.f;
	振刀参数::角度::扇子.右蓄2M = 60.f;
	振刀参数::角度::扇子.右蓄2M外 = 45.f;
	振刀参数::角度::扇子.双开圆 = 45.f;
	振刀参数::角度::扇子.三风摆3M = 45.f;
	振刀参数::角度::扇子.三风摆3M外 = 90.f;
	振刀参数::角度::扇子.鬼反 = 45.f;
	振刀参数::角度::扇子.惊雷 = 45.f;
	振刀参数::角度::扇子.缠龙奔野3M = 180.f;
	振刀参数::角度::扇子.缠龙奔野3M外 = 120.f;

	振刀参数::角度::横刀.左3 = 25.f;
	振刀参数::角度::横刀.右3 = 25.;
	振刀参数::角度::横刀.左蓄 = 45.f;
	振刀参数::角度::横刀.右蓄 = 60.f;
	振刀参数::角度::横刀.破千军 = 45.f;
	振刀参数::角度::横刀.极光破云闪 = 180.f;
}
//缓存指针
void Cache_Player_World_Data()
{
	vector<ObjData> m_ListData;
	ObjData tempData;
	while (true)
	{
		Global::WorldPtr.Character->GetCharacterManagerPtr();		//缓存CharacterManager
		Global::WorldPtr.Character->Cache_PlayerCount_ActorModelList();	//为后续做缓存
		Global::WorldPtr.UserData->GetUserDataManager();			//缓存UserDataManager
		Global::WorldPtr.Sync->GetCharactorSyncManager();			//缓存CharactorSyncManager
		Offset::MatrixAddr = Tool::GetMatrixAddr(Global::WorldPtr.Character->CharacterManagerPtr);

		Global::Cache_LocalPlayer.L_ActorModel = Global::WorldPtr.Character->GetLocalActorModel();		//缓存自身指针
		LocalPlayer_Data.MyTeam = Global::Cache_LocalPlayer.L_ActorModel->GetActorModelPropertyData()->GetTeam();
		uintptr_t SkillID_ = Memory::ReadEx<uintptr_t>(Global::MySkillData.Cache_Skill_PTR + 0x60);
		LocalPlayer_Data.MySkillID = Memory::ReadEx<int>(SkillID_ + Offset::UserData.Skill_ID);
		LocalPlayer_Data.MyHero = Memory::ReadEx<HeroType>((uintptr_t)Global::Cache_LocalPlayer.L_PropertyData + Offset::ActorModel.ProPerty.Heroid);

		if (!Global::Cache_LocalPlayer.L_ActorModel) {
			Sleep(1000);
			continue;
		}

		Global::MySkillData.L_LocalSkillData = Global::WorldPtr.UserData->GetAllSkillDataList();	//缓存技能
		Global::MySkillData.Cache_Skill_PTR = Global::MySkillData.L_LocalSkillData->Cache_Skill();

		//缓存ActorModel
		Global::Cache_LocalPlayer.L_PropertyData = Global::Cache_LocalPlayer.L_ActorModel->GetActorModelPropertyData();
		Global::Cache_LocalPlayer.L_ActorKit = Global::Cache_LocalPlayer.L_ActorModel->GetActorKit();
		Global::Cache_LocalPlayer.L_HitSimulate = Global::Cache_LocalPlayer.L_ActorKit->GetActionHitSimulateData();
		Global::Cache_LocalPlayer.L_RuntimeProperty = Global::Cache_LocalPlayer.L_ActorModel->GetRuntimePropertyData();
		Global::Cache_LocalPlayer.L_ObjectMessenger = Global::Cache_LocalPlayer.L_ActorModel->GetObjectMessenger();
		
		//缓存ActorModel下面各项指针
		Global::Cache_LocalPlayer.Cache_EventTracksForLayerPtr = Global::Cache_LocalPlayer.L_ActorModel->Cache_GetEventTracksForLayer();
		Global::Cache_LocalPlayer.Cache_PosPtr = Global::Cache_LocalPlayer.L_ActorModel->Cache_GetPosPtr();
		Global::Cache_LocalPlayer.Cache_ActorRootPtr = Global::Cache_LocalPlayer.L_ActorModel->Cache_GetActorRootPtr();
		Global::Cache_LocalPlayer.Cache_Bluetime_PTR = Global::Cache_LocalPlayer.L_ActorKit->Cache_BlueTime();
		Global::Cache_LocalPlayer.Cache_PropertData_PTR = Global::Cache_LocalPlayer.L_RuntimeProperty->Cache_PropertData();
		Global::Cache_LocalPlayer.Cache_PropertyDataID = Global::Cache_LocalPlayer.L_RuntimeProperty->GetPropertyDataID();
		Global::Cache_LocalPlayer.Cache_GetGlobalTime_PTR = Global::Cache_LocalPlayer.L_ObjectMessenger->Cache_GetGlobalTime();
		Global::Cache_LocalPlayer.Cache_GetCurTimeForLogicState_PTR = Global::Cache_LocalPlayer.L_ObjectMessenger->Cache_GetCurTimeForLogicState();
		Global::Cache_LocalPlayer.Cache_GetNameHash_PTR = Global::Cache_LocalPlayer.Cache_GetCurTimeForLogicState_PTR;
		Global::Cache_LocalPlayer.Cache_ActorPhysics_PTR = Global::Cache_LocalPlayer.L_ActorKit->Cache_ActorPhysics();


		auto PlayerCount = Global::WorldPtr.Character->GetPlayerCount();
		m_ListData.clear();
		for (int i = 0; i < PlayerCount; i++)
		{
			auto List = Global::WorldPtr.Character->GetActorModelList(i);
			if(List == Global::Cache_LocalPlayer.L_ActorModel || List == NULL) continue;
			tempData.O_PropertyData = List->GetActorModelPropertyData();
			if (LocalPlayer_Data.MyTeam == tempData.O_PropertyData->GetTeam()) continue;
			if(!List->IsAlive()) continue;

			//缓存对象
			tempData.O_ActorModel = List;
			if(tempData.O_PropertyData->GetTeam())
			tempData.O_ActorKit = List->GetActorKit();
			tempData.O_HitSimulate = tempData.O_ActorKit->GetActionHitSimulateData();
			tempData.O_RuntimeProperty = List->GetRuntimePropertyData();
			tempData.O_ObjectMessenger = List->GetObjectMessenger();

			//缓存ActorModel下面各项指针
			tempData.Cache_EventTracksForLayerPtr = List->Cache_GetEventTracksForLayer();
			tempData.Cache_PosPtr = List->Cache_GetPosPtr();
			tempData.Cache_ActorRootPtr = List->Cache_GetActorRootPtr();
			tempData.Cache_Bluetime_PTR = tempData.O_ActorKit->Cache_BlueTime();
			tempData.Cache_PropertData_PTR = tempData.O_RuntimeProperty->Cache_PropertData();
			tempData.Cache_PropertyDataID = tempData.O_RuntimeProperty->GetPropertyDataID();
			tempData.Cache_GetGlobalTime_PTR = tempData.O_ObjectMessenger->Cache_GetGlobalTime();
			tempData.Cache_GetCurTimeForLogicState_PTR = tempData.O_ObjectMessenger->Cache_GetCurTimeForLogicState();
			tempData.Cache_GetNameHash_PTR = tempData.Cache_GetCurTimeForLogicState_PTR;

			//以下缓存不经常变动的数据
			tempData.ISRobot = tempData.O_PropertyData->GetISRobotId();
			tempData.Team = tempData.O_PropertyData->GetTeam();
			tempData.HeroId = tempData.O_PropertyData->GetHeroTID();
			tempData.PlayerName = tempData.O_PropertyData->GetPlayerName();

			m_ListData.push_back(tempData);
		}
		//auto stop = chrono::high_resolution_clock::now();
		//auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
		//std::cout << "Read time: " << duration.count() << " ms | Count:" << PlayerCount << endl;

		全_游戏数据 = m_ListData;
		Sleep(1000);

		//Memory::scatterClear(DmaData::hS);
		//Memory::scatterPrep(DmaData::hS, Global::LocalPlayer.Cache_Bluetime_PTR + 0x24 + 3 * 0xC, sizeof(float));
		//Memory::scatterPrep(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x20 + Global::LocalPlayer.Cache_PropertyDataID.CurHpID * 4ull, sizeof(int));
		//Memory::scatterPrep(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x20 + Global::LocalPlayer.Cache_PropertyDataID.HpMaxID * 4ull, sizeof(int));
		//Memory::scatterPrep(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x20 + Global::LocalPlayer.Cache_PropertyDataID.CurshieldID * 4ull, sizeof(int));
		//Memory::scatterPrep(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x20 + Global::LocalPlayer.Cache_PropertyDataID.shieldMaxID * 4ull, sizeof(int));
		//Memory::scatterPrep(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x20 + Global::LocalPlayer.Cache_PropertyDataID.CurEnergyID * 4ull, sizeof(int));
		//Memory::scatterPrep(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x20 + Global::LocalPlayer.Cache_PropertyDataID.EnergyMaxID * 4ull, sizeof(int));
		//Memory::scatterPrep(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x30, sizeof(int));
		//Memory::scatterPrep(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x38, sizeof(int));
		//Memory::scatterExec(DmaData::hS);
		//auto MyBlueTime = Memory::scatterRead<float>(DmaData::hS, Global::LocalPlayer.Cache_Bluetime_PTR + 0x24 + 3 * 0xC, sizeof(float));
		//auto MyActionName = Global::LocalPlayer.L_ActorModel->GetActorName(Global::LocalPlayer.Cache_EventTracksForLayerPtr);
		//auto MyCurTime = Global::LocalPlayer.L_ObjectMessenger->GetCurTimeForLogicStateA(Global::LocalPlayer.Cache_GetGlobalTime_PTR, Global::LocalPlayer.Cache_GetCurTimeForLogicState_PTR);
		//auto MyActionHash = Global::Cache_LocalPlayer.L_ObjectMessenger->GetNameHash(Global::Cache_LocalPlayer.Cache_GetNameHash_PTR);
		//auto MyReactionType = Global::LocalPlayer.L_HitSimulate->GetReactionType();
		//auto MyendureLevel = Global::LocalPlayer.L_HitSimulate->GetEndureLevel();
		//auto MyWeaponType = Global::LocalPlayer.L_ActorModel->GetActorWeapon();

		//auto CurHp = Memory::scatterRead<int>(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x20 + Global::LocalPlayer.Cache_PropertyDataID.CurHpID * 4ull, sizeof(int));
		//auto MaxHp = Memory::scatterRead<int>(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x20 + Global::LocalPlayer.Cache_PropertyDataID.HpMaxID * 4ull, sizeof(int));
		//auto Curshield = Memory::scatterRead<int>(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x20 + Global::LocalPlayer.Cache_PropertyDataID.CurshieldID * 4ull, sizeof(int));
		//auto Maxshield = Memory::scatterRead<int>(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x20 + Global::LocalPlayer.Cache_PropertyDataID.shieldMaxID * 4ull, sizeof(int));
		//auto CurEnergy = Memory::scatterRead<int>(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x20 + Global::LocalPlayer.Cache_PropertyDataID.CurEnergyID * 4ull, sizeof(int));
		//auto MaxEnergy = Memory::scatterRead<int>(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x20 + Global::LocalPlayer.Cache_PropertyDataID.EnergyMaxID * 4ull, sizeof(int));
		//auto CurAnger = Memory::scatterRead<int>(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x30, sizeof(int));
		//auto MaxAnger = Memory::scatterRead<int>(DmaData::hS, Global::LocalPlayer.Cache_PropertData_PTR + 0x38, sizeof(int));

		//auto MyHeroID = Global::LocalPlayer.L_PropertyData->GetHeroTID();
		//auto MyIsRobot = Global::LocalPlayer.L_PropertyData->GetISRobotId();
		//auto MyName = Global::LocalPlayer.L_PropertyData->GetPlayerName();
		//auto MyTeam = Global::LocalPlayer.L_PropertyData->GetTeam();
		//auto MyWeaponID = Global::LocalPlayer.L_PropertyData->GetWeaponID();

		//auto MySkillID = Global::MySkillData.L_LocalSkillData->GetSkillID(Global::MySkillData.Cache_Skill_PTR);
		//auto MySkillState = Global::MySkillData.L_LocalSkillData->GetSkillState(Global::MySkillData.Cache_Skill_PTR);
		//auto MyLeftCdTime = Global::MySkillData.L_LocalSkillData->Get_LeftCdTime(Global::MySkillData.Cache_Skill_PTR);
		//auto MyLeftConCdTime = Global::MySkillData.L_LocalSkillData->Get_LeftContinueTime(Global::MySkillData.Cache_Skill_PTR);
	}
}
//读取具体数据
void LocalPlayer_Object_Data()
{
	vector<PlayerData> m_ListData;
	PlayerData tempData;
	vector<ObjData> m_APlayer;
	while (true)
	{
		//auto start = chrono::high_resolution_clock::now();
		if (!Global::Cache_LocalPlayer.L_ActorModel) {
			Sleep(800);
			continue;
		}

		//auto start = chrono::high_resolution_clock::now();

		//本人
		Global::WorldPtr.ping = Global::WorldPtr.Sync->GamePing();		//获取ping
		//uintptr_t ActorWeapon_= Memory::ReadEx<uintptr_t>((uintptr_t)Global::Cache_LocalPlayer.L_ActorModel + Offset::ActorModel.ActorWeapon);

		Global::WorldPtr.敌人数量5M内 = 0;
		int 遍历人数 = m_APlayer.size();
		m_APlayer = 全_游戏数据;
		m_ListData.clear();
		for (int i = 0; i < m_APlayer.size(); i++)
		{
			auto& PlayerTemp = m_APlayer.at(i);
			if (Global::Cache_LocalPlayer.L_ActorModel == PlayerTemp.O_ActorModel || PlayerTemp.O_ActorModel == NULL && !(PlayerTemp.O_ActorModel->IsAlive())) { continue; }
			
			tempData.ISRobot = PlayerTemp.ISRobot;
			tempData.Team = PlayerTemp.Team;
			tempData.HeroId = PlayerTemp.HeroId;
			tempData.PlayerName = PlayerTemp.PlayerName;
			tempData.HeroName = GetHeroType(tempData.HeroId);

			uintptr_t ActorWeapon_Local = Memory::ReadEx<uintptr_t>((uintptr_t)Global::Cache_LocalPlayer.L_ActorModel + Offset::ActorModel.ActorWeapon);
			uintptr_t ActorWeapon_ = Memory::ReadEx<uintptr_t>((uintptr_t)PlayerTemp.O_ActorModel + Offset::ActorModel.ActorWeapon);
			Memory::scatterClear(DmaData::hS1);
			//本人
			Memory::scatterPrep(DmaData::hS1, Global::Cache_LocalPlayer.Cache_GetCurTimeForLogicState_PTR + 0x58, sizeof(double));
			Memory::scatterPrep(DmaData::hS1, (uintptr_t)Global::Cache_LocalPlayer.L_HitSimulate + Offset::ActorModel.ActorKitS.HitSimulate.endureLevel, sizeof(ActionType));
			Memory::scatterPrep(DmaData::hS1, (uintptr_t)Global::Cache_LocalPlayer.L_HitSimulate + Offset::ActorModel.ActorKitS.HitSimulate.ReactionType, sizeof(int));
			Memory::scatterPrep(DmaData::hS1, (uintptr_t)Global::Cache_LocalPlayer.L_HitSimulate + 0x2C, sizeof(float));
			Memory::scatterPrep(DmaData::hS1, Global::Cache_LocalPlayer.Cache_GetGlobalTime_PTR + 0x28, sizeof(double));
			//Memory::scatterPrep(DmaData::hS1, (uintptr_t)Global::Cache_LocalPlayer.L_PropertyData + Offset::ActorModel.ProPerty.Heroid, sizeof(HeroType));
			Memory::scatterPrep(DmaData::hS1, ActorWeapon_Local + 0x68, sizeof(WeaponType));
			Memory::scatterPrep(DmaData::hS1, Global::Cache_LocalPlayer.Cache_Bluetime_PTR + 0x24 + 3 * 0xC, sizeof(float));
			Memory::scatterPrep(DmaData::hS1, Global::MySkillData.Cache_Skill_PTR + Offset::UserData.ClientLeftContinueTime, sizeof(float));
			Memory::scatterPrep(DmaData::hS1, Global::MySkillData.Cache_Skill_PTR + Offset::UserData.skillState, sizeof(int));
			//Memory::scatterPrep(DmaData::hS1, SkillID_ + Offset::UserData.Skill_ID, sizeof(int));
			Memory::scatterPrep(DmaData::hS1, Global::Cache_LocalPlayer.Cache_PosPtr + 0x90, sizeof(Vector3));
			Memory::scatterPrep(DmaData::hS1, Global::Cache_LocalPlayer.Cache_EventTracksForLayerPtr + 0x20, sizeof(uint64_t));
			Memory::scatterPrep(DmaData::hS1, Global::Cache_LocalPlayer.Cache_ActorPhysics_PTR + Offset::ActorModel.ActorKitS.CurrentCollisionFlags, sizeof(int));
			////最近敌人
			//if (Global::Cache_MinObj.Min_ActorModel)
			//{
			//	Memory::scatterPrep(DmaData::hS1, (uintptr_t)Global::Cache_MinObj.Min_HitSimulate + Offset::ActorModel.ActorKitS.HitSimulate.endureLevel, sizeof(ActionType));
			//	Memory::scatterPrep(DmaData::hS1, ActorWeapon_Min + 0x68, sizeof(WeaponType));
			//	Memory::scatterPrep(DmaData::hS1, Global::Cache_MinObj.Cache_Bluetime_PTR + 0x24 + 3 * 0xC, sizeof(float));
			//	Memory::scatterPrep(DmaData::hS1, (uintptr_t)Global::Cache_MinObj.Min_ActorModel + 0x6C, sizeof(bool));
			//	Memory::scatterPrep(DmaData::hS1, NameHash_Min + 0x18, sizeof(unsigned int));
			//	Memory::scatterPrep(DmaData::hS1, Global::Cache_MinObj.Cache_GetGlobalTime_PTR + 0x28, sizeof(double));
			//	Memory::scatterPrep(DmaData::hS1, Global::Cache_MinObj.Cache_GetCurTimeForLogicState_PTR + 0x58, sizeof(double));
			//}
			//对象
			Memory::scatterPrep(DmaData::hS1, (uintptr_t)PlayerTemp.O_ActorModel + 0x6C, sizeof(bool));
			Memory::scatterPrep(DmaData::hS1, ActorWeapon_ + 0x68, sizeof(WeaponType));
			Memory::scatterPrep(DmaData::hS1, (uintptr_t)PlayerTemp.O_PropertyData + Offset::ActorModel.ProPerty.WeaponId, sizeof(int));
			//Memory::scatterPrep(DmaData::hS1, (uintptr_t)PlayerTemp.O_HitSimulate + Offset::ActorModel.ActorKitS.HitSimulate.RangeReactionType, sizeof(int));
			Memory::scatterPrep(DmaData::hS1, (uintptr_t)PlayerTemp.O_HitSimulate + Offset::ActorModel.ActorKitS.HitSimulate.endureLevel, sizeof(ActionType));
			//Memory::scatterPrep(DmaData::hS1, NameHash_ + 0x18, sizeof(unsigned int));
			Memory::scatterPrep(DmaData::hS1, PlayerTemp.Cache_PropertData_PTR + 0x20 + PlayerTemp.Cache_PropertyDataID.CurHpID * 4ull, sizeof(int));
			//Memory::scatterPrep(DmaData::hS1, PlayerTemp.Cache_PropertData_PTR + 0x20 + PlayerTemp.Cache_PropertyDataID.HpMaxID * 4ull, sizeof(int));
			Memory::scatterPrep(DmaData::hS1, PlayerTemp.Cache_PropertData_PTR + 0x20 + PlayerTemp.Cache_PropertyDataID.CurshieldID * 4ull, sizeof(int));
			//Memory::scatterPrep(DmaData::hS1, PlayerTemp.Cache_PropertData_PTR + 0x20 + PlayerTemp.Cache_PropertyDataID.shieldMaxID * 4ull, sizeof(int));
			Memory::scatterPrep(DmaData::hS1, PlayerTemp.Cache_PropertData_PTR + 0x30, sizeof(int));
			//Memory::scatterPrep(DmaData::hS1, PlayerTemp.Cache_PropertData_PTR + 0x38, sizeof(int));
			Memory::scatterPrep(DmaData::hS1, PlayerTemp.Cache_PosPtr + 0x90, sizeof(Vector3));
			Memory::scatterPrep(DmaData::hS1, PlayerTemp.Cache_GetNameHash_PTR + 0x48, sizeof(uintptr_t));
			Memory::scatterPrep(DmaData::hS1, PlayerTemp.Cache_EventTracksForLayerPtr + 0x20, sizeof(uint64_t));
			Memory::scatterExec(DmaData::hS1);

			//本人
			LocalPlayer_Data.MyActionName = Global::Cache_LocalPlayer.L_ActorModel->GetActorName(Global::Cache_LocalPlayer.Cache_EventTracksForLayerPtr);
			LocalPlayer_Data.MyCurTime = (float)(Global::WorldPtr.GlobalTime - Memory::scatterRead<double>(DmaData::hS1, Global::Cache_LocalPlayer.Cache_GetCurTimeForLogicState_PTR + 0x58, sizeof(double)));
			LocalPlayer_Data.MyEndureLevel = Memory::scatterRead<ActionType>(DmaData::hS1, (uintptr_t)Global::Cache_LocalPlayer.L_HitSimulate + Offset::ActorModel.ActorKitS.HitSimulate.endureLevel, sizeof(ActionType));
			//LocalPlayer_Data.MyHero = Memory::scatterRead<HeroType>(DmaData::hS1, (uintptr_t)Global::Cache_LocalPlayer.L_PropertyData + Offset::ActorModel.ProPerty.Heroid, sizeof(HeroType));
			LocalPlayer_Data.MyWeaponType = Memory::scatterRead<WeaponType>(DmaData::hS1, ActorWeapon_Local + 0x70, sizeof(WeaponType));
			LocalPlayer_Data.MyReactionType = Memory::scatterRead<int>(DmaData::hS1, (uintptr_t)Global::Cache_LocalPlayer.L_HitSimulate + Offset::ActorModel.ActorKitS.HitSimulate.ReactionType, sizeof(int));
			LocalPlayer_Data.MyActionDuration = Memory::scatterRead<float>(DmaData::hS1, (uintptr_t)Global::Cache_LocalPlayer.L_HitSimulate + 0x2C, sizeof(float));
			Global::WorldPtr.GlobalTime = Memory::scatterRead<double>(DmaData::hS1, Global::Cache_LocalPlayer.Cache_GetGlobalTime_PTR + 0x28, sizeof(double));
			LocalPlayer_Data.MyBlueTime = Memory::scatterRead<float>(DmaData::hS1, Global::Cache_LocalPlayer.Cache_Bluetime_PTR + 0x24 + 3 * 0xC, sizeof(float));
			LocalPlayer_Data.MyLeftContinueTime = Memory::scatterRead<float>(DmaData::hS1, Global::MySkillData.Cache_Skill_PTR + Offset::UserData.ClientLeftContinueTime, sizeof(float));
			//LocalPlayer_Data.MySkillID = Memory::scatterRead<int>(DmaData::hS1, SkillID_ + Offset::UserData.Skill_ID, sizeof(int));
			LocalPlayer_Data.MySkillState = Memory::scatterRead<int>(DmaData::hS1, Global::MySkillData.Cache_Skill_PTR + Offset::UserData.skillState, sizeof(int));
			LocalPlayer_Data.MyPos = Memory::scatterRead<Vector3>(DmaData::hS1, Global::Cache_LocalPlayer.Cache_PosPtr + 0x90, sizeof(Vector3));
			LocalPlayer_Data.MyCurrentCollisionFlags = Memory::scatterRead<int>(DmaData::hS1, Global::Cache_LocalPlayer.Cache_ActorPhysics_PTR + Offset::ActorModel.ActorKitS.CurrentCollisionFlags, sizeof(int));

			//对象
			tempData.O_ActionName = PlayerTemp.O_ActorModel->GetActorName(PlayerTemp.Cache_EventTracksForLayerPtr);
			tempData.O_Visible = Memory::scatterRead<bool>(DmaData::hS1, (uintptr_t)PlayerTemp.O_ActorModel + 0x6C, sizeof(bool));
			tempData.O_ActorWeapon = Memory::scatterRead<WeaponType>(DmaData::hS1, ActorWeapon_ + 0x70, sizeof(WeaponType));
			tempData.O_WeaponID = Memory::scatterRead<int>(DmaData::hS1, (uintptr_t)PlayerTemp.O_PropertyData + Offset::ActorModel.ProPerty.WeaponId, sizeof(int));
			//tempData.O_RangeReactionType = Memory::scatterRead<int>(DmaData::hS1, (uintptr_t)PlayerTemp.O_HitSimulate + Offset::ActorModel.ActorKitS.HitSimulate.RangeReactionType, sizeof(int));		//可以不急
			tempData.O_EndureLevel = Memory::scatterRead<ActionType>(DmaData::hS1, (uintptr_t)PlayerTemp.O_HitSimulate + Offset::ActorModel.ActorKitS.HitSimulate.endureLevel, sizeof(ActionType));		//可以不急
			//tempData.O_NameHash = Memory::scatterRead<unsigned int>(DmaData::hS1, NameHash_ + 0x18, sizeof(unsigned int));																										//可以不急
			tempData.O_CurHp = Memory::scatterRead<int>(DmaData::hS1, PlayerTemp.Cache_PropertData_PTR + 0x20 + PlayerTemp.Cache_PropertyDataID.CurHpID * 4ull, sizeof(int));
			//tempData.O_MaxHp = Memory::scatterRead<int>(DmaData::hS1, PlayerTemp.Cache_PropertData_PTR + 0x20 + PlayerTemp.Cache_PropertyDataID.HpMaxID * 4ull, sizeof(int));
			tempData.O_Curshield = Memory::scatterRead<int>(DmaData::hS1, PlayerTemp.Cache_PropertData_PTR + 0x20 + PlayerTemp.Cache_PropertyDataID.CurshieldID * 4ull, sizeof(int));
			//tempData.O_Maxshield = Memory::scatterRead<int>(DmaData::hS1, PlayerTemp.Cache_PropertData_PTR + 0x20 + PlayerTemp.Cache_PropertyDataID.shieldMaxID * 4ull, sizeof(int));
			tempData.O_CurAnger = Memory::scatterRead<int>(DmaData::hS1, PlayerTemp.Cache_PropertData_PTR + 0x30, sizeof(int));
			//tempData.O_MaxAnger = Memory::scatterRead<int>(DmaData::hS1, PlayerTemp.Cache_PropertData_PTR + 0x38, sizeof(int));
			tempData.O_Pos = Memory::scatterRead<Vector3>(DmaData::hS1, PlayerTemp.Cache_PosPtr + 0x90, sizeof(Vector3));
			tempData.Cache_NameHash = Memory::scatterRead<uintptr_t>(DmaData::hS1, PlayerTemp.Cache_GetNameHash_PTR + 0x48, sizeof(uintptr_t));
			tempData.Cache_GetCurTimeForLogicState_PTR = PlayerTemp.Cache_GetCurTimeForLogicState_PTR;
			
			tempData.Cache_ActorRootPtr = PlayerTemp.Cache_ActorRootPtr;
			tempData.Cache_HitSimulate = (uintptr_t)PlayerTemp.O_HitSimulate;
			tempData.O_MaxHp = Memory::ReadEx<int>(PlayerTemp.Cache_PropertData_PTR + 0x20 + PlayerTemp.Cache_PropertyDataID.HpMaxID * 4ull);
			tempData.O_Maxshield = Memory::ReadEx<int>(PlayerTemp.Cache_PropertData_PTR + 0x20 + PlayerTemp.Cache_PropertyDataID.shieldMaxID * 4ull);
			tempData.O_ActorModel = (uintptr_t)PlayerTemp.O_ActorModel;
			
		
			//cout << "Visible:" << tempData.O_Visible << " | ActorWeapon:" << tempData.O_ActorWeapon << " | WeaponID:" << tempData.O_WeaponID << " | ReactionType:" << tempData.O_ReactionType << " | RangeReactionType:" << tempData.O_RangeReactionType <<
			//	" | EndureLeve:" << tempData.O_EndureLevel << " | NameHash:" << tempData.O_NameHash << endl;
			//cout << "CurHp:" << tempData.O_CurHp << " | MaxHp:" << tempData.O_MaxHp << " | Curshield:" << tempData.O_Curshield << " | Maxshield:" << tempData.O_Maxshield << " | CurAnger:" << tempData.O_CurAnger << " | MaxAnger:" << tempData.O_MaxAnger << endl;

			//获取最近敌人
			//auto TempPos = PlayerTemp.O_ActorModel->GetPos(PlayerTemp.Cache_PosPtr);
			auto ObjDis = tempData.O_Pos.DistTo(LocalPlayer_Data.MyPos);
			//tempData.O_Pos = TempPos;
			tempData.O_Dis = ObjDis;
			if (ObjDis <= 5.f)
				Global::WorldPtr.敌人数量5M内++;

			m_ListData.push_back(tempData);

			//if (ObjDis < 10.f && abs(LocalPlayer_Data.MyPos.y - TempPos.y) <= 3)
			//{
			//	附近人数++;
			//	if (Global::Cache_MinObj.Min_ActorModel != NULL)
			//	{
			//		if (Global::Cache_MinObj.Cache_PosPtr == NULL) continue;
			//		if (Global::Cache_MinObj.Min_ActorModel->GetPos(Global::Cache_MinObj.Cache_PosPtr).DistTo(LocalPlayer_Data.MyPos) > ObjDis)
			//			Global::Cache_MinObj.Min_ActorModel = PlayerTemp.O_ActorModel;
			//	}
			//	else
			//		Global::Cache_MinObj.Min_ActorModel = PlayerTemp.O_ActorModel;
			//}
		}

		//if (附近人数 == 0)
		//	Global::Cache_MinObj.Min_ActorModel = NULL;

		//wcout << LocalPlayer_Data.MyActionName << " | " << Function::Flag::IsMyManage << " | " << Function::Flag::IsBlueToRed << endl;

		//auto stop = chrono::high_resolution_clock::now();
		//auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
		//std::cout << "Read time: " << duration.count() << " ms | Count:" << 遍历人数 << endl;

		全_玩家交互 = true;
		全_玩家数据 = m_ListData;
		全_玩家交互 = false;
	}
}
//读取物品
void GetItemData()
{
	vector<ItemInfoData> m_ListData;
	ItemInfoData tempData;
	while (true)
	{
		uint64_t GameEntityManager = Memory::ReadEx<uint64_t>(Memory::ReadEx<uint64_t>(Memory::ReadEx<uint64_t>(Memory::ReadEx<uint64_t>(Offset::GameAssembly + Offset::m_EntityManager) + 0xB8) + 0x8) + 0x28);
		uint64_t Array = Memory::ReadEx<uint64_t>(GameEntityManager + 0x18);
		uint32_t Count = Memory::ReadEx<uint32_t>(Array + 0x18);
		m_ListData.clear();
		for (int A = 0; A < Count; A++)
		{
			uint64_t GameEntity = Memory::ReadEx<uint64_t>(Array + 0x28 + (A * 0x10));
			if (!GameEntity) { continue; }
			uint64_t DropItem = Memory::ReadEx<uint64_t>(GameEntity + 0x58);
			uint32_t ItemID = Memory::ReadEx<uint32_t>(DropItem + 0x30);
			if (ItemID == 0 || ItemID > 4000000) { continue; }
			uint64_t Itemtransform = GetItemPosAddr(GameEntity);
			if (Itemtransform <= 0) { continue; }
			uint32_t  ItemIndex = Memory::ReadEx<uint32_t>(Itemtransform + 64);
			uint64_t ItemPosPtr = Memory::ReadEx<uint64_t>(Memory::ReadEx<uint64_t>(Itemtransform + 56) + 24);

			if (itemTable.count(ItemID) != 0)
			{
				tempData.ID = ItemID;
				auto& [Name, Color, itemType] = itemTable[tempData.ID];
				tempData.Pos = Memory::ReadEx<Vector3>(ItemPosPtr + ItemIndex * 48);
				tempData.Name = Name;
				tempData.Color = Color;
				tempData.ItemType = itemType;
				//tempData.ItemType = itemData.itemType;
				m_ListData.push_back(tempData);
			}
		}
		全_物品数据 = m_ListData;
		Sleep(20);
	}
}
//读取堆堆任务
void GetUserBattleData()
{
	vector<InteractiveInfoData> m_ListData;
	InteractiveInfoData tempData;
	while (true)
	{
		uint64_t UserDataManager = Memory::ReadEx<uint64_t>(Memory::ReadEx<uint64_t>(Memory::ReadEx<uint64_t>(Memory::ReadEx<uint64_t>(Offset::GameAssembly + Offset::m_UserDataManager) + 0xB8) + 0) + 0x30);
		uint64_t InteractiveManager = Memory::ReadEx<uint64_t>(UserDataManager + 0x1F0);
		uint64_t InteractiveBuildDict = Memory::ReadEx<uint64_t>(InteractiveManager + 0x10);

		uint64_t InteractiveArray = Memory::ReadEx<uint64_t>(InteractiveBuildDict + 0x18);
		uint32_t InteractiveCount = Memory::ReadEx<uint32_t>(InteractiveArray + 0x18);

		m_ListData.clear();
		for (int A = 0; A < InteractiveCount; A++)
		{
			uint64_t GameEntity = Memory::ReadEx<uint64_t>(InteractiveArray + 0x30 + (A * 0x18));
			if (!GameEntity) { continue; }
			uint32_t InteractiveId = Memory::ReadEx<uint32_t>(GameEntity + 0x14);
			uint32_t status = Memory::ReadEx<uint32_t>(GameEntity + 0x34);
			if (InteractiveTable.count(InteractiveId) != 0 && status == 0)
			{
				tempData.ID = InteractiveId;
				auto& [Name, Color, itemType] = InteractiveTable[tempData.ID];
				tempData.Pos = Memory::ReadEx<Vector3>(GameEntity + 0x18);
				tempData.Name = Name;
				tempData.Color = Color;
				tempData.ItemType = itemType;

				m_ListData.push_back(tempData);
			}
		}
		全_金堆数据 = m_ListData;
		Sleep(20);
	}
}
//读取自身状态
void LocalPlayer_IsShock()
{
	while (true)
	{
		if (!Global::Cache_LocalPlayer.L_ActorModel) {
			Sleep(800);
			continue;
		}

		//cout << Function::Flag::IsMyManage << endl;
		//cout << LocalPlayer_Data.MyCurrentCollisionFlags << endl;

		////如果振刀成功则弹起物理鼠标左右键
		//if (LocalPlayer_Data.MyEndureLevel == 31)
		//{
		//	auto stop = chrono::high_resolution_clock::now();
		//	if (chrono::duration_cast<chrono::milliseconds>(stop - start) <= std::chrono::milliseconds(500)) continue;
		//	//左键弹起
		//	kmNet_mask_mouse_left(true);
		//	kmNet_mouse_move(1, 1);
		//	kmNet_mask_mouse_left(false);
		//	左键弹起();
		//	//右键弹起
		//	右键弹起();
		//	kmNet_mask_mouse_right(true);
		//	kmNet_mouse_move(1, 1);
		//	kmNet_mask_mouse_right(false);
		//	start = chrono::high_resolution_clock::now();
		//}

		//判断是否蓄转
		if (StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"01") && LocalPlayer_Data.MyBlueTime > 0.f && LocalPlayer_Data.MyBlueTime <= 0.49f /*&& LocalPlayer_Data.MyEndureLevel == 20*/)
		{
			Function::Flag::IsBlueToRed = true;
		}
		else
		{
			Function::Flag::IsBlueToRed = false;
		}
		//如果磐石，则可以振刀
		if ((StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"saber_parry") || StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"blade_parry")))
		{
			Function::Flag::IsMyManage = true;
			continue;
		}
		//如果已经变身，则不能振刀
		if (LocalPlayer_Data.MyHero == HeroType::shenjiang || LocalPlayer_Data.MyHero == HeroType::dafo || LocalPlayer_Data.MyHero == HeroType::tiewei)
		{
			Function::Flag::IsMyManage = false;
			continue;
		}
		//如果自身状态等级不对，则不能振刀
		if (LocalPlayer_Data.MyReactionType == 2 || LocalPlayer_Data.MyEndureLevel == 21 || LocalPlayer_Data.MyEndureLevel == 22 || LocalPlayer_Data.MyEndureLevel >= 30)
		{
			if (LocalPlayer_Data.MyHero == jiyingying && LocalPlayer_Data.MyEndureLevel == 30 && LocalPlayer_Data.MyBlueTime <= 0.49f)
			{
				Function::Flag::IsMyManage = true;
				continue;
			}
			else
			{
				Function::Flag::IsMyManage = false;
				continue;
			}
		}
		//如果自身倒地则可以振刀，否则不能振刀
		if (LocalPlayer_Data.MyActionDuration != 0)
		{
			if (LocalPlayer_Data.MyEndureLevel == 20 || regex_match(LocalPlayer_Data.MyActionName, wregex(L"(male|female)_injured_lie_(left|right|back|front)_01")) || StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"male_unarmed_idle_01") || (StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"injured_lie") && LocalPlayer_Data.MyCurTime >= 0.4f))
			{
				Function::Flag::IsMyManage = true;
				continue;
			}
			else
			{
				Function::Flag::IsMyManage = false;
				continue;
			}
		}
		//根据当前是否释放技能判断是否可以振刀
		switch (LocalPlayer_Data.MyHero)
		{
		case 1000001:
			//胡桃
			//判断自身是否在牵线中
			//cout << "进入胡桃判断" << endl;
			if (LocalPlayer_Data.MyLeftContinueTime == 0) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000003:
			//宁红夜
			//cout << "进入宁红夜判断" << endl;
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"blindsword") && (LocalPlayer_Data.MyEndureLevel != 52)) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000004:
			//迦南
			//判断自身是否正在使用F
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"desertassassin")) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000005:
			//沙南
			//判断自身是否正在使用F
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"wolfman")) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000006:
			//火男
			//判断自身是否正在使用F sprint
			if (StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"sprint") || !StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"spiritsman")) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000007:
			//和尚
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"monk")) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000009:
			//妖刀姬
			//判断自身是否正在使用F
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"yaodaoji")) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000010:
			//崔三娘
			//判断自身是否正在使用F
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"cuisanniang")) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000011:
			//岳山
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"yueshan")) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000013:
			//无尘
			//判断自身是否正在使用F
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"wuchen")) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000015:
			//顾清寒
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"guqinghan")) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000016:
			//武田
			//判断自身是否正在使用F
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"takeda") && LocalPlayer_Data.MyLeftContinueTime == 0) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000017:
			//殷紫萍
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), (L"yinziping"))) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			/*IsMyManage = true;*/
			break;
		case 1000018:
			//沈妙
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"shenmiao")) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000020:			//胡为
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"huwei")) { Function::Flag::IsMyManage = true; }
			else
			{
				if (StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"tigerleap"))
					Function::Flag::IsMyManage = true;
				else
					Function::Flag::IsMyManage = false;
			}
			break;
		case 1000021:
			//季莹莹
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"jiyingying")) { Function::Flag::IsMyManage = true; }
			else
			{
				if (StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"sprint") && LocalPlayer_Data.MyLeftContinueTime == 0)
				{
					Function::Flag::IsMyManage = true;
				}
				else
				{
					Function::Flag::IsMyManage = false;
				}
			}
			break;
		case 1000022:			//玉玲珑
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"yulinglong")) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000023:			//哈迪
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"hadi") && Tool::IsMeleeWeapon(LocalPlayer_Data.MyWeaponType)) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		case 1000024:
			//魏轻
			if (!StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"weiqing")) { Function::Flag::IsMyManage = true; }
			else { Function::Flag::IsMyManage = false; }
			break;
		default:
			Function::Flag::IsMyManage = false;
			break;
		}

		//auto stop = chrono::high_resolution_clock::now();
		//auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
		//std::cout << "Read time: " << duration.count() << " ms" << endl;
		Sleep(1);
	}
}
//振刀
void ShockKnifeThread()
{
	cout.setf(ios::fixed);
	cout.precision(3);
	while (true)
	{
		vector<PlayerData>m_ListData;
		if (!全_玩家交互)
		{
			m_ListData = 全_玩家数据;
		}
		
		for (int i = 0; i < m_ListData.size(); i++)
		{
			auto& List = m_ListData.at(i);
			if(List.O_Dis >= 12.f) continue;
			//printf("%f\n", List.obj.ObjCurTime);
			if (!(Function::Shock::F_ShockKnife || Function::Shock::F_MemShock) || Function::Flag::HeroTianHaiF2) continue;
			if (!Tool::IsMeleeWeapon(LocalPlayer_Data.MyWeaponType))continue;//检查是否获取武器
			switch (List.O_ActorWeapon)
			{
			case 101:
				SwShockKnife(List);
				break;
			case 102:
				KatanaShockKnife(List);
				break;
			case 103:
				BladeShockKnife(List);
				break;
			case 105:
				SpearShockKnife(List);
				break;
			case 106:
				DaggeShockKnife(List);
				break;
			case 116:
				nunchucksShockKnife(List);
				break;
			case 118:
				twinbladesShockKnife(List);
				break;
			case 119:
				SaberShockKnife(List);
				break;
			case 120:
				rodShockKnife(List);
				break;
			case 121:
				dualhalberdKnife(List);
				break;
			case 122:
				fanShockKnife(List);
				break;
			case 123:
				hengdaoShockKnife(List);
				break;
			default:
				break;
			}
		}
		Sleep(1);
	}
}
//闪避活化
void HeroActivationThread()
{
	while (true)
	{
		vector<PlayerData>m_ListData;
		if (!全_玩家交互)
		{
			m_ListData = 全_玩家数据;
		}
		for (int i = 0; i < m_ListData.size(); i++)
		{
			auto& List = m_ListData.at(i);
			if (List.O_Dis > 35.f) continue;
			
			//闪避活化
			if (Function::HeroActivation::IsDodge)
				DodgeSkill(List);

			//武田F活化
			if (Function::HeroActivation::武田自动毛刀)
				WuTianActivation(List);

			//和尚F2活化
			if (Function::HeroActivation::和尚自动F2)
			{
				if (LocalPlayer_Data.MySkillID == 1500501 && LocalPlayer_Data.MySkillState == 0)
				{
					Function::Flag::HeroTianHaiF2 = true;
					if (Function::Flag::IsMyManage)
					{
						switch (List.O_ActorWeapon)
						{
						case 101:
							TianHaiSwShockKnife(List);
							break;
						case 102:
							TianHaiKatanaShockKnife(List);
							break;
						case 103:
							TianHaiBladeShockKnife(List);
							break;
						case 105:
							TianHaiSpearShockKnife(List);
							break;
						case 106:
							TianHaiDaggeShockKnife(List);
							break;
						case 116:
							TianHainunchucksShockKnife(List);
							break;
						case 118:
							TianHaitwinbladesShockKnife(List);
							break;
						case 119:
							TianHaiSaberShockKnife(List);
							break;
						case 120:
							TianHairodShockKnife(List);
							break;
						case 121:
							TianHaidualhalberdKnife(List);
							break;
						case 122:
							TianHaifanShockKnife(List);
							break;
						case 123:
							TianHaihengdaoShockKnife(List);
							break;
						default:
							break;
						}
					}
				}
				else
					Function::Flag::HeroTianHaiF2 = false;
			}
		}
		Sleep(1);
	}
}
//出蓄博弈
void LogicKnifeThread()
{
	while (true)
	{
		if (Function::Kmbox::Net::NetState == 0 && !是否连接Net)
		{
			是否连接Net = true;
			kmNet_monitor(8769);		//启动监听端口
		}
		vector<PlayerData>m_ListData;
		if (!全_玩家交互)
		{
			m_ListData = 全_玩家数据;
		}
		for (int i = 0; i < m_ListData.size(); i++)
		{
			auto& List = m_ListData.at(i);
			if (List.O_Dis > 5.f || !Tool::IsMeleeWeapon(LocalPlayer_Data.MyWeaponType)) continue;
			if (Global::WorldPtr.敌人数量5M内 > 2 && List.O_Dis > 3.f) continue;//如果5M内敌人数量大于2，则只博弈3M内的敌人
			{
				//printf("666");
				if (Function::LogicKnife::BlueAttackShock)
				{
					float 振刀后摇 = 0.f;
					if (List.O_ActorWeapon == nunchucks)//双截棍振刀判定时间比其他武器多0.1S
						振刀后摇 += 0.1f;
					if (StrStrW(List.O_ActionName.c_str(), L"emptystep_back_01"))
						BlueAttackRed(List, 振刀后摇 + 0.347 + (活化参数::出蓄抓振延迟 / 1000));
					else if (StrStrW(List.O_ActionName.c_str(), L"emptystep_back_02"))
						BlueAttackRed(List, 振刀后摇 + 0.477 + (活化参数::出蓄抓振延迟 / 1000));
					else if (StrStrW(List.O_ActionName.c_str(), L"emptystep_back_03"))
						BlueAttackRed(List, 振刀后摇 + 0.447 + (活化参数::出蓄抓振延迟 / 1000));
					else if (StrStrW(List.O_ActionName.c_str(), L"emptystep_back_04"))
						BlueAttackRed(List, 振刀后摇 + 0.347 + (活化参数::出蓄抓振延迟 / 1000));
				}

				if (Function::LogicKnife::BlueAttackWrite)
				{
					if (List.O_EndureLevel == 11)
					{
						BlueAttackWriteA(List);
					}
				}
			}
		}
		Sleep(1);
	}
}

void 输出逻辑执行()		//下面的话写给用户：该功能可以在玩游戏时开启，此功能将记录本局所有的振刀-拼刀-闪避等一系列操作，方便用户优化实战中招式的角度以及范围
{
	
	while (true)
	{
		Sleep(1);
		if (Function::Shock::F_MemShock)
		{
			if (!是否HOOK)
			{
				是否HOOK = true;
				Hook::InitVtbaleHook();
			}
		}
		if (!调试::输出逻辑执行) { Sleep(3000); continue; }
		if (调试::输出逻辑执行Flag)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << 调试::逻辑执行.敌人类型 << 调试::逻辑执行.敌人动作 << 调试::逻辑执行.执行动作 << " 执行距离:" << 调试::逻辑执行.执行距离 << " | 执行角度:" << 调试::逻辑执行.执行角度 << " | 判断角度" << 调试::逻辑执行.判断角度 << endl;
			调试::输出逻辑执行Flag = false;
		}
	}
}
void 输出调试执行()			//下面的话写给用户：请勿开启输出调试执行玩游戏，此功能会显示范围内所有的出招距离以及角度，此功能仅仅只是方便用户自身调试范围和距离而开启的功能。
{
	while (true)
	{
		Sleep(1);

		if (!调试::输出调试执行) { Sleep(3000); continue; }

		vector<PlayerData>m_ListData;
		if (!全_玩家交互)
		{
			m_ListData = 全_玩家数据;
		}
		for (int i = 0; i < m_ListData.size(); i++)
		{
			auto& List = m_ListData.at(i);
			switch (List.O_ActorWeapon)
			{
			case 101:
				DebugSwShockKnife(List);
				break;
			case 102:
				DebugKatanaShockKnife(List);
				break;
			case 103:
				DebugBladeShockKnife(List);
				break;
			case 105:
				DebugSpearShockKnife(List);
				break;
			case 106:
				DebugDaggeShockKnife(List);
				break;
			case 116:
				DebugnunchucksShockKnife(List);
				break;
			case 118:
				DebugtwinbladesShockKnife(List);
				break;
			case 119:
				DebugSaberShockKnife(List);
				break;
			case 120:
				DebugrodShockKnife(List);
				break;
			case 121:
				DebugdualhalberdKnife(List);
				break;
			case 122:
				DebugfanShockKnife(List);
				break;
			case 123:
				DebughengdaoShockKnife(List);
				break;
			default:
				break;
			}
		}
	}
}



void Thread()
{
	SetConsoleCtrlHandler(HandlerRoutine, TRUE);
	初始化振刀距离参数数据();
	初始化振刀角度参数数据();
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Cache_Player_World_Data, 0, 0, 0));		//缓存指针
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)LocalPlayer_IsShock, 0, 0, 0));				//读取自身状态
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)LocalPlayer_Object_Data, 0, 0, 0));		//读取敌人数据
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)GetItemData, 0, 0, 0));						//读取物品
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)GetUserBattleData, 0, 0, 0));				//读取堆堆任务
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ShockKnifeThread, 0, 0, 0));				//振刀
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)HeroActivationThread, 0, 0, 0));			//闪避活化
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)LogicKnifeThread, 0, 0, 0));					//出蓄博弈

	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)输出逻辑执行, 0, 0, 0));			//调试输出逻辑执行
	CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)输出调试执行, 0, 0, 0));			//调试输出调试执行
	Gui.MyWindow(DrawRun);


}