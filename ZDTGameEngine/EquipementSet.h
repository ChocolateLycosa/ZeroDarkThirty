#pragma once
#include "MainPrincipale.h"
#include "MainSecondaire.h"
#include "DeuxMains.h"
using namespace ZDTGameEngine::CharacterManagement::Equipement::Offensif;
namespace ZDTGameEngine::CharacterManagement::Equipement
{
	class EquipementSet
	{
	public:
		EquipementSet();
		~EquipementSet();
	private:
		MainPrincipale _MainPrincipale;
		MainSecondaire _MainSecondaire;
	};
}

