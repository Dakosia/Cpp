#pragma once
#include "Tetrapoda.h"
class Bird :
	public virtual Tetrapoda
{
private:
	bool canFly = true;
public:
	Bird(std::string eyesColor = "Black", std::string name = "Unknown", bool hasSkull = true, bool hasTail = true, bool canFly = true);

	void setCanFly(bool canFly);
	bool getCanFly() const;

	void info() const;
};