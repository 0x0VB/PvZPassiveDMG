#pragma once
#include "Addresses/ValueAddresses.h"
#include "Structs/PlantData.h"
#include "Structs/Plant.h"
#include "Structs/Game.h"
#include "Functions/PvZFunctions.h"
#include "Enums/SeedType.h"

Plant* CPlant;
bool Continue;

// AdventureLevel 25
void DayTick(Plant* Plant)
{
    PlantData* Data = GetPlantData(Plant->Type);
    int SunCost = Data->SunCost;
    int BaseDamage = 30;

    if (Plant->Game->Waves > 10)
    {
        BaseDamage = 25;
    }

    if (Plant->CustomTimer == 0)// First Tick
    {
        if (Plant->Type == Sunflower) { Plant->MaxActionTimer = 2200; Plant->ActionTimer = 500; }
        Plant->CustomTimer = 300 + SunCost;
        return;
    }

    Plant->CustomTimer = max(Plant->CustomTimer - 1, 1);
    if (Plant->CustomTimer == 1)
    {
        Plant->CustomTimer = 300 + SunCost;
        Plant->ShineTimer = 50;
        Plant->HP -= BaseDamage - SunCost / 25;
    }
}

void NightTick(Plant* Plant)
{
    int SunCost = GetPlantData(Plant->Type)->SunCost;
    int BaseDamage = 30;

    if (Plant->Game->Waves > 10)
    {
        BaseDamage = 25;
    }

    if (Plant->CustomTimer == 0)// First Tick
    {
        if (Plant->Game->CurrentWave >= 8 && Plant->Type == SunShroom)
        {
            Plant->ArmingTimer = 2;
            Plant->ActionTimer = 300;
        }

        if (Plant->Type == PuffShroom || Plant->Type == ScaredyShroom)
        {
            Plant->CustomTimer = 100;
        }
        else
        {
            Plant->CustomTimer = 300 + SunCost;
        }
        return;
    }

    Plant->CustomTimer = max(Plant->CustomTimer - 1, 1);
    if (Plant->CustomTimer == 1)
    {
        Plant->ShineTimer = 50;
        if (Plant->Type == PuffShroom || Plant->Type == ScaredyShroom)
        {
            Plant->CustomTimer = 100;
            Plant->HP -= 30;
        }
        else
        {
            Plant->CustomTimer = 300 + SunCost;
            Plant->HP -= BaseDamage - SunCost / 25;
        }
    }
}

void PoolTick(Plant* Plant)
{
    int SunCost = GetPlantData(Plant->Type)->SunCost;
    int BaseDamage = 30;

    if (Plant->Game->Waves > 10)
    {
        BaseDamage = 25;
    }

    if (Plant->CustomTimer == 0)// First Tick
    {
        Plant->CustomTimer = 300 + SunCost;
        if (Plant->Type == Sunflower && (Plant->StartLane == 2 || Plant->StartLane == 3)) {
            Plant->StartLane = 0;
            if (Plant->Game->Waves > 10)
            {
                Plant->ShineTimer = 50;
                PvZFunctions::SpawnObject(SmallSun, PopAndGrow, Plant->Hitbox.X, Plant->Hitbox.Y);
            }
            Plant->MaxActionTimer = 2500 - (Plant->Game->CurrentWave * Plant->Game->Waves);
        }
        return;
    }

    Plant->CustomTimer = max(Plant->CustomTimer - 1, 1);
    if (Plant->CustomTimer <= 1)
    {
        Plant->CustomTimer = 300 + min(200, SunCost);
        Plant->ShineTimer = 50;
        Plant->HP -= BaseDamage - SunCost / 25;
    }
}

void FogTick(Plant* Plant)
{
    int SunCost = GetPlantData(Plant->Type)->SunCost;
    int BaseDamage = 30;

    if (Plant->Game->Waves > 10)
    {
        BaseDamage = 25;
    }

    if (Plant->CustomTimer == 0)// First Tick
    {
        if (Plant->Type == SunShroom)
        {
            CPlant = NULL;
            Continue = PvZFunctions::NextPlant(&CPlant, Plant->Game);
            while (Continue)
            {
                if (CPlant->Type == Plantern && CPlant->Column >= 4)
                {
                    PvZFunctions::SpawnObject(SmallSun, PopAndGrow, Plant->Hitbox.X, Plant->Hitbox.Y);
                    Plant->ShineTimer = 50;
                }
                Continue = PvZFunctions::NextPlant(&CPlant, Plant->Game);
            }
        }

        if (Plant->Type == PuffShroom || Plant->Type == ScaredyShroom)
        {
            Plant->CustomTimer = 100;
        }
        else if (Plant->Type == Plantern)
        {
            Plant->CustomTimer = 600 - Plant->Game->CurrentWave * 12;
        }
        else
        {
            Plant->CustomTimer = 300 + SunCost;
        }
        return;
    }

    Plant->CustomTimer = max(Plant->CustomTimer - 1, 1);
    if (Plant->CustomTimer == 1)
    {
        Plant->ShineTimer = 50;
        if (Plant->Type == PuffShroom || Plant->Type == ScaredyShroom)
        {
            Plant->CustomTimer = 100;
            Plant->HP -= 30;
        }
        else if (Plant->Type == Plantern)
        {
            Plant->CustomTimer = 600 - Plant->Game->CurrentWave * 12;
            Plant->HP -= BaseDamage - 1;
        }
        else
        {
            Plant->CustomTimer = 300 + SunCost;
            Plant->HP -= BaseDamage - SunCost / 25;
        }
    }
}

void RoofTick(Plant* Plant)
{
    int SunCost = GetPlantData(Plant->Type)->SunCost;
    int BaseDamage = 30;

    if (Plant->Game->Waves > 10)
    {
        BaseDamage = 25;
    }

    if (Plant->Type == FlowerPot) SunCost = 125;

    if (Plant->CustomTimer == 0)// First Tick
    {
        if (Plant->Type == Sunflower)
        {
            Plant->MaxActionTimer = 2500 - Plant->Game->CurrentWave * Plant->Game->Waves;
            if (Plant->Game->CurrentWave >= 10) Plant->ActionTimer = 200;
        }
        if (Plant->Type == TwinSunflower)
        {
            Plant->MaxActionTimer = 2250 - Plant->Game->CurrentWave * Plant->Game->Waves;
            Plant->ActionTimer = 300;
        }
        Plant->CustomTimer = 300 + SunCost;
        return;
    }

    Plant->CustomTimer = max(Plant->CustomTimer - 1, 1);
    if (Plant->CustomTimer <= 1)
    {
        Plant->CustomTimer = 300 + SunCost;
        Plant->ShineTimer = 50;
        Plant->HP -= BaseDamage - SunCost / 25;
    }
}

void NightRoofTick(Plant* Plant)
{
    PlantData* Data = GetPlantData(Plant->Type);
    int SunCost = Data->SunCost;
    int BaseDamage = 30;

    if (Plant->CustomTimer == 0)// First Tick
    {
        Plant->CustomTimer = 300 + SunCost;
        return;
    }

    Plant->CustomTimer = max(Plant->CustomTimer - 1, 1);
    if (Plant->CustomTimer == 1)
    {
        Plant->CustomTimer = 300 + SunCost;
        Plant->ShineTimer = 50;
        Plant->HP -= BaseDamage - SunCost / 25;
    }
}
