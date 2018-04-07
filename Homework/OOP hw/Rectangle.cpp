#include "Rectangle.h"



Rectangle::Rectangle()
{
	length = 1.0f;
	width = 1.0f;
}

Rectangle::Rectangle(float _length, float _width)
{
	length = _length;
	width = _width;
}


Rectangle::~Rectangle()
{
}

float Rectangle::getLength()
{
	return length;
}

void Rectangle::setLength(float _length)
{
	length = _length;
}

float Rectangle::getWidth()
{
	return width;
}

void Rectangle::setWidth(float _width)
{
	width = _width;
}

double Rectangle::getArea()
{
	return length * width;
}

double Rectangle::getPerimeter()
{
	return 2 * (length + width);
}

std::string Rectangle::toString()
{
	return "Rectangle[length=" + std::to_string(length) + ", width=" + std::to_string(width) + "]";
}
