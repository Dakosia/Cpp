#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include <Windows.h>
#include "Bike.h"
#include "Bus.h"
#include "Car.h"
#include "Tank.h"
class Crossroad
{
private:
	std::vector<std::auto_ptr<Vehicle>> traffic1;
	std::vector<std::auto_ptr<Vehicle>> traffic2;
	std::vector<std::auto_ptr<Vehicle>> traffic3;
	int durationRed;
	int durationGreen;
	int averageVehicle;
	int cntVehiclePerMinute;
public:
	Crossroad(int durationRed, int durationGreen, int averageVehicle, int cntVehiclePerMinute);

	void setDurationRed(int durationRed);
	void setDurationGreen(int durationGreen);
	void setAverageVehicle(int averageVehicle);
	void setCntVPM(int cntVehiclePerMinute);
	int getDurationRed() const;
	int getDurationGreen() const;
	int getOneVCT() const;
	int getAverageVehicle() const;

	void redLightOn();
	void greenLightOn();


	void print() const;

	//random vechicle
	Vehicle* randomVehicle();
};