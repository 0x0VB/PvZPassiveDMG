// dllmain.cpp : Defines the entry point for the DLL application.
#include <string>
#include <cmath>

#include "pch.h"
#include "WorldTicks.h"
#include "Enums/SceneType.h"
#include "Addresses/HookAddresses.h"
#include "Addresses/FunctionAddresses.h"

Plant* CurrentPlant;
Plant* Underplants[60];

void PassiveDamageTick()
{
    if (CurrentPlant->Type == LilyPad || CurrentPlant->Type == FlowerPot)
    {
        Underplants[CurrentPlant->Lane * 10 + CurrentPlant->Column] = CurrentPlant;
    }
    else
    {
        Plant* Underplant = Underplants[CurrentPlant->Lane * 10 + CurrentPlant->Column];
        if (Underplant != NULL && Underplant->Game == CurrentPlant->Game)
        {
            Underplant->HP = Underplant->MaxHP;
            Underplant->CustomTimer = 0;
        }
    }

    switch (CurrentPlant->Game->World)
    {
    case Day:
        DayTick(CurrentPlant);
        break;
    case Night:
        NightTick(CurrentPlant);
        break;
    case Pool:
        PoolTick(CurrentPlant);
        break;
    case Fog:
        FogTick(CurrentPlant);
        break;
    case Roof:
        RoofTick(CurrentPlant);
        break;
    case NightRoof:
        NightRoofTick(CurrentPlant);
        break;
    }
}

void __declspec(naked) ModTick()
{
    __asm
    {
        mov CurrentPlant, eax
        call PassiveDamageTick
        mov eax, CurrentPlant
        call FunctionAddresses::PlantTick
        jmp HookAddresses::PostPlantTick
    }
}

HMODULE Handle;
DWORD WINAPI ModThread(LPVOID Param)
{
    CreateHook(PlantTick, ModTick);
    while (TRUE)
    {
        Sleep(1000);
        Game* CGame = *CurrentGame;
        if (CGame == NULL) continue;
        if (CGame->AdventureLevel != 25) continue;
        if (CGame->Paused) continue;
        if (CGame->GameTime < 5) continue;
        break;
    }
    const char* Advice = "You unlocked the shop!\nYou now have infinite money!";
    PvZFunctions::DisplayAdvice((char*)Advice);
    Sleep(250);

    for (int _ = 0; _ < 1e3; _++)
    {
        Object* Cirno = PvZFunctions::SpawnObject(Diamond, Static, 400, 300);
        Cirno->BeingCollected = true;
        Sleep(2);
    }
    return TRUE;
}

BOOL APIENTRY DllMain(
    HMODULE HMod,
    DWORD  Reason,
    LPVOID Reserved
)
{
    if (Reason != DLL_PROCESS_ATTACH) return FALSE;

    Handle = HMod;
    CreateThread(NULL, 0, ModThread, &Handle, 0, NULL);
    return TRUE;
}