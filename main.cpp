#include"pak.h"
#include "Thread.h"
#include "SPVerify.h"
#include "VMProtectSDK.h"
#include <atltime.h>
#include "AntiDebug.h"
#include <fstream>
#include <sstream>
#define DISABLE_QUICK_EDIT_MODE 0x01
#define DISABLE_INSERT_MODE 0x02
#define DISABLE_MOUSE_INPUT 0x03 
#define DISABLE_ALL (DISABLE_QUICK_EDIT_MODE | DISABLE_INSERT_MODE | DISABLE_MOUSE_INPUT)
VOID CloseConsoleMode(UINT uTag = DISABLE_QUICK_EDIT_MODE)
{	//通用函数
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	if (uTag & DISABLE_QUICK_EDIT_MODE)
		mode &= ~ENABLE_QUICK_EDIT_MODE;  //移除快速编辑模式
	if (uTag & DISABLE_INSERT_MODE)
		mode &= ~ENABLE_INSERT_MODE;      //移除插入模式
	if (uTag & DISABLE_MOUSE_INPUT)
		mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin, mode);
	return;
}
VOID CloseConsoleQuickEditMode(VOID)
{	//关闭快速编辑模式,这个很好用
	CloseConsoleMode(DISABLE_QUICK_EDIT_MODE);
}
VOID CloseConsoleInsertMode(VOID)
{	//关闭插入模式？我也不是很懂
	CloseConsoleMode(DISABLE_INSERT_MODE);
}
VOID CloseConsoleMouseInput(VOID)
{	//关闭鼠标输入？我也不是很懂
	CloseConsoleMode(DISABLE_MOUSE_INPUT);
}

std::string g_Card;
__int64 iExpiredTimeStamp;
void SP_TimeStamp2SystemTime1(__int64 ts, SYSTEMTIME& st) {
	__int64 tmpTs = (ts + 8 * 60 * 60) * 10000000i64 + 116444736000000000i64;
	FILETIME ft;

	ft.dwLowDateTime = (DWORD)tmpTs;
	ft.dwHighDateTime = tmpTs >> 32;
	FileTimeToSystemTime(&ft, &st);
}
__int64 TimeDiff(SYSTEMTIME t1, SYSTEMTIME t2)
{
	CTimeSpan			sp;
	int					s1, s2;

	CTime tm1(t1.wYear, t1.wMonth, t1.wDay, 0, 0, 0);
	CTime tm2(t2.wYear, t2.wMonth, t2.wDay, 0, 0, 0);

	sp = tm1 - tm2;

	s1 = t1.wHour * 3600 + t1.wMinute * 60 + t1.wSecond;
	s2 = t2.wHour * 3600 + t2.wMinute * 60 + t2.wSecond;

	return  sp.GetDays() * 86400 + (s1 - s2);
}


void DataRefresh()
{
	while (true)
	{
		Memory::RefreshConfigSet();
		Sleep(1000);
	}
}
BOOL GetModuleStatus()
{
    DmaData::vmm_handle = Memory::DMA_Initialize();
    if (DmaData::vmm_handle != 0)
    {
		thread(DataRefresh).detach();//刷新缓存
        printf("[+] Dma初始化成功\n");
        DmaData::hS = Memory::scatterInit();
        DmaData::hS1 = Memory::scatterInit();
        do {
            Sleep(100);
            DmaData::Hwnd = FindWindowA("Progman", "Program Manager");
            if (DmaData::Hwnd) {

                printf("[+] 请进入游戏以待读取数据 \n");
                break;
            }
        } while (!DmaData::Hwnd);
        do {
            Sleep(100);
			Memory::RefreshConfigSetALL();
			DmaData::PID = Memory::get_process_id("NarakaBladepoint.exe");;
            if (DmaData::PID) {
                printf("[+] PID = %d\n", DmaData::PID);
                break;
            }
        } while (!DmaData::PID);
        do {
            Sleep(100);
            Offset::GameAssembly = Memory::get_module_handle(DmaData::vmm_handle, DmaData::PID, "GameAssembly_Super.dll");;
            if (Offset::GameAssembly) {
               // printf("[+] GameAddrBase = %llx\n", Offset::GameAssembly);
                break;
            }
        } while (!Offset::GameAssembly);

        if (Offset::GameAssembly)
        {
            printf("[+] 数据读取成功执行渲染 \n");
            //ShowWindow(FindWindowA("ConsoleWindowClass", NULL), HIDE_WINDOW);
            return true;
        }
    }
    else
    {
        printf("[+] Dma初始化失败\n");
        return false;
    }

}

int main()
{
	VMProtectBegin("main");
	CloseConsoleQuickEditMode();
	CloseConsoleInsertMode();
	CloseConsoleMouseInput();

	//执行代码
	if (GetModuleStatus())
	{
		Thread();
		//WaitForSingleObject(hThread, -1);
	}



    return getchar();

	VMProtectEnd();
}