#pragma once
#include "HealthPoints.h"
#include "ManaPoints.h"
#include "ExpGauge.h"
#include "SpecialPoints.h"
#include "StaminaPoints.h"
#include "Classe.h"
#include "SkillSet.h"
#include "EquipementSet.h"
using namespace ZDTGameEngine::CharacterManagement::General;
using namespace ZDTGameEngine::CharacterManagement::Equipement;
using namespace ZDTGameEngine::CharacterManagement::Skills::Classes;
using namespace ZDTGameEngine::CharacterManagement::Skills::Util;
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
	EquipementSet *equipement;
	SkillSet *skillSet;

};


