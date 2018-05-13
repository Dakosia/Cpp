#pragma once
#include <iostream>
#include <ctime>

class Time_
{
private:
	int hour;
	int minute;
	int second;
public:
	Time_(int hour = 0, int minute = 0, int second = 0);

	~Time_();

	//getter
	int getHour() const;
	int getMinute() const;
	int getSecond() const;
	//setter
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);

	void printTime() const;
	static void printSystemTime();

	void addHour(int hour = 0);
	void addMinute(int minute = 0);
	void addSecond(int second = 0);
	void reduceHour(int hour = 0);
	void reduceMinute(int minute = 0);
	void reduceSecond(int second = 0);

	const Time_& operator++();
	const Time_& operator++(int);
	const Time_& operator--();
	const Time_& operator--(int);

	const Time_& operator+=(const Time_ &a);
	const Time_& operator-=(const Time_ &a);
};

std::ostream& operator<<(std::ostream &out, const Time_ &a);
std::istream& operator >> (std::istream &in, Time_ &a);

bool operator>(const Time_ &a, const Time_ &b);
bool operator<(const Time_ &a, const Time_ &b);
bool operator>=(const Time_ &a, const Time_ &b);
bool operator<=(const Time_ &a, const Time_ &b);
bool operator!=(const Time_ &a, const Time_ &b);
bool operator==(const Time_ &a, const Time_ &b);
