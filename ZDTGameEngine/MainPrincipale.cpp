#include "stdafx.h"
#include "MainPrincipale.h"
#include <string>

using namespace ZDTGameEngine::CharacterManagement::Equipement::Offensif;
MainPrincipale::MainPrincipale()
{
}

MainPrincipale::MainPrincipale(std::string *name, StatBag *stats, enum WeaponType type) : EquipementOffensif(name, stats, type)
{

}

MainPrincipale::MainPrincipale(std::string *name, enum WeaponType type) : EquipementOffensif(name, type)
{

}


MainPrincipale::~MainPrincipale()
{
}
