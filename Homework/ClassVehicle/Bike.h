#pragma once
#include "GroundVehicle.h"
class Bike :
	public GroundVehicle
{
private:
	int cadence;
public:
	Bike(std::string color, std::string model, int max_speed, int number_of_seats, int price, int engine_power, int cadence);

	void setCadence(int cadence);
	int getCadence() const;

	void info() const override;
	std::string codeInfo() const override;
	void start() override;
	void stop() override;
};