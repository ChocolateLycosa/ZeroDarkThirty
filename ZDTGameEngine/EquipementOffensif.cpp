#include "stdafx.h"
#include "EquipementOffensif.h"

using namespace ZDTGameEngine::CharacterManagement::Equipement::Offensif;

EquipementOffensif::EquipementOffensif()
{
}

EquipementOffensif::EquipementOffensif(std::string * name, StatBag * stats, enum WeaponType type) : Equipement(name, stats)
{
	this->_WeaponType = type;
}

EquipementOffensif::EquipementOffensif(std::string * name, enum WeaponType type) : EquipementOffensif(name, new StatBag(), type)
{
}


EquipementOffensif::~EquipementOffensif()
{
}

enum WeaponType EquipementOffensif::WeaponType()
{
	return this->_WeaponType;
}

void EquipementOffensif::WeaponType(enum WeaponType type)
{
	this->_WeaponType = type;
}

bool EquipementOffensif::TwoHanded()
{
	if ((((int)this->_WeaponType) >= 5) &&
		(((int)this->_WeaponType) < 10))
	{
		return true;
	}
	else
		return false;
}

bool EquipementOffensif::OneHanded()
{
	if ((((int)this->_WeaponType) >= 0) &&
		(((int)this->_WeaponType) < 5))
	{
		return true;
	}
	else
		return false;
}
