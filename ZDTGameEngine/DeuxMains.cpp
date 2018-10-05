#include "stdafx.h"
#include "DeuxMains.h"
#include "EquipementOffensif.h"

using namespace ZDTGameEngine::CharacterManagement::Equipement::Offensif;
DeuxMains::DeuxMains()
{
}

DeuxMains::DeuxMains(std::string * name, StatBag * stats, enum WeaponType type) : EquipementOffensif(name, stats, type)
{
}


DeuxMains::DeuxMains(std::string * name, enum WeaponType type) : EquipementOffensif(name, type)
{
}

DeuxMains::~DeuxMains()
{
}
