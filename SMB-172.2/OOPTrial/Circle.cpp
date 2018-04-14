#include "Circle.h"

Circle::Circle()
{
	radius = 1.0;
	color = "red";
}

Circle::Circle(double _radius)
{
	radius = _radius;
	color = "red";
}

Circle::~Circle()
{
}

double Circle::getRadius()
{
	return radius;
}

double Circle::getArea()
{
	return M_PI * radius * radius;
}
