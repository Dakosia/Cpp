#include "Employee.h"



Employee::Employee()
{
}

Employee::Employee(int _id, std::string _firstName, std::string _lastName, int _salary)
{
	id = _id;
	firstName = _firstName;
	lastName = _lastName;
	salary = _salary;
}


Employee::~Employee()
{
}

int Employee::getID()
{
	return id;
}

std::string Employee::getFirstName()
{
	return firstName;
}

std::string Employee::getLastName()
{
	return lastName;
}

std::string Employee::getName()
{
	return firstName + " " + lastName;
}

int Employee::getSalary()
{
	return salary;
}

void Employee::setSalary(int _salary)
{
	salary = _salary;
}

int Employee::getAnnualSalary()
{
	return salary * 12;
}

int Employee::raiseSalary(int _percent)
{
	return salary * _percent / 100 + salary;
}

std::string Employee::toString()
{
	return "Employee[id=" + std::to_string(id) + ", name=" + firstName + " " + lastName + ", salary=" + std::to_string(salary) + "]";
}
