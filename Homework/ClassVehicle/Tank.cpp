#include "Tank.h"



Tank::Tank(std::string model, int max_speed, int number_of_seats, int engine_power, int damage) :
	GroundVehicle("Green", model, max_speed, number_of_seats, engine_power)
{
	this->setDamage(damage);
}

void Tank::setDamage(int damage)
{
	this->damage = damage;
}

int Tank::getDamage() const
{
	return this->damage;
}

void Tank::info() const
{
	std::cout << "Model: " << getModel() << std::endl;
	std::cout << "Max speed: " << getMaxSpeed() << std::endl;
	std::cout << "Number of seats: " << getNumberOfSeats() << std::endl;
	std::cout << "Engine power: " << getEnginePower() << std::endl;
	std::cout << "Damage: " << damage << std::endl;
}