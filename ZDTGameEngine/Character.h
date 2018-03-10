#pragma once
#include "HealthPoints.h"
#include "ManaPoints.h"
#include "ExpGauge.h"
#include "SpecialPoints.h"
#include "StaminaPoints.h"
#include "Classe.h"
#include "SkillSet.h"
#include "Equipement.h"


namespace ZDTGameEngine {
	namespace CharacterManagement {
		using namespace General;
		class Character
		{
			public:
				Character();
				~Character();
			protected:
				std::string *name;
				HealthPoints *hp;
				ManaPoints *mp;
				ExpGauge *expGauge;
				SpecialPoints *splp;
				StaminaPoints *stmp;
				Classe	*classe;
				Equipement *equipement;
				SkillSet *skillSet;

		};



	}
};


