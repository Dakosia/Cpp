#include "Chordate.h"



Chordate::Chordate(std::string eyesColor, std::string name, bool hasSkull)
{
	this->setEyesColor(eyesColor);
	this->setName(name);
	this->hasSkull = hasSkull;
}

void Chordate::setEyesColor(std::string eyesColor)
{
	this->eyes[0].setColor(eyesColor);
	this->eyes[1].setColor(eyesColor);
}

void Chordate::setName(std::string name)
{
	this->name = name;
}

std::string Chordate::getEyesColor() const
{
	return this->eyes[0].getColor();
}

std::string Chordate::getName() const
{
	return this->name;
}

bool Chordate::getSkull() const
{
	return this->hasSkull;
}

void Chordate::move() const
{
	std::cout << "Chordate is moving" << std::endl;
}

void Chordate::info() const
{
	std::cout << "Eyes color: " << getEyesColor() << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Has skull: " << hasSkull << std::endl;
}