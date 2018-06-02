#include "Developer.h"



Developer::Developer(std::string name, Date_ d, bool gender, int experience, int nmbProgLangs, std::string specialization) :
	Employee(name, d, gender, experience)
{
	this->setNmbProgLangs(nmbProgLangs);
	this->setSpecialization(specialization);
}

void Developer::setNmbProgLangs(int nmbProgLangs)
{
	this->nmbProgLangs = nmbProgLangs;
}

void Developer::setSpecialization(std::string specialization)
{
	this->specialization = specialization;
}

int Developer::getNmbProgLangs() const
{
	return this->nmbProgLangs;
}

std::string Developer::getSpecialization() const
{
	return this->specialization;
}

double Developer::getCoef() const
{
	double d = 1;
	double rateForLanguages = nmbProgLangs * 0.5;
	double rateForExperience = experience * 0.2;
	d += rateForLanguages + rateForExperience;
	return d;
}

void Developer::getInfo() const
{
	Employee::getInfo();
	std::cout << "Programming languages: " << nmbProgLangs << std::endl;
	std::cout << "Specialization: " << specialization << std::endl;
}