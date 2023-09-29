#pragma once
#include "../Structs/Game.h"

namespace ValueAddresses
{
	const DWORD LawnApp = 0x19FC94;
	const DWORD Game = 0x19984C;
	const DWORD PlantData = 0x69F2B0;
}

Game** CurrentGame = (Game**)ValueAddresses::Game;