#pragma once
#include "GroundVehicle.h"
class Tank :
	public GroundVehicle
{
private:
	int damage;
public:
	Tank(std::string model, int max_speed, int number_of_seats, int engine_power, int damage);

	void setDamage(int damage);
	int getDamage() const;

	void info() const;
};