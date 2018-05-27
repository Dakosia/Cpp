#include "Car.h"



Car::Car(std::string color, std::string model, int max_speed, int number_of_seats, int engine_power, int number_of_wheels) :
	GroundVehicle(color, model, max_speed, number_of_seats, engine_power)
{
	this->setNumberOfWheels(number_of_wheels);
}

void Car::setNumberOfWheels(int number_of_wheels)
{
	this->number_of_wheels = number_of_wheels;
}

int Car::getNumberOfWheels() const
{
	return this->number_of_wheels;
}

void Car::info() const
{
	GroundVehicle::info();
	std::cout << "Number of wheels: " << number_of_wheels << std::endl;
}