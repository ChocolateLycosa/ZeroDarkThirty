#pragma once
#include "EquipementOffensif.h"
#include "Equipement.h"
#include <string>
namespace ZDTGameEngine::CharacterManagement::Equipement::Offensif
{
	class MainPrincipale : public EquipementOffensif
	{
	public:
		MainPrincipale();
		MainPrincipale(std::string *name, StatBag *stats, enum WeaponType type);
		MainPrincipale(std::string *name, enum WeaponType type);
		~MainPrincipale();
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

