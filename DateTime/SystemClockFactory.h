#pragma once
#include "Clock.h"

class SystemClockFactory
{
public:
	SystemClockFactory();
	Clock Create();
};

