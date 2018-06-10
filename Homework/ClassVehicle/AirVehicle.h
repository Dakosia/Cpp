#pragma once
#include "Vehicle.h"
class AirVehicle :
	public Vehicle
{
private:
	int altitude;
public:
	AirVehicle(std::string color, std::string model, int max_speed, int number_of_seats, int price, int altitude);

	void setAltitude(int altitude);
	int getAltitude() const;

	void info() const override;
	std::string codeInfo() const override;
};