#include "Plane.h"



Plane::Plane(std::string color, std::string model, int max_speed, int number_of_seats, int altitude, std::string arrivalGate) :
	AirVehicle(color, model, max_speed, number_of_seats, altitude)
{
	this->setArrivalGate(arrivalGate);
}

void Plane::setArrivalGate(std::string arrivalGate)
{
	this->arrivalGate = arrivalGate;
}

std::string Plane::getArrivalGate() const
{
	return this->arrivalGate;
}

void Plane::info() const
{
	AirVehicle::info();
	std::cout << "Arrival gate: " << arrivalGate << std::endl;
}
