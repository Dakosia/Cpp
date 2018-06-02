#include "Admin.h"



Admin::Admin(std::string name, Date_ d, bool gender, int experience, int nmbOfComps) :
	Employee(name, d, gender, experience)
{
	this->setNmbOfComps(nmbOfComps);
}

void Admin::setNmbOfComps(int nmbOfComps)
{
	this->nmbOfComps = nmbOfComps;
}

int Admin::getNmbOfComps() const
{
	return this->nmbOfComps;
}

double Admin::getCoef() const
{
	double d = 1;
	double rateForComp = nmbOfComps * 0.05;
	double rateForExperience = experience * 0.1;
	d += rateForComp + rateForExperience;
	return d;
}

void Admin::getInfo() const
{
	Employee::getInfo();
	std::cout << "Number of computers: " << nmbOfComps << std::endl;
}