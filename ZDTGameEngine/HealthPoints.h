#pragma once
#include "Stat.h"

namespace ZDTGameEngine
{
	namespace CharacterManagement
	{
		namespace General
		{
			class HealthPoints : Stat
			{
				public:
					HealthPoints(int val);
					HealthPoints(int val, int max);
					~HealthPoints();
			};

		}
	}
}
	

