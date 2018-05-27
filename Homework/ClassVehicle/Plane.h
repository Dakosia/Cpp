#pragma once
#include "AirVehicle.h"
class Plane :
	public AirVehicle
{
private:
	std::string arrivalGate;
public:
	Plane(std::string color, std::string model, int max_speed, int number_of_seats, int altitude, std::string arrivalGate);

	void setArrivalGate(std::string arrivalGate);
	std::string getArrivalGate() const;

	void info() const;
};

