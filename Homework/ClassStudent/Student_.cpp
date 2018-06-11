#include "Student_.h"



Student_::Student_(std::string name, std::string surname, int age, int id, std::vector<int> marks)
{
	this->setName(name);
	this->setSurname(surname);
	this->setAge(age);
	this->setId(id);
	this->setMarks(marks);
}

void Student_::setName(std::string name)
{
	this->name = name;
}

void Student_::setSurname(std::string surname)
{
	this->surname = surname;
}

void Student_::setAge(int age)
{
	this->age = age;
}

void Student_::setId(int id)
{
	this->id = id;
}

void Student_::setMarks(std::vector<int> marks)
{
	this->marks = marks;
}

std::string Student_::getName() const
{
	return this->name;
}

std::string Student_::getSurname() const
{
	return this->surname;
}

int Student_::getAge() const
{
	return this->age;
}

int Student_::getId() const
{
	return this->id;
}

std::vector<int> Student_::getMarks() const
{
	return this->marks;
}

void Student_::addMark(int mark)
{
	this->marks.push_back(mark);
}

void Student_::deleteLastMark()
{
	this->marks.pop_back();
}

int Student_::getAvgMark()
{
	int sum = 0;
	for (size_t i = 0; i < this->marks.size(); i++)
	{
		sum += this->marks[i];
	}
	return sum / this->marks.size();;
}

std::ostream & operator<<(std::ostream & out, const Student_ & obj)
{
	out << "Name: " << obj.name << std::endl;
	out << "Surname: " << obj.surname << std::endl;
	out << "Age: " << obj.age << std::endl;
	out << "ID: " << obj.id << std::endl;
	out << "Marks: ";
	for (size_t i = 0; i < obj.marks.size(); i++)
	{
		out << obj.marks[i] << ' ';
	}
	out << std::endl;
	return out;
}