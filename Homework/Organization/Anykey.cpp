#include "Anykey.h"



Anykey::Anykey(std::string name, Date_ d, bool gender) :
	Admin(name, d, gender, 0, 0)
{
}

double Anykey::getCoef() const
{
	return 0.5;
}

std::string Anykey::codeInfo() const
{
	std::string str = "Anykey;";
	str += Employee::codeInfo();
	str += std::to_string(getNmbOfComps()) += ';';
	return str;
}
