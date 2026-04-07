#include "ShockKnife.h"
#include "Data.h"
#include <math.h>

//长剑振刀分支
auto SwShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 13.f)
	{
		int Shock_BlueToRead_Delay = 0;
		double ObjCurTime = 0;
		float NewAngle = 0.f;
		float Shock_Dis_Delay = 0;
		if (Function::Shock::F_ShockKnife)
		{
			//左3
			if (obj.O_ActionName == L"male_sw_attack_light_03" && obj.O_Dis <= 振刀参数::距离::长剑.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.391 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长剑.左3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::长剑.左3 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长剑】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长剑.左3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_sw_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::长剑.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.414 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长剑.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::长剑.右3 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长剑】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长剑.右3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左剑气
			else if ((obj.O_ActionName == L"male_sw_attack_hold_light_01" || obj.O_ActionName == L"male_sw_attack_hold_light_02") && obj.O_Dis <= 振刀参数::距离::长剑.左剑气 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				//if (obj.ISRobot) Shock_BlueToRead_Delay += 25;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长剑.左剑气2M;
				}
				else if (obj.O_Dis <= 4.f)
				{
					NewAngle = 振刀参数::角度::长剑.左剑气4M;
				}
				else if (obj.O_Dis <= 6.5f)
				{
					NewAngle = 振刀参数::角度::长剑.左剑气6M;
					Shock_Dis_Delay += (obj.O_Dis * 2.5) / 150;
				}
				else if (obj.O_Dis <= 9.5f)
				{
					NewAngle = 振刀参数::角度::长剑.左剑气9M;
					Shock_Dis_Delay += (obj.O_Dis * 3.8) / 150;
				}
				else
				{
					NewAngle = 振刀参数::角度::长剑.左剑气9M外;
					Shock_Dis_Delay += (obj.O_Dis * 4.5) / 150;

				}

				auto Shock_Timing = 0.245 + Shock_Dis_Delay - (Shock_BlueToRead_Delay + Global::WorldPtr.ping / 2 + 185 + Function::Shock::Shock_Delay) / 1000;
				if (Shock_Timing > 0.f)
				{
					if (ObjCurTime > Shock_Timing)
					{
						if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【A剑气】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
							振刀逻辑::BlueToRed();
							调试::逻辑执行.敌人类型 = "【长剑】";
							调试::逻辑执行.敌人动作 = "【左剑气】";
							调试::逻辑执行.执行动作 = "【振刀】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
							Sleep(400);
						}
					}
				}
				else
				{
					if (LocalPlayer_Data.MyBlueTime > 0.5f /*&& Function::Shock::Flag_CollideKnife*/)
					{
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【A剑气】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】| 时机:" << Shock_Timing << endl;
							振刀逻辑::BlueToRed();
							调试::逻辑执行.敌人类型 = "【长剑】";
							调试::逻辑执行.敌人动作 = "【左剑气】";
							调试::逻辑执行.执行动作 = "【振刀】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
							Sleep(500);
						}

						//if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
						//{
						//	//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【A剑气】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】| 时机:" << Shock_Timing << endl;
						//	振刀逻辑::CollideKnife();
						//	调试::逻辑执行.敌人类型 = "【长剑】";
						//	调试::逻辑执行.敌人动作 = "【左剑气】";
						//	调试::逻辑执行.执行动作 = "【拼刀】";
						//	调试::逻辑执行.执行距离 = obj.O_Dis;
						//	调试::逻辑执行.执行角度 = NewAngle;
						//	调试::输出逻辑执行Flag = true;
						//	Sleep(500);
						//}
					}
					else
					{
						if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
						{
							if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
							{
								//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【A剑气】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】| 时机:" << Shock_Timing << endl;
								振刀逻辑::ShortDodge(KEY_W);
								调试::逻辑执行.敌人类型 = "【长剑】";
								调试::逻辑执行.敌人动作 = "【左剑气】";
								调试::逻辑执行.执行动作 = "【闪避】";
								调试::逻辑执行.执行距离 = obj.O_Dis;
								调试::逻辑执行.执行角度 = NewAngle;
								调试::输出逻辑执行Flag = true;
								Sleep(800);
							}
						}
					}
				}
			}
			//右剑气
			else if ((obj.O_ActionName == L"male_sw_attack_hold_heavy_01" || obj.O_ActionName == L"male_sw_attack_hold_heavy_02") && obj.O_Dis <= 振刀参数::距离::长剑.右剑气 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				//if (obj.ISRobot) Shock_BlueToRead_Delay += 25;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长剑.右剑气2M;
				}
				else if (obj.O_Dis <= 4.f)
				{
					NewAngle = 振刀参数::角度::长剑.右剑气4M;
				}
				else if (obj.O_Dis <= 6.5f)
				{
					NewAngle = 振刀参数::角度::长剑.右剑气6M;
					Shock_Dis_Delay += (obj.O_Dis * 2.5) / 150;
				}
				else if (obj.O_Dis <= 9.5f)
				{
					NewAngle = 振刀参数::角度::长剑.右剑气9M;
					Shock_Dis_Delay += (obj.O_Dis * 3.8) / 150;
				}
				else
				{
					NewAngle = 振刀参数::角度::长剑.右剑气9M外;
					Shock_Dis_Delay += (obj.O_Dis * 4.5) / 150;

				}

				auto Shock_Timing = 0.245 + Shock_Dis_Delay - (Shock_BlueToRead_Delay + Global::WorldPtr.ping / 2 + 185 + Function::Shock::Shock_Delay) / 1000;
				if (Shock_Timing > 0.f)
				{
					if (ObjCurTime > Shock_Timing)
					{
						if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【B剑气】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
							振刀逻辑::BlueToRed();
							调试::逻辑执行.敌人类型 = "【长剑】";
							调试::逻辑执行.敌人动作 = "【右剑气】";
							调试::逻辑执行.执行动作 = "【振刀】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
							Sleep(400);
						}
					}
				}
				else
				{
					if (LocalPlayer_Data.MyBlueTime > 0.5f /*&& Function::Shock::Flag_CollideKnife*/)
					{
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【B剑气】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】| 时机:" << Shock_Timing << endl;
							振刀逻辑::CollideKnife();
							调试::逻辑执行.敌人类型 = "【长剑】";
							调试::逻辑执行.敌人动作 = "【右剑气】";
							调试::逻辑执行.执行动作 = "【拼刀】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
							Sleep(500);
						}
					}
					else
					{
						if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
						{
							if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
							{
								//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【B剑气】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】| 时机:" << Shock_Timing << endl;
								振刀逻辑::ShortDodge(KEY_W);
								调试::逻辑执行.敌人类型 = "【长剑】";
								调试::逻辑执行.敌人动作 = "【右剑气】";
								调试::逻辑执行.执行动作 = "【闪避】";
								调试::逻辑执行.执行距离 = obj.O_Dis;
								调试::逻辑执行.执行角度 = NewAngle;
								调试::输出逻辑执行Flag = true;
								Sleep(800);
							}
						}
					}
				}
			}
			//凤凰羽
			else if ((StrStrW(obj.O_ActionName.c_str(), L"soul_01") || StrStrW(obj.O_ActionName.c_str(), L"soul_02")) && obj.O_Dis <= 振刀参数::距离::长剑.凤凰羽 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				//if (obj.ISRobot) Shock_BlueToRead_Delay += 25;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长剑.凤凰羽2M;
				}
				else if (obj.O_Dis <= 5.f)
				{
					NewAngle = 振刀参数::角度::长剑.凤凰羽5M;
					Shock_Dis_Delay += (obj.O_Dis * 2.8f) / 150;
				}
				else if (obj.O_Dis <= 8.f)
				{
					NewAngle = 振刀参数::角度::长剑.凤凰羽8M;
					Shock_Dis_Delay += (obj.O_Dis * 2.8f) / 150;
				}
				else
				{
					NewAngle = 振刀参数::角度::长剑.凤凰羽8M外;
					Shock_Dis_Delay += (obj.O_Dis * 2.8) / 150;
				}


				auto Shock_Timing = (0.232 + Shock_Dis_Delay - (Shock_BlueToRead_Delay + Global::WorldPtr.ping / 2 + 185 - Function::Shock::Shock_Delay) / 1000);
				if (Shock_Timing > 0.f)
				{
					if (ObjCurTime > Shock_Timing)
					{
						if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【凤凰羽】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
							振刀逻辑::BlueToRed();
							调试::逻辑执行.敌人类型 = "【长剑】";
							调试::逻辑执行.敌人动作 = "【凤凰羽】";
							调试::逻辑执行.执行动作 = "【振刀】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
							Sleep(400);
						}
					}
				}
				else
				{
					if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
					{
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【凤凰羽】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】| 时机:" << Shock_Timing << endl;
							振刀逻辑::CollideKnife();
							调试::逻辑执行.敌人类型 = "【长剑】";
							调试::逻辑执行.敌人动作 = "【凤凰羽】";
							调试::逻辑执行.执行动作 = "【拼刀】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
							Sleep(500);
						}
					}
					else
					{
						if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
						{
							if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
							{
								//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【凤凰羽】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】| 时机:" << Shock_Timing << endl;
								振刀逻辑::ShortDodge(KEY_W);
								调试::逻辑执行.敌人类型 = "【长剑】";
								调试::逻辑执行.敌人动作 = "【凤凰羽】";
								调试::逻辑执行.执行动作 = "【闪避】";
								调试::逻辑执行.执行距离 = obj.O_Dis;
								调试::逻辑执行.执行角度 = NewAngle;
								调试::输出逻辑执行Flag = true;
								Sleep(800);
							}
						}
					}
				}

			}
			//蓝月
			else if (StrStrW(obj.O_ActionName.c_str(), L"copy_03") && obj.O_Dis <= 振刀参数::距离::长剑.蓝月 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (obj.ISRobot) Shock_BlueToRead_Delay += 25;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长剑.蓝月2M;
				}
				else if (obj.O_Dis <= 6.f)
				{
					NewAngle = 振刀参数::角度::长剑.蓝月6M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长剑.蓝月6M外;
					Shock_Dis_Delay += (obj.O_Dis * 1.5) / 150;
				}


				auto Shock_Timing = (0.405 + Shock_Dis_Delay - (Shock_BlueToRead_Delay + Global::WorldPtr.ping / 2 + 250 - Function::Shock::Shock_Delay) / 1000);
				if (Shock_Timing > 0.f)
				{
					if (ObjCurTime > Shock_Timing)
					{
						if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【蓝月】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
							振刀逻辑::BlueToRed();
							调试::逻辑执行.敌人类型 = "【长剑】";
							调试::逻辑执行.敌人动作 = "【蓝月】";
							调试::逻辑执行.执行动作 = "【振刀】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
							Sleep(400);
						}
					}
				}
				else
				{
					if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
					{
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【蓝月】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】| 时机:" << Shock_Timing << endl;
							振刀逻辑::CollideKnife();
							调试::逻辑执行.敌人类型 = "【长剑】";
							调试::逻辑执行.敌人动作 = "【蓝月】";
							调试::逻辑执行.执行动作 = "【拼刀】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
							Sleep(500);
						}
					}
					else
					{
						if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
						{
							if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
							{
								//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【蓝月】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】| 时机:" << Shock_Timing << endl;
								振刀逻辑::ShortDodge(KEY_W);
								调试::逻辑执行.敌人类型 = "【长剑】";
								调试::逻辑执行.敌人动作 = "【蓝月】";
								调试::逻辑执行.执行动作 = "【闪避】";
								调试::逻辑执行.执行距离 = obj.O_Dis;
								调试::逻辑执行.执行角度 = NewAngle;
								调试::输出逻辑执行Flag = true;
								Sleep(800);
							}
						}
					}
				}
			}
			//七星夺窍
			else if (obj.O_ActionName == L"male_sw_attack_light_soul_04" && obj.O_Dis <= 振刀参数::距离::长剑.七星夺窍 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				//if (obj.ISRobot) Shock_BlueToRead_Delay += 25;

				if (obj.O_Dis <= 4.f)
				{
					NewAngle = 振刀参数::角度::长剑.七星夺窍;
				}
				else if (obj.O_Dis <= 6.f)
				{
					NewAngle = 振刀参数::角度::长剑.七星夺窍;
					Shock_Dis_Delay += (obj.O_Dis * 1.0) / 150;
				}
				else
				{
					NewAngle = 振刀参数::角度::长剑.七星夺窍;
					Shock_Dis_Delay += (obj.O_Dis * 1.0) / 150;
				}


				auto Shock_Timing = (0.245 + Shock_Dis_Delay - (Shock_BlueToRead_Delay + Global::WorldPtr.ping / 2 + 185 + Function::Shock::Shock_Delay) / 1000);
				if (Shock_Timing > 0.f)
				{
					if (ObjCurTime > Shock_Timing)
					{
						if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【七星夺窍】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
							振刀逻辑::BlueToRed();
							调试::逻辑执行.敌人类型 = "【长剑】";
							调试::逻辑执行.敌人动作 = "【七星夺窍】";
							调试::逻辑执行.执行动作 = "【振刀】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
							Sleep(400);
						}
					}
				}
				else
				{
					if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
					{
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【七星夺窍】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】| 时机:" << Shock_Timing << endl;
							振刀逻辑::CollideKnife();
							调试::逻辑执行.敌人类型 = "【长剑】";
							调试::逻辑执行.敌人动作 = "【七星夺窍】";
							调试::逻辑执行.执行动作 = "【拼刀】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
							Sleep(500);
						}
					}
					else
					{
						if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
						{
							if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
							{
								//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【七星夺窍】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】| 时机:" << Shock_Timing << endl;
								振刀逻辑::ShortDodge(KEY_S);
								调试::逻辑执行.敌人类型 = "【长剑】";
								调试::逻辑执行.敌人动作 = "【七星夺窍】";
								调试::逻辑执行.执行动作 = "【闪避】";
								调试::逻辑执行.执行距离 = obj.O_Dis;
								调试::逻辑执行.执行角度 = NewAngle;
								调试::输出逻辑执行Flag = true;
								Sleep(800);
							}
						}
					}
				}
			}
		}
		else if (Function::Shock::F_MemShock)
		{
			//左3
			if (obj.O_ActionName == L"male_sw_attack_light_03" && obj.O_Dis <= 振刀参数::距离::长剑.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				auto Shock_Timing = (0.382069 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长剑.左3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::长剑.左3 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长剑】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长剑.左3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_sw_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::长剑.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长剑.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::长剑.右3 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长剑】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长剑.右3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;

					}
				}
			}
			//左剑气
			else if ((obj.O_ActionName == L"male_sw_attack_hold_light_01" || obj.O_ActionName == L"male_sw_attack_hold_light_02") && obj.O_Dis <= 振刀参数::距离::长剑.左剑气 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长剑.左剑气2M;
				}
				else if (obj.O_Dis <= 4.f)
				{
					NewAngle = 振刀参数::角度::长剑.左剑气4M;
				}
				else if (obj.O_Dis <= 6.5f)
				{
					NewAngle = 振刀参数::角度::长剑.左剑气6M;
					Shock_Dis_Delay += (obj.O_Dis * 2.5) / 150;
				}
				else if (obj.O_Dis <= 9.5f)
				{
					NewAngle = 振刀参数::角度::长剑.左剑气9M;
					Shock_Dis_Delay += (obj.O_Dis * 3.8) / 150;
				}
				else
				{
					NewAngle = 振刀参数::角度::长剑.左剑气9M外;
					Shock_Dis_Delay += (obj.O_Dis * 4.5) / 150;

				}

				auto Shock_Timing = 0.23 + Shock_Dis_Delay - (Shock_BlueToRead_Delay + Global::WorldPtr.ping / 2 + 235 + Function::Shock::Shock_Delay) / 1000;
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【A剑气】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长剑】";
						调试::逻辑执行.敌人动作 = "【左剑气】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//右剑气
			else if ((obj.O_ActionName == L"male_sw_attack_hold_heavy_01" || obj.O_ActionName == L"male_sw_attack_hold_heavy_02") && obj.O_Dis <= 振刀参数::距离::长剑.右剑气 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;
				//if (obj.ISRobot) Shock_BlueToRead_Delay += 25;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长剑.右剑气2M;
				}
				else if (obj.O_Dis <= 4.f)
				{
					NewAngle = 振刀参数::角度::长剑.右剑气4M;
				}
				else if (obj.O_Dis <= 6.5f)
				{
					NewAngle = 振刀参数::角度::长剑.右剑气6M;
					Shock_Dis_Delay += (obj.O_Dis * 2.5) / 150;
				}
				else if (obj.O_Dis <= 9.5f)
				{
					NewAngle = 振刀参数::角度::长剑.右剑气9M;
					Shock_Dis_Delay += (obj.O_Dis * 3.8) / 150;
				}
				else
				{
					NewAngle = 振刀参数::角度::长剑.右剑气9M外;
					Shock_Dis_Delay += (obj.O_Dis * 4.5) / 150;

				}


				auto Shock_Timing = 0.23 + Shock_Dis_Delay - (Shock_BlueToRead_Delay + Global::WorldPtr.ping / 2 + 235 + Function::Shock::Shock_Delay) / 1000;
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【B剑气】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长剑】";
						调试::逻辑执行.敌人动作 = "【右剑气】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//凤凰羽
			else if ((StrStrW(obj.O_ActionName.c_str(), L"soul_01") || StrStrW(obj.O_ActionName.c_str(), L"soul_02")) && obj.O_Dis <= 振刀参数::距离::长剑.凤凰羽 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;
				//if (obj.ISRobot) Shock_BlueToRead_Delay += 25;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长剑.凤凰羽2M;
				}
				else if (obj.O_Dis <= 5.f)
				{
					NewAngle = 振刀参数::角度::长剑.凤凰羽5M;
					Shock_Dis_Delay += (obj.O_Dis * 2.8f) / 150;
				}
				else if (obj.O_Dis <= 8.f)
				{
					NewAngle = 振刀参数::角度::长剑.凤凰羽8M;
					Shock_Dis_Delay += (obj.O_Dis * 2.8f) / 150;
				}
				else
				{
					NewAngle = 振刀参数::角度::长剑.凤凰羽8M外;
					Shock_Dis_Delay += (obj.O_Dis * 2.8) / 150;
				}

				auto Shock_Timing = (0.22 + Shock_Dis_Delay - (Shock_BlueToRead_Delay + Global::WorldPtr.ping / 2 + 235 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【凤凰羽】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长剑】";
						调试::逻辑执行.敌人动作 = "【凤凰羽】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//蓝月
			else if (StrStrW(obj.O_ActionName.c_str(), L"copy_03") && obj.O_Dis <= 振刀参数::距离::长剑.蓝月 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;
				if (obj.ISRobot) Shock_BlueToRead_Delay += 25;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长剑.蓝月2M;
				}
				else if (obj.O_Dis <= 6.f)
				{
					NewAngle = 振刀参数::角度::长剑.蓝月6M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长剑.蓝月6M外;
					Shock_Dis_Delay += (obj.O_Dis * 1.5) / 150;
				}

				auto Shock_Timing = (0.4 + Shock_Dis_Delay - (Shock_BlueToRead_Delay + Global::WorldPtr.ping / 2 + 230 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【蓝月】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长剑】";
						调试::逻辑执行.敌人动作 = "【蓝月】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//七星夺窍
			else if (obj.O_ActionName == L"male_sw_attack_light_soul_04" && obj.O_Dis <= 振刀参数::距离::长剑.七星夺窍 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;
				//if (obj.ISRobot) Shock_BlueToRead_Delay += 25;

				if (obj.O_Dis <= 4.f)
				{
					NewAngle = 振刀参数::角度::长剑.七星夺窍;
				}
				else if (obj.O_Dis <= 6.f)
				{
					NewAngle = 振刀参数::角度::长剑.七星夺窍;
					Shock_Dis_Delay += (obj.O_Dis * 1.0) / 150;
				}
				else
				{
					NewAngle = 振刀参数::角度::长剑.七星夺窍;
					Shock_Dis_Delay += (obj.O_Dis * 1.0) / 150;
				}

				auto Shock_Timing = (0.23 + Shock_Dis_Delay - (Shock_BlueToRead_Delay + Global::WorldPtr.ping / 2 + 235 + Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长剑】| " << "【七星夺窍】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长剑】";
						调试::逻辑执行.敌人动作 = "【七星夺窍】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
		}
	}
}

//太刀振刀分支
auto  KatanaShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 11.f)
	{
		int Shock_BlueToRead_Delay = 50;
		double ObjCurTime = 0;
		float NewAngle = 0.f;

		if (Function::Shock::F_ShockKnife)
		{
			//左3
			if (obj.O_ActionName == L"male_katana_attack_light_03" && obj.O_Dis <= 振刀参数::距离::太刀.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.433 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::太刀.左3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::太刀.左3 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::太刀.左3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_katana_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::太刀.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.415 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::太刀.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::太刀.右3 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::太刀.右3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左蓄
			else if ((obj.O_ActionName == L"male_katana_attack_hold_light_01" || obj.O_ActionName == L"male_katana_attack_hold_light_02") && obj.O_Dis <= 振刀参数::距离::太刀.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::太刀.左蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::太刀.左蓄2M外;
				}


				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//右蓄
			else if ((obj.O_ActionName == L"male_katana_attack_hold_heavy_01" || obj.O_ActionName == L"male_katana_attack_hold_heavy_02") && obj.O_Dis <= 振刀参数::距离::太刀.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::太刀.右蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::太刀.右蓄2M外;
				}


				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//左惊雷
			else if (obj.O_ActionName == L"male_katana_attack_light_05" && obj.O_Dis <= 振刀参数::距离::太刀.左惊雷 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.448 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::太刀.左惊雷) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【左惊雷】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::太刀.左惊雷 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【左惊雷】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::太刀.左惊雷;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//右惊雷
			else if (obj.O_ActionName == L"male_katana_attack_heavy_09_pre" && obj.O_Dis <= 振刀参数::距离::太刀.右惊雷/* && GetRangeReactionType(obj.Cache_HitSimulate) == 12*/)
			{
				if (obj.O_Dis <= 5.f)
				{
					NewAngle = 振刀参数::角度::太刀.右惊雷5M;
				}
				else
				{
					NewAngle = 振刀参数::角度::太刀.右惊雷5M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【右惊雷】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::BlueToRed();
					调试::逻辑执行.敌人类型 = "【太刀】";
					调试::逻辑执行.敌人动作 = "【右惊雷】";
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true;
					Sleep(400);
				}
			}
			//青鬼左
			else if (obj.O_ActionName == L"male_katana_attack_light_soul_03" && obj.O_Dis <= 振刀参数::距离::太刀.左青鬼 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.311 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::太刀.左青鬼) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【青鬼左】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::太刀.左青鬼 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【左青鬼】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::太刀.左青鬼;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//青鬼右
			else if (obj.O_ActionName == L"male_katana_attack_heavy_soul_03" && obj.O_Dis <= 振刀参数::距离::太刀.右青鬼 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.347 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::太刀.右青鬼) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【青鬼右】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::太刀.右青鬼 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【右青鬼】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::太刀.右青鬼;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//噬魂斩预判
			else if (StrStrW(obj.O_ActionName.c_str(), L"charge_soul_01") && obj.O_Dis <= 振刀参数::距离::太刀.噬魂斩 && Function::Shock::预判振刀)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				auto Shock_Timing = 0.85 + (Shock_BlueToRead_Delay - Global::WorldPtr.ping) / 1000;
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【噬魂斩】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::BlueToRed();
					调试::逻辑执行.敌人类型 = "【太刀】";
					调试::逻辑执行.敌人动作 = "【噬魂斩】";
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(400);
				}

			}

		}
		else if (Function::Shock::F_MemShock)
		{
			//左3
			if (obj.O_ActionName == L"male_katana_attack_light_03" && obj.O_Dis <= 振刀参数::距离::太刀.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.42 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::太刀.左3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::太刀.左3 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::太刀.左3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_katana_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::太刀.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::太刀.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::太刀.右3 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::太刀.右3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左蓄
			else if ((obj.O_ActionName == L"male_katana_attack_hold_light_01" || obj.O_ActionName == L"male_katana_attack_hold_light_02") && obj.O_Dis <= 振刀参数::距离::太刀.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::太刀.左蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::太刀.左蓄2M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【太刀】";
					调试::逻辑执行.敌人动作 = "【左蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//右蓄
			else if ((obj.O_ActionName == L"male_katana_attack_hold_heavy_01" || obj.O_ActionName == L"male_katana_attack_hold_heavy_02") && obj.O_Dis <= 振刀参数::距离::太刀.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::太刀.右蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::太刀.右蓄2M外;
				}


				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【太刀】";
					调试::逻辑执行.敌人动作 = "【右蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//左惊雷
			else if (obj.O_ActionName == L"male_katana_attack_light_05" && obj.O_Dis <= 振刀参数::距离::太刀.左惊雷 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.426018 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::太刀.左惊雷) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【左惊雷】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::太刀.左惊雷 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【左惊雷】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::太刀.左惊雷;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//右惊雷
			else if ((obj.O_ActionName == L"male_katana_attack_heavy_09" || obj.O_ActionName == L"male_katana_attack_heavy_soul_09") && obj.O_Dis <= 振刀参数::距离::太刀.右惊雷 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 5.f)
				{
					NewAngle = 振刀参数::角度::太刀.右惊雷5M;
				}
				else
				{
					NewAngle = 振刀参数::角度::太刀.右惊雷5M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【右惊雷】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【太刀】";
					调试::逻辑执行.敌人动作 = "【右惊雷】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//青鬼左
			else if (obj.O_ActionName == L"male_katana_attack_light_soul_03" && obj.O_Dis <= 振刀参数::距离::太刀.左青鬼 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.3 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::太刀.左青鬼) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【青鬼左】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::太刀.左青鬼 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【左青鬼】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::太刀.左青鬼;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//青鬼右
			else if (obj.O_ActionName == L"male_katana_attack_heavy_soul_03" && obj.O_Dis <= 振刀参数::距离::太刀.右青鬼 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.33 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::太刀.右青鬼) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【青鬼右】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::太刀.右青鬼 << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【太刀】";
						调试::逻辑执行.敌人动作 = "【右青鬼】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::太刀.右青鬼;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//噬魂斩预判
			else if (StrStrW(obj.O_ActionName.c_str(), L"charge_soul_01") && obj.O_Dis <= 振刀参数::距离::太刀.噬魂斩 && Function::Shock::预判振刀)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				auto Shock_Timing = 0.85 + (Shock_BlueToRead_Delay - Global::WorldPtr.ping) / 1000;
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【太刀】| " << "【噬魂斩】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::BlueToRed();
					调试::逻辑执行.敌人类型 = "【太刀】";
					调试::逻辑执行.敌人动作 = "【噬魂斩】";
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(400);
				}

			}
		}
	}
}

//阔刀振刀分支
auto BladeShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 9.5f)
	{
		int Shock_BlueToRead_Delay = 0;
		double ObjCurTime = 0;
		float NewAngle = 0.f;

		if (Function::Shock::F_ShockKnife)
		{
			//左左and右左左
			if ((StrStrW(obj.O_ActionName.c_str(), L"attack_light_02") || StrStrW(obj.O_ActionName.c_str(), L"attack_light_05")) && obj.O_Dis <= 振刀参数::距离::阔刀.左左 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.539 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::阔刀.左左) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【左左】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【左左】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::阔刀.左左;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左右
			else if (StrStrW(obj.O_ActionName.c_str(), L"attack_heavy_03") && obj.O_Dis <= 振刀参数::距离::阔刀.左右 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::阔刀.左右2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::阔刀.左右2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【左右】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【左右】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【左右】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【左右】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【左右】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【左右】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//右右and左右右
			else if ((StrStrW(obj.O_ActionName.c_str(), L"heavy_02") || StrStrW(obj.O_ActionName.c_str(), L"heavy_04")) && obj.O_Dis <= 振刀参数::距离::阔刀.右右 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.516 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::阔刀.右右) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【右右】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【右右】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::阔刀.右右;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//右左and左右左
			else if ((StrStrW(obj.O_ActionName.c_str(), L"light_06") || StrStrW(obj.O_ActionName.c_str(), L"light_07")) && obj.O_Dis <= 振刀参数::距离::阔刀.右左 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.609 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::阔刀.右左) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【右左】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【右左】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::阔刀.右左;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左蓄1段and左1火刀
			else if ((StrStrW(obj.O_ActionName.c_str(), L"attack_hold_light_01") || StrStrW(obj.O_ActionName.c_str(), L"soul_01")) && obj.O_Dis <= 振刀参数::距离::阔刀.左蓄一段 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (obj.ISRobot) Shock_BlueToRead_Delay += 100;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::阔刀.左蓄一段2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::阔刀.左蓄一段2M外;
				}

				auto Shock_Timing = (0.497 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【左蓄1段】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【左蓄1段】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左蓄2段and左2火刀
			else if ((StrStrW(obj.O_ActionName.c_str(), L"hold_light_02") || StrStrW(obj.O_ActionName.c_str(), L"copy_02")) && obj.O_Dis <= 振刀参数::距离::阔刀.左蓄二段 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.533 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【左蓄2段】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::BlueToRed();
					调试::逻辑执行.敌人类型 = "【阔刀】";
					调试::逻辑执行.敌人动作 = "【左蓄2段】";
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(400);
				}
			}
			//左蓄3段
			else if ((obj.O_ActionName == L"male_blade_attack_hold_light_03" || obj.O_ActionName == L"female_blade_attack_hold_light_03") && obj.O_Dis <= 振刀参数::距离::阔刀.左蓄三段 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.473 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【左蓄3段】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					if (obj.O_Dis >= 7.f)
					{
						振刀逻辑::JumpShock();
					}
					else
					{
						振刀逻辑::BlueToRed();
					}
					调试::逻辑执行.敌人类型 = "【阔刀】";
					调试::逻辑执行.敌人动作 = "【左蓄3段】";
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(400);
				}
			}
			//右蓄1/2/3段 and 左右1/2/3段or滑步右1/2/3 and 右1/2/3裂空 and 左右1/2/3段or滑步右1/2/3裂空
			else if ((StrStrW(obj.O_ActionName.c_str(), L"heavy_05") || StrStrW(obj.O_ActionName.c_str(), L"heavy_06") || StrStrW(obj.O_ActionName.c_str(), L"copy_05") || StrStrW(obj.O_ActionName.c_str(), L"copy_06")) && obj.O_Dis <= 振刀参数::距离::阔刀.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::阔刀.右蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::阔刀.右蓄2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪振】" << endl;
						if (振刀参数::特殊处理::阔刀右蓄是否短闪振)
						{
							振刀逻辑::ShortDodge(KEY_S);
							振刀逻辑::BlueToRed();
							调试::逻辑执行.敌人类型 = "【阔刀】";
							调试::逻辑执行.敌人动作 = "【右蓄】";
							调试::逻辑执行.执行动作 = "【短闪振】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
						}
						else
						{
							振刀逻辑::ShortDodge(KEY_S);
							调试::逻辑执行.敌人类型 = "【阔刀】";
							调试::逻辑执行.敌人动作 = "【右蓄】";
							调试::逻辑执行.执行动作 = "【闪避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
						}
						Sleep(1000);
					}
				}
			}
			//右右1/2/3段 and 左右右1/2/3段 and 右右1/2/3裂空 and 左右右1/2/3裂空
			else if ((StrStrW(obj.O_ActionName.c_str(), L"heavy_07") || StrStrW(obj.O_ActionName.c_str(), L"heavy_08") || StrStrW(obj.O_ActionName.c_str(), L"copy_07") || StrStrW(obj.O_ActionName.c_str(), L"copy_08")) && obj.O_Dis <= 振刀参数::距离::阔刀.右右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (obj.ISRobot) Shock_BlueToRead_Delay += 100;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::阔刀.右右蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::阔刀.右右蓄2M外;
				}

				auto Shock_Timing = (0.611 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【右右蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//雷刀
			else if ((obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_1" || obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_2" || obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_3") && obj.O_Dis <= 振刀参数::距离::阔刀.雷刀 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.469 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【雷刀】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					if (obj.O_Dis >= 7.5f)
						振刀逻辑::JumpShock();
					else
						振刀逻辑::BlueToRed();
					调试::逻辑执行.敌人类型 = "【阔刀】";
					调试::逻辑执行.敌人动作 = "【雷刀】";
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(400);
				}
			}
			//雷刀1
			else if (obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_4" && obj.O_Dis <= 振刀参数::距离::阔刀.雷刀下劈 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (2.192 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【雷刀】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::BlueToRed();
					调试::逻辑执行.敌人类型 = "【阔刀】";
					调试::逻辑执行.敌人动作 = "【雷刀】";
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(400);
				}
			}
		}
		else if (Function::Shock::F_MemShock)
		{
			//左左and右左左
			if ((StrStrW(obj.O_ActionName.c_str(), L"attack_light_02") || StrStrW(obj.O_ActionName.c_str(), L"attack_light_05")) && obj.O_Dis <= 振刀参数::距离::阔刀.左左 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.53 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::阔刀.左左) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【左左】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【左左】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::阔刀.左左;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左右
			else if (StrStrW(obj.O_ActionName.c_str(), L"attack_heavy_03") && obj.O_Dis <= 振刀参数::距离::阔刀.左右 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::阔刀.左右2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::阔刀.左右2M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.敌人类型 = "【阔刀】";
					调试::逻辑执行.敌人动作 = "【左右】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//右右and左右右
			else if ((StrStrW(obj.O_ActionName.c_str(), L"heavy_02") || StrStrW(obj.O_ActionName.c_str(), L"heavy_04")) && obj.O_Dis <= 振刀参数::距离::阔刀.右右 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.49 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::阔刀.右右) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【右右】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【右右】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::阔刀.右右;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//右左and左右左
			else if ((StrStrW(obj.O_ActionName.c_str(), L"light_06") || StrStrW(obj.O_ActionName.c_str(), L"light_07")) && obj.O_Dis <= 振刀参数::距离::阔刀.右左 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.6 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::阔刀.右左) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【右左】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【右左】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::阔刀.右左;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左蓄1段and左1火刀
			else if ((StrStrW(obj.O_ActionName.c_str(), L"attack_hold_light_01") || StrStrW(obj.O_ActionName.c_str(), L"soul_01")) && obj.O_Dis <= 振刀参数::距离::阔刀.左蓄一段 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;
				if (obj.ISRobot) Shock_BlueToRead_Delay += 100;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::阔刀.左蓄一段2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::阔刀.左蓄一段2M外;
				}

				auto Shock_Timing = (0.49 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【左蓄1段】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【左蓄1段】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左蓄2段and左2火刀
			else if ((StrStrW(obj.O_ActionName.c_str(), L"hold_light_02") || StrStrW(obj.O_ActionName.c_str(), L"copy_02")) && obj.O_Dis <= 振刀参数::距离::阔刀.左蓄二段 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.52 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【左蓄2段】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【阔刀】";
					调试::逻辑执行.敌人动作 = "【左蓄2段】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//左蓄3段
			else if ((obj.O_ActionName == L"male_blade_attack_hold_light_03" || obj.O_ActionName == L"female_blade_attack_hold_light_03") && obj.O_Dis <= 振刀参数::距离::阔刀.左蓄三段 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.46 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【左蓄3段】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【阔刀】";
					调试::逻辑执行.敌人动作 = "【左蓄3段】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//右蓄1/2/3段 and 左右1/2/3段or滑步右1/2/3 and 右1/2/3裂空 and 左右1/2/3段or滑步右1/2/3裂空
			else if ((StrStrW(obj.O_ActionName.c_str(), L"heavy_05") || StrStrW(obj.O_ActionName.c_str(), L"heavy_06") || StrStrW(obj.O_ActionName.c_str(), L"copy_05") || StrStrW(obj.O_ActionName.c_str(), L"copy_06")) && obj.O_Dis <= 振刀参数::距离::阔刀.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::阔刀.右蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::阔刀.右蓄2M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【阔刀】";
					调试::逻辑执行.敌人动作 = "【右蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//右右1/2/3段 and 左右右1/2/3段 and 右右1/2/3裂空 and 左右右1/2/3裂空
			else if ((StrStrW(obj.O_ActionName.c_str(), L"heavy_07") || StrStrW(obj.O_ActionName.c_str(), L"heavy_08") || StrStrW(obj.O_ActionName.c_str(), L"copy_07") || StrStrW(obj.O_ActionName.c_str(), L"copy_08")) && obj.O_Dis <= 振刀参数::距离::阔刀.右右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;
				if (obj.ISRobot) Shock_BlueToRead_Delay += 100;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::阔刀.右右蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::阔刀.右右蓄2M外;
				}

				auto Shock_Timing = (0.6 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【右右蓄力】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【阔刀】";
						调试::逻辑执行.敌人动作 = "【右右蓄】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//雷刀
			else if ((obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_1" || obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_2" || obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_3") && obj.O_Dis <= 振刀参数::距离::阔刀.雷刀 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.459329 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【雷刀】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【阔刀】";
					调试::逻辑执行.敌人动作 = "【雷刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//雷刀1
			else if (obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_4" && obj.O_Dis <= 振刀参数::距离::阔刀.雷刀下劈 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.13 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【阔刀】| " << "【雷刀】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【阔刀】";
					调试::逻辑执行.敌人动作 = "【雷刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
		}
	}
}

//长枪振刀分支
auto SpearShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 11.f)
	{
		int Shock_BlueToRead_Delay = 0;
		double ObjCurTime = 0;
		float NewAngle = 0.f;

		if (Function::Shock::F_ShockKnife)
		{
			//左3
			if (obj.O_ActionName == L"male_spear_attack_light_03" && obj.O_Dis <= 振刀参数::距离::长枪.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.414 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长枪.左3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长枪.左3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_spear_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::长枪.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.647 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长枪.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长枪.右3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_spear_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::长枪.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.417 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长枪.左蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长枪.左蓄;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//六合枪
			else if (obj.O_ActionName == L"male_spear_attack_hold_light_soul_01" && obj.O_Dis <= 振刀参数::距离::长枪.六合枪 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长枪.六合枪2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长枪.六合枪2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【六合枪】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【六合枪】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【六合枪】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【六合枪】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【六合枪】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【六合枪】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(1000);
					}
				}
			}
			//右蓄
			else if (obj.O_ActionName == L"male_spear_attack_hold_heavy_01" && obj.O_Dis <= 振刀参数::距离::长枪.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.357 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长枪.右蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长枪.右蓄;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//大圣游
			else if (obj.O_ActionName == L"male_spear_attack_hold_heavy_soul_01" && obj.O_Dis <= 振刀参数::距离::长枪.大圣游 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.436 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长枪.大圣游) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【大圣游】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【大圣游】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长枪.大圣游;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//风卷云残
			else if (obj.O_ActionName == L"male_spear_attack_heavy_soul_03" && obj.O_Dis <= 振刀参数::距离::长枪.风卷云残 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (1.028 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长枪.风卷云残) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【风卷云残】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【风卷云残】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长枪.风卷云残;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//双环扫
			else if (obj.O_ActionName == L"male_spear_attack_light_soul_03" && obj.O_Dis <= 振刀参数::距离::长枪.双环扫 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.31 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【双环扫】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::BlueToRed();
					调试::逻辑执行.敌人类型 = "【长枪】";
					调试::逻辑执行.敌人动作 = "【双环扫】";
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(400);
				}
			}
			//龙王破
			else if ((obj.O_ActionName == L"male_spear_attack_hold_light_03" || obj.O_ActionName == L"male_spear_attack_hold_heavy_03") && obj.O_Dis <= 振刀参数::距离::长枪.龙王破 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (obj.ISRobot) Shock_BlueToRead_Delay += 100;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长枪.龙王破2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长枪.龙王破2M外;
				}

				auto Shock_Timing = (0.357 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【龙王破】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【龙王破】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}

			}
			//穿心脚
			else if (StrStrW(obj.O_ActionName.c_str(), L"03_soul") && obj.O_Dis <= 振刀参数::距离::长枪.穿心脚 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (obj.ISRobot) Shock_BlueToRead_Delay += 100;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长枪.穿心脚2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长枪.穿心脚2M外;
				}

				auto Shock_Timing = (0.353 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【穿心脚】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【穿心脚】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
		}
		else if (Function::Shock::F_MemShock)
		{
			//左3
			if (obj.O_ActionName == L"male_spear_attack_light_03" && obj.O_Dis <= 振刀参数::距离::长枪.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长枪.左3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长枪.左3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_spear_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::长枪.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.63 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长枪.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长枪.右3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_spear_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::长枪.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长枪.左蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长枪.左蓄;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//六合枪
			else if (obj.O_ActionName == L"male_spear_attack_hold_light_soul_01" && obj.O_Dis <= 振刀参数::距离::长枪.六合枪 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长枪.六合枪2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长枪.六合枪2M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【六合枪】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【长枪】";
					调试::逻辑执行.敌人动作 = "【六合枪】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//右蓄
			else if (obj.O_ActionName == L"male_spear_attack_hold_heavy_01" && obj.O_Dis <= 振刀参数::距离::长枪.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.34 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长枪.右蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长枪.右蓄;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//大圣游
			else if (obj.O_ActionName == L"male_spear_attack_hold_heavy_soul_01" && obj.O_Dis <= 振刀参数::距离::长枪.大圣游 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.42 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长枪.大圣游) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【大圣游】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【大圣游】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长枪.大圣游;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//风卷云残
			else if (obj.O_ActionName == L"male_spear_attack_heavy_soul_03" && obj.O_Dis <= 振刀参数::距离::长枪.风卷云残 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (1.02 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长枪.风卷云残) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【风卷云残】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【风卷云残】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长枪.风卷云残;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//双环扫
			else if (obj.O_ActionName == L"male_spear_attack_light_soul_03" && obj.O_Dis <= 振刀参数::距离::长枪.双环扫 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.3 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【双环扫】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【长枪】";
					调试::逻辑执行.敌人动作 = "【双环扫】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//龙王破
			else if ((obj.O_ActionName == L"male_spear_attack_hold_light_03" || obj.O_ActionName == L"male_spear_attack_hold_heavy_03") && obj.O_Dis <= 振刀参数::距离::长枪.龙王破 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;
				if (obj.ISRobot) Shock_BlueToRead_Delay += 100;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长枪.龙王破2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长枪.龙王破2M外;
				}

				auto Shock_Timing = (0.34 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【龙王破】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【龙王破】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//穿心脚
			else if (StrStrW(obj.O_ActionName.c_str(), L"03_soul") && obj.O_Dis <= 振刀参数::距离::长枪.穿心脚 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;
				if (obj.ISRobot) Shock_BlueToRead_Delay += 100;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长枪.穿心脚2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长枪.穿心脚2M外;
				}

				auto Shock_Timing = (0.34 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长枪】| " << "【穿心脚】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长枪】";
						调试::逻辑执行.敌人动作 = "【穿心脚】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
		}
	}
}

//匕首振刀分支
auto DaggeShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 10.f)
	{
		int Shock_BlueToRead_Delay = 0;
		double ObjCurTime = 0;
		float NewAngle = 0.f;

		if (Function::Shock::F_ShockKnife)
		{
			//左3
			if (obj.O_ActionName == L"male_dagger_attack_light_03" && obj.O_Dis <= 振刀参数::距离::匕首.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.415 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::匕首.左3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::匕首.左3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_dagger_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::匕首.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.414 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::匕首.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::匕首.右3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_dagger_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::匕首.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::匕首.左蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::匕首.左蓄2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//右蓄
			else if (obj.O_ActionName == L"male_dagger_attack_hold_heavy_02" && obj.O_Dis <= 振刀参数::距离::匕首.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_EndureLevel != 20) return;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::匕首.右蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::匕首.右蓄2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(1000);
					}
				}
			}
			//鬼反
			else if (obj.O_ActionName == L"male_dagger_flashstep_attack_light_01" && obj.O_Dis <= 振刀参数::距离::匕首.鬼反 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.399 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::匕首.鬼反) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【鬼反】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【鬼反】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::匕首.鬼反;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//荆轲献匕
			else if (obj.O_ActionName == L"male_dagger_attack_hold_heavy_01" && obj.O_Dis <= 振刀参数::距离::匕首.荆轲献匕 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::匕首.荆轲献匕2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::匕首.荆轲献匕2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【荆轲献匕】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【荆轲献匕】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【荆轲献匕】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【荆轲献匕】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【荆轲献匕】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【荆轲献匕】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//鬼刃暗扎
			else if (obj.O_ActionName == L"male_dagger_attack_hold_heavy_soul_01" && obj.O_Dis <= 振刀参数::距离::匕首.鬼刃暗扎 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::匕首.鬼刃暗扎2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::匕首.鬼刃暗扎2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【鬼刃暗扎】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【鬼刃暗扎】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【鬼刃暗扎】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【鬼刃暗扎】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【鬼刃暗扎】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_W);
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【鬼刃暗扎】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//鬼哭神嚎
			else if (obj.O_ActionName == L"male_dagger_flashjump_attack_soul_01" && obj.O_Dis <= 振刀参数::距离::匕首.鬼哭神嚎 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_EndureLevel != 20) return;
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.378 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【鬼哭神嚎】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::BlueToRed();
					调试::逻辑执行.敌人类型 = "【匕首】";
					调试::逻辑执行.敌人动作 = "【鬼哭神嚎】";
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(400);
				}
			}
			//亢龙有悔
			else if (obj.O_ActionName == L"male_dagger_attack_hold_light_soul_02" && obj.O_Dis <= 振刀参数::距离::匕首.亢龙有悔 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::匕首.亢龙有悔2M;
				}
				else if (obj.O_Dis <= 4.f)
				{
					NewAngle = 振刀参数::角度::匕首.亢龙有悔4M;
				}
				else
				{
					NewAngle = 振刀参数::角度::匕首.亢龙有悔4M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【亢龙有悔】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【亢龙有悔】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【亢龙有悔】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【亢龙有悔】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【亢龙有悔】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【亢龙有悔】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
		}
		else if (Function::Shock::F_MemShock)
		{
			//左3
			if (obj.O_ActionName == L"male_dagger_attack_light_03" && obj.O_Dis <= 振刀参数::距离::匕首.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::匕首.左3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::匕首.左3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_dagger_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::匕首.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::匕首.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::匕首.右3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_dagger_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::匕首.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::匕首.左蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::匕首.左蓄2M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【匕首】";
					调试::逻辑执行.敌人动作 = "【左蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//右蓄
			else if (obj.O_ActionName == L"male_dagger_attack_hold_heavy_02" && obj.O_Dis <= 振刀参数::距离::匕首.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_EndureLevel != 20) return;

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::匕首.右蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::匕首.右蓄2M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【匕首】";
					调试::逻辑执行.敌人动作 = "【右蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//鬼反
			else if (obj.O_ActionName == L"male_dagger_flashstep_attack_light_01" && obj.O_Dis <= 振刀参数::距离::匕首.鬼反 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.36 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::匕首.鬼反) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【鬼反】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【匕首】";
						调试::逻辑执行.敌人动作 = "【鬼反】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::匕首.鬼反;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//荆轲献匕
			else if (obj.O_ActionName == L"male_dagger_attack_hold_heavy_01" && obj.O_Dis <= 振刀参数::距离::匕首.荆轲献匕 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::匕首.荆轲献匕2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::匕首.荆轲献匕2M外;
				}


				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【荆轲献匕】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.敌人类型 = "【匕首】";
					调试::逻辑执行.敌人动作 = "【荆轲献匕】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//鬼刃暗扎
			else if (obj.O_ActionName == L"male_dagger_attack_hold_heavy_soul_01" && obj.O_Dis <= 振刀参数::距离::匕首.鬼刃暗扎 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::匕首.鬼刃暗扎2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::匕首.鬼刃暗扎2M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【鬼刃暗扎】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【匕首】";
					调试::逻辑执行.敌人动作 = "【鬼刃暗扎】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//鬼哭神嚎
			else if (obj.O_ActionName == L"male_dagger_flashjump_attack_soul_01" && obj.O_Dis <= 振刀参数::距离::匕首.鬼哭神嚎 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_EndureLevel != 20) return;
				Shock_BlueToRead_Delay -= 50;
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;

				auto Shock_Timing = (0.36 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【鬼哭神嚎】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【匕首】";
					调试::逻辑执行.敌人动作 = "【鬼哭神嚎】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//亢龙有悔
			else if (obj.O_ActionName == L"male_dagger_attack_hold_light_soul_02" && obj.O_Dis <= 振刀参数::距离::匕首.亢龙有悔 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::匕首.亢龙有悔2M;
				}
				else if (obj.O_Dis <= 4.f)
				{
					NewAngle = 振刀参数::角度::匕首.亢龙有悔4M;
				}
				else
				{
					NewAngle = 振刀参数::角度::匕首.亢龙有悔4M外;
				}


				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【匕首】| " << "【亢龙有悔】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【匕首】";
					调试::逻辑执行.敌人动作 = "【亢龙有悔】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
		}
	}
}

//双节棍振刀分支
auto nunchucksShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 8.f)
	{
		int Shock_BlueToRead_Delay = 0;
		double ObjCurTime = 0;
		float NewAngle = 0.f;

		if (Function::Shock::F_ShockKnife)
		{
			//左右3
			if (obj.O_ActionName == L"male_nunchucks_attack_light_03" && obj.O_Dis <= 振刀参数::距离::双截棍.左右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.413 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.左右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【左右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【左右3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.左右3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_nunchucks_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::双截棍.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::双截棍.左蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::双截棍.左蓄2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪振】" << endl;
						if (振刀参数::特殊处理::双截棍左蓄是否短闪振)
						{
							振刀逻辑::ShortDodge(KEY_S);
							振刀逻辑::BlueToRed();
							调试::逻辑执行.敌人类型 = "【双节棍】";
							调试::逻辑执行.敌人动作 = "【左蓄】";
							调试::逻辑执行.执行动作 = "【短闪振】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
						}
						else
						{
							振刀逻辑::ShortDodge(KEY_S);
							调试::逻辑执行.敌人类型 = "【双节棍】";
							调试::逻辑执行.敌人动作 = "【左蓄】";
							调试::逻辑执行.执行动作 = "【闪避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
						}
						Sleep(1000);
					}
				}
			}
			//右蓄
			else if (obj.O_ActionName == L"male_nunchucks_attack_heavy_enhance_01" && obj.O_Dis <= 振刀参数::距离::双截棍.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::双截棍.右蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::双截棍.右蓄2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//飞踢
			else if (obj.O_ActionName == L"male_nunchucks_attack_light_03_soul_01" && obj.O_Dis <= 振刀参数::距离::双截棍.飞踢 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.飞踢) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【飞踢】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【飞踢】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.飞踢;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}

				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.飞踢) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【飞踢】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【飞踢】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.飞踢;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.飞踢) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【飞踢】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【飞踢】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.飞踢;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//扬鞭劲
			else if (obj.O_ActionName == L"male_nunchucks_attack_hold_light_soul_01" && obj.O_Dis <= 振刀参数::距离::双截棍.扬鞭劲 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Shock::扬鞭劲振刀) return;
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.扬鞭劲) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【扬鞭劲】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【扬鞭劲】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.扬鞭劲;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.扬鞭劲) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【扬鞭劲】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【扬鞭劲】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.扬鞭劲;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.扬鞭劲) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【扬鞭劲】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【扬鞭劲】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.扬鞭劲;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//横栏
			else if (obj.O_ActionName == L"male_nunchucks_attack_swing_light_01" && obj.O_Dis <= 振刀参数::距离::双截棍.横栏 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Shock::横栏振刀) return;
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.横栏) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【横栏】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【横栏】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.横栏;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.横栏) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【横栏】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【横栏】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.横栏;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.横栏) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【横栏】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【短闪振】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【横栏】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.横栏;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//龙虎乱舞预判
			else if (StrStrW(obj.O_ActionName.c_str(), L"01_charge") && obj.O_Dis <= 振刀参数::距离::双截棍.龙虎乱舞 && Function::Shock::预判振刀)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 150;
				auto Shock_Timing = 1.05f + (Shock_BlueToRead_Delay - Global::WorldPtr.ping) / 1000;
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【龙虎乱舞】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::BlueToRed();
					调试::逻辑执行.敌人类型 = "【双节棍】";
					调试::逻辑执行.敌人动作 = "【龙虎乱舞】";
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(400);
				}

			}
		}
		else if (Function::Shock::F_MemShock)
		{
			//左右3
			if (obj.O_ActionName == L"male_nunchucks_attack_light_03" && obj.O_Dis <= 振刀参数::距离::双截棍.左右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.左右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【左右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【双节棍】";
						调试::逻辑执行.敌人动作 = "【左右3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.左右3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_nunchucks_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::双截棍.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::双截棍.左蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::双截棍.左蓄2M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双节棍】";
					调试::逻辑执行.敌人动作 = "【左蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//右蓄
			else if (obj.O_ActionName == L"male_nunchucks_attack_heavy_enhance_01" && obj.O_Dis <= 振刀参数::距离::双截棍.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::双截棍.右蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::双截棍.右蓄2M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双节棍】";
					调试::逻辑执行.敌人动作 = "【右蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//飞踢
			else if (obj.O_ActionName == L"male_nunchucks_attack_light_03_soul_01" && obj.O_Dis <= 振刀参数::距离::双截棍.飞踢 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.飞踢) : FALSE)
				{
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双节棍】";
					调试::逻辑执行.敌人动作 = "【飞踢】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.飞踢;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}

			}
			//扬鞭劲
			else if (obj.O_ActionName == L"male_nunchucks_attack_hold_light_soul_01" && obj.O_Dis <= 振刀参数::距离::双截棍.扬鞭劲 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.扬鞭劲) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【扬鞭劲】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双节棍】";
					调试::逻辑执行.敌人动作 = "【扬鞭劲】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.扬鞭劲;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//横栏
			else if (obj.O_ActionName == L"male_nunchucks_attack_swing_light_01" && obj.O_Dis <= 振刀参数::距离::双截棍.横栏 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双截棍.横栏) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【横栏】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双节棍】";
					调试::逻辑执行.敌人动作 = "【横栏】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::双截棍.横栏;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//龙虎乱舞预判
			else if (StrStrW(obj.O_ActionName.c_str(), L"01_charge") && obj.O_Dis <= 振刀参数::距离::双截棍.龙虎乱舞 && Function::Shock::预判振刀)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 150;
				auto Shock_Timing = 1.05f + (Shock_BlueToRead_Delay - Global::WorldPtr.ping) / 1000;
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【龙虎乱舞】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::BlueToRed();
					调试::逻辑执行.敌人类型 = "【双节棍】";
					调试::逻辑执行.敌人动作 = "【龙虎乱舞】";
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(400);
				}

			}
		}
	}
}

//双刀振刀分支
auto twinbladesShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 10.f)
	{
		int Shock_BlueToRead_Delay = 0;
		double ObjCurTime = 0;
		float NewAngle = 0.f;

		if (Function::Shock::F_ShockKnife)
		{
			//左右3
			if ((obj.O_ActionName == L"male_twinblades_attack_light_03" || obj.O_ActionName == L"male_twinblades_attack_heavy_03") && obj.O_Dis <= 振刀参数::距离::双刀.左右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.42 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.左右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【左右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【左右3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.左右3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_twinblades_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::双刀.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.367 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.左蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.左蓄;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//右蓄
			else if ((obj.O_ActionName == L"male_twinblades_attack_hold_heavy_01" || obj.O_ActionName == L"male_twinblades_attack_hold_heavy_02") && obj.O_Dis <= 振刀参数::距离::双刀.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.右蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.右蓄;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.右蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.右蓄;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.右蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.右蓄;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			////分水斩
			//if (obj.O_ActionName == L"male_twinblades_attack_light_03_soul" && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			//{
			//	if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			//	{
			//		if (Function::Flag::IsBlueToRed)
			//		{
			//			if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
			//			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【分水斩】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
			//			振刀逻辑::BlueToRed();
			//			Sleep(400);
			//		}
			//		else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
			//		{
			//			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【分水斩】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【拼刀】" << endl;
			//			振刀逻辑::CollideKnife();
			//			Sleep(500);
			//		}
			//		else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
			//		{
			//			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【分水斩】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【短闪】" << endl;
			//			振刀逻辑::ShortDodge(KEY_S);
			//			Sleep(400);
			//		}
			//	}
			//}

			//铁马残红
			else if (obj.O_ActionName == L"male_twinblades_attack_hold_light_01_soul" && obj.O_Dis <= 振刀参数::距离::双刀.铁马残红 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				if (obj.O_Dis <= 3.f)
				{
					NewAngle = 振刀参数::角度::双刀.铁马残红3M;
				}
				else
				{
					NewAngle = 振刀参数::角度::双刀.铁马残红3M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【铁马残红】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【铁马残红】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【铁马残红】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【铁马残红】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【铁马残红】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodgeEx();
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【铁马残红】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//乾坤日月斩
			else if (obj.O_ActionName == L"male_twinblades_attack_hold_heavy_01_soul" && obj.O_Dis <= 振刀参数::距离::双刀.乾坤日月斩 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.乾坤日月斩) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【乾坤日月斩】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【乾坤日月斩】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.乾坤日月斩;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.乾坤日月斩) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【乾坤日月斩】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【乾坤日月斩】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.乾坤日月斩;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.乾坤日月斩) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【乾坤日月斩】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【乾坤日月斩】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.乾坤日月斩;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//蓄力后追击
			else if ((obj.O_ActionName == L"male_twinblades_attack_heavy_06" || obj.O_ActionName == L"male_twinblades_attack_heavy_04") && obj.O_Dis <= 振刀参数::距离::双刀.惊雷 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.425 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.惊雷) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【惊雷】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【惊雷】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.惊雷;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//八斩刀
			else if (obj.O_ActionName == L"male_twinblades_attack_light_soul_09" && obj.O_Dis <= 振刀参数::距离::双刀.八斩刀 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_EndureLevel != 20) return;
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.八斩刀) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【八斩刀】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【八斩刀】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.八斩刀;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.八斩刀) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【八斩刀】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【八斩刀】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.八斩刀;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.八斩刀) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【八斩刀】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【八斩刀】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.八斩刀;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
		}
		else if (Function::Shock::F_MemShock)
		{
			//左右3
			if ((obj.O_ActionName == L"male_twinblades_attack_light_03" || obj.O_ActionName == L"male_twinblades_attack_heavy_03") && obj.O_Dis <= 振刀参数::距离::双刀.左右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.左右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【左右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【左右3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.左右3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_twinblades_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::双刀.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.35 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.左蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.左蓄;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//右蓄
			else if ((obj.O_ActionName == L"male_twinblades_attack_hold_heavy_01" || obj.O_ActionName == L"male_twinblades_attack_hold_heavy_02") && obj.O_Dis <= 振刀参数::距离::双刀.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.右蓄) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双刀】";
					调试::逻辑执行.敌人动作 = "【右蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.右蓄;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//分水斩
			if (obj.O_ActionName == L"male_twinblades_attack_light_03_soul" && obj.O_Dis <= 振刀参数::距离::双刀.分水斩 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.分水斩) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双刀】";
					调试::逻辑执行.敌人动作 = "【分水斩】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.分水斩;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//铁马残红
			else if (obj.O_ActionName == L"male_twinblades_attack_hold_light_01_soul" && obj.O_Dis <= 振刀参数::距离::双刀.铁马残红 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				if (obj.O_Dis <= 3.f)
				{
					NewAngle = 振刀参数::角度::双刀.铁马残红3M;
				}
				else
				{
					NewAngle = 振刀参数::角度::双刀.铁马残红3M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【铁马残红】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双刀】";
					调试::逻辑执行.敌人动作 = "【铁马残红】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//乾坤日月斩
			else if (obj.O_ActionName == L"male_twinblades_attack_hold_heavy_01_soul" && obj.O_Dis <= 振刀参数::距离::双刀.乾坤日月斩 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.乾坤日月斩) : FALSE)
				{
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双刀】";
					调试::逻辑执行.敌人动作 = "【乾坤日月斩】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.乾坤日月斩;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//蓄力后追击
			else if ((obj.O_ActionName == L"male_twinblades_attack_heavy_06" || obj.O_ActionName == L"male_twinblades_attack_heavy_04") && obj.O_Dis <= 振刀参数::距离::双刀.惊雷 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.惊雷) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【惊雷】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【双刀】";
						调试::逻辑执行.敌人动作 = "【惊雷】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.惊雷;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//八斩刀
			else if (obj.O_ActionName == L"male_twinblades_attack_light_soul_09" && obj.O_Dis <= 振刀参数::距离::双刀.八斩刀 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双刀.八斩刀) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【八斩刀】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双刀】";
					调试::逻辑执行.敌人动作 = "【八斩刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::双刀.八斩刀;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
		}
	}
}

//长棍振刀分支
auto rodShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 14.f)
	{
		int Shock_BlueToRead_Delay = 0;
		double ObjCurTime = 0;
		float NewAngle = 0.f;

		if (Function::Shock::F_ShockKnife)
		{
			//左3
			if (obj.O_ActionName == L"male_rod_attack_light_03" && obj.O_Dis <= 振刀参数::距离::长棍.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.414 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.左3) : FALSE)
					{
						///cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.左3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_rod_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::长棍.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.647 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.右3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//少林棍
			else if (obj.O_ActionName == L"male_rod_attack_heavy_soul_03" && obj.O_Dis <= 振刀参数::距离::长棍.少林棍 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.484 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.少林棍) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【少林棍】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【少林棍】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.少林棍;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_rod_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::长棍.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长棍.左蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长棍.左蓄2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//右蓄
			else if (obj.O_ActionName == L"male_rod_attack_hold_heavy_01" && obj.O_Dis <= 振刀参数::距离::长棍.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_EndureLevel != 20) return;
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 " << endl;
					振刀逻辑::BlueToRed();
					调试::逻辑执行.敌人类型 = "【长棍】";
					调试::逻辑执行.敌人动作 = "【右蓄】";
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(400);
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【拼刀】" << endl;
					振刀逻辑::CollideKnife();
					调试::逻辑执行.敌人类型 = "【长棍】";
					调试::逻辑执行.敌人动作 = "【右蓄】";
					调试::逻辑执行.执行动作 = "【拼刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(500);
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【短闪】" << endl;
					振刀逻辑::ShortDodgeEx();
					调试::逻辑执行.敌人类型 = "【长棍】";
					调试::逻辑执行.敌人动作 = "【右蓄】";
					调试::逻辑执行.执行动作 = "【闪避】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(800);
				}
			}
			//腾云式
			else if (obj.O_ActionName == L"male_rod_attack_hold_light_03" && obj.O_Dis <= 振刀参数::距离::长棍.腾云式 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长棍.腾云式2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长棍.腾云式2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【腾云式】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【腾云式】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【腾云式】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【腾云式】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【腾云式】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【腾云式】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//乱点天宫
			else if (obj.O_ActionName == L"male_rod_attack_heavy_05_copy" && obj.O_Dis <= 振刀参数::距离::长棍.乱点天宫 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_EndureLevel != 20) return;
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.乱点天宫) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【乱点天宫】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【乱点天宫】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.乱点天宫;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.乱点天宫) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【乱点天宫】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【乱点天宫】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.乱点天宫;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.乱点天宫) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【乱点天宫】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【乱点天宫】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.乱点天宫;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//桶劲
			else if (obj.O_ActionName == L"male_rod_attack_hold_light_soul_01" && obj.O_Dis <= 振刀参数::距离::长棍.桶劲 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.桶劲) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【桶劲】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【桶劲】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.桶劲;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.桶劲) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【桶劲】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【桶劲】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.桶劲;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.桶劲) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【桶劲】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【桶劲】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.桶劲;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//五情七灭镇
			else if (obj.O_ActionName == L"male_rod_attack_heavy_soul_05" && obj.O_Dis <= 振刀参数::距离::长棍.五情七灭镇 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 8.5f)
				{
					NewAngle = 振刀参数::角度::长棍.五情七灭镇8M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长棍.五情七灭镇8M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【五情七灭镇】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【五情七灭镇】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【五情七灭镇】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【五情七灭镇】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【五情七灭镇】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodgeEx();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【五情七灭镇】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//双环扫
			else if (obj.O_ActionName == L"male_rod_attack_light_soul_03" && obj.O_Dis <= 振刀参数::距离::长棍.双环扫 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.31 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【双环扫】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::BlueToRed();
					调试::逻辑执行.敌人类型 = "【长棍】";
					调试::逻辑执行.敌人动作 = "【双环扫】";
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true;
					Sleep(400);
				}
			}
			//倒海棍
			else if (obj.O_ActionName == L"male_rod_attack_light_soul_05" && obj.O_Dis <= 振刀参数::距离::长棍.倒海棍 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.倒海棍) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【倒海棍】 | 【" << obj.O_Dis << "】 | 角度:" << 75.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【倒海棍】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.倒海棍;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.倒海棍) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【倒海棍】 | 【" << obj.O_Dis << "】 | 角度:" << 75.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【倒海棍】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.倒海棍;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.倒海棍) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【倒海棍】 | 【" << obj.O_Dis << "】 | 角度:" << 75.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【倒海棍】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.倒海棍;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//镇地撑天
			else if (obj.O_ActionName == L"male_rod_attack_hold_light_03_soul_01" && obj.O_Dis <= 振刀参数::距离::长棍.镇地撑天 && GetReactionType(obj.Cache_HitSimulate) == 2)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.镇地撑天) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【镇地撑天】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::长棍.镇地撑天 << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【镇地撑天】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.镇地撑天;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.镇地撑天) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【镇地撑天】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::长棍.镇地撑天 << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【镇地撑天】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.镇地撑天;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.镇地撑天) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【镇地撑天】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::长棍.镇地撑天 << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【镇地撑天】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.镇地撑天;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
		}
		else if (Function::Shock::F_MemShock)
		{
			//左3
			if (obj.O_ActionName == L"male_rod_attack_light_03" && obj.O_Dis <= 振刀参数::距离::长棍.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.左3) : FALSE)
					{
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.左3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_rod_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::长棍.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.63 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.右3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//少林棍
			else if (obj.O_ActionName == L"male_rod_attack_heavy_soul_03" && obj.O_Dis <= 振刀参数::距离::长棍.少林棍 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.47 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.少林棍) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【少林棍】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【长棍】";
						调试::逻辑执行.敌人动作 = "【少林棍】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.少林棍;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_rod_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::长棍.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长棍.左蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长棍.左蓄2M外;
				}


				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【长棍】";
					调试::逻辑执行.敌人动作 = "【左蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//右蓄
			else if (obj.O_ActionName == L"male_rod_attack_hold_heavy_01" && obj.O_Dis <= 振刀参数::距离::长棍.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_EndureLevel != 20) return;

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 " << endl;
				振刀逻辑::MemShock();
				调试::逻辑执行.执行动作 = "【内存振】";
				调试::逻辑执行.敌人类型 = "【长棍】";
				调试::逻辑执行.敌人动作 = "【右蓄】";
				调试::逻辑执行.执行距离 = obj.O_Dis;
				调试::逻辑执行.执行角度 = 360.f;
				调试::输出逻辑执行Flag = true; Sleep(500);
				//是否内存振 = false;
			}
			//腾云式
			else if (obj.O_ActionName == L"male_rod_attack_hold_light_03" && obj.O_Dis <= 振刀参数::距离::长棍.腾云式 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::长棍.腾云式2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长棍.腾云式2M外;
				}


				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【腾云式】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【长棍】";
					调试::逻辑执行.敌人动作 = "【腾云式】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//乱点天宫
			else if (obj.O_ActionName == L"male_rod_attack_heavy_05_copy" && obj.O_Dis <= 振刀参数::距离::长棍.乱点天宫 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_EndureLevel != 20) return;

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.乱点天宫) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【乱点天宫】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【长棍】";
					调试::逻辑执行.敌人动作 = "【乱点天宫】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.乱点天宫;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//桶劲
			else if (obj.O_ActionName == L"male_rod_attack_hold_light_soul_01" && obj.O_Dis <= 振刀参数::距离::长棍.桶劲 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.桶劲) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【桶劲】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【长棍】";
					调试::逻辑执行.敌人动作 = "【桶劲】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.桶劲;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//五情七灭镇
			else if (obj.O_ActionName == L"male_rod_attack_heavy_soul_05" && obj.O_Dis <= 振刀参数::距离::长棍.五情七灭镇 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 8.5f)
				{
					NewAngle = 振刀参数::角度::长棍.五情七灭镇8M;
				}
				else
				{
					NewAngle = 振刀参数::角度::长棍.五情七灭镇8M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【五情七灭镇】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【长棍】";
					调试::逻辑执行.敌人动作 = "【五情七灭镇】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//双环扫
			else if (obj.O_ActionName == L"male_rod_attack_light_soul_03" && obj.O_Dis <= 振刀参数::距离::长棍.双环扫 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.3 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【双环扫】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【长棍】";
					调试::逻辑执行.敌人动作 = "【双环扫】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 360.f;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//倒海棍
			else if (obj.O_ActionName == L"male_rod_attack_light_soul_05" && obj.O_Dis <= 振刀参数::距离::长棍.倒海棍 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.倒海棍) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【倒海棍】 | 【" << obj.O_Dis << "】 | 角度:" << 75.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【长棍】";
					调试::逻辑执行.敌人动作 = "【倒海棍】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.倒海棍;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//镇地撑天
			else if (obj.O_ActionName == L"male_rod_attack_hold_light_03_soul_01" && obj.O_Dis <= 振刀参数::距离::长棍.镇地撑天 && GetReactionType(obj.Cache_HitSimulate) == 2)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::长棍.镇地撑天) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【长棍】| " << "【镇地撑天】 | 【" << obj.O_Dis << "】 | 角度:" << 振刀参数::角度::长棍.镇地撑天 << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【长棍】";
					调试::逻辑执行.敌人动作 = "【镇地撑天】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::长棍.镇地撑天;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
		}
	}
}

//斩马刀振刀分支
auto SaberShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 9.f)
	{
		int Shock_BlueToRead_Delay = 0;
		double ObjCurTime = 0;
		float NewAngle = 0.f;

		if (Function::Shock::F_ShockKnife)
		{
			//左左and右左左
			if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_light_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_light_05")) && obj.O_Dis <= 振刀参数::距离::斩马刀.左左 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.539 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.左左) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【左左】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【左左】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.左左;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左右
			else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_03") && obj.O_Dis <= 振刀参数::距离::斩马刀.左右 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::斩马刀.左右2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::斩马刀.左右2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【左右】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【左右】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【左右】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【左右】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【左右】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//右右and左右右
			else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_04")) && obj.O_Dis <= 振刀参数::距离::斩马刀.右右 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.516 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.右右) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【右右】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【右右】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.右右;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//右左and左右左
			else if (StrStrW(obj.O_ActionName.c_str(), L"male_saber_attack_light_06") && obj.O_Dis <= 振刀参数::距离::斩马刀.右左 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.609 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.右左) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【右左】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【右左】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.右左;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左蓄
			else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_01") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_03")) && obj.O_Dis <= 振刀参数::距离::斩马刀.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::斩马刀.左蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::斩马刀.左蓄2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【长闪振】" << endl;
						if (振刀参数::特殊处理::斩马刀左蓄是否长闪振)
						{
							振刀逻辑::LongDodge(KEY_S);
							振刀逻辑::BlueToRed();
							调试::逻辑执行.敌人类型 = "【斩马刀】";
							调试::逻辑执行.敌人动作 = "【左蓄】";
							调试::逻辑执行.执行动作 = "【长闪振】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
						}
						else
						{
							振刀逻辑::ShortDodge(KEY_S);
							调试::逻辑执行.敌人类型 = "【斩马刀】";
							调试::逻辑执行.敌人动作 = "【左蓄】";
							调试::逻辑执行.执行动作 = "【闪避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
						}
						Sleep(800);
					}
				}
			}
			//右蓄
			else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_01") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_03")) && obj.O_Dis <= 振刀参数::距离::斩马刀.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.417 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.右蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.右蓄;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//柄击
			else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_light_03") && obj.O_Dis <= 振刀参数::距离::斩马刀.柄击 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.柄击) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【柄击】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【柄击】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.柄击;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.柄击) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【柄击】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【柄击】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.柄击;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.柄击) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【柄击】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【柄击】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.柄击;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//惊雷
			else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_09") && obj.O_Dis <= 振刀参数::距离::斩马刀.惊雷 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.527 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.惊雷) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【左左】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【惊雷】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.惊雷;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//炽焰斩
			else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_soul_01") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_soul_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_soul_03")) && obj.O_Dis <= 振刀参数::距离::斩马刀.炽焰斩 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.炽焰斩) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【炽焰斩】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【炽焰斩】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.炽焰斩;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.炽焰斩) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【炽焰斩】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【炽焰斩】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.炽焰斩;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.炽焰斩) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【炽焰斩】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【炽焰斩】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.炽焰斩;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//过关斩将
			else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_soul_03") && obj.O_Dis <= 振刀参数::距离::斩马刀.过关斩将 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.463 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.过关斩将) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【过关斩将】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【过关斩将】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.过关斩将;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
		}
		else if (Function::Shock::F_MemShock)
		{
			//左左and右左左
			if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_light_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_light_05")) && obj.O_Dis <= 振刀参数::距离::斩马刀.左左 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.53 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.左左) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【左左】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【左左】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.左左;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左右
			else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_03") && obj.O_Dis <= 振刀参数::距离::斩马刀.左右 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::斩马刀.左右2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::斩马刀.左右2M外;
				}


				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【左右】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【斩马刀】";
					调试::逻辑执行.敌人动作 = "【左右】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//右右and左右右
			else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_04")) && obj.O_Dis <= 振刀参数::距离::斩马刀.右右 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.49 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.右右) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【右右】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【右右】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.右右;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//右左and左右左
			else if (StrStrW(obj.O_ActionName.c_str(), L"male_saber_attack_light_06") && obj.O_Dis <= 振刀参数::距离::斩马刀.右左 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.609 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.右左) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【右左】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【右左】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.右左;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左蓄
			else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_01") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_03")) && obj.O_Dis <= 振刀参数::距离::斩马刀.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::斩马刀.左蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::斩马刀.左蓄2M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【斩马刀】";
					调试::逻辑执行.敌人动作 = "【左蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//右蓄
			else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_01") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_03")) && obj.O_Dis <= 振刀参数::距离::斩马刀.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.右蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.右蓄;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//柄击
			else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_light_03") && obj.O_Dis <= 振刀参数::距离::斩马刀.柄击 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.柄击) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【柄击】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【斩马刀】";
					调试::逻辑执行.敌人动作 = "【柄击】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.柄击;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//惊雷
			else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_09") && obj.O_Dis <= 振刀参数::距离::斩马刀.惊雷 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.51 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.惊雷) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【左左】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【惊雷】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.惊雷;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//炽焰斩
			else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_soul_01") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_soul_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_soul_03")) && obj.O_Dis <= 振刀参数::距离::斩马刀.炽焰斩 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.炽焰斩) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【斩马刀】| " << "【炽焰斩】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【斩马刀】";
					调试::逻辑执行.敌人动作 = "【炽焰斩】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.炽焰斩;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//过关斩将
			else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_soul_03") && obj.O_Dis <= 振刀参数::距离::斩马刀.过关斩将 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.463 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::斩马刀.过关斩将) : FALSE)
					{
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【斩马刀】";
						调试::逻辑执行.敌人动作 = "【过关斩将】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::斩马刀.过关斩将;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
		}
	}
}

//双戟振刀分支
auto dualhalberdKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 8.f)
	{
		int Shock_BlueToRead_Delay = 0;
		double ObjCurTime = 0;
		float NewAngle = 0.f;

		if (Function::Shock::F_ShockKnife)
		{
			//左右3
			if ((obj.O_ActionName == L"male_dualhalberd_attack_light_03" || obj.O_ActionName == L"male_dualhalberd_attack_heavy_03") && obj.O_Dis <= 振刀参数::距离::双戟.左右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.42 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.左右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【左右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【左右3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.左右3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_dualhalberd_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::双戟.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 3.f)
				{
					NewAngle = 振刀参数::角度::双戟.左蓄3M;
				}
				else
				{
					NewAngle = 振刀参数::角度::双戟.左蓄3M外;
				}
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.3 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【左右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				//if (obj.O_Dis <= 3.f)
				//{
				//	NewAngle = 振刀参数::角度::双戟.左蓄3M;
				//}
				//else
				//{
				//	NewAngle = 振刀参数::角度::双戟.左蓄3M外;
				//}
				//
				//if (Function::Flag::IsBlueToRed)
				//{
				//	if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				//	if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				//	{
				//		//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				//		振刀逻辑::BlueToRed();
				//		调试::逻辑执行.敌人类型 = "【双戟】";
				//		调试::逻辑执行.敌人动作 = "【左蓄】";
				//		调试::逻辑执行.执行动作 = "【振刀】";
				//		调试::逻辑执行.执行距离 = obj.O_Dis;
				//		调试::逻辑执行.执行角度 = NewAngle;
				//		调试::输出逻辑执行Flag = true;
				//		Sleep(400);
				//	}
				//}
				//else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				//{
				//	if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				//	{
				//		//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
				//		振刀逻辑::CollideKnife();
				//		调试::逻辑执行.敌人类型 = "【双戟】";
				//		调试::逻辑执行.敌人动作 = "【左蓄】";
				//		调试::逻辑执行.执行动作 = "【拼刀】";
				//		调试::逻辑执行.执行距离 = obj.O_Dis;
				//		调试::逻辑执行.执行角度 = NewAngle;
				//		调试::输出逻辑执行Flag = true;
				//		Sleep(500);
				//	}
				//}
				//else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				//{
				//	if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				//	{
				//		//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
				//		振刀逻辑::ShortDodge(KEY_S);
				//		调试::逻辑执行.敌人类型 = "【双戟】";
				//		调试::逻辑执行.敌人动作 = "【左蓄】";
				//		调试::逻辑执行.执行动作 = "【闪避】";
				//		调试::逻辑执行.执行距离 = obj.O_Dis;
				//		调试::逻辑执行.执行角度 = NewAngle;
				//		调试::输出逻辑执行Flag = true;
				//		Sleep(800);
				//	}
				//}
			}
			//右蓄
			else if ((obj.O_ActionName == L"male_dualhalberd_attack_hold_heavy_01" || obj.O_ActionName == L"male_dualhalberd_attack_hold_heavy_02") && obj.O_Dis <= 振刀参数::距离::双戟.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 3.f)
				{
					NewAngle = 振刀参数::角度::双戟.右蓄3M;
				}
				else
				{
					NewAngle = 振刀参数::角度::双戟.右蓄3M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_W);
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//勾旋斩
			else if (obj.O_ActionName == L"male_dualhalberd_attack_light_08" && obj.O_Dis <= 振刀参数::距离::双戟.勾旋斩 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.61 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.勾旋斩) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【勾旋斩】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【勾旋斩】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.勾旋斩;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//探海蛟
			else if (obj.O_ActionName == L"male_dualhalberd_attack_heavy_09" && obj.O_Dis <= 振刀参数::距离::双戟.探海蛟 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.探海蛟) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【探海蛟】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【探海蛟】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.探海蛟;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.探海蛟) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【探海蛟】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【探海蛟】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.探海蛟;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.探海蛟) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【探海蛟】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【探海蛟】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.探海蛟;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//钩挂
			else if (obj.O_ActionName == L"male_dualhalberd_attack_light_09" && obj.O_Dis <= 振刀参数::距离::双戟.钩挂 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.钩挂) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【钩挂】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【钩挂】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.钩挂;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.钩挂) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【钩挂】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【钩挂】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.钩挂;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.钩挂) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【钩挂】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【钩挂】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.钩挂;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//战龙在天
			else if ((obj.O_ActionName == L"male_dualhalberd_attack_hold_light_01_soul" || obj.O_ActionName == L"male_dualhalberd_attack_hold_light_01_soul_copy"
				|| obj.O_ActionName == L"male_dualhalberd_attack_hold_light_02_soul_copy") && obj.O_Dis <= 振刀参数::距离::双戟.战龙在天 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.战龙在天) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【战龙在天】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【战龙在天】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.战龙在天;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.战龙在天) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【战龙在天】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【战龙在天】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.战龙在天;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.战龙在天) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【战龙在天】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodgeEx();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【战龙在天】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.战龙在天;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//形意钩 male_dualhalberd_attack_hold_light_soul_02
			else if (obj.O_ActionName == L"male_dualhalberd_attack_hold_light_soul_02" && obj.O_Dis <= 振刀参数::距离::双戟.形意钩 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.形意钩) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【探海蛟】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【形意钩】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.形意钩;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.形意钩) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【探海蛟】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【形意钩】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.形意钩;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.形意钩) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【探海蛟】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【形意钩】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.形意钩;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
		}
		else if (Function::Shock::F_MemShock)
		{
			//左右3
			if ((obj.O_ActionName == L"male_dualhalberd_attack_light_03" || obj.O_ActionName == L"male_dualhalberd_attack_heavy_03") && obj.O_Dis <= 振刀参数::距离::双戟.左右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.左右3) : FALSE)
					{
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【左右3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.左右3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_dualhalberd_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::双戟.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 3.f)
				{
					NewAngle = 振刀参数::角度::双戟.左蓄3M;
				}
				else
				{
					NewAngle = 振刀参数::角度::双戟.左蓄3M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双戟】";
					调试::逻辑执行.敌人动作 = "【左蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//右蓄
			else if ((obj.O_ActionName == L"male_dualhalberd_attack_hold_heavy_01" || obj.O_ActionName == L"male_dualhalberd_attack_hold_heavy_02") && obj.O_Dis <= 振刀参数::距离::双戟.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 3.f)
				{
					NewAngle = 振刀参数::角度::双戟.右蓄3M;
				}
				else
				{
					NewAngle = 振刀参数::角度::双戟.右蓄3M外;
				}

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双戟】";
					调试::逻辑执行.敌人动作 = "【右蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
				}
			}
			//勾旋斩
			else if (obj.O_ActionName == L"male_dualhalberd_attack_light_08" && obj.O_Dis <= 振刀参数::距离::双戟.勾旋斩 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.6 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.勾旋斩) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【勾旋斩】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【双戟】";
						调试::逻辑执行.敌人动作 = "【勾旋斩】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.勾旋斩;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//探海蛟
			else if (obj.O_ActionName == L"male_dualhalberd_attack_heavy_09" && obj.O_Dis <= 振刀参数::距离::双戟.探海蛟 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.探海蛟) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【探海蛟】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双戟】";
					调试::逻辑执行.敌人动作 = "【探海蛟】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.探海蛟;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//钩挂
			else if (obj.O_ActionName == L"male_dualhalberd_attack_light_09" && obj.O_Dis <= 振刀参数::距离::双戟.钩挂 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.钩挂) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【钩挂】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双戟】";
					调试::逻辑执行.敌人动作 = "【钩挂】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.钩挂;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//战龙在天
			else if ((obj.O_ActionName == L"male_dualhalberd_attack_hold_light_01_soul" || obj.O_ActionName == L"male_dualhalberd_attack_hold_light_01_soul_copy"
				|| obj.O_ActionName == L"male_dualhalberd_attack_hold_light_02_soul_copy") && obj.O_Dis <= 振刀参数::距离::双戟.战龙在天 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.战龙在天) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【战龙在天】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【振刀】";
					调试::逻辑执行.敌人类型 = "【双戟】";
					调试::逻辑执行.敌人动作 = "【战龙在天】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.战龙在天;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//形意钩 male_dualhalberd_attack_hold_light_soul_02
			else if (obj.O_ActionName == L"male_dualhalberd_attack_hold_light_soul_02" && obj.O_Dis <= 振刀参数::距离::双戟.形意钩 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::双戟.形意钩) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双戟】| " << "【探海蛟】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【双戟】";
					调试::逻辑执行.敌人动作 = "【形意钩】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::双戟.形意钩;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
		}
	}
}

//扇子振刀分支
auto fanShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 12.5f)
	{
		int Shock_BlueToRead_Delay = 0;
		double ObjCurTime = 0;
		float NewAngle = 0.f;

		if (Function::Shock::F_ShockKnife)
		{
			//左3
			if (obj.O_ActionName == L"male_fan_attack_light_03" && obj.O_Dis <= 振刀参数::距离::扇子.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.415 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::扇子.左3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::扇子.左3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_fan_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::扇子.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.414 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::扇子.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::扇子.右3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_fan_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::扇子.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				NewAngle = 振刀参数::角度::扇子.左蓄;

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						if (振刀参数::特殊处理::扇子左蓄是否中闪振)
						{
							振刀逻辑::ZhongDodge();
							振刀逻辑::BlueToRed();
							调试::逻辑执行.敌人类型 = "【扇子】";
							调试::逻辑执行.敌人动作 = "【左蓄】";
							调试::逻辑执行.执行动作 = "【中闪振】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
						}
						else
						{
							振刀逻辑::ShortDodgeEx();
							调试::逻辑执行.敌人类型 = "【扇子】";
							调试::逻辑执行.敌人动作 = "【左蓄】";
							调试::逻辑执行.执行动作 = "【闪避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
						}
						Sleep(800);
					}
				}
			}
			//右蓄
			else if (obj.O_ActionName == L"male_fan_attack_hold_heavy_01" && obj.O_Dis <= 振刀参数::距离::扇子.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::扇子.右蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::扇子.右蓄2M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						if (振刀参数::特殊处理::扇子右蓄是否中闪振)
						{
							振刀逻辑::ZhongDodge();
							振刀逻辑::BlueToRed();
							调试::逻辑执行.敌人类型 = "【扇子】";
							调试::逻辑执行.敌人动作 = "【右蓄】";
							调试::逻辑执行.执行动作 = "【中闪振】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
						}
						else
						{
							振刀逻辑::ShortDodgeEx();
							调试::逻辑执行.敌人类型 = "【扇子】";
							调试::逻辑执行.敌人动作 = "【右蓄】";
							调试::逻辑执行.执行动作 = "【闪避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = NewAngle;
							调试::输出逻辑执行Flag = true;
						}
						Sleep(800);
					}
				}
			}
			//双开圆
			else if (obj.O_ActionName == L"male_fan_attack_light_soul_03" && obj.O_Dis <= 振刀参数::距离::扇子.双开圆 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.415 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::扇子.双开圆) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【双开圆】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【双开圆】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::扇子.双开圆;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//三风摆
			else if (obj.O_ActionName == L"male_fan_attack_hold_light_soul_01" && obj.O_Dis <= 振刀参数::距离::扇子.三风摆 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 3.f)
				{
					NewAngle = 振刀参数::角度::扇子.三风摆3M;
				}
				else
				{
					NewAngle = 振刀参数::角度::扇子.三风摆3M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【三风摆】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【三风摆】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【三风摆】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【三风摆】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【三风摆】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【三风摆】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//鬼反
			if (obj.O_ActionName == L"male_fan_flashstep_attack_light_02_pre" && obj.O_Dis <= 振刀参数::距离::扇子.鬼反 /*&& GetRangeReactionType(obj.Cache_HitSimulate) == 12*/)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::扇子.鬼反) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【鬼反】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::扇子.鬼反;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::扇子.鬼反) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【鬼反】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::扇子.鬼反;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::扇子.鬼反) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双节棍】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【鬼反】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::扇子.鬼反;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//惊雷
			else if (obj.O_ActionName == L"male_fan_attack_light_04" && obj.O_Dis <= 振刀参数::距离::扇子.惊雷 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.377 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::扇子.惊雷) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【惊雷】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【惊雷】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::扇子.惊雷;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//缠龙奔野
			else if (obj.O_ActionName == L"male_fan_attack_hold_heavy_soul_01" && obj.O_Dis <= 振刀参数::距离::扇子.缠龙奔野 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 3.f)
				{
					NewAngle = 振刀参数::角度::扇子.缠龙奔野3M;
				}
				else
				{
					NewAngle = 振刀参数::角度::扇子.缠龙奔野3M外;
				}

				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【缠龙奔野】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【缠龙奔野】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【缠龙奔野】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【缠龙奔野】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
		}
		else if (Function::Shock::F_MemShock)
		{
			//左3
			if (obj.O_ActionName == L"male_fan_attack_light_03" && obj.O_Dis <= 振刀参数::距离::扇子.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::扇子.左3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::扇子.左3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_fan_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::扇子.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::扇子.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::扇子.右3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左蓄
			else if (obj.O_ActionName == L"male_fan_attack_hold_light_01" && obj.O_Dis <= 振刀参数::距离::扇子.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				NewAngle = 振刀参数::角度::扇子.左蓄;


				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【扇子】";
					调试::逻辑执行.敌人动作 = "【左蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//右蓄
			else if (obj.O_ActionName == L"male_fan_attack_hold_heavy_01" && obj.O_Dis <= 振刀参数::距离::扇子.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 2.f)
				{
					NewAngle = 振刀参数::角度::扇子.右蓄2M;
				}
				else
				{
					NewAngle = 振刀参数::角度::扇子.右蓄2M外;
				}


				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【扇子】";
					调试::逻辑执行.敌人动作 = "【右蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//双开圆
			else if (obj.O_ActionName == L"male_fan_attack_light_soul_03" && obj.O_Dis <= 振刀参数::距离::扇子.双开圆 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.28 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::扇子.双开圆) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【双开圆】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【双开圆】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::扇子.双开圆;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//三风摆
			else if (obj.O_ActionName == L"male_fan_attack_hold_light_soul_01" && obj.O_Dis <= 振刀参数::距离::扇子.三风摆 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (obj.O_Dis <= 3.f)
				{
					NewAngle = 振刀参数::角度::扇子.三风摆3M;
				}
				else
				{
					NewAngle = 振刀参数::角度::扇子.三风摆3M外;
				}


				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【三风摆】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【扇子】";
					调试::逻辑执行.敌人动作 = "【三风摆】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = NewAngle;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//鬼反
			else if (obj.O_ActionName == L"male_fan_flashstep_attack_light_02_pre" && obj.O_Dis <= 振刀参数::距离::扇子.鬼反 /*&& GetRangeReactionType(obj.Cache_HitSimulate) == 12*/)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::扇子.鬼反) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【三风摆】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【扇子】";
					调试::逻辑执行.敌人动作 = "【鬼反】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::扇子.鬼反;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//惊雷
			else if (obj.O_ActionName == L"male_fan_attack_light_04" && obj.O_Dis <= 振刀参数::距离::扇子.惊雷 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.36 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::扇子.惊雷) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【惊雷】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【惊雷】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::扇子.惊雷;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//缠龙奔野
			else if (obj.O_ActionName == L"male_fan_attack_hold_heavy_soul_01" && obj.O_Dis <= 振刀参数::距离::扇子.缠龙奔野 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				float Shock_Dis_Delay = 0;
				if (obj.O_Dis <= 3.f)
				{
					NewAngle = 振刀参数::角度::扇子.缠龙奔野3M;
				}
				else
				{
					NewAngle = 振刀参数::角度::扇子.缠龙奔野3M外;
					Shock_Dis_Delay += (obj.O_Dis * 2) / 200;
				}
				auto Shock_Timing = (0.17 + Shock_Dis_Delay - (Shock_BlueToRead_Delay + Global::WorldPtr.ping / 2 + 235 + Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【缠龙奔野】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【扇子】";
						调试::逻辑执行.敌人动作 = "【缠龙奔野】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = NewAngle;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
		}
	}
}

//横刀振刀分支
auto hengdaoShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 7.f)
	{
		int Shock_BlueToRead_Delay = 0;
		double ObjCurTime = 0;
		float NewAngle = 0.f;

		if (Function::Shock::F_ShockKnife)
		{		//左3
			if (obj.O_ActionName == L"male_hengdao_attack_light_03" && obj.O_Dis <= 振刀参数::距离::横刀.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.433 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.左3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【横刀】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.左3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_hengdao_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::横刀.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.415 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【横刀】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.右3;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//左蓄
			else if ((obj.O_ActionName == L"male_hengdao_attack_hold_light_01" || obj.O_ActionName == L"male_hengdao_attack_light_05") && obj.O_Dis <= 振刀参数::距离::横刀.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Shock::横刀左蓄振刀) return;
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.48 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.左蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						if (振刀参数::特殊处理::横刀左蓄是否只短闪)
						{
							振刀逻辑::ShortDodge(KEY_W);
							调试::逻辑执行.敌人类型 = "【横刀】";
							调试::逻辑执行.敌人动作 = "【左蓄】";
							调试::逻辑执行.执行动作 = "【闪避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.左蓄;
							调试::输出逻辑执行Flag = true;

						}
						else
						{
							振刀逻辑::BlueToRed();
							调试::逻辑执行.敌人类型 = "【横刀】";
							调试::逻辑执行.敌人动作 = "【左蓄】";
							调试::逻辑执行.执行动作 = "【振刀】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.左蓄;
							调试::输出逻辑执行Flag = true;
						}
						Sleep(800);
					}
				}
			}
			//右蓄
			else if ((obj.O_ActionName == L"male_hengdao_attack_hold_heavy_01" || obj.O_ActionName == L"male_hengdao_attack_hold_heavy_02") && obj.O_Dis <= 振刀参数::距离::横刀.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.右蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【横刀】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.右蓄;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.右蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【横刀】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.右蓄;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.右蓄) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【横刀】";
						调试::逻辑执行.敌人动作 = "【右蓄】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.右蓄;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
			//破千军
			else if ((obj.O_ActionName == L"male_hengdao_attack_hold_light_soul_01" || obj.O_ActionName == L"male_hengdao_attack_light_soul_05") && obj.O_Dis <= 振刀参数::距离::横刀.破千军 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Shock::横刀左蓄振刀) return;
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (!Function::Flag::IsBlueToRed) Shock_BlueToRead_Delay = 100;
				if (!obj.ISRobot) Shock_BlueToRead_Delay += 100;
				auto Shock_Timing = (0.352 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 250 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.破千军) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【破千军】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【横刀】";
						调试::逻辑执行.敌人动作 = "【破千军】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.破千军;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
			}
			//极光破云闪
			else if (obj.O_ActionName == L"male_hengdao_attack_hold_heavy_soul_02" && obj.O_Dis <= 振刀参数::距离::横刀.极光破云闪 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (ObjCurTime > 0.6f) return;
				if (Function::Flag::IsBlueToRed)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.极光破云闪) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 180.f << " | 【振刀】 " << endl;
						振刀逻辑::BlueToRed();
						调试::逻辑执行.敌人类型 = "【横刀】";
						调试::逻辑执行.敌人动作 = "【极光破云闪】";
						调试::逻辑执行.执行动作 = "【振刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.极光破云闪;
						调试::输出逻辑执行Flag = true;
						Sleep(400);
					}
				}
				else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.极光破云闪) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 180.f << " | 【拼刀】" << endl;
						振刀逻辑::CollideKnife();
						调试::逻辑执行.敌人类型 = "【横刀】";
						调试::逻辑执行.敌人动作 = "【极光破云闪】";
						调试::逻辑执行.执行动作 = "【拼刀】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.极光破云闪;
						调试::输出逻辑执行Flag = true;
						Sleep(500);
					}
				}
				else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.极光破云闪) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 180.f << " | 【短闪】" << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【横刀】";
						调试::逻辑执行.敌人动作 = "【极光破云闪】";
						调试::逻辑执行.执行动作 = "【闪避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.极光破云闪;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}

		}
		else if (Function::Shock::F_MemShock)
		{
			//左3
			if (obj.O_ActionName == L"male_hengdao_attack_light_03" && obj.O_Dis <= 振刀参数::距离::横刀.左3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.42 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.左3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【横刀】";
						调试::逻辑执行.敌人动作 = "【左3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.左3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//右3
			else if (obj.O_ActionName == L"male_hengdao_attack_heavy_03" && obj.O_Dis <= 振刀参数::距离::横刀.右3 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.4 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.右3) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【横刀】";
						调试::逻辑执行.敌人动作 = "【右3】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.右3;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//左蓄
			else if ((obj.O_ActionName == L"male_hengdao_attack_hold_light_01" || obj.O_ActionName == L"male_hengdao_attack_light_05") && obj.O_Dis <= 振刀参数::距离::横刀.左蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Shock::横刀左蓄振刀) return;
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));

				auto Shock_Timing = 0.47 - (200.f - Function::Shock::Shock_Delay) / 1000;
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.左蓄) : FALSE)
					{

						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【横刀】";
						调试::逻辑执行.敌人动作 = "【左蓄】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.左蓄;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;

					}
				}
			}
			//右蓄
			else if ((obj.O_ActionName == L"male_hengdao_attack_hold_heavy_01" || obj.O_ActionName == L"male_hengdao_attack_hold_heavy_02") && obj.O_Dis <= 振刀参数::距离::横刀.右蓄 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.右蓄) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【横刀】";
					调试::逻辑执行.敌人动作 = "【右蓄】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.右蓄;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
			//破千军
			else if ((obj.O_ActionName == L"male_hengdao_attack_hold_light_soul_01" || obj.O_ActionName == L"male_hengdao_attack_light_soul_05") && obj.O_Dis <= 振刀参数::距离::横刀.破千军 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				if (!Function::Shock::横刀左蓄振刀) return;
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				Shock_BlueToRead_Delay -= 50;

				auto Shock_Timing = (0.33 - (Shock_BlueToRead_Delay + Global::WorldPtr.ping + 300 - Function::Shock::Shock_Delay) / 1000);
				if (ObjCurTime > Shock_Timing)
				{
					if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.破千军) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【破千军】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 | 时机:" << Shock_Timing << endl;
						振刀逻辑::MemShock();
						调试::逻辑执行.执行动作 = "【内存振】";
						调试::逻辑执行.敌人类型 = "【横刀】";
						调试::逻辑执行.敌人动作 = "【破千军】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.破千军;
						调试::输出逻辑执行Flag = true; Sleep(500);
						//是否内存振 = false;
					}
				}
			}
			//极光破云闪
			else if (obj.O_ActionName == L"male_hengdao_attack_hold_heavy_soul_02" && obj.O_Dis <= 振刀参数::距离::横刀.极光破云闪 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
			{
				ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
				if (ObjCurTime > 0.6f) return;

				if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
				if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 振刀参数::角度::横刀.极光破云闪) : FALSE)
				{
					//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【横刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 180.f << " | 【振刀】 " << endl;
					振刀逻辑::MemShock();
					调试::逻辑执行.执行动作 = "【内存振】";
					调试::逻辑执行.敌人类型 = "【横刀】";
					调试::逻辑执行.敌人动作 = "【极光破云闪】";
					调试::逻辑执行.执行距离 = obj.O_Dis;
					调试::逻辑执行.执行角度 = 振刀参数::角度::横刀.极光破云闪;
					调试::输出逻辑执行Flag = true; Sleep(500);
					//是否内存振 = false;
				}
			}
		}
	}
}


auto DebugSwShockKnife(PlayerData obj)
{
	if (obj.O_ActionName == L"male_sw_attack_light_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长剑】" << "【左3】"  << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//右3
	else if (obj.O_ActionName == L"male_sw_attack_heavy_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长剑】" << "【右3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//左剑气
	else if ((obj.O_ActionName == L"male_sw_attack_hold_light_01" || obj.O_ActionName == L"male_sw_attack_hold_light_02") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长剑】" << "【左剑气】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//右剑气
	else if ((obj.O_ActionName == L"male_sw_attack_hold_heavy_01" || obj.O_ActionName == L"male_sw_attack_hold_heavy_02") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长剑】" << "【右剑气】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//凤凰羽
	else if ((StrStrW(obj.O_ActionName.c_str(), L"soul_01") || StrStrW(obj.O_ActionName.c_str(), L"soul_02")) && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长剑】" << "【凤凰羽】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//蓝月
	else if (StrStrW(obj.O_ActionName.c_str(), L"copy_03") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长剑】" << "【蓝月】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//七星夺窍
	else if (obj.O_ActionName == L"male_sw_attack_light_soul_04" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长剑】" << "【七星夺窍】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
}
auto  DebugKatanaShockKnife(PlayerData obj)
{
	//左3
	if (obj.O_ActionName == L"male_katana_attack_light_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【太刀】" << "【左3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//右3
	else if (obj.O_ActionName == L"male_katana_attack_heavy_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【太刀】" << "【右3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//左蓄
	else if ((obj.O_ActionName == L"male_katana_attack_hold_light_01" || obj.O_ActionName == L"male_katana_attack_hold_light_02") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【太刀】" << "【左蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//右蓄
	else if ((obj.O_ActionName == L"male_katana_attack_hold_heavy_01" || obj.O_ActionName == L"male_katana_attack_hold_heavy_02") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【太刀】" << "【右蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//左惊雷
	else if (obj.O_ActionName == L"male_katana_attack_light_05" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【太刀】" << "【左惊雷】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//右惊雷
	else if (obj.O_ActionName == L"male_katana_attack_heavy_09_pre")
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【太刀】" << "【右惊雷】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//青鬼左
	else if (obj.O_ActionName == L"male_katana_attack_light_soul_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【太刀】" << "【青鬼左】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//青鬼右
	else if (obj.O_ActionName == L"male_katana_attack_heavy_soul_03" && obj.O_Dis <= 振刀参数::距离::太刀.右青鬼 && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【太刀】" << "【青鬼右】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//噬魂斩预判
	else if (StrStrW(obj.O_ActionName.c_str(), L"charge_soul_01") && obj.O_Dis <= 振刀参数::距离::太刀.噬魂斩 && Function::Shock::预判振刀)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【太刀】" << "【噬魂斩】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
}
auto DebugBladeShockKnife(PlayerData obj)
{
		//左左and右左左
		if ((StrStrW(obj.O_ActionName.c_str(), L"attack_light_02") || StrStrW(obj.O_ActionName.c_str(), L"attack_light_05")) && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【阔刀】" << "【左左】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//左右
		else if (StrStrW(obj.O_ActionName.c_str(), L"attack_heavy_03") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【阔刀】" << "【左右】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右右and左右右
		else if ((StrStrW(obj.O_ActionName.c_str(), L"heavy_02") || StrStrW(obj.O_ActionName.c_str(), L"heavy_04")) && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【阔刀】" << "【右右】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右左and左右左
		else if ((StrStrW(obj.O_ActionName.c_str(), L"light_06") || StrStrW(obj.O_ActionName.c_str(), L"light_07")) && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【阔刀】" << "【右左】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//左蓄1段and左1火刀
		else if ((StrStrW(obj.O_ActionName.c_str(), L"attack_hold_light_01") || StrStrW(obj.O_ActionName.c_str(), L"soul_01")) && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【阔刀】" << "【左蓄1段】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//左蓄2段and左2火刀
		else if ((StrStrW(obj.O_ActionName.c_str(), L"hold_light_02") || StrStrW(obj.O_ActionName.c_str(), L"copy_02")) && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【阔刀】" << "【左蓄2段】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//左蓄3段
		else if ((obj.O_ActionName == L"male_blade_attack_hold_light_03" || obj.O_ActionName == L"female_blade_attack_hold_light_03") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【阔刀】" << "【左蓄3段】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右蓄1/2/3段 and 左右1/2/3段or滑步右1/2/3 and 右1/2/3裂空 and 左右1/2/3段or滑步右1/2/3裂空
		else if ((StrStrW(obj.O_ActionName.c_str(), L"heavy_05") || StrStrW(obj.O_ActionName.c_str(), L"heavy_06") || StrStrW(obj.O_ActionName.c_str(), L"copy_05") || StrStrW(obj.O_ActionName.c_str(), L"copy_06")) && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【阔刀】" << "【右蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右右1/2/3段 and 左右右1/2/3段 and 右右1/2/3裂空 and 左右右1/2/3裂空
		else if ((StrStrW(obj.O_ActionName.c_str(), L"heavy_07") || StrStrW(obj.O_ActionName.c_str(), L"heavy_08") || StrStrW(obj.O_ActionName.c_str(), L"copy_07") || StrStrW(obj.O_ActionName.c_str(), L"copy_08")) && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【阔刀】" << "【右右蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//雷刀
		else if ((obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_1" || obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_2" || obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_3") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【阔刀】" << "【雷刀】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//雷刀1
		else if (obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_4" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【阔刀】" << "【雷刀】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
	}
auto DebugSpearShockKnife(PlayerData obj)
{
		//左3
		if (obj.O_ActionName == L"male_spear_attack_light_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长枪】" << "【左3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右3
		else if (obj.O_ActionName == L"male_spear_attack_heavy_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长枪】" << "【右3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//左蓄
		else if (obj.O_ActionName == L"male_spear_attack_hold_light_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长枪】" << "【左蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//六合枪
		else if (obj.O_ActionName == L"male_spear_attack_hold_light_soul_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长枪】" << "【六合枪】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右蓄
		else if (obj.O_ActionName == L"male_spear_attack_hold_heavy_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长枪】" << "【右蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//大圣游
		else if (obj.O_ActionName == L"male_spear_attack_hold_heavy_soul_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长枪】" << "【大圣游】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//风卷云残
		else if (obj.O_ActionName == L"male_spear_attack_heavy_soul_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长枪】" << "【风卷云残】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//双环扫
		else if (obj.O_ActionName == L"male_spear_attack_light_soul_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长枪】" << "【双环扫】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//龙王破
		else if ((obj.O_ActionName == L"male_spear_attack_hold_light_03" || obj.O_ActionName == L"male_spear_attack_hold_heavy_03") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长枪】" << "【龙王破】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//穿心脚
		else if (StrStrW(obj.O_ActionName.c_str(), L"03_soul") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长枪】" << "【穿心脚】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
	}
auto DebugDaggeShockKnife(PlayerData obj)
{
		//左3
		if (obj.O_ActionName == L"male_dagger_attack_light_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【匕首】" << "【左3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右3
		else if (obj.O_ActionName == L"male_dagger_attack_heavy_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【匕首】" << "【右3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//左蓄
		else if (obj.O_ActionName == L"male_dagger_attack_hold_light_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【匕首】" << "【左蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右蓄
		else if (obj.O_ActionName == L"male_dagger_attack_hold_heavy_02" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【匕首】" << "【右蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//鬼反
		else if (obj.O_ActionName == L"male_dagger_flashstep_attack_light_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【匕首】" << "【鬼反】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//荆轲献匕
		else if (obj.O_ActionName == L"male_dagger_attack_hold_heavy_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【匕首】" << "【荆轲献匕】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//鬼刃暗扎
		else if (obj.O_ActionName == L"male_dagger_attack_hold_heavy_soul_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【匕首】" << "【鬼刃暗扎】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//鬼哭神嚎
		else if (obj.O_ActionName == L"male_dagger_flashjump_attack_soul_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【匕首】" << "【鬼哭神嚎】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//亢龙有悔
		else if (obj.O_ActionName == L"male_dagger_attack_hold_light_soul_02" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【匕首】" << "【亢龙有悔】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
	}
auto DebugnunchucksShockKnife(PlayerData obj)
{
		//左右3
		if (obj.O_ActionName == L"male_nunchucks_attack_light_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双截棍】" << "【左右3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//左蓄
		else if (obj.O_ActionName == L"male_nunchucks_attack_hold_light_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双截棍】" << "【左蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右蓄
		else if (obj.O_ActionName == L"male_nunchucks_attack_heavy_enhance_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双截棍】" << "【右蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//飞踢
		else if (obj.O_ActionName == L"male_nunchucks_attack_light_03_soul_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双截棍】" << "【飞踢】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//扬鞭劲
		else if (obj.O_ActionName == L"male_nunchucks_attack_hold_light_soul_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双截棍】" << "【扬鞭劲】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//横栏
		else if (obj.O_ActionName == L"male_nunchucks_attack_swing_light_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双截棍】" << "【横栏】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//龙虎乱舞预判
		else if (StrStrW(obj.O_ActionName.c_str(), L"01_charge") && Function::Shock::预判振刀)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双截棍】" << "【龙虎乱舞】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
	}
auto DebugtwinbladesShockKnife(PlayerData obj)
{
		//左右3
		if ((obj.O_ActionName == L"male_twinblades_attack_light_03" || obj.O_ActionName == L"male_twinblades_attack_heavy_03") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双刀】" << "【左右3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//左蓄
		else if (obj.O_ActionName == L"male_twinblades_attack_hold_light_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双刀】" << "【左蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右蓄
		else if ((obj.O_ActionName == L"male_twinblades_attack_hold_heavy_01" || obj.O_ActionName == L"male_twinblades_attack_hold_heavy_02") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双刀】" << "【右蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//铁马残红
		else if (obj.O_ActionName == L"male_twinblades_attack_hold_light_01_soul" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双刀】" << "【铁马残红】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//乾坤日月斩
		else if (obj.O_ActionName == L"male_twinblades_attack_hold_heavy_01_soul" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双刀】" << "【乾坤日月斩】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//蓄力后追击
		else if ((obj.O_ActionName == L"male_twinblades_attack_heavy_06" || obj.O_ActionName == L"male_twinblades_attack_heavy_04") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双刀】" << "【惊雷】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//八斩刀
		else if (obj.O_ActionName == L"male_twinblades_attack_light_soul_09" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双刀】" << "【八斩刀】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
	}
auto DebugrodShockKnife(PlayerData obj)
{
		//左3
		if (obj.O_ActionName == L"male_rod_attack_light_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长棍】" << "【左3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右3
		else if (obj.O_ActionName == L"male_rod_attack_heavy_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长棍】" << "【右3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//少林棍
		else if (obj.O_ActionName == L"male_rod_attack_heavy_soul_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长棍】" << "【少林棍】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//左蓄
		else if (obj.O_ActionName == L"male_rod_attack_hold_light_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长棍】" << "【左蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右蓄
		else if (obj.O_ActionName == L"male_rod_attack_hold_heavy_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长棍】" << "【右蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//腾云式
		else if (obj.O_ActionName == L"male_rod_attack_hold_light_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长棍】" << "【腾云式】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//乱点天宫
		else if (obj.O_ActionName == L"male_rod_attack_heavy_05_copy" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长棍】" << "【乱点天宫】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//桶劲
		else if (obj.O_ActionName == L"male_rod_attack_hold_light_soul_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长棍】" << "【桶劲】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//五情七灭镇
		else if (obj.O_ActionName == L"male_rod_attack_heavy_soul_05" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);//AA
			//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长棍】" << "【五情七灭镇】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//双环扫
		else if (obj.O_ActionName == L"male_rod_attack_light_soul_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长棍】" << "【双环扫】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//倒海棍
		else if (obj.O_ActionName == L"male_rod_attack_light_soul_05" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长棍】" << "【倒海棍】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//镇地撑天
		else if (obj.O_ActionName == L"male_rod_attack_hold_light_03_soul_01" && GetReactionType(obj.Cache_HitSimulate) == 2)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【长棍】" << "【镇地撑天】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
	}
auto DebugSaberShockKnife(PlayerData obj)
{
		//左左and右左左
		if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_light_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_light_05")) && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【斩马刀】" << "【左左】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//左右
		else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_03") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【斩马刀】" << "【左右】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右右and左右右
		else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_04")) && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【斩马刀】" << "【右右】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右左and左右左
		else if (StrStrW(obj.O_ActionName.c_str(), L"male_saber_attack_light_06") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【斩马刀】" << "【右左】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//左蓄
		else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_01") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_03")) && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【斩马刀】" << "【左蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右蓄
		else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_01") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_03")) && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【斩马刀】" << "【右蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//柄击
		else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_light_03") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【斩马刀】" << "【柄击】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//惊雷
		else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_09") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【斩马刀】" << "【惊雷】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//炽焰斩
		else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_soul_01") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_soul_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_soul_03")) && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【斩马刀】" << "【炽焰斩】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//过关斩将
		else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_soul_03") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【斩马刀】" << "【过关斩将】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
	}
auto DebugdualhalberdKnife(PlayerData obj)
{
		//左右3
		if ((obj.O_ActionName == L"male_dualhalberd_attack_light_03" || obj.O_ActionName == L"male_dualhalberd_attack_heavy_03") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双戟】" << "【左右3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//左蓄
		else if (obj.O_ActionName == L"male_dualhalberd_attack_hold_light_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双戟】" << "【左蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//右蓄
		else if ((obj.O_ActionName == L"male_dualhalberd_attack_hold_heavy_01" || obj.O_ActionName == L"male_dualhalberd_attack_hold_heavy_02") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双戟】" << "【右蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//勾旋斩
		else if (obj.O_ActionName == L"male_dualhalberd_attack_light_08" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双戟】" << "【勾旋斩】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//探海蛟
		else if (obj.O_ActionName == L"male_dualhalberd_attack_heavy_09" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双戟】" << "【探海蛟】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//钩挂
		else if (obj.O_ActionName == L"male_dualhalberd_attack_light_09" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双戟】" << "【钩挂】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}
		//战龙在天
		else if ((obj.O_ActionName == L"male_dualhalberd_attack_hold_light_01_soul" || obj.O_ActionName == L"male_dualhalberd_attack_hold_light_01_soul_copy"
			|| obj.O_ActionName == L"male_dualhalberd_attack_hold_light_02_soul_copy") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			time_t t = time(nullptr);
			Global::WorldPtr.now = localtime(&t);
			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【双戟】" << "【战龙在天】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
			Sleep(400);
		}

	}
auto DebugfanShockKnife(PlayerData obj)
{
	//左3
	if (obj.O_ActionName == L"male_fan_attack_light_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【扇子】" << "【左3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//右3
	else if (obj.O_ActionName == L"male_fan_attack_heavy_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【扇子】" << "【右3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//左蓄
	else if (obj.O_ActionName == L"male_fan_attack_hold_light_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【扇子】" << "【左蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//右蓄
	else if (obj.O_ActionName == L"male_fan_attack_hold_heavy_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【扇子】" << "【右蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//双开圆
	else if (obj.O_ActionName == L"male_fan_attack_light_soul_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【扇子】" << "【双开圆】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//三风摆
	else if (obj.O_ActionName == L"male_fan_attack_hold_light_soul_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【扇子】" << "【三风摆】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	////鬼反
	//if (obj.O_ActionName == L"male_fan_flashstep_attack_light_02" && obj.O_Dis <= 6.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	//{
	//	if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 60.f) : FALSE)
	//	{
	//		if (Function::Flag::IsBlueToRed)
	//		{
	//			if (!Function::Flag::IsMyManage || !Function::Shock::Flag_ShockKnife) { return; }
	//			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【三风摆】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
	//			振刀逻辑::BlueToRed();
	//			Sleep(400);
	//		}
	//		else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
	//		{
	//			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【三风摆】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【拼刀】" << endl;
	//			振刀逻辑::CollideKnife();
	//			Sleep(500);
	//		}
	//		else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
	//		{
	//			cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【扇子】| " << "【三风摆】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【短闪】" << endl;
	//			振刀逻辑::ShortDodge(KEY_S);
	//			Sleep(400);
	//		}
	//	}
	//}
	//惊雷
	else if (obj.O_ActionName == L"male_fan_attack_light_04" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【扇子】" << "【惊雷】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//缠龙奔野
	else if (obj.O_ActionName == L"male_fan_attack_hold_heavy_soul_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【扇子】" << "【缠龙奔野】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
}
auto DebughengdaoShockKnife(PlayerData obj)
{
	//左3
	if (obj.O_ActionName == L"male_hengdao_attack_light_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【横刀】" << "【左3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//右3
	else if (obj.O_ActionName == L"male_hengdao_attack_heavy_03" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【横刀】" << "【右3】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//左蓄
	else if ((obj.O_ActionName == L"male_hengdao_attack_hold_light_01" || obj.O_ActionName == L"male_hengdao_attack_light_05") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【横刀】" << "【左蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//右蓄
	else if ((obj.O_ActionName == L"male_hengdao_attack_hold_heavy_01" || obj.O_ActionName == L"male_hengdao_attack_hold_heavy_02") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【横刀】" << "【右蓄】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//破千军
	else if ((obj.O_ActionName == L"male_hengdao_attack_hold_light_soul_01" || obj.O_ActionName == L"male_hengdao_attack_light_soul_05") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【横刀】" << "【破千军】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
	//极光破云闪
	else if (obj.O_ActionName == L"male_hengdao_attack_hold_heavy_soul_02" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
	{
		time_t t = time(nullptr);
		Global::WorldPtr.now = localtime(&t);
		cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】" << "【横刀】" << "【极光破云闪】" << " 释放距离:" << obj.O_Dis << " | 释放角度:" << GetAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos) << endl;
		Sleep(400);
	}
}