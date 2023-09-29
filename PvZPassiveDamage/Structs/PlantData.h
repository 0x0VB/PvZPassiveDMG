#pragma once
#include "../Addresses/ValueAddresses.h"
#include "../Enums/SeedType.h"

class PlantData
{
public:
	SeedType Type; //0x0000
	char pad_0004[4]; //0x0004
	int Sprite; //0x0008
	char pad_000C[4]; //0x000C
	int SunCost; //0x0010
	int Recharge; //0x0014
	int SubClass; //0x0018
	int MaxShotTimer; //0x001C
	char* PlantIdentifier; //0x0020
}; //Size: 0x0024

PlantData* GetPlantData(SeedType Type)
{
	PlantData* Data = (PlantData*)ValueAddresses::PlantData;
	return Data + Type;
}
