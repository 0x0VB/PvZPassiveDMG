#pragma once
#include "Plant.h"

template <class Type>
class DataArray
{
public:
	Type* DataArray; //0x0000
	int HighestUsedCount; //0x0004
	int MaxSize; //0x0008
	int NextIndex; //0x000C
	int Count; //0x0010
	int NextKeyDet; //0x0014
	char* Name; //0x0018
}; //Size: 0x001C