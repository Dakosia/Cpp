#pragma once
#include "Chordate.h"
class Fish :
	public Chordate
{
private:
	bool hasGills;
	bool hasScale;
public:
	Fish(std::string eyesColor = "Black", std::string name = "Unknown", bool hasSkull = true, bool hasGills = true, bool hasScale = true);

	void setHasGills(bool hasGills);
	void setHasScale(bool hasScale);
	bool getHasGills() const;
	bool getHasScale() const;

	void info() const;
};

