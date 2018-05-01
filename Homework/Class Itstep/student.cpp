#include "student.h"




student::student()
{
	this->name = new char[5];
	strcpy_s(this->name, 5, "none"); //none
	this->age = 17;
}

student::student(const char *n, int age)
{
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);

	this->age = age;
}

student::student(const student & obj)
{
	this->name = new char[strlen(obj.name) + 1];
	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);

	this->age = obj.age;

}

student & student::operator=(const student & st)
{
	if (&st == this)
		return *this;
	this->age = st.age;
	if (strlen(this->name) != strlen(st.name))
	{
		delete[] this->name;
		this->name = new char[strlen(st.name) + 1];
	}
	strcpy_s(this->name, strlen(st.name) + 1, st.name);
	return *this;
}

student::~student()
{
	delete[] this->name;
}

void student::print()
{
	std::cout << "Student name: " << name << std::endl;
	std::cout << "Student age: " << age << std::endl;
}
