#include "Developer.h"



Developer::Developer(std::string name, Date_ d, bool gender, int experience, int nmbProgLangs) :
	Employee(name, d, gender, experience)
{
	this->setNmbProgLangs(nmbProgLangs);
}

void Developer::setNmbProgLangs(int nmbProgLangs)
{
	this->nmbProgLangs = nmbProgLangs;
}

int Developer::getNmbProgLangs() const
{
	return this->nmbProgLangs;
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
}

std::string Developer::codeInfo() const
{
	std::string str = "Developer;";
	str += Employee::codeInfo();
	str += std::to_string(nmbProgLangs) += ';';
	return str;
}
