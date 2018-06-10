#include "GroundVehicle.h"



GroundVehicle::GroundVehicle(std::string color, std::string model, int max_speed, int number_of_seats, int price, int engine_power) :
	Vehicle(color, model, max_speed, number_of_seats, price)
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

std::string GroundVehicle::codeInfo() const
{
	std::string str = Vehicle::codeInfo();
	str += std::to_string(engine_power) += ';';
	return str;
}
