#include "WaterVehicle.h"



WaterVehicle::WaterVehicle(std::string color, std::string model, int max_speed, int number_of_seats, int price, std::string seaworthiness) :
	Vehicle(color, model, max_speed, number_of_seats, price)
{
	this->setSeaworthiness(seaworthiness);
}

void WaterVehicle::setSeaworthiness(std::string seaworthiness)
{
	this->seaworthiness = seaworthiness;
}

std::string WaterVehicle::getSeaworthiness() const
{
	return this->seaworthiness;
}

void WaterVehicle::info() const
{
	Vehicle::info();
	std::cout << "Seaworthiness: " << seaworthiness << std::endl;
}

std::string WaterVehicle::codeInfo() const
{
	std::string str = Vehicle::codeInfo();
	str += seaworthiness + ';';
	return str;
}
