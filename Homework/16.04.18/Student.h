#pragma once
#include <iostream>
#include <string>
class Student
{
private:
	std::string lastName; //фамилия
	std::string firstName; //имя - в динамической памяти
	std::string middleName; //отчество
	std::string dateOfBirth;
	std::string phoneNumber;
	std::string address;
	std::string faculty;
	int course;
	int rating;
public:
	Student();
	~Student();

	void setLastName(std::string);
	void setFirstName(std::string);
	void setMiddleName(std::string);
	void setDateOfBirth(std::string);
	void setPhoneNumber(std::string);
	void setAddress(std::string);
	void setFaculty(std::string);
	void setCourse(int);
	void setRating(int);

	std::string getLastName();
	std::string getFirstName();
	std::string getMiddleName();
	std::string getDateOfBirth();
	std::string getPhoneNumber();
	std::string getAddress();
	std::string getFaculty();
	int getCourse();
	int getRating();

	void print();
};

