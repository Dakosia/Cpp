#include "Organization.h"



Organization::Organization(std::string name, double salary)
{
	this->setName(name);
	this->setSalary(salary);
}

void Organization::setName(std::string name)
{
	this->name = name;
}

void Organization::setSalary(double salary)
{
	this->salary = salary;
}

std::string Organization::getName() const
{
	return this->name;
}

double Organization::getSalary() const
{
	return this->salary;
}

void Organization::addEmployee(Employee * emp)
{
	emps.push_back(std::auto_ptr<Employee>(emp));
}

void Organization::deleteEmployee(int pos)
{
	if (pos < emps.size())
		emps.erase(emps.begin() + pos);
}

void Organization::changeEmployeeName(int pos, std::string name)
{
	if (pos < emps.size())
		emps[pos]->setName(name);
}

void Organization::changeEmployeeBirthdate(int pos, int day, int month, int year)
{
	if (pos < emps.size())
		emps[pos]->setDate(day, month, year);
}

void Organization::changeEmployeeGender(int pos, bool gender)
{
	if (pos < emps.size())
		emps[pos]->setGender(gender);
}

void Organization::changeEmployeeExperience(int pos, int experience)
{
	if (pos < emps.size())
		emps[pos]->setExperience(experience);
}

void Organization::needForSalary()
{
	double sum = 0.0;
	for (size_t i = 0; i < emps.size(); i++)
	{
		sum += emps[i]->getCoef() * salary;
	}
	std::cout << "Need for salary: " << sum << std::endl << "----------\n";
}

void Organization::getInfo() const
{
	std::cout << "Oraganization name: " << name << std::endl << "----------\n";
	for (size_t i = 0; i < emps.size(); i++)
	{
		//std::cout << std::string(typeid(*emps[i]).name()).substr(6) << ":\n";
		std::string pos = typeid(*emps[i]).name();
		pos = pos.substr(6);
		std::cout << pos << ":\n";
		emps[i].get()->getInfo();
		std::cout << std::endl;
		std::cout << "Salary: " << emps[i]->getCoef() * salary << std::endl << "----------\n";
	}
}