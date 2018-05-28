#include "Lizard.h"



Lizard::Lizard(std::string eyesColor, std::string name, bool hasSkull, bool hasTail, int bodyLength) :
	Tetrapoda(eyesColor, name, hasSkull, hasTail)
{
	this->setBodyLength(bodyLength);
}

void Lizard::setBodyLength(int bodyLength)
{
	this->bodyLength = bodyLength;
}

int Lizard::getBodyLength() const
{
	return this->bodyLength;
}

void Lizard::info() const
{
	Tetrapoda::info();
	std::cout << "Body length: " << bodyLength << std::endl;
}