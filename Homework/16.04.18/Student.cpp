#include "Student.h"




Student::Student(const char *n, int a, const char *gr_name, const int *m)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);

	age = a;

	group_name = new char[strlen(gr_name) + 1];
	strcpy_s(group_name, strlen(gr_name) + 1, gr_name);

	int size = sizeof(m) / sizeof(int);
	marks = new int[size];
	for (int i = 0; i < size; i++)
	{
		marks[i] = m[i];
	}
}

Student::Student(const Student & obj)
{
	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(name) + 1, obj.name);

	age = obj.age;

	group_name = new char[strlen(obj.group_name) + 1];
	strcpy_s(group_name, strlen(group_name) + 1, obj.group_name);

	int size = sizeof(obj.marks) / sizeof(int);
	marks = new int[size];
	for (int i = 0; i < size; i++)
	{
		marks[i] = obj.marks[i];
	}

}

Student::~Student()
{
	delete[] name;
	delete[] group_name;
	delete[] marks;
}

void Student::print()
{
	std::cout << "Student name: " << name << std::endl;
	std::cout << "Student age: " << age << std::endl;
	std::cout << "Group name: " << group_name << std::endl;
	std::cout << "Student marks: ";
	for (size_t i = 0; i < sizeof(marks) / sizeof(int); ++i)
	{
		std::cout << marks[i] << " ";
	}
	std::cout << std::endl;
}