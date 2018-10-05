#pragma once
#include "Item.h"
#include "StatBag.h"
#include <string>
using namespace ZDTGameEngine::ItemManagement;
namespace ZDTGameEngine::CharacterManagement::Equipement
{
	class Equipement : Item
	{
	public:
		Equipement();
		Equipement(std::string *name, StatBag *stats);
		Equipement(std::string *name);
		~Equipement();		
	protected:
		StatBag *_Stats;
		StatBag *Stats();
		void Stats(StatBag *stats);
		int PuissancePhysique();
		int PuissanceMagique();
		int PuissanceRunique();
		int DefensePhysique();
		int DefenseMagique();
		int DefenseRunique();
		int Vitesse();
		int Intelligence();
		double HitRatio();
		void PuissancePhysique(int val);
		void PuissanceMagique(int val);
		void PuissanceRunique(int val);
		void DefensePhysique(int val);
		void DefenseMagique(int val);
		void DefenseRunique(int val);
		void Vitesse(int val);
		void Intelligence(int val);
		void HitRatio(double val);
		using Item::Name;
	};
}
