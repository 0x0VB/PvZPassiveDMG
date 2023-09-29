#pragma once
#include "../Addresses/FunctionAddresses.h"
#include "../Addresses/ValueAddresses.h"

#include "../Structs/PvZString.h"
#include "../Structs/Object.h"

#include "../Enums/MessageStyle.h"
#include "../Enums/ObjectAnimation.h"
#include "../Enums/CurrencyType.h"

namespace PvZFunctions
{
	void WaveTick()
	{
		__asm
		{
			mov ecx, [ValueAddresses::Game]
			mov ecx, [ecx]
			call FunctionAddresses::WaveTick
		}
	}

	void DisplayAdvice(char* Advice, MessageStyle Style = MESSAGE_STYLE_TUTORIAL_LEVEL2)
	{
		PvZString* Message = new PvZString(Advice);
		__asm
		{
			mov ebx, 1
			mov ecx, Style
			mov edx, Message
			mov edi, [ValueAddresses::Game]
			mov edi, [edi]
			call FunctionAddresses::DisplayAdvice
		}
	}

	Object* SpawnObject(CurrencyType ObjectType, ObjectAnimation Animation, int X, int Y)
	{
		Object* Result;
		__asm
		{
			mov ecx, [ValueAddresses::Game]
			mov ecx, [ecx]
			push Animation
			push ObjectType
			push Y
			push X
			call FunctionAddresses::SpawnObject
			mov Result, eax
		}
		return Result;
	}

	bool NextPlant(Plant** CurrentPlant, Game* Game)
	{
		bool Result;
		__asm
		{
			mov esi, CurrentPlant
			mov edx, Game
			call FunctionAddresses::NextPlant
			mov Result, al
		}
		return Result;
	}
}