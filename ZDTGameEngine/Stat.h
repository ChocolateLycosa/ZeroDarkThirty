#pragma once
#include <iostream>
#include <string>
namespace ZDTGameEngine
{
	namespace CharacterManagement
	{
		namespace General
		{
			class Stat
			{
				public:
					Stat();
					Stat(std::string valueName);
					Stat(std::string valueName, int maxValue);
					~Stat();
					virtual int GetValue();
					virtual void SetValue(int value);
					virtual int GetMaxValue();
					virtual void SetMaxValue(int value);
					virtual std::string *GetValueName();
					virtual void SetValueName(std::string *valueName);
				protected:
					std::string *valueName;
					int value;
					int maxValue;
					float increaseRate;
			};
		}
	}
}


