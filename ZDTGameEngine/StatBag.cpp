#include "stdafx.h"
#include "StatBag.h"


StatBag::StatBag()
{
	this->_DefenseMagique = 0;
	this->_DefensePhysique = 0;
	this->_DefenseRunique = 0;
	this->_HitRatio = 0;
	this->_Intelligence = 0;
	this->_PuissanceMagique = 0;
	this->_PuissancePhysique = 0;
	this->_PuissanceRunique = 0;
	this->_Vitesse = 0;
}


StatBag::~StatBag()
{
}

int StatBag::PuissancePhysique()
{
	return this->_PuissancePhysique;
}

int StatBag::PuissanceMagique()
{
	return this->_PuissanceMagique;
}

int StatBag::PuissanceRunique()
{
	return this->_PuissanceRunique;
}

int StatBag::DefensePhysique()
{
	return this->_DefensePhysique;
}

int StatBag::DefenseMagique()
{
	return this->_DefenseMagique;
}

int StatBag::DefenseRunique()
{
	return this->_DefenseRunique;
}

int StatBag::Vitesse()
{
	return this->_Vitesse;
}

int StatBag::Intelligence()
{
	return this->_Intelligence;
}

int StatBag::HitRatio()
{
	return this->_HitRatio;
}

void StatBag::PuissancePhysique(int val)
{
	this->_PuissancePhysique = val;
}

void StatBag::PuissanceMagique(int val)
{
	this->_PuissanceMagique = val;
}

void StatBag::PuissanceRunique(int val)
{
	this->_PuissanceRunique = val;
}

void StatBag::DefensePhysique(int val)
{
	this->_DefensePhysique = val;
}

void StatBag::DefenseMagique(int val)
{
	this->_DefenseMagique = val;
}

void StatBag::DefenseRunique(int val)
{
	this->_DefenseRunique = val;
}

void StatBag::Vitesse(int val)
{
	this->_Vitesse = val;
}

void StatBag::Intelligence(int val)
{
	this->_Intelligence = val;
}

void StatBag::HitRatio(int val)
{
	this->_HitRatio = val;
}
