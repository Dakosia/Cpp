#include "Date_.h"



//Date_::Date_()
//{
//	day = 1;
//	month = 1;
//	year = 1990;
//}
//
//
//Date_::Date_(int d)
//{
//	setDay(d);
//	month = 1;
//	year = 1990;
//}
//
//Date_::Date_(int d, int m)
//{
//	setDay(d);
//	setMonth(m);
//	year = 1990;
//}
//
//Date_::Date_(int d, int m, int y)
//{
//	setDay(d);
//	setMonth(m);
//	setYear(y);
//}

Date_::Date_(int d = 1, int m = 1, int y = 1990)
{
}

Date_::~Date_()
{
}

void Date_::setDay(int d)
{
	if (d > 31 || d < 0)
		day = 1;
	else
		day = d;
}

void Date_::setMonth(int m)
{
	if (m > 12 || m < 0)
		month = 1;
	else
		month = m;
}

void Date_::setYear(int y)
{
	if (y > 2999 || y < 1899)
		year = 1900;
	else
		year = y;
}

void Date_::printDate()
{
	if (day < 10)
		std::cout << "0";
	std::cout << day << ".";
	if (month < 10)
		std::cout << "0";
	std::cout << month << ".";
	std::cout << year << std::endl;
}
