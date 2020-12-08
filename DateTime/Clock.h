#pragma once
#include "DateTime.h"

class Clock
{
public:
	Clock(std::string clockName, DateTime dateTime);

	// What would you want to do with a clock?
private:
	std::string _clockName;
	DateTime _currentDateTime;
};

