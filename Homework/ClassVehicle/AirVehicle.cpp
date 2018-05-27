#include "AirVehicle.h"



AirVehicle::AirVehicle(std::string color, std::string model, int max_speed, int number_of_seats, int altitude) :
	Vehicle(color, model, max_speed, number_of_seats)
{
	this->setAltitude(altitude);
}

void AirVehicle::setAltitude(int altitude)
{
	this->altitude = altitude;
}

int AirVehicle::getAltitude() const
{
	return this->altitude;
}

void AirVehicle::info() const
{
	Vehicle::info();
	std::cout << "Altitude: " << altitude << std::endl;
}