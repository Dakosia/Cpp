#include "Group.h"



Group::Group()
{
	this->gr_name = new char[4];
	strcpy_s(this->gr_name, 4, "SMP");
	this->gr = new student[10];
}

Group::Group(char * name, int cnt)
{
	this->gr_name = new char[strlen(name) + 1];
	strcpy_s(this->gr_name, strlen(name) + 1, name);
	this->cnt = cnt;
	this->gr = new student[cnt];
}

Group::Group(const Group & obj)
{
	this->cnt = obj.cnt;
	this->gr_name = new char[strlen(obj.gr_name) + 1];
	strcpy_s(this->gr_name, strlen(obj.gr_name) + 1, obj.gr_name);
	this->gr = new student[obj.cnt];
	for (int i = 0; i < cnt; i++)
	{
		this->gr[i] = obj.gr[i];
	}
}

Group & Group::operator=(const Group & a)
{
	if (&a == this)
		return *this;
	this->~Group();
	this->cnt = a.cnt;
	this->gr_name = new char[strlen(a.gr_name) + 1];
	strcpy_s(this->gr_name, strlen(a.gr_name) + 1, a.gr_name);
	this->gr = new student[a.cnt];
	for (int i = 0; i < cnt; i++)
	{
		this->gr[i] = a.gr[i];
	}
	return *this;
}

Group::~Group()
{
	if (this->gr != nullptr)
	{
		delete[] this->gr;
		this->gr = nullptr;
	}
	delete[] this->gr_name;
	this->gr_name = nullptr;
	this->cnt = 0;
}