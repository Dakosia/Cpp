#pragma once
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

class Circle
{
	double radius;
	std::string color;
public:
	Circle();
	Circle(double  _radius);
	~Circle();
	double getRadius();
	double getArea();
};

