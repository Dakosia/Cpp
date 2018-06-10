#pragma once
#include <iostream>
#include <string>
class Date_
{
private:
	int day;
	int month;
	int year;
public:
	Date_(int day = 1, int month = 1, int year = 1970);

	//setters
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	//getters
	int getDay() const { return this->day; }
	int	getMonth() const { return this->month; }
	int	getYear() const { return this->year; }
	std::string getDate() const;

	friend std::ostream& operator<<(std::ostream &out, const Date_ &obj);
};

std::ostream& operator<<(std::ostream &out, const Date_ &obj);