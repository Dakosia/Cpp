#pragma once
#include "GroundVehicle.h"
class Car :
	public GroundVehicle
{
private:
	int number_of_wheels;
public:
	Car(std::string color, std::string model, int max_speed, int number_of_seats, int engine_power, int number_of_wheels);

	void setNumberOfWheels(int number_of_wheels);
	int getNumberOfWheels() const;

	void info() const;
	void start() override;
	void stop() override;
};