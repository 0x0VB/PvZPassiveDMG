#pragma once
#include <Windows.h>

class PvZString
{
public:
	DWORD Pad0 = 0;// 0x00-0x04
	DWORD Data = 0;// 0x04-0x08
	DWORD Pad1 = 0;// 0x08-0x0C
	DWORD Pad2 = 0;// 0x0C-0x10
	DWORD Pad3 = 0;// 0x10-0x14
	DWORD _Len = 0;// 0x14-0x18
	DWORD Len = -1;// 0x18-0x1C

	PvZString(char* Str)
	{
		_Len = strlen(Str);
		Data = (DWORD)Str;
	}
};