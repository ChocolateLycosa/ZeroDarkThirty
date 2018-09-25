#pragma once
#include "Jauge.h"
namespace ZDTGameEngine::CharacterManagement::General
{
	class ExpGauge : public Jauge
	{
	public:
		ExpGauge(int max);
		ExpGauge(int val, int max);
		ExpGauge();
		~ExpGauge();
	};
}
