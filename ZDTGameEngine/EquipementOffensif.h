#pragma once
#include "Equipement.h"
#include <string>
namespace ZDTGameEngine::CharacterManagement::Equipement::Offensif
{
	enum class OneHandedType : int
	{
		Sword = 0,
		Wand = 1,
		Dagger = 2,
		Firearm = 3,
		Axe = 4
	};

	enum class TwoHandedType : int
	{
		Spear = 5,
		GreatSword = 6,
		Staff = 7,
		Gauntlets = 8,
		MachineGun = 9
	};

	enum class WeaponType : int
	{
		Sword = 0,
		Wand = 1,
		Dagger = 2,
		Firearm = 3,
		Axe = 4,
		Spear = 5,
		GreatSword = 6,
		Staff = 7,
		Gauntlets = 8,
		MachineGun = 9
	};
	class EquipementOffensif : public Equipement
	{
	public:
		EquipementOffensif();
		EquipementOffensif(std::string *name,StatBag *stats, enum WeaponType type);
		EquipementOffensif(std::string *name, enum WeaponType type);
		~EquipementOffensif();
		enum WeaponType WeaponType();
		void WeaponType(enum WeaponType type);
		bool TwoHanded();
		bool OneHanded();
	protected:
		enum WeaponType _WeaponType;
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

