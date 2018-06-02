#pragma once
#include "Employee.h"
class Admin :
	public Employee
{
private:
	int nmbOfComps;
public:
	Admin(std::string name = "Unknown", Date_ d = Date_(), bool gender = 1, int experience = 0, int nmbOfComps = 1);

	void setNmbOfComps(int nmbOfComps);
	int getNmbOfComps() const;

	double getCoef() const override;
	void getInfo() const override;
};