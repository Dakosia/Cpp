#pragma once
#include <string>
#include <iostream>
class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time();
	Time(int, int, int);
	~Time();

	int getHour();
	int getMinute();
	int getSecond();
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	void setTime(int, int, int);
	std::string toString();
	void nextSecond();
	void previousSecond();
};

