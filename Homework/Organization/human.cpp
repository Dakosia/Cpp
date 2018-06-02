#include "human.h"



human::human(std::string name, Date_ d, bool gender)
{
	this->setName(name);
	this->birthDate = d;
	this->setGender(gender);
}

void human::setName(std::string name)
{
	this->name = name;
}

void human::setDate(int day, int month, int year)
{
	this->birthDate.setDay(day);
	this->birthDate.setMonth(month);
	this->birthDate.setYear(year);
}

void human::setGender(bool gender)
{
	this->gender = gender;
}

const std::string& human::getName() const
{
	return this->name;
}

const Date_ & human::getBirthDate() const
{
	return this->birthDate;
}

bool human::getGender() const
{
	return this->gender;
}

void human::getInfo() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Birthdate: " << birthDate << std::endl;
	std::cout << "Gender: " << (gender == 1 ? "Male" : "Female") << std::endl;
}