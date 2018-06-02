#pragma once
#include <iostream>
#include <string>
class Vehicle
{
private:
	std::string color;
	std::string model;
	int max_speed;
	int number_of_seats;
public:
	Vehicle(std::string color, std::string model, int max_speed, int number_of_seats);
	//setters
	void setColor(std::string color);
	void setModel(std::string model);
	void setMaxSpeed(int max_speed);
	void setNumberOfSeats(int number_of_seats);
	//getters
	std::string getColor() const;
	std::string getModel() const;
	int getMaxSpeed() const;
	int getNumberOfSeats() const;

	void info() const;
	virtual void start() = 0;
	virtual void stop() = 0;
};