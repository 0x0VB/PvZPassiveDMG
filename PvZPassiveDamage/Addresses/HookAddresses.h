#pragma once
#include <Windows.h>
namespace HookAddresses
{
	const DWORD PreWaveTick = 0x0041601E;
	const DWORD PostWaveTick = 0x00416023;

	const DWORD PrePlantTick = 0x004130f4;
	const DWORD PostPlantTick = 0x004130f9;
}

enum HookPoint
{
	WaveTick,

	PlantSpawn,
	PlantTick,
	PlantRender,

	ZombieSpawn,
	ZombieTick,
	ZombieRender
};

void CreateHook(HookPoint Point, void* Func)
{
	DWORD RelativeAddress, Old, _;
	switch (Point)
	{
	case WaveTick:
		// Hooking LevelTick
		VirtualProtect((LPVOID)HookAddresses::PreWaveTick, 5, PAGE_EXECUTE_READWRITE, &Old);

		*(BYTE*)HookAddresses::PreWaveTick = 0xE9;
		RelativeAddress = (DWORD)Func - (DWORD)HookAddresses::PreWaveTick - 0x5;
		*(DWORD*)((DWORD)HookAddresses::PreWaveTick + 1) = RelativeAddress;

		// Restore Permissions
		VirtualProtect((LPVOID)HookAddresses::PrePlantTick, 5, Old, &_);
		break;
	case PlantTick:
		// Hooking PlantTick
		VirtualProtect((LPVOID)HookAddresses::PrePlantTick, 5, PAGE_EXECUTE_READWRITE, &Old);

		*(BYTE*)HookAddresses::PrePlantTick = 0xE9;
		RelativeAddress = (DWORD)Func - (DWORD)HookAddresses::PrePlantTick - 0x5;
		*(DWORD*)((DWORD)HookAddresses::PrePlantTick + 1) = RelativeAddress;

		// Restore Permissions
		VirtualProtect((LPVOID)HookAddresses::PrePlantTick, 5, Old, &_);
		break;
	}
}