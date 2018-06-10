#include "Plane.h"



Plane::Plane(std::string color, std::string model, int max_speed, int number_of_seats, int price, int altitude, std::string arrivalGate) :
	AirVehicle(color, model, max_speed, number_of_seats, price, altitude)
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

std::string Plane::codeInfo() const
{
	std::string str = "Plane;";
	str += AirVehicle::codeInfo();
	str += arrivalGate + ';';
	return str;
}

void Plane::start()
{
	std::cout << "Plane started to move" << std::endl;
}

void Plane::stop()
{
	std::cout << "Plane stopped" << std::endl;
}