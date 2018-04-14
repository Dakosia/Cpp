#include "Mammal.h"



Mammal::Mammal()
{
}

Mammal::~Mammal()
{
}


void Mammal::eat()
{
	std::cout << ", I'm mammal and I eat" << std::endl;
}

int Mammal::getAmountOfEyes() {
	return amountOfEyes;
}

void Mammal::setAmountOfEyes(int _amountOfEyes)
{
	if (_amountOfEyes < 0)
	{
		std::cout << "Error: amount of eyes can not be negative" << std::endl;
	}
	else
	{
		amountOfEyes = _amountOfEyes;
	}
}