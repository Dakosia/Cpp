#include "Human.h"



Human::Human(std::string eyesColor, std::string name, bool hasSkull, bool hasTail, int numberOfMammaryGlands, std::string hairColor) :
	Mammal(eyesColor, name, hasSkull, hasTail, numberOfMammaryGlands)
{
	this->setHairColor(hairColor);
}

void Human::setHairColor(std::string hairColor)
{
	this->hairColor = hairColor;
}

std::string Human::getHairColor() const
{
	return this->hairColor;
}

void Human::info() const
{
	Mammal::info();
	std::cout << "Hair color: " << hairColor << std::endl;
}
