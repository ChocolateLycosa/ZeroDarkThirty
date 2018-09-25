#include "stdafx.h"
#include "ExpGauge.h"
#include "Jauge.h"

using namespace ZDTGameEngine::CharacterManagement::General;
ExpGauge::ExpGauge(int max) : Jauge("EXP", max)
{
	this->value = 0;
}
ExpGauge::ExpGauge()
{
}

ExpGauge::ExpGauge(int val, int max): Jauge("EXP", val, max)
{
}


ExpGauge::~ExpGauge()
{
}