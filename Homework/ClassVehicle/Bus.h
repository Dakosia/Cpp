#pragma once
#include "GroundVehicle.h"
class Bus :
	public GroundVehicle
{
private:
	int bus_number;
public:
	Bus(std::string color, std::string model, int max_speed, int number_of_seats, int price, int engine_power, int bus_number);

	void setBusNumber(int bus_number);
	int getBusNumber() const;

	void info() const override;
	std::string codeInfo() const override;
	void start() override;
	void stop() override;
};

