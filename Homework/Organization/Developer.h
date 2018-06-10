#pragma once
#include "Employee.h"
class Developer final :
	public Employee
{
private:
	int nmbProgLangs;
public:
	Developer(std::string name = "Unknown", Date_ d = Date_(), bool gender = 1, int experience = 0, int nmbProgLangs = 0);

	void setNmbProgLangs(int nmbProgLangs);
	int getNmbProgLangs() const;

	double getCoef() const override;
	void getInfo() const override;
	std::string codeInfo() const override;
};
