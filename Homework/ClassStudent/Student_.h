#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
class Student_
{
private:
	std::string name;
	std::string surname;
	int age;
	int id;
	std::vector<int> marks;
public:
	Student_(std::string name = "Name", std::string surname = "Surname", int age = 18, int id = 0, std::vector<int> marks = std::vector<int>());

	void setName(std::string name);
	void setSurname(std::string surname);
	void setAge(int age);
	void setId(int id);
	void setMarks(std::vector<int> marks);

	std::string getName() const;
	std::string getSurname() const;
	int getAge() const;
	int getId() const;
	std::vector<int> getMarks() const;

	void addMark(int mark);
	void deleteLastMark();
	int getAvgMark();

	friend std::ostream& operator<<(std::ostream &out, const Student_ &obj);
};

std::ostream& operator<<(std::ostream &out, const Student_ &obj);