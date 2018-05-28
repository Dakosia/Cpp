#pragma once
#include <string>
class Eye
{
private:
	std::string color;
public:
	Eye(std::string color = "Black");

	void setColor(std::string color);
	std::string getColor() const;
};