#pragma once
#include "AirVehicle.h"
class Helicopter :
	public AirVehicle
{
private:
	int number_of_blades;
public:
	Helicopter(std::string color, std::string model, int max_speed, int number_of_seats, int price, int altitude, int number_of_blades);

	void setNumberOfBlades(int number_of_blades);
	int getNumberOfBlades() const;

	void info() const override;
	std::string codeInfo() const override;
	void start() override;
	void stop() override;
};

