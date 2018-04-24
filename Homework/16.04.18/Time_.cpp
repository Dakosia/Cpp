#include "Time_.h"



Time_::Time_()
{
	hour = 0;
	minute = 0;
	second = 0;
}

Time_::Time_(int _hour)
{
	setHour(_hour);
	minute = 0;
	second = 0;
}

Time_::Time_(int _hour, int _minute)
{
	setHour(_hour);
	setMinute(_minute);
	second = 0;
}


Time_::Time_(int _hour, int _minute, int _second)
{
	setHour(_hour);
	setMinute(_minute);
	setSecond(_second);
}

//Time_::Time_(int _hour = 0, int _minute = 0, int _second = 0)
//{
//}

Time_::~Time_()
{
}

int Time_::getHour()
{
	return hour;
}

int Time_::getMinute()
{
	return minute;
}

int Time_::getSecond()
{
	return second;
}

void Time_::setHour(int _hour)
{
	if (_hour >= 24 && _hour < 0)
		hour = 0;
	else
		hour = _hour;
}

void Time_::setMinute(int _minute)
{
	if (_minute > 59 && _minute < 0)
		minute = 0;
	else
		minute = _minute;
}

void Time_::setSecond(int _second)
{
	if (_second > 59 && _second < 0)
		second = 0;
	else
		second = _second;
}

void Time_::printTime()
{
	if (hour < 10)
		std::cout << "0";
	std::cout << hour << ":";
	if (minute < 10)
		std::cout << "0";
	std::cout << minute << ":";
	if (second < 10)
		std::cout << "0";
	std::cout << second << std::endl;
	//std::cout << hour << ":" << minute << ":" << second << std::endl;
}

void Time_::addHour()
{
	hour++;
	if (hour == 24)
		hour = 0;
}

void Time_::addMinute()
{
	minute++;
	if (minute == 60)
	{
		minute = 0;
		addHour();
	}
}

void Time_::addSecond()
{
	second++;
	if (second == 60)
	{
		second = 0;
		addMinute();
	}
}
