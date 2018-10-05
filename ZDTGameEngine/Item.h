#pragma once
#include <string>
namespace ZDTGameEngine::ItemManagement
{
	class Item
	{
	public:
		Item();
		Item(std::string *name);
		~Item();
		std::string* Name();
		void Name(std::string* name);
	protected:
		std::string* _Name;
	};
}

