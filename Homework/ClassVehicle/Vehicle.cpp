#include "Vehicle.h"



Vehicle::Vehicle(std::string color, std::string model, int max_speed, int number_of_seats, int price)
{
	this->setColor(color);
	this->setModel(model);
	this->setMaxSpeed(max_speed);
	this->setNumberOfSeats(number_of_seats);
	this->setPrice(price);
}

void Vehicle::setColor(std::string color)
{
	this->color = color;
}

void Vehicle::setModel(std::string model)
{
	this->model = model;
}

void Vehicle::setMaxSpeed(int max_speed)
{
	this->max_speed = max_speed;
}

void Vehicle::setNumberOfSeats(int number_of_seats)
{
	this->number_of_seats = number_of_seats;
}

void Vehicle::setPrice(int price)
{
	this->price = price;
}

std::string Vehicle::getColor() const
{
	return this->color;
}

std::string Vehicle::getModel() const
{
	return this->model;
}

int Vehicle::getMaxSpeed() const
{
	return this->max_speed;
}

int Vehicle::getNumberOfSeats() const
{
	return this->number_of_seats;
}

int Vehicle::getPrice() const
{
	return this->price;
}

void Vehicle::info() const
{
	std::cout << "Color: " << color << std::endl;
	std::cout << "Model: " << model << std::endl;
	std::cout << "Max speed: " << max_speed << std::endl;
	std::cout << "Number of seats: " << number_of_seats << std::endl;
	std::cout << "Price: " << price << std::endl;
}

std::string Vehicle::codeInfo() const
{
	std::string str;
	str = color + ';';
	str += model + ';';
	str += std::to_string(max_speed) += ';';
	str += std::to_string(number_of_seats) += ';';
	str += std::to_string(price) += ';';
	return str;
}
