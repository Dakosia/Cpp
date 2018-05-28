#include "Bird.h"



Bird::Bird(std::string eyesColor, std::string name, bool hasSkull, bool hasTail, bool canFly) :
	Tetrapoda(eyesColor, name, hasSkull, hasTail)
{
	this->setCanFly(canFly);
}

void Bird::setCanFly(bool canFly)
{
	this->canFly = canFly;
}

bool Bird::getCanFly() const
{
	return this->canFly;
}

void Bird::info() const
{
	Tetrapoda::info();
	std::cout << "Can fly: " << canFly << std::endl;
}