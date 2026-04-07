#pragma once
#define _WINSOCKAPI_
#include <iostream>
#include <windows.h>
#include <vector>
#include <shared_mutex>
#include <array>
#include <Shlwapi.h>
#include <regex>
#include <iostream>
#include <iomanip>
#include "kmboxNet.h"
#include "vmmdll.h"
#include "Memory/memory.h"
#include "Offset.h"
#include "HidTable.h"
#include "OS-ImGui/OS-ImGui.h"
#pragma comment(lib, "vmm.lib")
#pragma comment(lib, "Shlwapi.lib")
#pragma comment(lib,"ws2_32.lib")

using namespace std;
