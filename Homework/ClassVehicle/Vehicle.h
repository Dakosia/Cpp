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
	int price;
public:
	Vehicle(std::string color, std::string model, int max_speed, int number_of_seats, int price);
	//setters
	void setColor(std::string color);
	void setModel(std::string model);
	void setMaxSpeed(int max_speed);
	void setNumberOfSeats(int number_of_seats);
	void setPrice(int price);
	//getters
	std::string getColor() const;
	std::string getModel() const;
	int getMaxSpeed() const;
	int getNumberOfSeats() const;
	int getPrice() const;

	virtual void info() const;
	virtual std::string codeInfo() const;
	virtual void start() = 0;
	virtual void stop() = 0;
};