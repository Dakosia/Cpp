#include "Helicopter.h"



Helicopter::Helicopter(std::string color, std::string model, int max_speed, int number_of_seats, int altitude, int number_of_blades) :
	AirVehicle(color, model, max_speed, number_of_seats, altitude) 
{
	this->setNumberOfBlades(number_of_blades);
}

void Helicopter::setNumberOfBlades(int number_of_blades)
{
	this->number_of_blades = number_of_blades;
}

int Helicopter::getNumberOfBlades() const
{
	return this->number_of_blades;
}

void Helicopter::info() const
{
	AirVehicle::info();
	std::cout << "Number of blades: " << number_of_blades << std::endl;
}
