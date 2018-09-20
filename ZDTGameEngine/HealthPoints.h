#pragma once
#include "Stat.h"

namespace ZDTGameEngine::CharacterManagement::General
{
	class HealthPoints : Stat
	{
	public:
		HealthPoints(int val);
		HealthPoints(int val, int max);
		HealthPoints();
		~HealthPoints();
	};
}



