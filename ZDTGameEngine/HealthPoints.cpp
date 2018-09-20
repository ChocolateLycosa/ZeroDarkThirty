#include "stdafx.h"
#include "HealthPoints.h"

using namespace ZDTGameEngine::CharacterManagement::General;
HealthPoints::HealthPoints(int val) : Stat("HP", val)
{
	this->increaseRate = 30;
}

HealthPoints::HealthPoints(int val, int max) : Stat("HP", max)
{
	this->value = val;
}

HealthPoints::HealthPoints()
{
}


HealthPoints::~HealthPoints()
{
}
