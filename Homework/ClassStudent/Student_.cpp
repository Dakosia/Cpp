#include "Student_.h"



Student_::Student_(String_ name, String_ surname, int age, int id, vector_<int> marks)
{
	this->setName(name);
	this->setSurname(surname);
	this->setAge(age);
	this->setId(id);
	this->setMarks(marks);
}

void Student_::setName(String_ name)
{
	this->name = name;
}

void Student_::setSurname(String_ surname)
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

void Student_::setMarks(vector_<int> marks)
{
	this->marks = marks;
}

String_ Student_::getName() const
{
	return this->name;
}

String_ Student_::getSurname() const
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

vector_<int> Student_::getMarks() const
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
	for (size_t i = 0; i < this->marks.getSize(); i++)
	{
		sum += this->marks[i];
	}
	return sum / this->marks.getSize();;
}

std::ostream & operator<<(std::ostream & out, const Student_ & obj)
{
	out << obj.name << std::endl << obj.surname;
	out << std::endl << obj.age << std::endl << obj.id << std::endl << obj.marks;
	return out;
}