#pragma once
#include "DataArray.h"

class Game
{
public:
	char pad_0000[140]; //0x0000
	void* Lawnapp; //0x008C
	char pad_0090[28]; //0x0090
	class DataArray<Plant> Plants; //0x00AC
	char pad_00C8[156]; //0x00C8
	bool Paused; //0x0164
	char pad_0165[21479]; //0x0165
	int World; //0x554C
	int AdventureLevel; //0x5550
	char pad_5554[4]; //0x5554
	int MouseX; //0x5558
	int MouseY; //0x555C
	int Sun; //0x5560
	int Waves; //0x5564
	int GameTime; //0x5568
	int LevelTime; //0x556C
	int FocusTimer; //0x5570
	char pad_5574[8]; //0x5574
	int CurrentWave; //0x557C
	int RefreshedWave; //0x5580
	char pad_5584[36]; //0x5584
};