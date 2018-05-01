#pragma once
#include "Group.h"
class Itstep
{
private:
	Group *arr;
	int count;
public:
	Itstep(int count);
	Itstep(const Itstep &obj);
	Itstep& operator=(const Itstep &a);
	~Itstep();
};