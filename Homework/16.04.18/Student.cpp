#include "Student.h"



Student::Student()
{
}


Student::~Student()
{
}

void Student::setLastName(std::string _lastName)
{
	lastName = _lastName;
}

void Student::setFirstName(std::string _firstName)
{
	firstName = _firstName;
}

void Student::setMiddleName(std::string _middleName)
{
	middleName = _middleName;
}

void Student::setDateOfBirth(std::string _dateOfBirth)
{
	dateOfBirth = _dateOfBirth;
}

void Student::setPhoneNumber(std::string _phoneNumber)
{
	phoneNumber = _phoneNumber;
}

void Student::setAddress(std::string _address)
{
	address = _address;
}

void Student::setFaculty(std::string _faculty)
{
	faculty = _faculty;
}

void Student::setCourse(int _course)
{
	course = _course;
}

void Student::setRating(int _rating)
{
	rating = _rating;
}

std::string Student::getLastName()
{
	return lastName;
}

std::string Student::getFirstName()
{
	return firstName;
}

std::string Student::getMiddleName()
{
	return middleName;
}

std::string Student::getDateOfBirth()
{
	return dateOfBirth;
}

std::string Student::getPhoneNumber()
{
	return phoneNumber;
}

std::string Student::getAddress()
{
	return address;
}

std::string Student::getFaculty()
{
	return faculty;
}

int Student::getCourse()
{
	return course;
}

int Student::getRating()
{
	return rating;
}

void Student::print()
{
	std::cout << getLastName() << std::endl;
	std::cout << getFirstName() << std::endl;
	std::cout << getMiddleName() << std::endl;
	std::cout << getDateOfBirth() << std::endl;
	std::cout << getPhoneNumber() << std::endl;
	std::cout << getAddress() << std::endl;
	std::cout << getFaculty() << std::endl;
	std::cout << getCourse() << std::endl;
	std::cout << getRating() << std::endl;
}
