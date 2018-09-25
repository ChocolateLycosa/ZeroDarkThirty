#include "stdafx.h"
#include "HealthPoints.h"

using namespace ZDTGameEngine::CharacterManagement::General;
HealthPoints::HealthPoints(int val) : Jauge("HP", val)
{
}

HealthPoints::HealthPoints(int val, int max) : Jauge("HP", max)
{
	this->value = val;
}

HealthPoints::HealthPoints()
{
}


HealthPoints::~HealthPoints()
{
}