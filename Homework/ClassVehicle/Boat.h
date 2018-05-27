#pragma once
#include "WaterVehicle.h"
class Boat :
	public WaterVehicle
{
private:
	std::string boatType; //human-powered, sailboat, motorboat, etc
public:
	Boat(std::string color, std::string model, int max_speed, int number_of_seats, std::string seaworthiness, std::string boatType);

	void setBoatType(std::string boatType);
	std::string getBoatType() const;

	void info() const;
};

