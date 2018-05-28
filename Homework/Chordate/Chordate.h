#pragma once
#include "Eye.h"
#include <string>
#include <iostream>
class Chordate
{
private:
	Eye eyes[2];
	std::string name;
	bool hasSkull = true;
public:
	Chordate(std::string eyesColor = "Black", std::string name = "Unknown", bool hasSkull = true);

	void setEyesColor(std::string eyesColor);
	void setName(std::string name);
	std::string getEyesColor() const;
	std::string getName() const;
	bool getSkull() const;

	void move() const;
	void info() const;
};