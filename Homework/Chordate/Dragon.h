#pragma once
#include "Bird.h"
#include "Lizard.h"
class Dragon :
	public Bird, public Lizard
{
private:
	int fireDistance;
public:
	Dragon(std::string eyesColor = "Black", std::string name = "Unknown", bool hasSkull = true, bool hasTail = true, bool canFly = true, int bodyLength = 10, int fireDistance = 1);

	void setFireDistance(int fireDistance);
	int getFireDistance() const;

	void info() const;
};