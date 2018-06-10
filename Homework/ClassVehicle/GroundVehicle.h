#pragma once
#include "Vehicle.h"
class GroundVehicle :
	public Vehicle
{
private:
	int engine_power;
public:
	GroundVehicle(std::string color, std::string model, int max_speed, int number_of_seats, int price, int engine_power);

	void setEnginePower(int engine_power);
	int getEnginePower() const;

	void info() const override;
	std::string codeInfo() const override;
};