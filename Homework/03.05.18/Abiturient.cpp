#include "Abiturient.h"



Abiturient::Abiturient(String_ fio, String_ address, VectorMy marks)
{
	this->setFio(fio);
	this->setAddress(address);
	this->setMarks(marks);
}

Abiturient::~Abiturient()
{
	this->fio.~String_();
	this->address.~String_();
	this->marks.~VectorMy();
}

void Abiturient::setFio(String_ fio)
{
	this->fio = fio;
	//this->fio.operator=(fio);
}

void Abiturient::setAddress(String_ address)
{
	this->address = address;
}

void Abiturient::setMarks(VectorMy marks)
{
	this->marks = marks;
}

String_ Abiturient::getFio() const
{
	return this->fio;
}

String_ Abiturient::getAddress() const
{
	return this->address;
}

VectorMy Abiturient::getMarks() const
{
	return this->marks;
}

void Abiturient::addMark(int mark)
{
	this->marks.push_back(mark);
}

bool Abiturient::isLoser()
{
	for (size_t i = 0; i < this->marks.getSize(); i++)
	{
		if (this->marks[i] < 5)
		{
			return true;
		}
		return false;
	}
}

int Abiturient::getAvgMark()
{
	int sum = 0;
	for (size_t i = 0; i < this->marks.getSize(); i++)
	{
		sum += this->marks[i];
	}
	return sum / this->marks.getSize();;
}

Abiturient & Abiturient::operator=(const Abiturient & a)
{
	if (&a == this)
		return *this;
	this->~Abiturient();
	this->fio = a.fio;
	this->address = a.address;
	this->marks = a.marks;
	return *this;
}

std::ostream & operator<<(std::ostream & out, const Abiturient & a)
{
	out << a.fio << std::endl << a.address;
	out << std::endl << a.marks;
	return out;
}