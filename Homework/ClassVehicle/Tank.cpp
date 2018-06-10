#include "Tank.h"



Tank::Tank(std::string model, int max_speed, int number_of_seats, int engine_power, int price, int damage) :
	GroundVehicle("Green", model, max_speed, number_of_seats, price, engine_power)
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

std::string Tank::codeInfo() const
{
	std::string str = "Tank;";
	str += GroundVehicle::codeInfo();
	str += std::to_string(damage) += ';';
	return str;
}

void Tank::start()
{
	std::cout << "Tank started to move" << std::endl;
}

void Tank::stop()
{
	std::cout << "Tank stopped" << std::endl;
}