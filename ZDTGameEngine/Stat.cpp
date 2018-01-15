#include "stdafx.h"
#include "Stat.h"

using namespace ZDTGameEngine::CharacterManagement::General;


Stat::Stat()
{
	this->valueName = NULL;
}

Stat::Stat(const char *valueName)
{
	this->valueName = new std::string(valueName);
}



Stat::Stat(const char *valueName, int maxValue)
{
	this->valueName = (std::string *)strdup(valueName);
	this->maxValue = maxValue;
	this->value = maxValue;
}


Stat::~Stat()
{
	delete this->valueName;
}

int Stat::GetValue()
{
	return this->value;
}
void Stat::SetValue(int value)
{
	this->value = value;
}
int Stat::GetMaxValue()
{
	return  this->maxValue;
}
void Stat::SetMaxValue(int value)
{
	this->maxValue = value;
}

std::string * Stat::GetValueName()
{
	return this->valueName;
}
void Stat::SetValueName(std::string * valueName)
{
	this->valueName->erase();
	this->valueName->assign((char *)valueName);
}

