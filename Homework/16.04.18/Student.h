#pragma once
#include <iostream>
#include <string>
class Student
{
private:
	char* name;
	int age;
	char* group_name;
	int* marks;
public:
	Student(const char*, int, const char*, const int*);
	Student(const Student &obj);
	~Student();

	void print();
};
