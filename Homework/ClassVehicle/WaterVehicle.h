#pragma once
#include "Vehicle.h"
class WaterVehicle :
	public Vehicle
{
private:
	std::string seaworthiness;
public:
	WaterVehicle(std::string color, std::string model, int max_speed, int number_of_seats, std::string seaworthiness);

	void setSeaworthiness(std::string seaworthiness);
	std::string getSeaworthiness() const;

	void info() const;
};

