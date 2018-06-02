#pragma once
#include "Employee.h"
#include <vector>
#include <memory>
class Organization
{
private:
	std::string name;
	std::vector<std::auto_ptr<Employee>> emps;
	double salary;
public:
	Organization(std::string name = "Unknown", double salary = 100000);

	void setName(std::string name);
	void setSalary(double salary);
	std::string getName() const;
	double getSalary() const;

	void addEmployee(Employee* emp);
	void deleteEmployee(int pos);
	void changeEmployeeName(int pos, std::string name);
	void changeEmployeeBirthdate(int pos, int day, int month, int year);
	void changeEmployeeGender(int pos, bool gender);
	void changeEmployeeExperience(int pos, int experience);
	void needForSalary();

	void getInfo() const;
};