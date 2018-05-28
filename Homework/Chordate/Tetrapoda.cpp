#include "Tetrapoda.h"



Tetrapoda::Tetrapoda(std::string eyesColor, std::string name, bool hasSkull, bool hasTail) :
	Chordate(eyesColor, name, hasSkull)
{
	this->hasTail = hasTail;
}

void Tetrapoda::setTail(bool hasTail)
{
	this->hasTail = hasTail;
}

bool Tetrapoda::getTail() const
{
	return this->hasTail;
}

void Tetrapoda::info() const
{
	Chordate::info();
	std::cout << "Has tail: " << hasTail << std::endl;
}