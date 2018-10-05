#include "stdafx.h"
#include "MainSecondaire.h"
#include "EquipementOffensif.h"
using namespace ZDTGameEngine::CharacterManagement::Equipement::Offensif;

MainSecondaire::MainSecondaire()
{
}

MainSecondaire::MainSecondaire(std::string * name, StatBag * stats, enum WeaponType type) : EquipementOffensif(name, stats, type)
{
}

MainSecondaire::MainSecondaire(std::string * name, enum WeaponType type) : EquipementOffensif(name, type)
{
}


MainSecondaire::~MainSecondaire()
{
}
