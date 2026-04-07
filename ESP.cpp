#include"ESP.h"
std::string string_To_UTF8(const std::string& str)
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t* pwBuf = new wchar_t[nwLen + 1];
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char* pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr(pBuf);

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}


void PlayerESP()
{
	vector<PlayerData>m_ListData;
	if (!全_玩家交互)
	{
		m_ListData = 全_玩家数据;
	}
	Vec2 PM;
	Vec4 RW;
	int 信息Y轴 =0,预警Y轴 =0;
	int 盲区外敌人数量 = 0, 盲区敌人怒气 = 0;
	float 盲区外最近敌人距离 = 101.f;
	string 盲区最近敌人职业 = "", 盲区最近敌人是否有大 = "";
	for (int i = 0; i < m_ListData.size(); i++)
	{
		auto& CurList = m_ListData.at(i);
		if (WorldToScreen(MATRIX, CurList.O_Pos, PM, RW))
		{
			if (CurList.ISRobot)
			{
				if (Function::ESP::方框)Gui.Rectangle({ RW.x,RW.y }, { RW.w,RW.z }, Function::ESP::人机颜色, 1.f);
			}
			else if (!CurList.ISRobot) { if (Function::ESP::方框)Gui.Rectangle({ RW.x,RW.y }, { RW.w,RW.z }, Function::ESP::玩家颜色, 1.f); }
			if (Function::ESP::手持)
			{
				string Name = GetWeaponData(CurList.O_WeaponID).WeaponName;
				ImColor Color = GetWeaponData(CurList.O_WeaponID).WeaponColor;
				float TextSize = ImGui::CalcTextSize(string_To_UTF8(Name).c_str()).x;
				Gui.StrokeText(Name.c_str(), { PM.x - TextSize / 2,PM.y }, Color, 15.f);

			} 
			if (Function::ESP::信息)
			{
				int 怒气 = ((float)CurList.O_CurAnger / 75000) * 100;
				std::string Iffo = "T:" + std::to_string(CurList.Team)  + " | " + CurList.HeroName.c_str() + " | " + std::to_string(怒气) + "%%";
				float TextSize = ImGui::CalcTextSize(string_To_UTF8(Iffo).c_str()).x;
				float NameSize = ImGui::CalcTextSize(string_To_UTF8(CurList.PlayerName).c_str()).x;
				
				if (Function::ESP::血条样式 == 0) { 信息Y轴 = 30; }
				if (Function::ESP::血条样式 == 1) { 信息Y轴 = 25; }
				if (Function::ESP::血条样式 == 2) { 信息Y轴 = 25; }
				Gui.StrokeText(Iffo, { PM.x - TextSize / 2, RW.y - 信息Y轴 }, Function::ESP::信息颜色, 15.f);
				if (Function::ESP::名字) { Gui.StrokeText(CurList.PlayerName, { PM.x - NameSize / 2, RW.y - 信息Y轴 - 15 }, Function::ESP::名字颜色, 15.f); }
			}
			if (Function::ESP::血条)
			{
				//OB
				if (Function::ESP::血条样式 == 0)Gui.DrawArmorBar(RW, CurList.O_CurHp, CurList.O_MaxHp, CurList.O_Curshield, CurList.O_Maxshield);
				//自定义1
				if (Function::ESP::血条样式 == 1)Gui.PlayerHealth(RW, CurList.O_CurHp, CurList.O_MaxHp, CurList.O_Curshield, CurList.O_Maxshield);
				//自定义2
				if (Function::ESP::血条样式 == 2)Gui.PlayerHealth2(RW, CurList.O_CurHp, CurList.O_MaxHp, CurList.O_Curshield, CurList.O_Maxshield);


			}

		}

		if (Function::ESP::预警)
		{
			if (!CurList.O_Visible)
			{
				盲区外敌人数量++;
				if (CurList.O_Dis < 盲区外最近敌人距离)
				{
					盲区外最近敌人距离 = CurList.O_Dis;
					盲区最近敌人职业 = CurList.HeroName.c_str();
					盲区敌人怒气 = CurList.O_CurAnger;
					if (盲区敌人怒气 == 75000)
					{
						盲区最近敌人是否有大 = "有大";
					}else 盲区最近敌人是否有大 = "没大";
				}


			}
		}

	}
	if (Function::ESP::预警)
	{
		if (Function::ESP::预警样式 == 0) { 预警Y轴 += 400; }
		if (Function::ESP::预警样式 == 1) { 预警Y轴 -= 400; }
		if (盲区外敌人数量 == 0) return;
		string Info = "盲区敌人[ " + to_string(盲区外敌人数量) + " ]" + " 最近距离[ " + to_string((int)盲区外最近敌人距离) + " ]"+" 玩家职业[ "+ 盲区最近敌人职业+" ]"+" 是否有大[ "+ 盲区最近敌人是否有大+" ]";
		float TextSize = ImGui::CalcTextSize(string_To_UTF8(Info).c_str()).x;
		Gui.StrokeText(Info, Vec2{ (Gui.Window.Size.x / 2) - TextSize/1.6f ,Gui.Window.Size.y / 2 - 预警Y轴 }, ImColor{ 255,0,0 }, 18.0F);
	}
} 

void ItemESP()
{
	vector<ItemInfoData>m_ListData;
	m_ListData = 全_物品数据;
	Vec2 PM;
	Vec4 RW;
	for (int i = 0; i < m_ListData.size(); i++)
	{
		auto& CurList = m_ListData.at(i);

		if (WorldToScreen(MATRIX, CurList.Pos, PM, RW))
		{
			if (Function::ESP::盒子 && CurList.ItemType == 1)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::果实 && CurList.ItemType == 2)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::萤火虫 && CurList.ItemType == 14)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::护甲Lv1 && CurList.ItemType == 10)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::护甲Lv2 && CurList.ItemType == 11)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::护甲Lv3 && CurList.ItemType == 12)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::护甲Lv4 && CurList.ItemType == 13)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::护甲Lv5 && CurList.ItemType == 15)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::道具 && CurList.ItemType == 4)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::扩容 && CurList.ItemType == 16)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::近战 && CurList.ItemType == 5)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::远程 && CurList.ItemType == 6)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::夺魂 && CurList.ItemType == 7)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::金魂 && CurList.ItemType == 8)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::金魂 && CurList.ItemType == 9)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			//Gui.StrokeText(std::to_string(CurList.ID), PM, CurList.Color);

		}

	}


}

void InteractiveESP()
{
	vector<InteractiveInfoData>m_ListData;
	m_ListData = 全_金堆数据;
	Vec2 PM;
	Vec4 RW;
	for (int i = 0; i < m_ListData.size(); i++)
	{
		auto& CurList = m_ListData.at(i);
		if (WorldToScreen(MATRIX, CurList.Pos, PM, RW))
		{
			if (Function::ESP::蓝堆 && CurList.ItemType == 2)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::绿堆 && CurList.ItemType == 1)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::金堆 && CurList.ItemType == 3)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}
			if (Function::ESP::任务 && CurList.ItemType == 4)
			{
				Gui.StrokeText(CurList.Name, PM, CurList.Color);
			}


		}

	}


}