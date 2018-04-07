#include "Date.h"



Date::Date()
{
}

Date::Date(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
}


Date::~Date()
{
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void Date::setDay(int _day)
{
	day = _day;
}

void Date::setMonth(int _month)
{
	month = _month;
}

void Date::setYear(int _year)
{
	year = _year;
}

void Date::setDate(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
}

std::string Date::toString()
{
	return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}
