#include "Eye.h"



Eye::Eye(std::string color)
{
	this->setColor(color);
}

void Eye::setColor(std::string color)
{
	this->color = color;
}

std::string Eye::getColor() const
{
	return this->color;
}