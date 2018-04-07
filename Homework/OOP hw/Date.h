#pragma once
#include <string>
#include <iostream>
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int, int, int);
	~Date();

	int getDay();
	int getMonth();
	int getYear();
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate(int, int, int);
	std::string toString();
};

