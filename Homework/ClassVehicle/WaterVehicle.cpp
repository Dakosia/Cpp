#include "WaterVehicle.h"



WaterVehicle::WaterVehicle(std::string color, std::string model, int max_speed, int number_of_seats, std::string seaworthiness) :
	Vehicle(color, model, max_speed, number_of_seats)
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
