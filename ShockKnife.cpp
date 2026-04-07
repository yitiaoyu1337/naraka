#include "ShockKnife.h"
void 振刀逻辑::BlueToRed()
{
	if (按键方式 ==0)
	{
		SendKeyPressEx(KEY_G);
		Sleep(25);
		SendKeyUpEx(KEY_G);
	}
	else if (按键方式 == 1)
	{
		按下键盘(KEY_G);
		Sleep(25);
		弹起键盘(KEY_G);
	}
}

void 振刀逻辑::JumpShock()
{
	if (按键方式 == 0)
	{
		SendKeyPressEx(KEY_SPACEBAR);
		Sleep(15);
		BlueToRed();
		SendKeyUpEx(KEY_SPACEBAR);
	}
	else if (按键方式 == 1)
	{
		按下键盘(KEY_SPACEBAR);
		Sleep(15);
		BlueToRed();
		弹起键盘(KEY_SPACEBAR);
	}

}

void 振刀逻辑::TianhaiF2()
{
	if (按键方式 == 0)
	{
		SendKeyPressEx(KEY_SPACEBAR);
		Sleep(1);
		SendKeyPressEx(KEY_F);
		Sleep(25);
		SendKeyUpEx(KEY_F);
		SendKeyUpEx(KEY_SPACEBAR);
	}
	else if (按键方式 == 1)
	{
		按下键盘(KEY_SPACEBAR);
		Sleep(1);
		按下键盘(KEY_F);
		Sleep(25);
		弹起键盘(KEY_F);
		弹起键盘(KEY_SPACEBAR);
	}

}

void 振刀逻辑::CollideKnife()
{
	if (按键方式 == 0)
	{
		//左键弹起
		kmNet_mask_mouse_left(true);
		kmNet_mouse_move(1, 1);
		kmNet_mask_mouse_left(false);

		//右键弹起
		kmNet_mask_mouse_right(true);
		kmNet_mouse_move(1, 1);
		kmNet_mask_mouse_right(false);
	}
	else if (按键方式 == 1)
	{
		右键弹起();
		左键弹起();

	}

}

void 振刀逻辑::ShortDodge(uint32_t Key)
{
	if (按键方式 == 0)
	{
		SendKeyPressEx(Key);
		SendKeyPressEx(KEY_LEFTSHIFT);
		Sleep(50);
		SendKeyUpEx(KEY_LEFTSHIFT);
		SendKeyUpEx(Key);
	}
	else if (按键方式 == 1)
	{
		按下键盘(Key);
		按下键盘(KEY_LEFTSHIFT);
		Sleep(50);
		弹起键盘(KEY_LEFTSHIFT);
		弹起键盘(Key);
	}

}

void 振刀逻辑::LongDodge(uint32_t Key)
{
	if (按键方式 == 0)
	{
		SendKeyPressEx(Key);
		SendKeyPressEx(KEY_LEFTSHIFT);
		Sleep(200);
		SendKeyUpEx(KEY_LEFTSHIFT);
		SendKeyUpEx(Key);
	}
	else if (按键方式 == 1)
	{
		按下键盘(Key);
		按下键盘(KEY_LEFTSHIFT);
		Sleep(200);
		弹起键盘(KEY_LEFTSHIFT);
		弹起键盘(Key);
	}
}

void 振刀逻辑::ZhongDodge()
{
	if (按键方式 == 0)
	{
		//SendKeyPressEx(Key);
		SendKeyPressEx(KEY_LEFTSHIFT);
		Sleep(200);
		SendKeyUpEx(KEY_LEFTSHIFT);
		//SendKeyUpEx(Key);
	}
	else if (按键方式 == 1)
	{
		//按下键盘(Key);
		按下键盘(KEY_LEFTSHIFT);
		Sleep(200);
		弹起键盘(KEY_LEFTSHIFT);
		//弹起键盘(Key);
	}
}

void 振刀逻辑::ShortDodgeEx()
{
	if (rand() % 2)
		ShortDodge(KEY_A);
	else
		ShortDodge(KEY_D);
}

void 振刀逻辑::MemShock()
{
	//wcout << LocalPlayer_Data.MyActionName << endl;
	if (LocalPlayer_Data.MyCurrentCollisionFlags == 0 || LocalPlayer_Data.MyCurrentCollisionFlags == 5 || StrStrW(LocalPlayer_Data.MyActionName.c_str(), L"beam"))
	{
		if (按键方式 == 0)
		{

			Hook::enable_vtbale(true);
			SendKeyPressEx(KEY_SPACEBAR);
			Sleep(2);
			MouseLeftEx(true);
			MouseRightEx(true);
			Sleep(50);
			MouseLeftEx(false);
			MouseRightEx(false);
			SendKeyUpEx(KEY_SPACEBAR);
			Sleep(5);
			Hook::enable_vtbale(false);
			MouseLeftEx(false);
			MouseRightEx(false);
		}
		else if (按键方式 == 1)
		{
			Hook::enable_vtbale(true);
			按下键盘(KEY_SPACEBAR);
			Sleep(1);
			左键按下();
			右键按下();
			Sleep(50);
			左键弹起();
			右键弹起();
			弹起键盘(KEY_SPACEBAR);
			Hook::enable_vtbale(false);
		}
	}
	else
	{
		if (按键方式 == 0)
		{
			Hook::enable_vtbale(true);
			SendKeyPressEx(KEY_C);
			Sleep(2);
			MouseLeftEx(true);
			MouseRightEx(true);
			Sleep(50);
			MouseLeftEx(false);
			MouseRightEx(false);
			SendKeyUpEx(KEY_C);
			Sleep(5);
			Hook::enable_vtbale(false);
			MouseLeftEx(false);
			MouseRightEx(false);
		}
		else if (按键方式 == 1)
		{
			Hook::enable_vtbale(true);
			按下键盘(KEY_C);
			Sleep(1);
			左键按下();
			右键按下();
			Sleep(50);
			左键弹起();
			右键弹起();
			弹起键盘(KEY_C);
			Hook::enable_vtbale(false);
		}
	}
}

void 振刀逻辑::WuTianF()
{
	if (按键方式 == 0)
	{
		SendKeyPressEx(KEY_SPACEBAR);
		Sleep(1);
		SendKeyPressEx(KEY_F);
		Sleep(50);
		SendKeyUpEx(KEY_F);
		SendKeyUpEx(KEY_SPACEBAR);
	}
	else if (按键方式 == 1)
	{
		按下键盘(KEY_SPACEBAR);
		Sleep(1);
		按下键盘(KEY_F);
		Sleep(50);
		弹起键盘(KEY_F);
		弹起键盘(KEY_SPACEBAR);
	}
}

void 振刀逻辑::腾云式B()
{
	if (按键方式 == 0)
	{
		MouseRightEx(1);
		Sleep(5);
		MouseRightEx(0);
	}
	else if (按键方式 == 1)
	{
		右键按下();
		Sleep(5);
		右键弹起();
	}
}

