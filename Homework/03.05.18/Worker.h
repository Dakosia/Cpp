#pragma once
#include "String_.h"
class Worker
{
private:
	String_ fio;
	String_ position;
	int year;
	int salary;
public:
	Worker(String_ fio = "Fio", String_ position = "Position", int year = 2018, int salary = 100000);
	~Worker();

	//setters
	void setFio(String_ fio);
	void setPosition(String_ position);
	void setYear(int year);
	void setSalary(int salary);
	//getters
	String_ getFio() const;
	String_ getPosition() const;
	int getYear() const;
	int getSalary() const;

	Worker& operator=(const Worker &a);

	friend std::ostream& operator<<(std::ostream &out, const Worker &a);
};

std::ostream& operator<<(std::ostream &out, const Worker &a);
