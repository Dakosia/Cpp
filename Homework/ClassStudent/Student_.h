#pragma once
#include <iostream>
#include "String_.h"
#include "vector_.h"
#include <ctime>
class Student_
{
private:
	String_ name;
	String_ surname;
	int age;
	int id;
	vector_<int> marks;
public:
	Student_(String_ name = "Name", String_ surname = "Surname", int age = 18, int id = 0, vector_<int> marks = vector_<int>());

	void setName(String_ name);
	void setSurname(String_ surname);
	void setAge(int age);
	void setId(int id);
	void setMarks(vector_<int> marks);

	String_ getName() const;
	String_ getSurname() const;
	int getAge() const;
	int getId() const;
	vector_<int> getMarks() const;

	void addMark(int mark);
	void deleteLastMark();
	int getAvgMark();

	friend std::ostream& operator<<(std::ostream &out, const Student_ &obj);
};

std::ostream& operator<<(std::ostream &out, const Student_ &obj);