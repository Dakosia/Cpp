#pragma once
#include <string>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
class Circle
{
private:
	double radius;
	std::string color;
public:
	Circle();
	Circle(double);
	Circle(double, std::string);
	~Circle();

	double getRadius();
	double getArea();
	std::string getColor();
	void setRadius(double);
	void setColor(std::string);
	std::string toString();
};