#include "WaterScooter.h"



WaterScooter::WaterScooter(std::string color, std::string model, int max_speed, int number_of_seats, std::string seaworthiness, std::string useType) :
	WaterVehicle(color, model, max_speed, number_of_seats, seaworthiness)
{
	this->setUseType(useType);
}

void WaterScooter::setUseType(std::string useType)
{
	this->useType = useType;
}

std::string WaterScooter::getUseType() const
{
	return this->useType;
}

void WaterScooter::info() const
{
	WaterVehicle::info();
	std::cout << "Use type: " << useType << std::endl;
}
