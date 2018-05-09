#pragma once
#include "String_.h"
#include "Time_.h"
class AirAstana
{
private:
	String_ destination;
	String_ flightNumber;
	String_ airplaneType;
	Time_ departureTime;
	String_ day;
public:
	AirAstana(String_ destination = "Destination", String_ flightNumber = "Flight Number", String_ airplaneType = "Airplane Type", Time_ departureTime = Time_(), String_ day = "Day");
	~AirAstana();
	//setters
	void setDestination(String_ destination);
	void setFlightNumber(String_ flightNumber);
	void setAirplaneType(String_ airplaneType);
	void setDepartureTime(Time_ departureTime);
	void setDay(String_ day);
	//getters
	String_ getDestination() const;
	String_ getFlightNumber() const;
	String_ getAirplaneType() const;
	Time_ getDepartureTime() const;
	String_ getDay() const;

	AirAstana& operator=(const AirAstana &a);

	friend std::ostream& operator<<(std::ostream &out, const AirAstana &a);
};

std::ostream& operator<<(std::ostream &out, const AirAstana &a);
