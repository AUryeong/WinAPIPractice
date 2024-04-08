#ifndef PCH_H
#define PCH_H

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.

#define ASSERT(condition) \
if (!condition) \
{ \
    DebugBreak(); \
} \

#define SAFE_DELETE(ptr) \
ASSERT(ptr); \
{ \
    delete ptr; \
    ptr = nullptr; \
}

// lib link
#pragma comment(lib, "msimg32")

// win32 api
#include <Windows.h>
#include <mmsystem.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <string>
#include <unordered_map>
#include <limits>
#include <cstring>
#include <vector>

using std::vector;
using std::unordered_map;
using std::pair;
using std::make_pair;
using std::string;
using std::wstring;

#include "resource.h"
#include "Singleton.h"
#include "Vector2.h"

#endif