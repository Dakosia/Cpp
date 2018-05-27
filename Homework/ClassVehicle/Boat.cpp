#include "Boat.h"



Boat::Boat(std::string color, std::string model, int max_speed, int number_of_seats, std::string seaworthiness, std::string boatType) :
	WaterVehicle(color, model, max_speed, number_of_seats, seaworthiness)
{
	this->setBoatType(boatType);
}

void Boat::setBoatType(std::string boatType)
{
	this->boatType = boatType;
}

std::string Boat::getBoatType() const
{
	return this->boatType;
}

void Boat::info() const
{
	WaterVehicle::info();
	std::cout << "Boat type: " << boatType << std::endl;
}
