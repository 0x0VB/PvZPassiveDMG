#pragma once
#include <Windows.h>

#include "../Enums/SeedType.h"
#include "Rect.h"

class Plant
{
public:
	void* Lawnapp; //0x0000
	class Game* Game; //0x0004
	class Rect Hitbox; //0x0008
	bool Visible; //0x0018
	char pad_0019[3]; //0x0019
	int Lane; //0x001C
	int Layer; //0x0020
	SeedType Type; //0x0024
	int Column; //0x0028
	char pad_002C[20]; //0x002C
	int HP; //0x0040
	int MaxHP; //0x0044
	int SubClass; //0x0048
	int VanishTimer; //0x004C
	int DetonationTimer; //0x0050
	int ArmingTimer; //0x0054
	int ActionTimer; //0x0058
	int MaxActionTimer; //0x005C
	class Rect PlantRect; //0x0060
	class Rect PlantAttackRect; //0x0070
	int TargetX; //0x0080
	int TargetY; //0x0084
	int StartLane; //0x0088
	int ParticleID; //0x008C
	int ShootingTimer; //0x0090
	void* BodyReanim; //0x0094
	void* HeadReanim; //0x0098
	void* HeadReanim2; //0x009C
	void* HeadReanim3; //0x00A0
	void* BlinkReanim; //0x00A4
	void* LightReanim; //0x00A8
	void* SleepingReanim; //0x00AC
	int EyeBlinkTimer; //0x00B0
	int EatenTimer; //0x00B4
	int ShineTimer; //0x00B8
	int BlinkTimer; //0x00BC
	float XOffset; //0x00C0
	float YOffset; //0x00C4
	void* MagnetItems[25]; //0x00C8
	void* TargetZombie; //0x012C
	int WakeupTimer; //0x0130
	int OnBungeeState; //0x0134
	int ImitatedPlantType; //0x0138
	int PottedPlantIndex; //0x013C
	bool AnimPing; //0x0140
	bool PlantDestroyed; //0x0141
	bool Smashed; //0x0142
	bool Asleep; //0x0143
	bool Active; //0x0144
	bool Highlighted; //0x0145
	WORD CustomTimer; //0x0146
	void* PrevPlantDet; //0x0148
}; //Size: 0x014C