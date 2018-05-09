#include "Worker.h"



Worker::Worker(String_ fio, String_ position, int year, int salary)
{
	this->setFio(fio);
	this->setPosition(position);
	this->setYear(year);
	this->setSalary(salary);
}

Worker::~Worker()
{
	this->fio.~String_();
	this->position.~String_();
}

void Worker::setFio(String_ fio)
{
	this->fio = fio;
}

void Worker::setPosition(String_ position)
{
	this->position = position;
}

void Worker::setYear(int year)
{
	this->year = year;
}

void Worker::setSalary(int salary)
{
	this->salary = salary;
}

String_ Worker::getFio() const
{
	return this->fio;
}

String_ Worker::getPosition() const
{
	return this->position;
}

int Worker::getYear() const
{
	return this->year;
}

int Worker::getSalary() const
{
	return this->salary;
}

Worker & Worker::operator=(const Worker & a)
{
	if (&a == this)
		return *this;
	this->~Worker();
	this->fio = a.fio;
	this->position = a.position;
	this->year = a.year;
	this->salary = a.salary;
	return *this;
}

std::ostream & operator<<(std::ostream & out, const Worker & a)
{
	out << a.fio << std::endl << a.position << std::endl;
	out << a.year << std::endl << a.salary << std::endl;
	return out;
}
