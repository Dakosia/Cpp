#include "GroundVehicle.h"



GroundVehicle::GroundVehicle(std::string color, std::string model, int max_speed, int number_of_seats, int engine_power) :
	Vehicle(color, model, max_speed, number_of_seats)
{
	this->setEnginePower(engine_power);
}

void GroundVehicle::setEnginePower(int engine_power)
{
	this->engine_power = engine_power;
}

int GroundVehicle::getEnginePower() const
{
	return this->engine_power;
}

void GroundVehicle::info() const
{
	Vehicle::info();
	std::cout << "Engine power: " << engine_power << std::endl;
}