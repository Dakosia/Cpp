#include "Date_.h"



Date_::Date_(int day, int month, int year)
{
	this->setDay(day);
	this->setMonth(month);
	this->setYear(year);
}

void Date_::setDay(int day)
{
	if (day > 31 || day <= 0)
		this->day = 1;
	else
		this->day = day;
}

void Date_::setMonth(int month)
{
	if (month > 12 || month <= 0)
		this->month = 1;
	else
		this->month = month;
}

void Date_::setYear(int year)
{
	if (year < 1970)
		this->year = 1970;
	else
		this->year = year;
}

std::string Date_::getDate() const
{
	std::string s;
	if (day < 10)
		s += "0";
	s += std::to_string(day) += ".";
	if (month < 10)
		s += "0";
	s += std::to_string(month) += ".";
	s += std::to_string(year);
	return s;
}

std::ostream & operator<<(std::ostream & out, const Date_ & obj)
{
	out << obj.getDate();
	return out;
}
