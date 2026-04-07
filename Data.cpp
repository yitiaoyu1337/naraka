#include "Data.h"

LocalPlayer_Data1 LocalPlayer_Data;

namespace Function
{
	namespace ESP
	{
		bool 菜单 = true;
		bool 菜单_2 = true;
		bool 方框 = true;
		bool 信息 = true;
		bool 血条 = true;
		bool 预警 = true;
		bool 手持 = true;
		bool 名字 = true;

		bool 近战 = false;
		bool 远程 = false;
		bool 道具 = false;
		bool 扩容 = false;
		bool 金魂 = false;
		bool 夺魂 = false;
		bool 属性 = false;
		bool 盒子 = false;

		bool 护甲Lv1 = false;
		bool 护甲Lv2 = false;
		bool 护甲Lv3 = false;
		bool 护甲Lv4 = false;
		bool 护甲Lv5 = false;

		bool 果实 = false;
		bool 萤火虫 = false;
		bool 金堆 = false;
		bool 蓝堆 = false;
		bool 绿堆 = false;
		bool 任务 = false;

		bool 堆堆Debug = false;

		int 血条样式 = 0;
		int 预警样式 = 0;
		ImColor 人机颜色 = ImColor(60, 179, 113);
		ImColor 玩家颜色 = ImColor(255, 0, 0);
		ImColor 信息颜色 = ImColor(255, 0, 0);
		ImColor 名字颜色 = ImColor(60, 179, 0);
		
	}
	namespace Kmbox
	{
		namespace Net
		{
			char IP[0XFF], Port[0XFF], mac[0XFF];
			int NetState = 5;
		}
		namespace B_Pro
		{
			bool BproState = false;
			char PorttextBuffer[0XFF] = "\0";
			char SpeedBuffer[0XFF] = "115200";
		}
	}
	namespace Shock
	{
		bool F_ShockKnife = true;		//振刀功能开关
		bool F_MemShock = false;		//内存振
		bool 预判振刀 = true;				//预判振噬魂斩 龙虎乱舞等等
		int Shock_Delay = 0;				//振刀时机精度调整
		bool Flag_ShockKnife = true;	//振刀判断到需要振刀时，是否执行振刀
		bool Flag_CollideKnife = true;	//振刀判断到需要拼刀时，是否执行拼刀
		bool Flag_ShortDodge = true;	//振刀判断到需要闪避时，是否执行闪避
		bool 扬鞭劲振刀 = false;
		bool 横栏振刀 = false;
		bool 横刀左蓄振刀 = true;
	}
	namespace LogicKnife
	{
		bool BlueAttackShock = true;	//出蓄抓振刀功能开关
		bool BlueAttackWrite = true;	//出蓄抓白刀功能开关
	}
	namespace HeroActivation
	{
		bool IsDodge = true;		//闪避功能开关
		bool 躲避火男F = true;
		bool 躲避火男冲拳 = true;
		bool 躲避妖刀大招 = true;
		bool 躲避顾清寒V1V2 = true;
		bool 躲避武田F = true;
		bool 躲避胡为 = true;
		bool 躲避宁红叶F = true;
		bool 躲避狐狸大招 = true;
		bool 躲避三娘V2 = true;
		bool 躲避哈迪大招 = true;
		bool 躲避魏轻F1 = true;
		bool 躲避魏轻V = true;

		bool 武田自动毛刀 = true;
		bool 和尚自动F2 = true;

		namespace 特殊处理
		{
			bool 永远躲避顾倾寒V1 = true;
		}

	}
	namespace Flag
	{
		bool IsMyManage = false;					//自身是否可以振刀的FLAG
		bool IsBlueToRed = false;					//自身是否可以续转
		bool ISAtoG = true;							//判断招式是否可以G震
		bool HeroTianHaiF2 = false;				//天海是否可以使用F2
	}
}

namespace 振刀参数
{
	namespace 距离
	{

		长剑1 长剑;
		太刀1 太刀;
		阔刀1 阔刀;
		长枪1 长枪;
		匕首1 匕首;
		双截棍1 双截棍;
		双刀1 双刀;
		长棍1 长棍;
		斩马刀1 斩马刀;
		双戟1 双戟;
		扇子1 扇子;
		横刀1 横刀;
	}

	namespace 角度
	{
		长剑2 长剑;
		太刀2 太刀;
		阔刀2 阔刀;
		长枪2 长枪;
		匕首2 匕首;
		双截棍2 双截棍;
		双刀2 双刀;
		长棍2 长棍;
		斩马刀2 斩马刀;
		双戟2 双戟;
		扇子2 扇子;
		横刀2 横刀;
	}

	namespace 特殊处理
	{
		bool 阔刀右蓄是否短闪振 = true;
		bool 双截棍左蓄是否短闪振 = true;
		bool 斩马刀左蓄是否长闪振 = true;
		bool 扇子左蓄是否中闪振 = true;
		bool 扇子右蓄是否中闪振 = true;
		bool 横刀左蓄是否只短闪 = false;
	}
}

namespace 活化参数
{
	namespace 距离
	{
		float 火男冲拳 = 3.5f;		//0-5M
		float 妖刀大招 = 25.f;		//0-35M
		float 顾倾寒大招 = 25.f;	//0-35M
		float 武田F2 = 5.f;			//0-6M
		float 武田F3 = 3.5f;			//0-4M
		float 胡为F1 = 5.5f;			//0-7M
		float 胡为F2 = 8.f;			//0-10m
		float 胡为跃击 = 10.f;		//0-12M
		float 胡为V1V2 = 10.f;		//0-15M
		float 宁红叶F1 = 8.f;		//0-10M
		float 宁红叶F2 = 8.f;		//0-10M
		float 宁红叶F3 = 8.f;		//0-10M
		float 狐狸大招 = 12.f;		//0-20M
		float 火男F = 4.f;			//0-5M
		float 三娘V2 = 35.f;		//0-40M
		float 哈迪大招2段 = 8.f;	//0-12M
		float 哈迪大招3段 = 12.f;	//0-15M
		float 魏轻F1 = 6.f;		//0-8M
		float 魏轻V1 = 12.f;		//0-20M
		float 魏轻V2 = 4.f;		//0-6M
	}

	namespace 角度
	{
		float 火男冲拳 = 25.f;
		float 妖刀大招3M = 120.f;
		float 妖刀大招3M外 = 35.f;
		float 顾倾寒大招3M = 45.f;
		float 顾倾寒大招3M外 = 5.f;
		float 武田F21M = 180.f;
		float 武田F21M外 = 8.f;
		float 武田F31M = 180.f;
		float 武田F31M外 = 8.f;
		float 胡为F2 = 45.f;
		float 胡为跃击 = 45.f;
		float 胡为V1V2 = 45.f;
		float 宁红叶F1 = 90.f;
		float 宁红叶F2 = 90.f;
		float 宁红叶F3 = 90.f;
		float 狐狸大招4M = 90.f;
		float 狐狸大招8M = 45.f;
		float 狐狸大招12M = 25.f;
		float 狐狸大招12M外 = 15.f;
		float 火男F = 90.f;
		float 三娘V24M = 45.f;
		float 三娘V210M = 25.f;
		float 三娘V210M外 = 12.f;
		float 哈迪大招 = 45.f;
		float 魏轻V1 = 90.f;
		float 魏轻V2 = 90.f;
	}

	int 出蓄抓振延迟 = 0;
}

namespace 调试
{
	逻辑执行1 逻辑执行;
	bool 输出逻辑执行 = false;
	bool 输出逻辑执行Flag = false;		//这个不用加在菜单，随动的。
	bool 输出调试执行 = false;
}
