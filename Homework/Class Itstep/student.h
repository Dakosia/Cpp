#pragma once
#include <iostream>
#include <string>
class student
{
private:
	char* name;
	int age;
public:
	student();
	student(const char* n, int age);
	student(const student &obj);
	student& operator=(const student &obj);
	~student();

	void print();
};
