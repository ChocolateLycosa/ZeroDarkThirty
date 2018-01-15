#pragma once
#include "HealthPoints.h"


namespace ZDTGameEngine {
	namespace CharacterManagement {
		using namespace General;
		class Character
		{
			public:
				Character();
				~Character();
			protected:
				HealthPoints *hp;
		};



	}
};


