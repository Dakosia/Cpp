#include <iostream>
#pragma once

class Mammal
{
private:
	//state
	int amountOfEyes;
	//getters and setters
	int getAmountOfEyes();
	void setAmountOfEyes(int _amountOfEyes);
	//operations
	void eat();
public:
	Mammal();
	~Mammal();
};
