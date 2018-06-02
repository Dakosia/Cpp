#include "Employee.h"



Employee::Employee(std::string name, Date_ d, bool gender, int experience) :
	human(name, d, gender)
{
	this->setExperience(experience);
}

void Employee::setExperience(int experience)
{
	this->experience = experience;
}

int Employee::getExperience() const
{
	return this->experience;
}

void Employee::getInfo() const
{
	human::getInfo();
	std::cout << "Work experience: " << experience << " years" << std::endl;
}