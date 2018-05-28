#include "Mammal.h"



Mammal::Mammal(std::string eyesColor, std::string name, bool hasSkull, bool hasTail, int numberOfMammaryGlands) :
	Tetrapoda(eyesColor, name, hasSkull, hasTail)
{
	this->setNumberOfMammaryGlands(numberOfMammaryGlands);
}

void Mammal::setNumberOfMammaryGlands(int numberOfMammaryGlands)
{
	this->numberOfMammaryGlands = numberOfMammaryGlands;
}

int Mammal::getNumberOfMammaryGlands() const
{
	return this->numberOfMammaryGlands;
}

void Mammal::info() const
{
	Tetrapoda::info();
	std::cout << "Number of mammary glands: " << numberOfMammaryGlands << std::endl;
}
