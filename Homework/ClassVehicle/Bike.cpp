#include "Bike.h"



Bike::Bike(std::string color, std::string model, int max_speed, int number_of_seats, int engine_power, int cadence) :
	GroundVehicle(color, model, max_speed, number_of_seats, engine_power)
{
	this->setCadence(cadence);
}

void Bike::setCadence(int cadence)
{
	this->cadence = cadence;
}

int Bike::getCadence() const
{
	return this->cadence;
}

void Bike::info() const
{
	GroundVehicle::info();
	std::cout << "Cadence: " << cadence << std::endl;
}
