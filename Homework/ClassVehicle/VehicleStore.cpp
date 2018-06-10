#include "VehicleStore.h"



VehicleStore::VehicleStore(std::string name)
{
	this->setName(name);
}

void VehicleStore::setName(std::string name)
{
	this->name = name;
}

std::string VehicleStore::getName() const
{
	return this->name;
}

void VehicleStore::addVehicle(Vehicle * v)
{
	vehicles.push_back(std::auto_ptr<Vehicle>(v));
}

void VehicleStore::deleteVehicle(int pos)
{
	if (pos < vehicles.size())
		vehicles.erase(vehicles.begin() + pos);
}

void VehicleStore::getInfo() const
{
	std::cout << "Vehicle store name: " << name << std::endl << "----------\n";
	for (size_t i = 0; i < vehicles.size(); i++)
	{
		//std::cout << std::string(typeid(*vehicles[i]).name()).substr(6) << ":\n";
		std::string res = typeid(*vehicles[i]).name();
		res = res.substr(6);
		std::cout << res << ":\n";
		vehicles[i]->info();
		std::cout << std::endl;
	}
}

void VehicleStore::saveToFile() const
{
	std::fstream f("store.csv", std::ios::out);
	f << this->name << ';' << std::endl;
	for (size_t i = 0; i < vehicles.size(); i++)
	{
		f << vehicles[i]->codeInfo();
		if (i != vehicles.size() - 1)
			f << std::endl;
	}
}

void VehicleStore::readFromFile()
{
	std::fstream f("store.csv", std::ios::in);
	std::string str;
	char divider = ';';
	getline(f, str, divider);
	this->name = str;
	std::vector<std::string> s;
	while (!f.eof())
	{
		s.clear();
		for (int i = 0; i < 8; i++)
		{
			std::string s1;
			getline(f, s1, ';');
			s.push_back(s1);
		}
		if (s[0] == "\nBike")
			addVehicle(new Bike(s[1], s[2], stoi(s[3]), stoi(s[4]), stoi(s[5]), stoi(s[6]), stoi(s[7])));
		else if (s[0] == "\nBus")
			addVehicle(new Bus(s[1], s[2], stoi(s[3]), stoi(s[4]), stoi(s[5]), stoi(s[6]), stoi(s[7])));
		else if (s[0] == "\nCar")
			addVehicle(new Car(s[1], s[2], stoi(s[3]), stoi(s[4]), stoi(s[5]), stoi(s[6]), stoi(s[7])));
		else if (s[0] == "\nTank")
			addVehicle(new Tank(s[2], stoi(s[3]), stoi(s[4]), stoi(s[5]), stoi(s[6]), stoi(s[7])));
		else if (s[0] == "\nBoat")
			addVehicle(new Boat(s[1], s[2], stoi(s[3]), stoi(s[4]), stoi(s[5]), s[6], s[7]));
		else if (s[0] == "\nWaterScooter")
			addVehicle(new WaterScooter(s[1], s[2], stoi(s[3]), stoi(s[4]), stoi(s[5]), s[6], s[7]));
		else if (s[0] == "\nHelicopter")
			addVehicle(new Helicopter(s[1], s[2], stoi(s[3]), stoi(s[4]), stoi(s[5]), stoi(s[6]), stoi(s[7])));
		else if (s[0] == "\nPlane")
			addVehicle(new Plane(s[1], s[2], stoi(s[3]), stoi(s[4]), stoi(s[5]), stoi(s[6]), s[7]));

	}
}
