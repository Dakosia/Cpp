#pragma once
#include "String_.h"
#include "Time_.h"
class Train
{
private:
	String_ destination;
	String_ trainNumber;
	Time_ departureTime;
	int numberOfSeats;
	int numberOfCompartmentSeats;
	int numberOfReservedSeats;
public:
	Train(String_ destination = "Destination", String_ trainNumber = "Train Number", Time_ departureTime = Time_(), int numberOfSeats = 20, int numberOfCompartmentSeats = 50, int numberOfReservedSeats = 50);
	~Train();

	//setters
	void setDestination(String_ destination);
	void setTrainNumber(String_ trainNumber);
	void setDepartureTime(Time_ departureTime);
	void setNumberOfSeats(int numberOfSeats);
	void setNumberOfCompartmentSeats(int numberOfCompartmentSeats);
	void setNumberOfReservedSeats(int numberOfReservedSeats);
	//getters
	String_ getDestination() const;
	String_ getTrainNumber() const;
	Time_ getDepartureTime() const;
	int getNumberOfSeats() const;
	int getNumberOfCompartmentSeats() const;
	int getNumberOfReservedSeats() const;

	Train& operator=(const Train &a);

	friend std::ostream& operator<<(std::ostream &out, const Train &a);
};

std::ostream& operator<<(std::ostream &out, const Train &a);
