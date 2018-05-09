#include "AirAstana.h"



AirAstana::AirAstana(String_ destination, String_ flightNumber, String_ airplaneType, Time_ departureTime, String_ day)
{
	this->setDestination(destination);
	this->setFlightNumber(flightNumber);
	this->setAirplaneType(airplaneType);
	this->setDepartureTime(departureTime);
	this->setDay(day);
}

AirAstana::~AirAstana()
{
	this->destination.~String_();
	this->flightNumber.~String_();
	this->airplaneType.~String_();
	this->day.~String_();
}

void AirAstana::setDestination(String_ destination)
{
	this->destination = destination;
}

void AirAstana::setFlightNumber(String_ flightNumber)
{
	this->flightNumber = flightNumber;
}

void AirAstana::setAirplaneType(String_ airplaneType)
{
	this->airplaneType = airplaneType;
}

void AirAstana::setDepartureTime(Time_ departureTime)
{
	this->departureTime = departureTime;
}

void AirAstana::setDay(String_ day)
{
	this->day = day;
}

String_ AirAstana::getDestination() const
{
	return this->destination;
}

String_ AirAstana::getFlightNumber() const
{
	return this->flightNumber;
}

String_ AirAstana::getAirplaneType() const
{
	return this->airplaneType;
}

Time_ AirAstana::getDepartureTime() const
{
	return this->departureTime;
}

String_ AirAstana::getDay() const
{
	return this->day;
}

AirAstana & AirAstana::operator=(const AirAstana & a)
{
	if (&a == this)
		return *this;
	this->~AirAstana();
	this->destination = a.destination;
	this->flightNumber = a.flightNumber;
	this->airplaneType = a.airplaneType;
	this->departureTime = a.departureTime;
	this->day = a.day;
	return *this;
}

std::ostream & operator<<(std::ostream & out, const AirAstana & a)
{
	out << a.destination << std::endl << a.flightNumber << std::endl << a.airplaneType << std::endl << a.departureTime << std::endl << a.day << std::endl;
	return out;
}
