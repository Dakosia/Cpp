#include "Time_.h"



Time_::Time_(int hour, int minute, int second)
{
	if (hour >= 24 && hour < 0)
		throw std::exception("non-existent hour");
	if (minute > 59 && minute < 0)
		throw std::exception("non-existent minute");
	if (second > 59 && second < 0)
		throw std::exception("non-existent second");
	this->setHour(hour);
	this->setMinute(minute);
	this->setSecond(second);
}

int Time_::getHour() const
{
	return this->hour;
}

int Time_::getMinute() const
{
	return this->minute;
}

int Time_::getSecond() const
{
	return this->second;
}

void Time_::setHour(int hour)
{
	if (hour >= 24 && hour < 0)
		this->hour = 0;
	else
		this->hour = hour;
}

void Time_::setMinute(int minute)
{
	if (minute > 59 && minute < 0)
		this->minute = 0;
	else
		this->minute = minute;
}

void Time_::setSecond(int second)
{
	if (second > 59 && second < 0)
		this->second = 0;
	else
		this->second = second;
}

void Time_::printTime() const
{
	if (this->hour < 10)
		std::cout << "0";
	std::cout << this->hour << ":";
	if (this->minute < 10)
		std::cout << "0";
	std::cout << this->minute << ":";
	if (this->second < 10)
		std::cout << "0";
	std::cout << this->second << std::endl;
}

void Time_::printSystemTime()
{
	time_t now = time(0);
	tm* localtm = localtime(&now);
	std::cout << "The local date and time is: " << asctime(localtm);
}

void Time_::addHour(int hour)
{
	int new_hour = this->hour + hour;
	this->hour = new_hour % 24; //73 % 24 = 1
}

void Time_::addMinute(int minute)
{
	int new_minute = this->minute + minute;
	this->minute = new_minute % 60;
	new_minute /= 60;
	addHour(new_minute);
}

void Time_::addSecond(int second)
{
	int new_second = this->second + second;
	this->second = new_second % 60;
	new_second /= 60;
	addMinute(new_second);
}

void Time_::reduceHour(int hour)
{
	if (this->hour >= hour)
	{
		this->hour -= hour;
	}
	else
	{
		this->hour = 24 - (hour - this->hour);
		if (this->hour < 0)
		{
			this->hour = this->hour + 24 * (hour / 24);
			if (this->hour >= 24)
				this->hour -= 24;
		}
	}
}

void Time_::reduceMinute(int minute)
{
	int tmp = this->minute;
	if (this->minute >= minute)
	{
		this->minute -= minute;
	}
	else
	{
		this->minute = 60 - (minute - this->minute);
		if (this->minute < 0)
		{
			this->minute = this->minute + 60 * (minute / 60);
			if (this->minute >= 60)
				this->minute -= 60;
		}
	}
	if (minute % 60 > tmp)
		this->reduceHour(minute / 60 + 1);
	else
		this->reduceHour(minute / 60);
}

void Time_::reduceSecond(int second)
{
	int tmp = this->second;
	if (this->second >= second)
	{
		this->second -= second;
	}
	else
	{
		this->second = 60 - (second - this->second);
		if (this->second < 0)
		{
			this->second = this->second + 60 * (second / 60);
			if (this->second >= 60)
				this->second -= 60;
		}
	}
	if (second % 60 > tmp)
		this->reduceMinute(second / 60 + 1);
	else
		this->reduceMinute(second / 60);
}

const Time_ & Time_::operator++()
{
	this->addSecond(1);
	return *this;
}

const Time_ & Time_::operator++(int)
{
	Time_ tmp(*this);
	this->addSecond(1);
	return tmp;
}

const Time_ & Time_::operator--()
{
	this->reduceSecond(1);
	return *this;
}

const Time_ & Time_::operator--(int)
{
	Time_ tmp(*this);
	this->reduceSecond(1);
	return tmp;
}

const Time_ & Time_::operator+=(const Time_ & a)
{
	this->addHour(a.hour);
	this->addMinute(a.minute);
	this->addSecond(a.second);
	return *this;
}

const Time_ & Time_::operator-=(const Time_ & a)
{
	this->reduceHour(a.hour);
	this->reduceMinute(a.minute);
	this->reduceSecond(a.second);
	return *this;
}

std::ostream & operator<<(std::ostream & out, const Time_ & a)
{
	a.printTime();
	return out;
}

std::istream & operator >> (std::istream & in, Time_ & a)
{
	int hour, minute, second;
	//std::cout << "Введите часы\n";
	in >> hour;
	//std::cout << "Введите минуты\n";
	in >> minute;
	//std::cout << "Введите секунды\n";
	in >> second;
	a.setHour(hour);
	a.setMinute(minute);
	a.setSecond(second);
	return in;
}

bool operator>(const Time_ & a, const Time_ & b)
{
	if (a.getHour() > b.getHour())
		return true;
	if (a.getHour() == b.getHour() && a.getMinute() > b.getMinute())
		return true;
	if (a.getHour() == b.getHour() && a.getMinute() == b.getMinute() && a.getSecond() > b.getSecond())
		return true;
	return false;
}

bool operator<(const Time_ & a, const Time_ & b)
{
	if (a.getHour() < b.getHour())
		return true;
	if (a.getHour() == b.getHour() && a.getMinute() < b.getMinute())
		return true;
	if (a.getHour() == b.getHour() && a.getMinute() == b.getMinute() && a.getSecond() < b.getSecond())
		return true;
	return false;
}

bool operator>=(const Time_ & a, const Time_ & b)
{
	if (a.getHour() >= b.getHour())
		return true;
	if (a.getHour() == b.getHour() && a.getMinute() >= b.getMinute())
		return true;
	if (a.getHour() == b.getHour() && a.getMinute() == b.getMinute() && a.getSecond() >= b.getSecond())
		return true;
	return false;
}

bool operator<=(const Time_ & a, const Time_ & b)
{
	if (a.getHour() <= b.getHour())
		return true;
	if (a.getHour() == b.getHour() && a.getMinute() <= b.getMinute())
		return true;
	if (a.getHour() == b.getHour() && a.getMinute() == b.getMinute() && a.getSecond() <= b.getSecond())
		return true;
	return false;
}

bool operator!=(const Time_ & a, const Time_ & b)
{
	if (a.getHour() != b.getHour() && a.getMinute() != b.getMinute() && a.getSecond() != b.getSecond())
		return true;
	return false;
}

bool operator==(const Time_ & a, const Time_ & b)
{
	if (a.getHour() == b.getHour() && a.getMinute() == b.getMinute() && a.getSecond() == b.getSecond())
		return true;
	return false;
}
