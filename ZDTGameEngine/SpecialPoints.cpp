#include "stdafx.h"
#include "SpecialPoints.h"
#include "Jauge.h"

using namespace ZDTGameEngine::CharacterManagement::General;
SpecialPoints::SpecialPoints()
{

}
SpecialPoints::SpecialPoints(int maxVal) : Jauge("SPE", maxVal)
{
}

SpecialPoints::SpecialPoints(int val, int maxVal) : Jauge("SPE", val, maxVal)
{
}


SpecialPoints::~SpecialPoints()
{
}
