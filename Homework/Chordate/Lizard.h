#pragma once
#include "Tetrapoda.h"
class Lizard :
	public virtual Tetrapoda
{
private:
	int bodyLength;
public:
	Lizard(std::string eyesColor = "Black", std::string name = "Unknown", bool hasSkull = true, bool hasTail = true, int bodyLength = 10);

	void setBodyLength(int bodyLength);
	int getBodyLength() const;

	void info() const;
};