#include "Time.h"



Time::Time()
{
}

Time::Time(int _hour, int _minute, int _second)
{
	hour = _hour;
	minute = _minute;
	second = _second;
}


Time::~Time()
{
}

int Time::getHour()
{
	return hour;
}

int Time::getMinute()
{
	return minute;
}

int Time::getSecond()
{
	return second;
}

void Time::setHour(int _hour)
{
	hour = _hour;
}

void Time::setMinute(int _minute)
{
	minute = _minute;
}

void Time::setSecond(int _second)
{
	second = _second;
}

void Time::setTime(int _hour, int _minute, int _second)
{
	hour = _hour;
	minute = _minute;
	second = _second;
}

std::string Time::toString()
{
	return std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
}

void Time::nextSecond()
{
	if (second == 59)
	{
		second = 0;
	}
	else
	{
		second += 1;
	}
}

void Time::previousSecond()
{
	if (second == 0)
	{
		second = 59;
	}
	else
	{
		second -= 1;
	}
}
