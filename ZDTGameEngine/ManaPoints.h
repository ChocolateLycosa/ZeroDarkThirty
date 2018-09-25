#pragma once
#include "Jauge.h"

namespace ZDTGameEngine::CharacterManagement::General
{
	class ManaPoints : public Jauge
	{
	public:

		ManaPoints(int maxValue);
		ManaPoints(int val, int maxValue);
		ManaPoints();
		~ManaPoints();
	};
}


