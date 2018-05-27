#include "Bus.h"



Bus::Bus(std::string color, std::string model, int max_speed, int number_of_seats, int engine_power, int bus_number) :
	GroundVehicle(color, model, max_speed, number_of_seats, engine_power)
{
	this->setBusNumber(bus_number);
}

void Bus::setBusNumber(int bus_number)
{
	this->bus_number = bus_number;
}

int Bus::getBusNumber() const
{
	return this->bus_number;
}

void Bus::info() const
{
	GroundVehicle::info();
	std::cout << "Bus number: " << bus_number << std::endl;
}
