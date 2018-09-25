#include "stdafx.h"
#include "ManaPoints.h"
#include "Jauge.h"

using namespace ZDTGameEngine::CharacterManagement::General;
ManaPoints::ManaPoints(int maxValue) : Jauge("MP", maxValue)
{
}

ManaPoints::ManaPoints(int val, int maxValue) : Jauge("MP",val, maxValue)
{
}

ManaPoints::ManaPoints()
{}



ManaPoints::~ManaPoints()
{
}
