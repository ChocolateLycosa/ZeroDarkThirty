#pragma once
#include "HealthPoints.h"
#include "ManaPoints.h"
#include "ExpGauge.h"
#include "SpecialPoints.h"
#include "StaminaPoints.h"
#include "Classe.h"
#include "SkillSet.h"
#include "Equipement.h"
using namespace ZDTGameEngine::CharacterManagement::General;
using ZDTGameEngine::CharacterManagement::Skills::Classes::Classe;
using ZDTGameEngine::CharacterManagement::Equip::Equipement;
using ZDTGameEngine::CharacterManagement::Skills::Util::SkillSet;
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


