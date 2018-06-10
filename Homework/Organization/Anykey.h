#pragma once
#include "Admin.h"
class Anykey :
	public Admin
{
public:
	Anykey(std::string name = "Unknown", Date_ d = Date_(), bool gender = 1);
	double getCoef() const override;
	std::string codeInfo() const override;
};

