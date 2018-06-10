#pragma once
#include <iostream>
#include <string>
#include "Date_.h"
class human
{
private:
	std::string name;
	Date_ birthDate;
	bool gender;
public:
	human(std::string name = "Unknown", Date_ d = Date_(), bool gender = 1);

	void setName(std::string name);
	void setDate(int day, int month, int year);
	void setGender(bool gender);
	const std::string& getName() const;
	const Date_& getBirthDate() const;
	bool getGender() const;

	virtual void getInfo() const;
	virtual std::string codeInfo() const;
};