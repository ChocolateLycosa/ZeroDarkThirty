#pragma once
#include "Jauge.h"

namespace ZDTGameEngine::CharacterManagement::General
{
	class HealthPoints : public Jauge
	{
	public:
		HealthPoints(int val);
		HealthPoints(int val, int max);
		HealthPoints();
		~HealthPoints();
	};
}



