#pragma once
#include "MainPrincipale.h"
#include "MainSecondaire.h"
#include "EquipementOffensif.h"
namespace ZDTGameEngine::CharacterManagement::Equipement::Offensif
{
	class DeuxMains : public EquipementOffensif
	{
	public:
		DeuxMains();
		DeuxMains(std::string *name, StatBag *stats, enum WeaponType type);
		DeuxMains(std::string *name, enum WeaponType type);
		~DeuxMains();
		using EquipementOffensif::DefenseMagique;
		using EquipementOffensif::DefensePhysique;
		using EquipementOffensif::DefenseRunique;
		using EquipementOffensif::HitRatio;
		using EquipementOffensif::Intelligence;
		using EquipementOffensif::Name;
		using EquipementOffensif::PuissanceMagique;
		using EquipementOffensif::PuissancePhysique;
		using EquipementOffensif::PuissanceRunique;
		using EquipementOffensif::Vitesse;
	};
}


