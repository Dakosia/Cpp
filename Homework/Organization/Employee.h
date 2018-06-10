#pragma once
#include "human.h"
class Employee abstract :
	public human
{
protected:
	int experience;
public:
	Employee(std::string name = "Unknown", Date_ d = Date_(), bool gender = 1, int experience = 0);

	void setExperience(int experience);
	int getExperience() const;

	virtual double getCoef() const = 0;
	void getInfo() const override;
	std::string codeInfo() const override;
};