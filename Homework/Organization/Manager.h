#pragma once
#include "Employee.h"
class Manager :
	public Employee
{
private:
	int nmbOfSales;
public:
	Manager(std::string name = "Unknown", Date_ d = Date_(), bool gender = 1, int experience = 0, int nmbOfSales = 1);

	void setNmbOfSales(int nmbOfSales);
	int getNmbOfSales() const;

	double getCoef() const override;
	void getInfo() const override;
	std::string codeInfo() const override;
};