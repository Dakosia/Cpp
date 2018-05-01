#pragma once
#include "student.h"
class Group
{
private:
	student *gr;
	char *gr_name;
	int cnt;
public:
	Group();
	Group(char *name, int cnt);
	Group(const Group &obj);
	Group& operator=(const Group &gr);
	~Group();
};