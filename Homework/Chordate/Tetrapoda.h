#pragma once
#include "Chordate.h"
class Tetrapoda :
	public Chordate
{
private:
	bool hasTail = true;
public:
	Tetrapoda(std::string eyesColor = "Black", std::string name = "Unknown", bool hasSkull = true, bool hasTail = true);

	void setTail(bool hasTail);
	bool getTail() const;

	void info() const;
};