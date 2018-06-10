#include "Helicopter.h"



Helicopter::Helicopter(std::string color, std::string model, int max_speed, int number_of_seats, int price, int altitude, int number_of_blades) :
	AirVehicle(color, model, max_speed, number_of_seats, price, altitude)
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

std::string Helicopter::codeInfo() const
{
	std::string str = "Helicopter;";
	str += AirVehicle::codeInfo();
	str += std::to_string(number_of_blades) += ';';
	return str;
}

void Helicopter::start()
{
	std::cout << "Helicopter started to move" << std::endl;
}

void Helicopter::stop()
{
	std::cout << "Helicopter stopped" << std::endl;
}