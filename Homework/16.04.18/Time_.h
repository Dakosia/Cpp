#pragma once
#include <iostream>

class Time_
{
private:
	int hour;
	int minute;
	int second;
public:
	//default constructor
	Time_();
	//constructor with settings
	Time_(int);
	Time_(int, int);
	Time_(int, int, int);
	//constructor with default settings
	//Time_(int _hour = 0, int _minute = 0, int _second = 0);

	~Time_();

	//getter
	int getHour();
	int getMinute();
	int getSecond();
	//setter
	void setHour(int);
	void setMinute(int);
	void setSecond(int);

	void printTime();

	void addHour();
	void addMinute();
	void addSecond();
};
