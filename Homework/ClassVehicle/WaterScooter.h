#pragma once
#include "WaterVehicle.h"
class WaterScooter :
	public WaterVehicle
{
private:
	std::string useType; //sports, family, tourist, etc
public:
	WaterScooter(std::string color, std::string model, int max_speed, int number_of_seats, std::string seaworthiness, std::string useType);

	void setUseType(std::string useType);
	std::string getUseType() const;

	void info() const;
};

