#include "stdafx.h"
#include "Jauge.h"
#include <string>
using namespace ZDTGameEngine::CharacterManagement::General;


Jauge::Jauge()
{
	this->valueName = NULL;
}

Jauge::Jauge(std::string valueName)
{
	this->valueName = new std::string(valueName);
	this->value = 0;
	this->maxValue = 0;
}



Jauge::Jauge(std::string valueName, int maxValue)
{
	this->valueName = new std::string(valueName);
	this->maxValue = maxValue;
	this->value = maxValue;
}

Jauge::Jauge(std::string valueName, int val, int maxValue)
{
	this->valueName = new std::string(valueName);
	this->maxValue = maxValue;
	this->value = val;
}


Jauge::~Jauge()
{
	delete this->valueName;
}

int Jauge::GetValue()
{
	return this->value;
}
void Jauge::SetValue(int value)
{
	this->value = value;
}
int Jauge::GetMaxValue()
{
	return  this->maxValue;
}
void Jauge::SetMaxValue(int value)
{
	this->maxValue = value;
}

std::string * Jauge::GetValueName()
{
	return this->valueName;
}
void Jauge::SetValueName(std::string *valueName)
{
	delete this->valueName;
	this->valueName = new std::string(valueName->data());
}
