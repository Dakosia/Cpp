#pragma once
#include <iostream>
class Date_
{
private:
	int day;
	int month;
	int year;
public:
	//default constructor
	//Date_();
	//constructor with settings
	//Date_(int);
	//Date_(int, int);
	//Date_(int, int, int);
	//constructor with default settings
	Date_(int d = 1, int m = 1, int y = 1990);
	~Date_();

	//setters
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	//getters
	int getDay() { return day; }
	int	getMonth() { return month; }
	int	getYear() { return year; }

	void printDate();
};