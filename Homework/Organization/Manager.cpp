#include "Manager.h"



Manager::Manager(std::string name, Date_ d, bool gender, int experience, int nmbOfSales) :
	Employee(name, d, gender, experience)
{
	this->setNmbOfSales(nmbOfSales);
}

void Manager::setNmbOfSales(int nmbOfSales)
{
	this->nmbOfSales = nmbOfSales;
}

int Manager::getNmbOfSales() const
{
	return this->nmbOfSales;
}

double Manager::getCoef() const
{
	double d = 1;
	double rateForSales = nmbOfSales * 0.01;
	double rateForExperience = experience * 0.001;
	d += rateForSales + rateForExperience;
	return d;
}

void Manager::getInfo() const
{
	Employee::getInfo();
	std::cout << "Number of sales: " << nmbOfSales << std::endl;
}