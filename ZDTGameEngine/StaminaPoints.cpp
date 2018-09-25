#include "stdafx.h"
#include "StaminaPoints.h"
#include "Jauge.h"

using namespace ZDTGameEngine::CharacterManagement::General;
StaminaPoints::StaminaPoints()
{
}

StaminaPoints::StaminaPoints(int maxVal): Jauge("STM", maxVal)
{
}

StaminaPoints::StaminaPoints(int val, int maxVal) :Jauge("STM", val, maxVal)
{
}


StaminaPoints::~StaminaPoints()
{
}
