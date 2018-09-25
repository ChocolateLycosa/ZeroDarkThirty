#pragma once
#include "Jauge.h"
namespace ZDTGameEngine::CharacterManagement::General
{
	class StaminaPoints : public Jauge
	{
	public:
		StaminaPoints();
		StaminaPoints(int val, int maxVal);
		StaminaPoints(int val);
		~StaminaPoints();
	};
}


