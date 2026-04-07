#pragma once
#include "Data.h"
#include "ShockKnife.h"

//技能躲避
void DodgeSkill(PlayerData obj)
{
	if (obj.O_Visible)
	{
		//躲避火男F1
		if (Function::HeroActivation::躲避火男F && obj.O_Dis <= 活化参数::距离::火男F)
		{
			if (obj.O_ActionName == L"male_hero_spiritsman_attack_01_counter_01" || obj.O_ActionName == L"male_hero_spiritsman_attack_02_counter_01" || obj.O_ActionName == L"male_hero_spiritsman_attack_02_counter_02")//判断动作，距离
			{
				if (LocalPlayer_Data.MyEndureLevel < 30)//判断自身等级
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::火男F) : FALSE)
					{
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【火男】";
						调试::逻辑执行.敌人动作 = "【燎原劲】";
						调试::逻辑执行.执行动作 = "【躲避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 活化参数::角度::火男F;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
		}
		//躲避火男冲拳
		if (Function::HeroActivation::躲避火男冲拳 && obj.O_Dis <= 活化参数::距离::火男冲拳)
		{
			if (StrStrW(obj.O_ActionName.c_str(), L"male_hero_spiritsman_dodge_front_double_01"))//判断动作，距离
			{
				if (LocalPlayer_Data.MyEndureLevel < 30)//判断自身等级
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::火男冲拳) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【火男冲拳】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【火男】";
						调试::逻辑执行.敌人动作 = "【冲拳】";
						调试::逻辑执行.执行动作 = "【躲避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 活化参数::角度::火男冲拳;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
		}
		//躲避妖刀大招
		if (Function::HeroActivation::躲避妖刀大招 && obj.O_Dis <= 活化参数::距离::妖刀大招)
		{
			if (StrStrW(obj.O_ActionName.c_str(), L"hero_yaodaoji_jump_uniqueskill_01_02") || StrStrW(obj.O_ActionName.c_str(), L"hero_yaodaoji_jump_uniqueskill_02_02") ||
				StrStrW(obj.O_ActionName.c_str(), L"hero_yaodaoji_jump_uniqueskill_03_02"))//判断动作
			{
				if (LocalPlayer_Data.MyEndureLevel < 40)//判断自身等级
				{
					if (obj.O_Dis <= 3.f)		//3M
					{
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::妖刀大招3M) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【妖刀大招】 | 【" << obj.O_Dis << "】 | 角度:" << 120.f << endl;
							振刀逻辑::ShortDodgeEx();
							调试::逻辑执行.敌人类型 = "【妖刀】";
							调试::逻辑执行.敌人动作 = "【大招】";
							调试::逻辑执行.执行动作 = "【躲避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = 活化参数::角度::妖刀大招3M;
							调试::输出逻辑执行Flag = true;
							Sleep(900);
						}
					}
					else//3-25M内
					{
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 25.f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -25.f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::妖刀大招3M外) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【妖刀大招】 | 【" << obj.O_Dis << "】 | 角度:" << 35.f << endl;
							振刀逻辑::ShortDodgeEx();
							调试::逻辑执行.敌人类型 = "【妖刀】";
							调试::逻辑执行.敌人动作 = "【大招】";
							调试::逻辑执行.执行动作 = "【躲避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = 活化参数::角度::妖刀大招3M外;
							调试::输出逻辑执行Flag = true;
							Sleep(900);
						}
					}
				}
			}
		}
		//躲避顾清寒大招
		if (Function::HeroActivation::躲避顾清寒V1V2 && obj.O_Dis <= 活化参数::距离::顾倾寒大招)
		{
			//V1
			if (obj.O_ActionName == L"female_hero_guqinghan_attack_02_90_pre" || obj.O_ActionName == L"female_hero_guqinghan_jump_attack_02_90_pre")//判断动作
			{
				if (Function::HeroActivation::特殊处理::永远躲避顾倾寒V1)//判断自身等级
				{
					if (obj.O_Dis <= 3.f)		//3M
					{
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::顾倾寒大招3M) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【顾清寒大招】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << endl;
							振刀逻辑::ShortDodgeEx();
							调试::逻辑执行.敌人类型 = "【顾清寒】";
							调试::逻辑执行.敌人动作 = "【V1】";
							调试::逻辑执行.执行动作 = "【躲避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = 活化参数::角度::顾倾寒大招3M;
							调试::输出逻辑执行Flag = true;
							Sleep(500);
						}
					}
					else//3-25M内
					{
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 25.f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -25.f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::顾倾寒大招3M外) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【顾清寒大招】 | 【" << obj.O_Dis << "】 | 角度:" << 5.f << endl;
							振刀逻辑::ShortDodgeEx();
							调试::逻辑执行.敌人类型 = "【顾清寒】";
							调试::逻辑执行.敌人动作 = "【V1】";
							调试::逻辑执行.执行动作 = "【躲避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = 活化参数::角度::顾倾寒大招3M外;
							调试::输出逻辑执行Flag = true;
							Sleep(1000);
						}
					}
				}
				else
				{
					if (LocalPlayer_Data.MyEndureLevel < 20)
					{
						if (obj.O_Dis <= 3.f)		//3M
						{
							if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::顾倾寒大招3M) : FALSE)
							{
								//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【顾清寒大招】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << endl;
								振刀逻辑::ShortDodgeEx();
								调试::逻辑执行.敌人类型 = "【顾清寒】";
								调试::逻辑执行.敌人动作 = "【V1】";
								调试::逻辑执行.执行动作 = "【躲避】";
								调试::逻辑执行.执行距离 = obj.O_Dis;
								调试::逻辑执行.执行角度 = 活化参数::角度::顾倾寒大招3M;
								调试::输出逻辑执行Flag = true;
								Sleep(500);
							}
						}
						else//3-25M内
						{
							if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 25.f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -25.f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::顾倾寒大招3M外) : FALSE)
							{
								//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【顾清寒大招】 | 【" << obj.O_Dis << "】 | 角度:" << 5.f << endl;
								振刀逻辑::ShortDodgeEx();
								调试::逻辑执行.敌人类型 = "【顾清寒】";
								调试::逻辑执行.敌人动作 = "【V1】";
								调试::逻辑执行.执行动作 = "【躲避】";
								调试::逻辑执行.执行距离 = obj.O_Dis;
								调试::逻辑执行.执行角度 = 活化参数::角度::顾倾寒大招3M外;
								调试::输出逻辑执行Flag = true;
								Sleep(1000);
							}
						}
					}
				}
			}
			//V2
			if (obj.O_ActionName == L"female_hero_guqinghan_attack_03_90_pre" || obj.O_ActionName == L"female_hero_guqinghan_jump_attack_03_90_pre")//判断动作
			{
				if (LocalPlayer_Data.MyEndureLevel <= 22)
				{
					if (obj.O_Dis <= 3.f)		//3M
					{
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::顾倾寒大招3M) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【顾清寒大招】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << endl;
							振刀逻辑::ShortDodgeEx();
							调试::逻辑执行.敌人类型 = "【顾清寒】";
							调试::逻辑执行.敌人动作 = "【V2】";
							调试::逻辑执行.执行动作 = "【躲避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = 活化参数::角度::顾倾寒大招3M;
							调试::输出逻辑执行Flag = true;

						}
					}
					else//3-25M内
					{
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 25.f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -25.f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::顾倾寒大招3M外) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【顾清寒大招】 | 【" << obj.O_Dis << "】 | 角度:" << 5.f << endl;
							振刀逻辑::ShortDodgeEx();
							调试::逻辑执行.敌人类型 = "【顾清寒】";
							调试::逻辑执行.敌人动作 = "【V2】";
							调试::逻辑执行.执行动作 = "【躲避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = 活化参数::角度::顾倾寒大招3M外;
							调试::输出逻辑执行Flag = true;
							Sleep(1000);
						}
					}
				}
			}
		}
		//武田F躲避
		if (Function::HeroActivation::躲避武田F)
		{
			if (/*LocalPlayer_Data.MyEndureLevel == 21 ||*/ LocalPlayer_Data.MyEndureLevel == 20 || LocalPlayer_Data.MyEndureLevel == 22)
			{
				if (obj.O_ActionName == L"male_hero_takeda_attack_01_branch_01" || obj.O_ActionName == L"male_hero_takeda_jump_attack_01_branch_01")//F2
				{
					if (obj.O_Dis <= 1.2f)
					{
						if (LocalPlayer_Data.MyBlueTime <= 0.49 && LocalPlayer_Data.MyBlueTime > 0.f)		//1.0之前
						{
							if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::武田F21M) : FALSE)
							{
								//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【出刀】| " << "【躲避武田F2】 | 【" << obj.O_Dis << "】 | 角度:" << 180.f << endl;
								振刀逻辑::CollideKnife();
								调试::逻辑执行.敌人类型 = "【武田】";
								调试::逻辑执行.敌人动作 = "【F2】";
								调试::逻辑执行.执行动作 = "【出刀】";
								调试::逻辑执行.执行距离 = obj.O_Dis;
								调试::逻辑执行.执行角度 = 活化参数::角度::武田F21M;
								调试::输出逻辑执行Flag = true;
							}
						}
						else//1.0之后
						{
							if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::武田F21M) : FALSE)
							{
								//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【躲避武田F22】 | 【" << obj.O_Dis << "】 | 角度:" << 180.f << endl;
								振刀逻辑::ShortDodge(KEY_S);
								调试::逻辑执行.敌人类型 = "【武田】";
								调试::逻辑执行.敌人动作 = "【F2】";
								调试::逻辑执行.执行动作 = "【躲避】";
								调试::逻辑执行.执行距离 = obj.O_Dis;
								调试::逻辑执行.执行角度 = 活化参数::角度::武田F21M;
								调试::输出逻辑执行Flag = true;
							}
						}
						Sleep(1200);
					}
					else if (obj.O_Dis <= 活化参数::距离::武田F2)
					{

						if (LocalPlayer_Data.MyBlueTime <= 0.49 && LocalPlayer_Data.MyBlueTime > 0.f)		//1.0之前
						{
							if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::武田F21M外) : FALSE)
							{
								//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【出刀】| " << "【躲避武田F2】 | 【" << obj.O_Dis << "】 | 角度:" << 8.f << endl;
								振刀逻辑::CollideKnife();
								调试::逻辑执行.敌人类型 = "【武田】";
								调试::逻辑执行.敌人动作 = "【F2】";
								调试::逻辑执行.执行动作 = "【出刀】";
								调试::逻辑执行.执行距离 = obj.O_Dis;
								调试::逻辑执行.执行角度 = 活化参数::角度::武田F21M外;
								调试::输出逻辑执行Flag = true;
							}
						}
						else//1.0之后
						{
							if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::武田F21M外) : FALSE)
							{
								//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【躲避武田F2】 | 【" << obj.O_Dis << "】 | 角度:" << 8.f << endl;
								振刀逻辑::ShortDodge(KEY_S);
								调试::逻辑执行.敌人类型 = "【武田】";
								调试::逻辑执行.敌人动作 = "【F2】";
								调试::逻辑执行.执行动作 = "【躲避】";
								调试::逻辑执行.执行距离 = obj.O_Dis;
								调试::逻辑执行.执行角度 = 活化参数::角度::武田F21M外;
								调试::输出逻辑执行Flag = true;
							}
						}
						Sleep(1200);
					}
				}
				else if (obj.O_ActionName == L"male_hero_takeda_attack_01_branch_02" || obj.O_ActionName == L"male_hero_takeda_jump_attack_01_branch_02")//F3
				{
					if (obj.O_Dis <= 1.2f)
					{
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::武田F31M) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【躲避武田F3】 | 【" << obj.O_Dis << "】 | 角度:" << 180.f << endl;
							振刀逻辑::ShortDodge(KEY_S);
							调试::逻辑执行.敌人类型 = "【武田】";
							调试::逻辑执行.敌人动作 = "【F3】";
							调试::逻辑执行.执行动作 = "【躲避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = 活化参数::角度::武田F31M;
							调试::输出逻辑执行Flag = true;
							Sleep(1200);
						}
					}
					else if (obj.O_Dis <= 活化参数::距离::武田F3)
					{
						if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::武田F31M外) : FALSE)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【躲避武田F3】 | 【" << obj.O_Dis << "】 | 角度:" << 8.f << endl;
							振刀逻辑::ShortDodge(KEY_S);
							调试::逻辑执行.敌人类型 = "【武田】";
							调试::逻辑执行.敌人动作 = "【F3】";
							调试::逻辑执行.执行动作 = "【躲避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = 活化参数::角度::武田F31M外;
							调试::输出逻辑执行Flag = true;
							Sleep(1200);
						}
					}
				}
			}
		}
		//胡为躲避
		if (Function::HeroActivation::躲避胡为)
		{
			if (LocalPlayer_Data.MyEndureLevel != 30 && LocalPlayer_Data.MyEndureLevel != 31 && LocalPlayer_Data.MyEndureLevel < 40 && LocalPlayer_Data.MyEndureLevel != 35)//判断自身等级
			{
				//躲避胡为F1
				if (obj.O_ActionName == L"male_hero_huwei_attack_01" || obj.O_ActionName == L"male_hero_huwei_jump_attack_01")
				{
					if (obj.O_Dis <= 活化参数::距离::胡为F1)
					{
						auto ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
						if (ObjCurTime >= 0.2f)
						{
							//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【胡为F1】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << endl;
							振刀逻辑::ShortDodge(KEY_S);
							调试::逻辑执行.敌人类型 = "【胡为】";
							调试::逻辑执行.敌人动作 = "【F1】";
							调试::逻辑执行.执行动作 = "【躲避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = 360.f;
							调试::输出逻辑执行Flag = true;
							Sleep(1000);
						}
					}
				}
				//胡为F2
				else if (obj.O_ActionName == L"male_hero_huwei_attack_02_branch_01" || obj.O_ActionName == L"male_hero_huwei_jump_attack_02_branch_01" ||
					obj.O_ActionName == L"male_hero_huwei_attack_01_branch_01" || obj.O_ActionName == L"male_hero_huwei_jump_attack_01_branch_01")
				{
					if (obj.O_Dis <= 活化参数::距离::胡为F2 && (fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::胡为F2) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【胡为F2】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << endl;
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【胡为】";
						调试::逻辑执行.敌人动作 = "【F2】";
						调试::逻辑执行.执行动作 = "【躲避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 活化参数::角度::胡为F2;
						调试::输出逻辑执行Flag = true;
						Sleep(600);
					}
				}
				//躲避胡为跳跃攻击
				else if (StrStrW(obj.O_ActionName.c_str(), L"huwei_tigerleap_attack_01_pre") || StrStrW(obj.O_ActionName.c_str(), L"huwei_tigerleap_attack_02_pre") || StrStrW(obj.O_ActionName.c_str(), L"huwei_tigerleap_attack_03_pre"))
				{
					if (obj.O_Dis <= 活化参数::距离::胡为跃击 && (fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::胡为跃击) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【胡为跃击】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << endl;
						Sleep((DWORD)obj.O_Dis * 2);
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【胡为】";
						调试::逻辑执行.敌人动作 = "【跃击】";
						调试::逻辑执行.执行动作 = "【躲避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 活化参数::角度::胡为跃击;
						调试::输出逻辑执行Flag = true;
						Sleep(600);
					}
				}
				//躲避胡为V1 V2
				else if (StrStrW(obj.O_ActionName.c_str(), L"hero_huwei_uniqueskill_extend_05_pre"))
				{
					if (obj.O_Dis <= 活化参数::距离::胡为V1V2 && (fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::胡为V1V2) : FALSE)
					{
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【胡为V1V2】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << endl;
						振刀逻辑::ShortDodgeEx();
						调试::逻辑执行.敌人类型 = "【胡为】";
						调试::逻辑执行.敌人动作 = "【大招】";
						调试::逻辑执行.执行动作 = "【躲避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 活化参数::角度::胡为V1V2;
						调试::输出逻辑执行Flag = true;
						Sleep(600);
					}
				}
			}
		}
		//躲避宁红叶F
		if (Function::HeroActivation::躲避宁红叶F)
		{
			if (LocalPlayer_Data.MyEndureLevel != 30 && LocalPlayer_Data.MyEndureLevel != 31 && LocalPlayer_Data.MyEndureLevel < 40 && LocalPlayer_Data.MyEndureLevel != 35)//判断自身等级
			{
				//躲避宁红叶F1
				if (obj.O_ActionName == L"female_hero_blindswordswoman_attack_04_copy_02" || obj.O_ActionName == L"female_hero_blindswordswoman_jump_attack_04_copy_02")
				{
					if (obj.O_Dis <= 活化参数::距离::宁红叶F1)
					{
						auto ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
						if (ObjCurTime >= 0.15f)
						{
							if (obj.O_Dis <= 4.f)
							{
								if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::宁红叶F1) : FALSE)
								{
									振刀逻辑::ShortDodge(KEY_W);
									调试::逻辑执行.敌人类型 = "【宁红叶】";
									调试::逻辑执行.敌人动作 = "【F1】";
									调试::逻辑执行.执行动作 = "【躲避】";
									调试::逻辑执行.执行距离 = obj.O_Dis;
									调试::逻辑执行.执行角度 = 活化参数::角度::宁红叶F1;
									调试::输出逻辑执行Flag = true;
									Sleep(1000);
								}
							}
							else
							{
								if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::宁红叶F1) : FALSE)
								{
									振刀逻辑::ShortDodge(KEY_S);
									调试::逻辑执行.敌人类型 = "【宁红叶】";
									调试::逻辑执行.敌人动作 = "【F1】";
									调试::逻辑执行.执行动作 = "【躲避】";
									调试::逻辑执行.执行距离 = obj.O_Dis;
									调试::逻辑执行.执行角度 = 活化参数::角度::宁红叶F1;
									调试::输出逻辑执行Flag = true;
									Sleep(1000);
								}
							}
						}
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【胡为F1】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << endl;
					}
				}
				//躲避宁红叶F2
				if (obj.O_ActionName == L"female_hero_blindswordswoman_attack_04_copy_01" || obj.O_ActionName == L"female_hero_blindswordswoman_jump_attack_04_copy_01")
				{
					if (obj.O_Dis <= 活化参数::距离::宁红叶F2)
					{
						auto ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
						if (ObjCurTime >= 0.15f)
						{
							if (obj.O_Dis <= 4.f)
							{
								if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::宁红叶F2) : FALSE)
								{
									振刀逻辑::ShortDodge(KEY_W);
									调试::逻辑执行.敌人类型 = "【宁红叶】";
									调试::逻辑执行.敌人动作 = "【F2】";
									调试::逻辑执行.执行动作 = "【躲避】";
									调试::逻辑执行.执行距离 = obj.O_Dis;
									调试::逻辑执行.执行角度 = 活化参数::角度::宁红叶F2;
									调试::输出逻辑执行Flag = true;
									Sleep(1000);
								}
							}
							else
							{
								if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::宁红叶F2) : FALSE)
								{
									振刀逻辑::ShortDodge(KEY_S);
									调试::逻辑执行.敌人类型 = "【宁红叶】";
									调试::逻辑执行.敌人动作 = "【F2】";
									调试::逻辑执行.执行动作 = "【躲避】";
									调试::逻辑执行.执行距离 = obj.O_Dis;
									调试::逻辑执行.执行角度 = 活化参数::角度::宁红叶F2;
									调试::输出逻辑执行Flag = true;
									Sleep(1000);
								}
							}
						}
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【胡为F1】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << endl;
					}
				}
				//躲避宁红叶F3
				if (obj.O_ActionName == L"female_hero_blindswordswoman_attack_04" || obj.O_ActionName == L"female_hero_blindswordswoman_jump_attack_04")
				{
					if (obj.O_Dis <= 活化参数::距离::宁红叶F3)
					{
						auto ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
						if (ObjCurTime >= 0.15f)
						{
							if (obj.O_Dis <= 4.f)
							{
								if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::宁红叶F3) : FALSE)
								{
									振刀逻辑::ShortDodge(KEY_W);
									调试::逻辑执行.敌人类型 = "【宁红叶】";
									调试::逻辑执行.敌人动作 = "【F3】";
									调试::逻辑执行.执行动作 = "【躲避】";
									调试::逻辑执行.执行距离 = obj.O_Dis;
									调试::逻辑执行.执行角度 = 活化参数::角度::宁红叶F3;
									调试::输出逻辑执行Flag = true;
									Sleep(1000);
								}
							}
							else
							{
								if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::宁红叶F3) : FALSE)
								{
									振刀逻辑::ShortDodge(KEY_S);
									调试::逻辑执行.敌人类型 = "【宁红叶】";
									调试::逻辑执行.敌人动作 = "【F3】";
									调试::逻辑执行.执行动作 = "【躲避】";
									调试::逻辑执行.执行距离 = obj.O_Dis;
									调试::逻辑执行.执行角度 = 活化参数::角度::宁红叶F3;
									调试::输出逻辑执行Flag = true;
									Sleep(1000);
								}
							}
						}
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【胡为F1】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << endl;
					}
				}
			}
		}
		//躲避狐狸大招
		if (Function::HeroActivation::躲避狐狸大招)
		{
			if (LocalPlayer_Data.MyEndureLevel < 40 && LocalPlayer_Data.MyEndureLevel != 35)//判断自身等级
			{
				if (obj.O_ActionName == L"female_hero_yulinglong_uniqueskill_01" || obj.O_ActionName == L"female_hero_yulinglong_jump_uniqueskill_01" ||
					obj.O_ActionName == L"female_hero_yulinglong_uniqueskill_01_branch_01" || obj.O_ActionName == L"female_hero_yulinglong_jump_uniqueskill_01_branch_01")
				{
					if (obj.O_Dis <= 活化参数::距离::狐狸大招)
					{
						auto ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
						if (ObjCurTime >= 0.28f)
						{
							if (obj.O_Dis <= 4.f)
							{
								if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::狐狸大招4M) : FALSE)
								{
									振刀逻辑::ShortDodgeEx();
									调试::逻辑执行.敌人类型 = "【玉玲珑】";
									调试::逻辑执行.敌人动作 = "【大招】";
									调试::逻辑执行.执行动作 = "【躲避】";
									调试::逻辑执行.执行距离 = obj.O_Dis;
									调试::逻辑执行.执行角度 = 活化参数::角度::狐狸大招4M;
									调试::输出逻辑执行Flag = true;
									Sleep(1500);
								}
							}
							else if (obj.O_Dis <= 8.f)
							{
								if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::狐狸大招8M) : FALSE)
								{//A
									振刀逻辑::ShortDodgeEx();
									调试::逻辑执行.敌人类型 = "【玉玲珑】";
									调试::逻辑执行.敌人动作 = "【大招】";
									调试::逻辑执行.执行动作 = "【躲避】";
									调试::逻辑执行.执行距离 = obj.O_Dis;
									调试::逻辑执行.执行角度 = 活化参数::角度::狐狸大招8M;
									调试::输出逻辑执行Flag = true;
									Sleep(1500);
								}
							}
							else if (obj.O_Dis <= 12.f)
							{
								if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::狐狸大招12M) : FALSE)
								{
									振刀逻辑::ShortDodgeEx();
									调试::逻辑执行.敌人类型 = "【玉玲珑】";
									调试::逻辑执行.敌人动作 = "【大招】";
									调试::逻辑执行.执行动作 = "【躲避】";
									调试::逻辑执行.执行距离 = obj.O_Dis;
									调试::逻辑执行.执行角度 = 活化参数::角度::狐狸大招12M;
									调试::输出逻辑执行Flag = true;
									Sleep(1500);
								}
							}
							else
							{
								if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::狐狸大招12M外) : FALSE)
								{
									振刀逻辑::ShortDodgeEx();
									调试::逻辑执行.敌人类型 = "【玉玲珑】";
									调试::逻辑执行.敌人动作 = "【大招】";
									调试::逻辑执行.执行动作 = "【躲避】";
									调试::逻辑执行.执行距离 = obj.O_Dis;
									调试::逻辑执行.执行角度 = 活化参数::角度::狐狸大招12M外;
									调试::输出逻辑执行Flag = true;
									Sleep(1500);
								}
							}
						}
						//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【躲避】| " << "【胡为F1】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << endl;
					}
				}
			}
		}
		//躲避三娘V2
		if (Function::HeroActivation::躲避三娘V2)
		{
			if (LocalPlayer_Data.MyEndureLevel < 40 && LocalPlayer_Data.MyEndureLevel != 35)//判断自身等级
			{
				if (obj.O_ActionName == L"female_hero_cuisanniang_uniqueskill_03_attack_01_copy_01" || obj.O_ActionName == L"female_hero_cuisanniang_uniqueskill_03_jump_attack_01_copy_01" ||
					obj.O_ActionName == L"female_hero_cuisanniang_uniqueskill_03_attack_01" || obj.O_ActionName == L"female_hero_cuisanniang_uniqueskill_03_jump_attack_01")
				{
					if (obj.O_Dis <= 活化参数::距离::三娘V2)
					{
						auto ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
						if (ObjCurTime >= 0.22f + (obj.O_Dis * 5) / 1000)
						{
							if (obj.O_Dis <= 4.f)
							{
								if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 活化参数::距离::三娘V2 && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -活化参数::距离::三娘V2) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::三娘V24M) : FALSE)
								{
									振刀逻辑::ShortDodgeEx();
									调试::逻辑执行.敌人类型 = "【崔三娘】";
									调试::逻辑执行.敌人动作 = "【大招】";
									调试::逻辑执行.执行动作 = "【躲避】";
									调试::逻辑执行.执行距离 = obj.O_Dis;
									调试::逻辑执行.执行角度 = 活化参数::角度::三娘V24M;
									调试::输出逻辑执行Flag = true;

								}
							}
							else if (obj.O_Dis <= 10.f)
							{
								if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 活化参数::距离::三娘V2 && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -活化参数::距离::三娘V2) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::三娘V210M) : FALSE)
								{
									振刀逻辑::ShortDodgeEx();
									调试::逻辑执行.敌人类型 = "【崔三娘】";
									调试::逻辑执行.敌人动作 = "【大招】";
									调试::逻辑执行.执行动作 = "【躲避】";
									调试::逻辑执行.执行距离 = obj.O_Dis;
									调试::逻辑执行.执行角度 = 活化参数::角度::三娘V210M;
									调试::输出逻辑执行Flag = true;

								}
							}
							else
							{
								if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 活化参数::距离::三娘V2 && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > 活化参数::距离::三娘V2) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::三娘V210M外) : FALSE)
								{
									振刀逻辑::ShortDodgeEx();
									调试::逻辑执行.敌人类型 = "【崔三娘】";
									调试::逻辑执行.敌人动作 = "【大招】";
									调试::逻辑执行.执行动作 = "【躲避】";
									调试::逻辑执行.执行距离 = obj.O_Dis;
									调试::逻辑执行.执行角度 = 活化参数::角度::三娘V210M外;
									调试::输出逻辑执行Flag = true;

								}
							}
						}
					}
				}
			}
		}
		//躲避哈迪大招
		if (Function::HeroActivation::躲避哈迪大招)
		{
			//二段大招
			if (StrStrW(obj.O_ActionName.c_str(), L"male_hero_hadi_fly_attack_hold_02_90") && obj.O_Dis >= 5.f && obj.O_Dis <= 活化参数::距离::哈迪大招2段)
			{
				if (LocalPlayer_Data.MyEndureLevel != 31 && LocalPlayer_Data.MyEndureLevel < 40 && LocalPlayer_Data.MyEndureLevel != 35)//判断自身等级
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 活化参数::距离::哈迪大招2段 && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -活化参数::距离::哈迪大招2段) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::哈迪大招) : FALSE)
					{
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【哈迪】";
						调试::逻辑执行.敌人动作 = "【2段大招】";
						调试::逻辑执行.执行动作 = "【躲避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 活化参数::角度::哈迪大招;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			} {}
			//三段大招
			if (StrStrW(obj.O_ActionName.c_str(), L"male_hero_hadi_fly_attack_hold_03_90") && obj.O_Dis >= 8.2f && obj.O_Dis <= 活化参数::距离::哈迪大招3段)
			{
				if (LocalPlayer_Data.MyEndureLevel != 31 && LocalPlayer_Data.MyEndureLevel < 40 && LocalPlayer_Data.MyEndureLevel != 35)//判断自身等级
				{
					if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 活化参数::距离::哈迪大招3段 && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -活化参数::距离::哈迪大招3段) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::哈迪大招) : FALSE)
					{
						振刀逻辑::ShortDodge(KEY_S);
						调试::逻辑执行.敌人类型 = "【哈迪】";
						调试::逻辑执行.敌人动作 = "【3段大招】";
						调试::逻辑执行.执行动作 = "【躲避】";
						调试::逻辑执行.执行距离 = obj.O_Dis;
						调试::逻辑执行.执行角度 = 活化参数::角度::哈迪大招;
						调试::输出逻辑执行Flag = true;
						Sleep(800);
					}
				}
			}
		}
		//躲避魏轻F1
		if (Function::HeroActivation::躲避魏轻F1)
		{
			if (LocalPlayer_Data.MyEndureLevel < 40 && LocalPlayer_Data.MyEndureLevel != 35)//判断自身等级
			{
				if (obj.O_ActionName == L"female_hero_weiqing_attack_01")
				{
					if (obj.O_Dis <= 活化参数::距离::魏轻F1)
					{
						auto ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
						if (ObjCurTime >= 0.1f)
						{
							振刀逻辑::ShortDodge(KEY_S);
							调试::逻辑执行.敌人类型 = "【魏轻】";
							调试::逻辑执行.敌人动作 = "【F1】";
							调试::逻辑执行.执行动作 = "【躲避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = 360.f;
							调试::输出逻辑执行Flag = true;
							Sleep(1200);
						}
					}
				}
				else if (obj.O_ActionName == L"female_hero_weiqing_jump_attack_01")
				{
					if (obj.O_Dis <= 活化参数::距离::魏轻F1)
					{
						auto ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
						if (ObjCurTime >= 0.05f)
						{
							振刀逻辑::ShortDodge(KEY_S);
							调试::逻辑执行.敌人类型 = "【魏轻】";
							调试::逻辑执行.敌人动作 = "【F1】";
							调试::逻辑执行.执行动作 = "【躲避】";
							调试::逻辑执行.执行距离 = obj.O_Dis;
							调试::逻辑执行.执行角度 = 360.f;
							调试::输出逻辑执行Flag = true;
							Sleep(1200);
						}
					}
				}
			}
		}
		//躲避魏轻V
		if (Function::HeroActivation::躲避魏轻V)
		{
			if (LocalPlayer_Data.MyEndureLevel < 40 && LocalPlayer_Data.MyEndureLevel != 35)//判断自身等级
			{
				//V1
				if (obj.O_ActionName == L"female_hero_weiqing_attack_03_90")
				{
					if (obj.O_Dis <= 活化参数::距离::魏轻V1)
					{
						auto ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
						if (ObjCurTime >= 0.05f)
						{
							if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::魏轻V1) : FALSE)
							{
								振刀逻辑::ShortDodgeEx();
								调试::逻辑执行.敌人类型 = "【魏轻】";
								调试::逻辑执行.敌人动作 = "【V1】";
								调试::逻辑执行.执行动作 = "【躲避】";
								调试::逻辑执行.执行距离 = obj.O_Dis;
								调试::逻辑执行.执行角度 = 活化参数::角度::魏轻V1;
								调试::输出逻辑执行Flag = true;
								Sleep(1000);
							}
						}
					}
				}
				//v2
				else if (obj.O_ActionName == L"female_hero_weiqing_jump_attack_03_copy_01")
				{
					if (obj.O_Dis <= 活化参数::距离::魏轻V2)
					{
						auto ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
						if (ObjCurTime >= 0.25f)
						{
							if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 活化参数::角度::魏轻V2) : FALSE)
							{
								振刀逻辑::ShortDodge(KEY_S);
								调试::逻辑执行.敌人类型 = "【魏轻】";
								调试::逻辑执行.敌人动作 = "【V2】";
								调试::逻辑执行.执行动作 = "【躲避】";
								调试::逻辑执行.执行距离 = obj.O_Dis;
								调试::逻辑执行.执行角度 = 活化参数::角度::魏轻V2;
								调试::输出逻辑执行Flag = true;
								Sleep(1000);
							}
						}
					}
				}
			}
		}
	}
}

//武田随机自动F
void WuTianActivation(PlayerData obj)
{
	if (obj.O_Visible)
	{
		if ((LocalPlayer_Data.MySkillID == 1501401 || LocalPlayer_Data.MySkillID == 1501402) && LocalPlayer_Data.MySkillState == 0)
		{
			if (obj.O_Dis <= 3.f)
			{
				auto ObjEndureLevel = Memory::RAM<ActionType>(obj.Cache_HitSimulate + Offset::ActorModel.ActorKitS.HitSimulate.endureLevel);
				if (ObjEndureLevel == 20 && !(rand() % 200))
				{
					振刀逻辑::WuTianF();
					Sleep(400);
				}
			}
		}
	}
}

//天海F2
auto TianHaiSwShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 12.5f)
	{
		float NewAngle = 0.f;
		//左3
		if (obj.O_ActionName == L"male_sw_attack_light_03" && obj.O_Dis <= 4.2f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 25.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长剑】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右3
		else if (obj.O_ActionName == L"male_sw_attack_heavy_03" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 25.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长剑】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左剑气
		else if ((obj.O_ActionName == L"male_sw_attack_hold_light_01" || obj.O_ActionName == L"male_sw_attack_hold_light_02") && obj.O_Dis <= 12.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 180.f;
			}
			else if (obj.O_Dis <= 4.f)
			{
				NewAngle = 25.f;
			}
			else if (obj.O_Dis <= 6.5f)
			{
				NewAngle = 25.f;
			}
			else if (obj.O_Dis <= 9.5f)
			{
				NewAngle = 11.f;
			}
			else
			{
				NewAngle = 11.f;

			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长剑】| " << "【左剑气】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右剑气
		else if ((obj.O_ActionName == L"male_sw_attack_hold_heavy_01" || obj.O_ActionName == L"male_sw_attack_hold_heavy_02") && obj.O_Dis <= 12.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 60.f;
			}
			else if (obj.O_Dis <= 4.f)
			{
				NewAngle = 20.f;
			}
			else if (obj.O_Dis <= 6.5f)
			{
				NewAngle = 12.f;
			}
			else if (obj.O_Dis <= 9.5f)
			{
				NewAngle = 6.f;
			}
			else
			{
				NewAngle = 6.f;

			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长剑】| " << "【右剑气】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//凤凰羽
		else if ((StrStrW(obj.O_ActionName.c_str(), L"soul_01") || StrStrW(obj.O_ActionName.c_str(), L"soul_02")) && obj.O_Dis <= 12.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 90.f;
			}
			else if (obj.O_Dis <= 5.f)
			{
				NewAngle = 20.f;
			}
			else if (obj.O_Dis <= 8.f)
			{
				NewAngle = 20.f;
			}
			else
			{
				NewAngle = 12.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长剑】| " << "【凤凰羽】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//蓝月
		else if (StrStrW(obj.O_ActionName.c_str(), L"copy_03") && obj.O_Dis <= 12.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 45.f;
			}
			else if (obj.O_Dis <= 6.f)
			{
				NewAngle = 45.f;
			}
			else
			{
				NewAngle = 20.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长剑】| " << "【蓝月】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//七星夺窍
		else if (obj.O_ActionName == L"male_sw_attack_light_soul_04" && obj.O_Dis <= 10.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 4.f)
			{
				NewAngle = 45.f;
			}
			else if (obj.O_Dis <= 6.f)
			{
				NewAngle = 45.f;
			}
			else
			{
				NewAngle = 45.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长剑】| " << "【七星夺窍】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
	}
}
auto TianHaiKatanaShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 10.f)
	{
		float NewAngle = 0.f;

		//左3
		if (obj.O_ActionName == L"male_katana_attack_light_03" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 25.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【太刀】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右3
		else if (obj.O_ActionName == L"male_katana_attack_heavy_03" && obj.O_Dis <= 4.8f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 25.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【太刀】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左蓄
		else if ((obj.O_ActionName == L"male_katana_attack_hold_light_01" || obj.O_ActionName == L"male_katana_attack_hold_light_02") && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{

			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 60.f;
			}
			else
			{
				NewAngle = 30.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【太刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右蓄
		else if ((obj.O_ActionName == L"male_katana_attack_hold_heavy_01" || obj.O_ActionName == L"male_katana_attack_hold_heavy_02") && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 45.f;
			}
			else
			{
				NewAngle = 25.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【太刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左惊雷
		else if (obj.O_ActionName == L"male_katana_attack_light_05" && obj.O_Dis <= 8.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 25.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【太刀】| " << "【左惊雷】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右惊雷
		else if (obj.O_ActionName == L"male_katana_attack_heavy_09_pre" && obj.O_Dis <= 9.5f/* && GetRangeReactionType(obj.Cache_HitSimulate) == 12*/)
		{
			if (obj.O_Dis <= 5.f)
			{
				NewAngle = 25.f;
			}
			else
			{
				NewAngle = 13.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【太刀】| " << "【右惊雷】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//青鬼左
		else if (obj.O_ActionName == L"male_katana_attack_light_soul_03" && obj.O_Dis <= 6.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 25.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【太刀】| " << "【青鬼左】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//青鬼右
		else if (obj.O_ActionName == L"male_katana_attack_heavy_soul_03" && obj.O_Dis <= 4.2f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 25.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【太刀】| " << "【青鬼右】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//噬魂斩预判
		else if (StrStrW(obj.O_ActionName.c_str(), L"charge_soul_01") && Function::Shock::预判振刀)
		{
			auto ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
			auto Shock_Timing = 0.9;
			if (ObjCurTime > Shock_Timing)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【太刀】| " << "【噬魂斩】 | 【" << obj.O_Dis << "】 | 角度:" << 360.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
	}
}
auto TianHaiBladeShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 8.5f)
	{
		float NewAngle = 0.f;

		//左左and右左左
		if ((StrStrW(obj.O_ActionName.c_str(), L"attack_light_02") || StrStrW(obj.O_ActionName.c_str(), L"attack_light_05")) && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 25.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【阔刀】| " << "【左左】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左右
		else if (StrStrW(obj.O_ActionName.c_str(), L"attack_heavy_03") && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{

			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 60.f;
			}
			else
			{
				NewAngle = 30.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【阔刀】| " << "【左右】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右右and左右右
		else if ((StrStrW(obj.O_ActionName.c_str(), L"heavy_02") || StrStrW(obj.O_ActionName.c_str(), L"heavy_04")) && obj.O_Dis <= 4.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 30.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【阔刀】| " << "【右右】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右左and左右左
		else if ((StrStrW(obj.O_ActionName.c_str(), L"light_06") || StrStrW(obj.O_ActionName.c_str(), L"light_07")) && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【阔刀】| " << "【右左】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左蓄1段and左1火刀
		else if ((StrStrW(obj.O_ActionName.c_str(), L"attack_hold_light_01") || StrStrW(obj.O_ActionName.c_str(), L"soul_01")) && obj.O_Dis <= 7.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 60.f;
			}
			else
			{
				NewAngle = 45.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【阔刀】| " << "【左蓄1段】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左蓄2段and左2火刀
		else if ((StrStrW(obj.O_ActionName.c_str(), L"hold_light_02") || StrStrW(obj.O_ActionName.c_str(), L"copy_02")) && obj.O_Dis <= 4.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【阔刀】| " << "【左蓄2段】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
			振刀逻辑::TianhaiF2(); Sleep(300);
		}
		//左蓄3段
		else if ((obj.O_ActionName == L"male_blade_attack_hold_light_03" || obj.O_ActionName == L"female_blade_attack_hold_light_03") && obj.O_Dis <= 5.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【阔刀】| " << "【左蓄3段】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
			振刀逻辑::TianhaiF2(); Sleep(300);
		}
		//右蓄1/2/3段 and 左右1/2/3段or滑步右1/2/3 and 右1/2/3裂空 and 左右1/2/3段or滑步右1/2/3裂空
		else if ((StrStrW(obj.O_ActionName.c_str(), L"heavy_05") || StrStrW(obj.O_ActionName.c_str(), L"heavy_06") || StrStrW(obj.O_ActionName.c_str(), L"copy_05") || StrStrW(obj.O_ActionName.c_str(), L"copy_06")) && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 60.f;
			}
			else
			{
				NewAngle = 45.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【阔刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右右1/2/3段 and 左右右1/2/3段 and 右右1/2/3裂空 and 左右右1/2/3裂空
		else if ((StrStrW(obj.O_ActionName.c_str(), L"heavy_07") || StrStrW(obj.O_ActionName.c_str(), L"heavy_08") || StrStrW(obj.O_ActionName.c_str(), L"copy_07") || StrStrW(obj.O_ActionName.c_str(), L"copy_08")) && obj.O_Dis <= 8.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 45.f;
			}
			else
			{
				NewAngle = 15.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【阔刀】| " << "【右右】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//雷刀
		else if ((obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_1" || obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_2" || obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_3") && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【阔刀】| " << "【雷刀】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
			振刀逻辑::TianhaiF2(); Sleep(300);
		}
		//雷刀1
		else if (obj.O_ActionName == L"male_blade_attack_hold_light_soul_03_4" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【阔刀】| " << "【雷刀】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
			振刀逻辑::TianhaiF2(); Sleep(300);
		}
	}
}
auto TianHaiSpearShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 10.f)
	{
		float NewAngle = 0.f;

		//左3
		if (obj.O_ActionName == L"male_spear_attack_light_03" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长枪】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右3
		else if (obj.O_ActionName == L"male_spear_attack_heavy_03" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长枪】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左蓄
		else if (obj.O_ActionName == L"male_spear_attack_hold_light_01" && obj.O_Dis <= 5.2f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长枪】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//六合枪
		else if (obj.O_ActionName == L"male_spear_attack_hold_light_soul_01" && obj.O_Dis <= 8.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 60.f;
			}
			else
			{
				NewAngle = 25.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长枪】| " << "【六合枪】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右蓄
		else if (obj.O_ActionName == L"male_spear_attack_hold_heavy_01" && obj.O_Dis <= 8.3f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长枪】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//大圣游
		else if (obj.O_ActionName == L"male_spear_attack_hold_heavy_soul_01" && obj.O_Dis <= 6.2f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 60.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长枪】| " << "【大圣游】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//风卷云残
		else if (obj.O_ActionName == L"male_spear_attack_heavy_soul_03" && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长枪】| " << "【风卷云残】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//双环扫
		else if (obj.O_ActionName == L"male_spear_attack_light_soul_03" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长枪】| " << "【双环扫】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
			振刀逻辑::TianhaiF2(); Sleep(300);
		}
		//龙王破
		else if ((obj.O_ActionName == L"male_spear_attack_hold_light_03" || obj.O_ActionName == L"male_spear_attack_hold_heavy_03") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 45.f;
			}
			else
			{
				NewAngle = 25.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长枪】| " << "【龙王破】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//穿心脚
		else if (StrStrW(obj.O_ActionName.c_str(), L"03_soul") && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 45.f;
			}
			else
			{
				NewAngle = 25.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长枪】| " << "【穿心脚】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
	}
}
auto TianHaiDaggeShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 9.f)
	{
		float NewAngle = 0.f;

		//左3
		if (obj.O_ActionName == L"male_dagger_attack_light_03" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【匕首】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右3
		else if (obj.O_ActionName == L"male_dagger_attack_heavy_03" && obj.O_Dis <= 4.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【匕首】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左蓄
		else if (obj.O_ActionName == L"male_dagger_attack_hold_light_01" && obj.O_Dis <= 5.8f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{

			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 90.f;
			}
			else
			{
				NewAngle = 60.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【匕首】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右蓄
		else if (obj.O_ActionName == L"male_dagger_attack_hold_heavy_02" && obj.O_Dis <= 4.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			auto ObjEndureLevel = Memory::RAM<ActionType>(obj.Cache_HitSimulate + Offset::ActorModel.ActorKitS.HitSimulate.endureLevel);
			if (ObjEndureLevel != 20) return;

			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 180.f;
			}
			else
			{
				NewAngle = 90.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【匕首】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//鬼反
		else if (obj.O_ActionName == L"male_dagger_flashstep_attack_light_01" && obj.O_Dis <= 5.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【匕首】| " << "【鬼反】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//荆轲献匕
		else if (obj.O_ActionName == L"male_dagger_attack_hold_heavy_01" && obj.O_Dis <= 8.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 90.f;
			}
			else
			{
				NewAngle = 45.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【匕首】| " << "【荆轲献匕】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//鬼刃暗扎
		else if (obj.O_ActionName == L"male_dagger_attack_hold_heavy_soul_01" && obj.O_Dis <= 6.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 180.f;
			}
			else
			{
				NewAngle = 45.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【匕首】| " << "【鬼刃暗扎】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//鬼哭神嚎
		else if (obj.O_ActionName == L"male_dagger_flashjump_attack_soul_01" && obj.O_Dis <= 6.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【匕首】| " << "【鬼哭神嚎】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
			振刀逻辑::TianhaiF2(); Sleep(300);
		}
		//亢龙有悔
		else if (obj.O_ActionName == L"male_dagger_attack_hold_light_soul_02" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{

			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 180.f;
			}
			else if (obj.O_Dis <= 4.f)
			{
				NewAngle = 45.f;
			}
			else
			{
				NewAngle = 20.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【匕首】| " << "【亢龙有悔】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
	}
}
auto TianHainunchucksShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 8.f)
	{
		float NewAngle = 0.f;

		//左右3
		if (obj.O_ActionName == L"male_nunchucks_attack_light_03" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双截棍】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左蓄
		else if (obj.O_ActionName == L"male_nunchucks_attack_hold_light_01" && obj.O_Dis <= 6.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 60.f;
			}
			else
			{
				NewAngle = 30.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双截棍】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右蓄
		else if (obj.O_ActionName == L"male_nunchucks_attack_heavy_enhance_01" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 60.f;
			}
			else
			{
				NewAngle = 30.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双截棍】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//飞踢
		else if (obj.O_ActionName == L"male_nunchucks_attack_light_03_soul_01" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双截棍】| " << "【飞踢】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//扬鞭劲
		else if (obj.O_ActionName == L"male_nunchucks_attack_hold_light_soul_01" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双截棍】| " << "【扬鞭劲】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//横栏
		else if (obj.O_ActionName == L"male_nunchucks_attack_swing_light_01" && obj.O_Dis <= 3.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双截棍】| " << "【横栏】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//龙虎乱舞预判
		else if (StrStrW(obj.O_ActionName.c_str(), L"01_charge") && obj.O_Dis <= 6 && Function::Shock::预判振刀)
		{
			auto ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
			auto Shock_Timing = 1.0f;
			if (ObjCurTime > Shock_Timing)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双截棍】| " << "【龙虎乱舞】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}

		}
	}
}
auto TianHaitwinbladesShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 9.f)
	{
		float NewAngle = 0.f;

		//左右3
		if ((obj.O_ActionName == L"male_twinblades_attack_light_03" || obj.O_ActionName == L"male_twinblades_attack_heavy_03") && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双刀】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左蓄
		else if (obj.O_ActionName == L"male_twinblades_attack_hold_light_01" && obj.O_Dis <= 5.0f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 60.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右蓄
		else if ((obj.O_ActionName == L"male_twinblades_attack_hold_heavy_01" || obj.O_ActionName == L"male_twinblades_attack_hold_heavy_02") && obj.O_Dis <= 4.8f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 60.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
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
		//			//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【分水斩】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
		//			振刀逻辑::BlueToRed();
		//			Sleep(800);
		//		}
		//		else if (LocalPlayer_Data.MyBlueTime > 0.5f && Function::Shock::Flag_CollideKnife)
		//		{
		//			//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【分水斩】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【拼刀】" << endl;
		//			振刀逻辑::CollideKnife();
		//			Sleep(450);
		//		}
		//		else if (LocalPlayer_Data.MyEndureLevel < 30 && LocalPlayer_Data.MyEndureLevel != 21 && LocalPlayer_Data.MyEndureLevel != 22 && Function::Shock::Flag_ShortDodge)
		//		{
		//			//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【双刀】| " << "【分水斩】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【短闪】" << endl;
		//			振刀逻辑::ShortDodge(KEY_S);
		//			Sleep(800);
		//		}
		//	}
		//}

		//铁马残红
		else if (obj.O_ActionName == L"male_twinblades_attack_hold_light_01_soul" && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{

			if (obj.O_Dis <= 3.f)
			{
				NewAngle = 180.f;
			}
			else
			{
				NewAngle = 60.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双刀】| " << "【铁马残红】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//乾坤日月斩
		else if (obj.O_ActionName == L"male_twinblades_attack_hold_heavy_01_soul" && obj.O_Dis <= 11.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双刀】| " << "【乾坤日月斩】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//蓄力后追击
		else if ((obj.O_ActionName == L"male_twinblades_attack_heavy_06" || obj.O_ActionName == L"male_twinblades_attack_heavy_04") && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双刀】| " << "【惊雷】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//八斩刀
		else if (obj.O_ActionName == L"male_twinblades_attack_light_soul_09" && obj.O_Dis <= 6.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 60.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双刀】| " << "【八斩刀】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
	}
}
auto TianHairodShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 13.f)
	{
		float NewAngle = 0.f;

		//左3
		if (obj.O_ActionName == L"male_rod_attack_light_03" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长棍】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右3
		else if (obj.O_ActionName == L"male_rod_attack_heavy_03" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长棍】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//少林棍
		else if (obj.O_ActionName == L"male_rod_attack_heavy_soul_03" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长棍】| " << "【少林棍】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左蓄
		else if (obj.O_ActionName == L"male_rod_attack_hold_light_01" && obj.O_Dis <= 6.7f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 180.f;
			}
			else
			{
				NewAngle = 90.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长棍】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右蓄
		else if (obj.O_ActionName == L"male_rod_attack_hold_heavy_01" && obj.O_Dis <= 5.2f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			auto ObjEndureLevel = Memory::RAM<ActionType>(obj.Cache_HitSimulate + Offset::ActorModel.ActorKitS.HitSimulate.endureLevel);
			if (ObjEndureLevel != 20) return;
			//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长棍】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
			振刀逻辑::TianhaiF2(); Sleep(300);
		}
		//腾云式
		else if (obj.O_ActionName == L"male_rod_attack_hold_light_03" && obj.O_Dis <= 9.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 45.f;
			}
			else
			{
				NewAngle = 20.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长棍】| " << "【腾云式】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//乱点天宫
		else if (obj.O_ActionName == L"male_rod_attack_heavy_05_copy" && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			auto ObjEndureLevel = Memory::RAM<ActionType>(obj.Cache_HitSimulate + Offset::ActorModel.ActorKitS.HitSimulate.endureLevel);
			if (ObjEndureLevel != 20) return;
			//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长棍】| " << "【乱点天宫】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
			振刀逻辑::TianhaiF2(); Sleep(300);
		}
		//桶劲
		else if (obj.O_ActionName == L"male_rod_attack_hold_light_soul_01" && obj.O_Dis <= 8.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长棍】| " << "【桶劲】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//五情七灭镇
		else if (obj.O_ActionName == L"male_rod_attack_heavy_soul_05" && obj.O_Dis <= 13.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 8.5f)
			{
				NewAngle = 90.f;
			}
			else
			{
				NewAngle = 60.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长棍】| " << "【五情七灭镇】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//双环扫
		else if (obj.O_ActionName == L"male_rod_attack_light_soul_03" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长棍】| " << "【双环扫】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
			振刀逻辑::TianhaiF2(); Sleep(300);
		}
		//倒海棍
		else if (obj.O_ActionName == L"male_rod_attack_light_soul_05" && obj.O_Dis <= 6.3f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 75.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长棍】| " << "【倒海棍】 | 【" << obj.O_Dis << "】 | 角度:" << 75.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//镇地撑天
		else if (obj.O_ActionName == L"male_rod_attack_hold_light_03_soul_01" && obj.O_Dis <= 5.5f && GetReactionType(obj.Cache_HitSimulate) == 2)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 120.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【长棍】| " << "【倒海棍】 | 【" << obj.O_Dis << "】 | 角度:" << 120.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
	}
}
auto TianHaiSaberShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 8.5f)
	{
		float NewAngle = 0.f;

		//左左and右左左
		if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_light_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_light_05")) && obj.O_Dis <= 6.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【斩马刀】| " << "【左左】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左右
		else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_03") && obj.O_Dis <= 5.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 60.f;
			}
			else
			{
				NewAngle = 30.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【斩马刀】| " << "【左右】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右右and左右右
		else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_04")) && obj.O_Dis <= 4.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 30.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【斩马刀】| " << "【右右】 | 【" << obj.O_Dis << "】 | 角度:" << 30.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右左and左右左
		else if (StrStrW(obj.O_ActionName.c_str(), L"male_saber_attack_light_06") && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【斩马刀】| " << "【右左】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左蓄
		else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_01") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_03")) && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 180.f;
			}
			else
			{
				NewAngle = 45.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【斩马刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右蓄
		else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_01") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_03")) && obj.O_Dis <= 5.3f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【斩马刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//柄击
		else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_light_03") && obj.O_Dis <= 6.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【斩马刀】| " << "【柄击】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//惊雷
		else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_heavy_09") && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【斩马刀】| " << "【惊雷】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//炽焰斩
		else if ((StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_soul_01") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_soul_02") || StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_light_soul_03")) && obj.O_Dis <= 7.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 60.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【斩马刀】| " << "【炽焰斩】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//过关斩将
		else if (StrStrW(obj.O_ActionName.c_str(), L"saber_attack_hold_heavy_soul_03") && obj.O_Dis <= 8.3f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 25.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【斩马刀】| " << "【过关斩将】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
	}
}
auto TianHaidualhalberdKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 8.f)
	{
		float NewAngle = 0.f;

		//左右3
		if ((obj.O_ActionName == L"male_dualhalberd_attack_light_03" || obj.O_ActionName == L"male_dualhalberd_attack_heavy_03") && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双戟】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左蓄
		else if (obj.O_ActionName == L"male_dualhalberd_attack_hold_light_01" && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 3.f)
			{
				NewAngle = 90.f;
			}
			else
			{
				NewAngle = 60.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双戟】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右蓄
		else if ((obj.O_ActionName == L"male_dualhalberd_attack_hold_heavy_01" || obj.O_ActionName == L"male_dualhalberd_attack_hold_heavy_02") && obj.O_Dis <= 6.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 3.f)
			{
				NewAngle = 90.f;
			}
			else
			{
				NewAngle = 60.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双戟】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//勾旋斩
		else if (obj.O_ActionName == L"male_dualhalberd_attack_light_08" && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双戟】| " << "【勾旋斩】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//探海蛟
		else if (obj.O_ActionName == L"male_dualhalberd_attack_heavy_09" && obj.O_Dis <= 7.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双戟】| " << "【探海蛟】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//钩挂
		else if (obj.O_ActionName == L"male_dualhalberd_attack_light_09" && obj.O_Dis <= 6.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双戟】| " << "【钩挂】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//战龙在天
		else if ((obj.O_ActionName == L"male_dualhalberd_attack_hold_light_01_soul" || obj.O_ActionName == L"male_dualhalberd_attack_hold_light_01_soul_copy"
			|| obj.O_ActionName == L"male_dualhalberd_attack_hold_light_02_soul_copy") && obj.O_Dis <= 6.4f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【双戟】| " << "【战龙在天】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}

	}
}
auto TianHaifanShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 11.5f)
	{
		float NewAngle = 0.f;

		//左3
		if (obj.O_ActionName == L"male_fan_attack_light_03" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【扇子】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右3
		else if (obj.O_ActionName == L"male_fan_attack_heavy_03" && obj.O_Dis <= 4.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【扇子】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左蓄
		else if (obj.O_ActionName == L"male_fan_attack_hold_light_01" && obj.O_Dis <= 7.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 3.f)
			{
				NewAngle = 45.f;
			}
			else
			{
				NewAngle = 90.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【扇子】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右蓄
		else if (obj.O_ActionName == L"male_fan_attack_hold_heavy_01" && obj.O_Dis <= 7.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 2.f)
			{
				NewAngle = 45.f;
			}
			else
			{
				NewAngle = 60.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【扇子】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//双开圆
		else if (obj.O_ActionName == L"male_fan_attack_light_soul_03" && obj.O_Dis <= 6.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【扇子】| " << "【双开圆】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//三风摆
		else if (obj.O_ActionName == L"male_fan_attack_hold_light_soul_01" && obj.O_Dis <= 9.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 3.f)
			{
				NewAngle = 45.f;
			}
			else
			{
				NewAngle = 90.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【扇子】| " << "【三风摆】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//鬼反
		if (obj.O_ActionName == L"male_fan_flashstep_attack_light_02" && obj.O_Dis <= 6.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【扇子】| " << "【鬼反】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//惊雷
		else if (obj.O_ActionName == L"male_fan_attack_light_04" && obj.O_Dis <= 5.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【扇子】| " << "【惊雷】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//缠龙奔野
		else if (obj.O_ActionName == L"male_fan_attack_hold_heavy_soul_01" && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (obj.O_Dis <= 3.f)
			{
				NewAngle = 180.f;
			}
			else
			{
				NewAngle = 120.f;
			}

			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, NewAngle) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【扇子】| " << "【缠龙奔野】 | 【" << obj.O_Dis << "】 | 角度:" << NewAngle << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}

	}
}
auto TianHaihengdaoShockKnife(PlayerData obj)
{
	if (obj.O_Visible && obj.O_Dis <= 12.f)
	{
		float NewAngle = 0.f;

		//左3
		if (obj.O_ActionName == L"male_hengdao_attack_light_03" && obj.O_Dis <= 4.5f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 25.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【横刀】| " << "【左3】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右3
		else if (obj.O_ActionName == L"male_hengdao_attack_heavy_03" && obj.O_Dis <= 4.8f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 25.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【横刀】| " << "【右3】 | 【" << obj.O_Dis << "】 | 角度:" << 25.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//左蓄
		else if ((obj.O_ActionName == L"male_hengdao_attack_hold_light_01" || obj.O_ActionName == L"male_hengdao_attack_light_05") && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (!Function::Shock::横刀左蓄振刀) return;
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【横刀】| " << "【左蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//右蓄
		else if ((obj.O_ActionName == L"male_hengdao_attack_hold_heavy_01" || obj.O_ActionName == L"male_hengdao_attack_hold_heavy_02") && obj.O_Dis <= 6.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 60.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【横刀】| " << "【右蓄】 | 【" << obj.O_Dis << "】 | 角度:" << 60.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//破千军
		else if ((obj.O_ActionName == L"male_hengdao_attack_hold_light_soul_01" || obj.O_ActionName == L"male_hengdao_attack_light_soul_05") && obj.O_Dis <= 5.f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			if (!Function::Shock::横刀左蓄振刀) return;
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 45.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【横刀】| " << "【破千军】 | 【" << obj.O_Dis << "】 | 角度:" << 45.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
		//极光破云闪
		else if (obj.O_ActionName == L"male_hengdao_attack_hold_heavy_soul_02" && obj.O_Dis <= 6.1f && GetRangeReactionType(obj.Cache_HitSimulate) == 12)
		{
			auto ObjCurTime = (Global::WorldPtr.GlobalTime - Memory::RAM<double>(obj.Cache_GetCurTimeForLogicState_PTR + 0x58));
			if (ObjCurTime > 0.6f) return;
			if ((fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) < 4.5f && fabs(obj.O_Pos.y - LocalPlayer_Data.MyPos.y) > -4.5f) ? CheckPlayerAngle(obj.Cache_ActorRootPtr, obj.O_Pos, LocalPlayer_Data.MyPos, 180.f) : FALSE)
			{
				//cout << "【" << Global::WorldPtr.now->tm_hour << ":" << Global::WorldPtr.now->tm_min << ":" << Global::WorldPtr.now->tm_sec << "】 | " << "【天海F2】" << "【横刀】| " << "【极光破云闪】 | 【" << obj.O_Dis << "】 | 角度:" << 180.f << " | 【振刀】 " << endl;
				振刀逻辑::TianhaiF2(); Sleep(300);
			}
		}
	}
}