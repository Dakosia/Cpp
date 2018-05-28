#pragma once
#include "Tetrapoda.h"
class Mammal :
	public Tetrapoda
{
private:
	int numberOfMammaryGlands;
public:
	Mammal(std::string eyesColor = "Black", std::string name = "Unknown", bool hasSkull = true, bool hasTail = true, int numberOfMammaryGlands = 2);

	void setNumberOfMammaryGlands(int numberOfMammaryGlands);
	int getNumberOfMammaryGlands() const;

	void info() const;
};

