#pragma once
#include <iostream>
#include <string>
namespace ZDTGameEngine::CharacterManagement::General
{
	class Jauge
	{
	public:
		Jauge();
		Jauge(std::string valueName);
		Jauge(std::string valueName, int maxValue);
		Jauge(std::string valueName, int val, int maxValue);
		~Jauge();
		int GetValue();
		virtual void SetValue(int value);
		int GetMaxValue();
		virtual void SetMaxValue(int value);
		virtual std::string *GetValueName();
		virtual void SetValueName(std::string *valueName);
	protected:
		std::string *valueName;
		int value;
		int maxValue;
		double increaseRate;
	};
}



