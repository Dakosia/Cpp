#include "Train.h"



Train::Train(String_ destination, String_ trainNumber, Time_ departureTime, int numberOfSeats, int numberOfCompartmentSeats, int numberOfReservedSeats)
{
	this->setDestination(destination);
	this->setTrainNumber(trainNumber);
	this->setDepartureTime(departureTime);
	this->setNumberOfSeats(numberOfSeats);
	this->setNumberOfCompartmentSeats(numberOfCompartmentSeats);
	this->setNumberOfReservedSeats(numberOfReservedSeats);
}

Train::~Train()
{
	this->destination.~String_();
	this->trainNumber.~String_();
}

void Train::setDestination(String_ destination)
{
	this->destination = destination;
}

void Train::setTrainNumber(String_ trainNumber)
{
	this->trainNumber = trainNumber;
}

void Train::setDepartureTime(Time_ departureTime)
{
	this->departureTime = departureTime;
}

void Train::setNumberOfSeats(int numberOfSeats)
{
	this->numberOfSeats = numberOfSeats;
}

void Train::setNumberOfCompartmentSeats(int numberOfCompartmentSeats)
{
	this->numberOfCompartmentSeats = numberOfCompartmentSeats;
}

void Train::setNumberOfReservedSeats(int numberOfReservedSeats)
{
	this->numberOfReservedSeats = numberOfReservedSeats;
}

String_ Train::getDestination() const
{
	return this->destination;
}

String_ Train::getTrainNumber() const
{
	return this->trainNumber;
}

Time_ Train::getDepartureTime() const
{
	return this->departureTime;
}

int Train::getNumberOfSeats() const
{
	return this->numberOfSeats;
}

int Train::getNumberOfCompartmentSeats() const
{
	return this->numberOfCompartmentSeats;
}

int Train::getNumberOfReservedSeats() const
{
	return this->numberOfReservedSeats;
}

Train & Train::operator=(const Train & a)
{
	if (&a == this)
		return *this;
	this->~Train();
	this->destination = a.destination;
	this->trainNumber = a.trainNumber;
	this->departureTime = a.departureTime;
	this->numberOfSeats = a.numberOfSeats;
	this->numberOfCompartmentSeats = a.numberOfCompartmentSeats;
	this->numberOfReservedSeats = a.numberOfReservedSeats;
	return *this;
}

std::ostream & operator<<(std::ostream & out, const Train & a)
{
	out << a.destination << std::endl << a.trainNumber << std::endl << a.departureTime << std::endl;
	out << a.numberOfSeats << std::endl << a.numberOfCompartmentSeats << std::endl << a.numberOfReservedSeats << std::endl;
	return out;
}
