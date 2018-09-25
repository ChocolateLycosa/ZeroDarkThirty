#pragma once
#include "Jauge.h"
namespace ZDTGameEngine::CharacterManagement::General
{
	class SpecialPoints : public Jauge
	{
	public:
		SpecialPoints();
		SpecialPoints(int val, int maxVal);
		SpecialPoints(int maxVal);
		~SpecialPoints();
	};
}

