#pragma once
#include "Mammal.h"
class Human :
	public Mammal
{
private:
	std::string hairColor;
public:
	Human(std::string eyesColor = "Black", std::string name = "Unknown", bool hasSkull = true, bool hasTail = false, int numberOfMammaryGlands = 2, std::string hairColor = "Black");
	
	void setHairColor(std::string hairColor);
	std::string getHairColor() const;

	void info() const;
};

