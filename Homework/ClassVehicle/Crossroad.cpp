#include "Crossroad.h"



Crossroad::Crossroad(int durationRed, int durationGreen, int averageVehicle, int cntVehiclePerMinute)
{
	srand(time(NULL));
	this->setDurationRed(durationRed);
	this->setDurationGreen(durationGreen);
	this->setAverageVehicle(averageVehicle);
	this->setCntVPM(cntVehiclePerMinute);
}

void Crossroad::setDurationRed(int durationRed)
{
	this->durationRed = durationRed;
}

void Crossroad::setDurationGreen(int durationGreen)
{
	this->durationGreen = durationGreen;
}

void Crossroad::setAverageVehicle(int averageVehicle)
{
	this->averageVehicle = averageVehicle;
}

void Crossroad::setCntVPM(int cntVehiclePerMinute)
{
	this->cntVehiclePerMinute = cntVehiclePerMinute;
}

int Crossroad::getDurationRed() const
{
	return this->durationRed;
}

int Crossroad::getDurationGreen() const
{
	return this->durationGreen;
}

int Crossroad::getOneVCT() const
{
	return this->cntVehiclePerMinute;
}

int Crossroad::getAverageVehicle() const
{
	return this->averageVehicle;
}

void Crossroad::redLightOn()
{
	int min = averageVehicle / 2;
	int max = averageVehicle + averageVehicle / 2;
	int Rand = rand() % (min + 1) + max;
	Rand = Rand * durationRed / 60;
	double cntSec = (double)Rand / durationRed;
	double ost = 0.0;
	for (size_t i = 0; i < durationRed; i++)
	{
		ost += cntSec;
		system("cls");
		std::cout << "Red - " << durationRed - i << " sec\n" << "------------\n";
		while (ost >= 1)
		{
			if (traffic2.size() < traffic1.size())
			{
				traffic2.push_back(std::auto_ptr<Vehicle>(randomVehicle()));
				ost -= 1;
				continue;
			}
			else if (traffic3.size() < traffic2.size())
			{
				traffic3.push_back(std::auto_ptr<Vehicle>(randomVehicle()));
				ost -= 1;
				continue;
			}
			else
			{
				traffic1.push_back(std::auto_ptr<Vehicle>(randomVehicle()));
				ost -= 1;
			}
		}
		print();
		Sleep(1000);
	}
}

void Crossroad::greenLightOn()
{
	double cntSec = (double)cntVehiclePerMinute / 60;
	double ost = 0.0;
	for (size_t i = 0; i < durationGreen; i++)
	{
		ost += cntSec;
		system("cls");
		std::cout << "Green - " << durationGreen - i << "sec\n" << cntSec << "------------\n";
		while (ost >= 1)
		{
			if(traffic1.size() > 0)
				traffic1.erase(traffic1.begin());
			if (traffic2.size() > 0)
				traffic2.erase(traffic2.begin());
			if (traffic3.size() > 0)
				traffic3.erase(traffic3.begin());
			ost -= 1;
		}
		print();
		Sleep(1000);
	}
}

void Crossroad::print() const
{
	for (size_t i = 0; i < traffic1.size(); i++)
	{
		std::string type1 = typeid(*traffic1[i]).name();
		type1 = type1.substr(6);
		std::cout << type1 << " " << traffic1[i]->getColor() << " " << traffic1[i]->getModel() << "\t\t";
		if (i < traffic2.size())
		{
			std::string type2 = typeid(*traffic2[i]).name();
			type2 = type2.substr(6);
			std::cout << type2 << " " << traffic2[i]->getColor() << " " << traffic2[i]->getModel() << "\t\t";
		}
		if (i < traffic3.size())
		{
			std::string type3 = typeid(*traffic3[i]).name();
			type3 = type3.substr(6);
			std::cout << type3 << " " << traffic3[i]->getColor() << " " << traffic3[i]->getModel() << std::endl;
		}
	}
}

Vehicle * Crossroad::randomVehicle()
{
	Vehicle* v = nullptr;
	std::vector<std::string> color = { "Red", "Green", "Yellow", "Black", "Purple", "Pink", "Orange" };
	std::vector<std::string> marks = { "Acura", "Alfa Romeo", "Aston Martin", "Audi", "Bentley", "BMW", "Bugatti", "Buick" };
	int randColor = rand() % color.size();
	int randMarks = rand() % marks.size();
	int randVehicleType = rand() % 4;
	switch (randVehicleType)
	{
	case 0:
		v = new Bus(color[randColor], marks[randMarks], 100, 100, 300, 1);
		break;
	case 1:
		v = new Car(color[randColor], marks[randMarks], 300, 2, 700, 4);
		break;
	case 2:
		v = new Tank(marks[randMarks], 80, 6, 1000, 2000);
		break;
	case 3:
		v = new Bike(color[randColor], marks[randMarks], 200, 1, 0, 100);
		break;
	}
	return v;
}