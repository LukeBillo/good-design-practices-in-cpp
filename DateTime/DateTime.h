#pragma once
#include <string>
#include <ostream>

class DateTime
{
public:
	DateTime();
	DateTime(std::string fromString);

	// Would you want more precision? Milliseconds?
	DateTime(int year, int month, int day);
	DateTime(int year, int month, int day, int hour, int minute, int seconds);

	std::string ToString();

	// What other functions might you want on a date time?

	~DateTime();
private:
	int _year = 0;
	int _month = 0;
	int _day = 0;
	int _hour = 0;
	int _minutes = 0;
	int _seconds = 0;
};

const DateTime EPOCH = DateTime(1970, 1, 1);