#include "Boat.h"



Boat::Boat(std::string color, std::string model, int max_speed, int number_of_seats, int price, std::string seaworthiness, std::string boatType) :
	WaterVehicle(color, model, max_speed, number_of_seats, price, seaworthiness)
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

std::string Boat::codeInfo() const
{
	std::string str = "Boat;";
	str += WaterVehicle::codeInfo();
	str += boatType + ';';
	return str;
}

void Boat::start()
{
	std::cout << "Boat started to move" << std::endl;
}

void Boat::stop()
{
	std::cout << "Boat stopped" << std::endl;
}