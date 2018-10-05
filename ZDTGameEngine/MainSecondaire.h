#pragma once
#include "EquipementOffensif.h"
namespace ZDTGameEngine::CharacterManagement::Equipement::Offensif
{
	class MainSecondaire : public EquipementOffensif
	{
	public:
		MainSecondaire();
		MainSecondaire(std::string *name, StatBag *stats, enum WeaponType type);
		MainSecondaire(std::string *name, enum WeaponType type);
		~MainSecondaire();
		using Equipement::DefenseMagique;
		using Equipement::DefensePhysique;
		using Equipement::DefenseRunique;
		using Equipement::HitRatio;
		using Equipement::Intelligence;
		using Equipement::Name;
		using Equipement::PuissanceMagique;
		using Equipement::PuissancePhysique;
		using Equipement::PuissanceRunique;
		using Equipement::Vitesse;		
	};
}

