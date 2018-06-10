#pragma once
#include "WaterVehicle.h"
class Boat :
	public WaterVehicle
{
private:
	std::string boatType; //human-powered, sailboat, motorboat, etc
public:
	Boat(std::string color, std::string model, int max_speed, int number_of_seats, int price, std::string seaworthiness, std::string boatType);

	void setBoatType(std::string boatType);
	std::string getBoatType() const;

	void info() const override;
	std::string codeInfo() const override;
	void start() override;
	void stop() override;
};

