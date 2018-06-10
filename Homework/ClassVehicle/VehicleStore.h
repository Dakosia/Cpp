#pragma once
#include "Bike.h"
#include "Bus.h"
#include "Car.h"
#include "Tank.h"
#include "Boat.h"
#include "WaterScooter.h"
#include "Helicopter.h"
#include "Plane.h"
#include <vector>
#include <memory>
#include <fstream>
class VehicleStore
{
private:
	std::string name;
	std::vector<std::auto_ptr<Vehicle>> vehicles;
public:
	VehicleStore(std::string name = "Unknown");

	void setName(std::string name);
	std::string getName() const;

	void addVehicle(Vehicle* v);
	void deleteVehicle(int pos);

	void getInfo() const;
	void saveToFile() const;
	void readFromFile();
};

