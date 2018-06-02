#pragma once
#include "GroundVehicle.h"
class Bus :
	public GroundVehicle
{
private:
	int bus_number;
public:
	Bus(std::string color, std::string model, int max_speed, int number_of_seats, int engine_power, int bus_number);

	void setBusNumber(int bus_number);
	int getBusNumber() const;

	void info() const;
	void start() override;
	void stop() override;
};

