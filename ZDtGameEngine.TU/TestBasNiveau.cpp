#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ZDTGameEngine/Jauge.h"
#include "../ZDTGameEngine/HealthPoints.h"
#include "../ZDTGameEngine/ManaPoints.h"
#include "../ZDTGameEngine/ExpGauge.h"
#include "../ZDTGameEngine/SpecialPoints.h"
#include "../ZDTGameEngine/StaminaPoints.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ZDTGameEngine::CharacterManagement::General;
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
			ExpGauge *exp = new ExpGauge(44,100);
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
		
	};
}