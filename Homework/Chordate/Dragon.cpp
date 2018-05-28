#include "Dragon.h"



Dragon::Dragon(std::string eyesColor, std::string name, bool hasSkull, bool hasTail, bool canFly, int bodyLength, int fireDistance) :
	Bird(eyesColor, name, hasSkull, hasTail, canFly), Lizard(eyesColor, name, hasSkull, hasTail, bodyLength), Tetrapoda(eyesColor, name, hasSkull, hasTail)
{
	this->setFireDistance(fireDistance);
}

void Dragon::setFireDistance(int fireDistance)
{
	this->fireDistance = fireDistance;
}

int Dragon::getFireDistance() const
{
	return this->fireDistance;
}

void Dragon::info() const
{
	Tetrapoda::info();
	std::cout << "Can fly: " << getCanFly() << std::endl;
	std::cout << "Body length: " << getBodyLength() << std::endl;
	std::cout << "Fire distance: " << fireDistance << std::endl;
}