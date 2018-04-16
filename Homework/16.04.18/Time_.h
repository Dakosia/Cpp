#pragma once
#include <iostream>

class Time_
{
private:
	int hour;
	int minute;
	int second;
public:
	Time_();
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
