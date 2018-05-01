#include "Itstep.h"



Itstep::Itstep(int count)
{
	this->count = count;
	this->arr = new Group[count];
}

Itstep::Itstep(const Itstep & obj)
{
	this->count = obj.count;
	this->arr = new Group[obj.count];
	for (int i = 0; i < count; i++)
	{
		this->arr[i] = obj.arr[i];
	}
}

Itstep & Itstep::operator=(const Itstep & a)
{
	if (&a == this)
		return *this;
	this->~Itstep();
	this->count = a.count;
	this->arr = new Group[a.count];
	for (int i = 0; i < count; i++)
	{
		this->arr[i] = a.arr[i];
	}
	return *this;
}


Itstep::~Itstep()
{
	if (this->arr != nullptr)
	{
		delete this->arr;
		this->arr = nullptr;
	}
	this->count = 0;
}