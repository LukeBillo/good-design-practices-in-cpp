#include "DateTime.h"

DateTime::DateTime() 
{
	_year = EPOCH._year;
	_month = EPOCH._month;
	_day = EPOCH._day;
}

DateTime::DateTime(std::string fromString)
{
	// todo: implement a constructor from a string!
	// Consider timezones: do you want to support just DD/MM/YYYY? What about other formats?
}

DateTime::DateTime(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

DateTime::DateTime(int year, int month, int day, int hour, int minutes, int seconds)
{
	_year = year;
	_month = month;
	_day = day;
	_hour = hour;
	_minutes = minutes;
	_seconds = seconds;
}

std::string DateTime::ToString()
{
	
	// todo: implement conversion to a string!
	// Again, consider what format you want to output. DD/MM/YYYY?

	// If you're done, maybe consider overloading operator<<

	return "";
}

DateTime::~DateTime() = default;
