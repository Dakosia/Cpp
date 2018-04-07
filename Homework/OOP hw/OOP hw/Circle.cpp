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

Circle::Circle(double _radius, std::string _color)
{
	radius = _radius;
	color = _color;
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

std::string Circle::getColor()
{
	return color;
}

void Circle::setRadius(double _radius)
{
	radius = _radius;
}

void Circle::setColor(std::string _color)
{
	color = _color;
}

std::string Circle::toString()
{
	return "Circle[radius=" + std::to_string(radius) + ", color=" + color + "]";
}