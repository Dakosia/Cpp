#pragma once
#include <string>
#include <iostream>
class Employee
{
private:
	int id;
	std::string firstName;
	std::string lastName;
	int salary;
public:
	Employee();
	Employee(int, std::string, std::string, int);
	~Employee();

	int getID();
	std::string getFirstName();
	std::string getLastName();
	std::string getName();
	int getSalary();
	void setSalary(int);
	int getAnnualSalary();
	int raiseSalary(int);
	std::string toString();
};

