#include "stdafx.h"
#include "Item.h"

using namespace ZDTGameEngine::ItemManagement;
Item::Item()
{
}

Item::Item(std::string *name)
{
	this->_Name = new std::string(*name);
}

Item::~Item()
{
	delete this->_Name;
}

std::string* Item::Name()
{
	return this->_Name;
}

void Item::Name(std::string* name)
{
	this->_Name = name;
}
