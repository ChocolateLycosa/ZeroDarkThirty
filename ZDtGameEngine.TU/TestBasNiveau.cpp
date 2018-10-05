#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "../ZDTGameEngine/Jauge.h"
#include "../ZDTGameEngine/HealthPoints.h"
#include "../ZDTGameEngine/ManaPoints.h"
#include "../ZDTGameEngine/ExpGauge.h"
#include "../ZDTGameEngine/SpecialPoints.h"
#include "../ZDTGameEngine/StaminaPoints.h"
#include "../ZDTGameEngine/StatBag.h"
#include "../ZDTGameEngine/Equipement.h"
#include "../ZDTGameEngine/EquipementSet.h"
#include "../ZDTGameEngine/MainPrincipale.h"
#include "../ZDTGameEngine/MainSecondaire.h"
#include "../ZDTGameEngine/DeuxMains.h"
#include "../ZDTGameEngine/EquipementDefensif.h"
#include "../ZDTGameEngine/EquipementOffensif.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ZDTGameEngine::CharacterManagement::General;
using namespace ZDTGameEngine::CharacterManagement::Equipement;
using namespace ZDTGameEngine::CharacterManagement::Equipement::Offensif;
using namespace ZDTGameEngine::CharacterManagement::Equipement::Defensif;
namespace TestBasNiveau
{
	TEST_CLASS(TestJauges)
	{
	public:

		TEST_METHOD(TestJaugePV)
		{
			HealthPoints *hp = new HealthPoints(50, 100);
			Assert::IsTrue(100 == hp->GetMaxValue());
			Assert::IsTrue(50 == hp->GetValue());
			delete hp;
			hp = new HealthPoints(100);
			Assert::IsTrue(100 == hp->GetMaxValue());
			Assert::IsTrue(100 == hp->GetValue());
			delete hp;
		}

		TEST_METHOD(TestJaugePM)
		{
			ManaPoints *mp = new ManaPoints(30, 100);
			Assert::IsTrue(100 == mp->GetMaxValue());
			Assert::IsTrue(30 == mp->GetValue());
			delete mp;
			mp = new ManaPoints(100);
			Assert::IsTrue(100 == mp->GetMaxValue());
			Assert::IsTrue(100 == mp->GetValue());
			delete mp;
		}
		TEST_METHOD(TestJaugeEXP)
		{
			ExpGauge *exp = new ExpGauge(44, 100);
			Assert::IsTrue(100 == exp->GetMaxValue());
			Assert::IsTrue(44 == exp->GetValue());
			delete exp;
			exp = new ExpGauge(100);
			Assert::IsTrue(100 == exp->GetMaxValue());
			Assert::IsTrue(0 == exp->GetValue());
			delete exp;
		}

		TEST_METHOD(TestJaugeSpecial)
		{
			SpecialPoints *spe = new SpecialPoints(80, 100);
			Assert::IsTrue(100 == spe->GetMaxValue());
			Assert::IsTrue(80 == spe->GetValue());
			delete spe;
			spe = new SpecialPoints(100);
			Assert::IsTrue(100 == spe->GetMaxValue());
			Assert::IsTrue(100 == spe->GetValue());
			delete spe;
		}

		TEST_METHOD(TestJaugeStamina)
		{
			StaminaPoints *sta = new StaminaPoints(70, 100);
			Assert::IsTrue(100 == sta->GetMaxValue());
			Assert::IsTrue(70 == sta->GetValue());
			delete sta;
			sta = new StaminaPoints(100);
			Assert::IsTrue(100 == sta->GetMaxValue());
			Assert::IsTrue(100 == sta->GetValue());
			delete sta;
		}

	};

	TEST_CLASS(TestStats)
	{
	public:
		TEST_METHOD(TestStatSack)
		{
			StatBag *stats = new StatBag();
			stats->DefenseMagique(30);
			stats->DefensePhysique(70);
			Assert::IsTrue(30 == stats->DefenseMagique());
			Assert::IsTrue(70 == stats->DefensePhysique());
			delete stats;

		}
	};

	TEST_CLASS(TestEquipement)
	{
	public:
		TEST_METHOD(TestOffensif)
		{
			std::string *nomEpee = new std::string("Samihadara");
			std::string *nomFlingue = new std::string("Falchion");
			std::string *nomLance = new std::string("Gungnir");
			MainPrincipale *epee = new MainPrincipale(nomEpee,WeaponType::Sword);
			epee->HitRatio(1.74);
			epee->PuissanceMagique(24);
			epee->PuissancePhysique(213);
			epee->PuissanceRunique(139);			
			MainSecondaire *flingue = new MainSecondaire(nomFlingue,  WeaponType::Firearm);
			flingue->HitRatio(2.93);
			flingue->PuissanceMagique(0);
			flingue->PuissancePhysique(500);
			flingue->PuissanceRunique(0);
			DeuxMains *lance = new DeuxMains(nomLance, WeaponType::Spear);
			lance->HitRatio(1.31);
			lance->PuissanceMagique(200);
			lance->PuissancePhysique(312);
			lance->PuissanceRunique(0);
			Assert::IsTrue(epee->Name()->compare("Samihadara") == 0);
			Assert::IsTrue(epee->HitRatio() == 1.74);
			Assert::IsTrue(epee->PuissanceMagique() == 24);
			Assert::IsTrue(epee->PuissanceRunique() == 139);
			Assert::IsTrue(epee->PuissancePhysique() == 213);
			Assert::IsTrue(flingue->Name()->compare("Falchion") == 0);
			Assert::IsTrue(flingue->HitRatio() == 2.93);
			Assert::IsTrue(flingue->PuissanceMagique() == 0);
			Assert::IsTrue(flingue->PuissanceRunique() == 0);
			Assert::IsTrue(flingue->PuissancePhysique() == 500);
			Assert::IsTrue(lance->Name()->compare("Gungnir") == 0);
			Assert::IsTrue(lance->HitRatio() == 1.31);
			Assert::IsTrue(lance->PuissanceMagique() == 200);
			Assert::IsTrue(lance->PuissanceRunique() == 0);
			Assert::IsTrue(lance->PuissancePhysique() == 312);
			delete epee;
			delete flingue;
			delete lance;			
		}

		TEST_METHOD(TestDefensif)
		{

		}

		TEST_METHOD(TestEquipementSet)
		{
			EquipementSet *equipementSet = new EquipementSet();
			delete equipementSet;
		}
	};
}