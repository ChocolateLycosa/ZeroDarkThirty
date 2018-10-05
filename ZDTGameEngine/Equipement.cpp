#include "stdafx.h"
#include "Equipement.h"

using namespace ZDTGameEngine::CharacterManagement::Equipement;
Equipement::Equipement()
{
}

Equipement::Equipement(std::string *name, StatBag *stats) : Item(name)
{
	this->_Stats = stats;
}

Equipement::Equipement(std::string * name) : Item(name)
{
	this->_Stats = new StatBag();
}


Equipement::~Equipement()
{
	delete this->_Stats;
}

StatBag *Equipement::Stats()
{
	return this->_Stats;
}

void Equipement::Stats(StatBag *stats)
{
	this->_Stats = stats;
}

int Equipement::PuissancePhysique()
{
	return this->_Stats->PuissancePhysique();
}

int Equipement::PuissanceMagique()
{
	return this->_Stats->PuissanceMagique();
}

int Equipement::PuissanceRunique()
{
	return this->_Stats->PuissanceRunique();
}

int Equipement::DefensePhysique()
{
	return this->_Stats->DefensePhysique();
}

int Equipement::DefenseMagique()
{
	return this->_Stats->DefenseMagique();
}

int Equipement::DefenseRunique()
{
	return this->_Stats->DefenseRunique();
}

int Equipement::Vitesse()
{
	return this->_Stats->Vitesse();
}

int Equipement::Intelligence()
{
	return this->_Stats->Intelligence();
}

double Equipement::HitRatio()
{
	return this->_Stats->HitRatio();
}

void Equipement::PuissancePhysique(int val)
{
	this->_Stats->PuissancePhysique(val);
}

void Equipement::PuissanceMagique(int val)
{
	this->_Stats->PuissanceMagique(val);
}

void Equipement::PuissanceRunique(int val)
{
	this->_Stats->PuissanceRunique(val);
}

void Equipement::DefensePhysique(int val)
{
	this->_Stats->DefensePhysique(val);
}

void Equipement::DefenseMagique(int val)
{
	this->_Stats->DefenseMagique(val);
}

void Equipement::DefenseRunique(int val)
{
	this->_Stats->DefenseRunique(val);
}

void Equipement::Vitesse(int val)
{
	this->_Stats->Vitesse(val);
}

void Equipement::Intelligence(int val)
{
	this->_Stats->Intelligence(val);
}

void Equipement::HitRatio(double val)
{
	this->_Stats->HitRatio(val);
}
