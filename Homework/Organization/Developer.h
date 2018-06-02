#pragma once
#include "Employee.h"
class Developer final :
	public Employee
{
private:
	int nmbProgLangs;
	std::string specialization;
public:
	Developer(std::string name = "Unknown", Date_ d = Date_(), bool gender = 1, int experience = 0, int nmbProgLangs = 0, std::string specialization = "DEV");

	void setNmbProgLangs(int nmbProgLangs);
	void setSpecialization(std::string specialization);
	int getNmbProgLangs() const;
	std::string getSpecialization() const;

	double getCoef() const override;
	void getInfo() const override;
};
