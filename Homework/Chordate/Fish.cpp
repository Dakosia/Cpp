#include "Fish.h"



Fish::Fish(std::string eyesColor, std::string name, bool hasSkull, bool hasGills, bool hasScale) :
	Chordate(eyesColor, name, hasSkull)
{
	this->setHasGills(hasGills);
	this->setHasScale(hasScale);
}

void Fish::setHasGills(bool hasGills)
{
	this->hasGills = hasGills;
}

void Fish::setHasScale(bool hasScale)
{
	this->hasScale = hasScale;
}

bool Fish::getHasGills() const
{
	return this->hasGills;
}

bool Fish::getHasScale() const
{
	return this->hasScale;
}

void Fish::info() const
{
	Chordate::info();
	std::cout << "Has gills: " << hasGills << std::endl;
	std::cout << "Has scale: " << hasScale << std::endl;
}
