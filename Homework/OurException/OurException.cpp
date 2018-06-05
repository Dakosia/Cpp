#include "OurException.h"



OurException::OurException(std::string error, int errorLevel) :
	exception(error.c_str())
{
	this->errorLevel = errorLevel;
}

void OurException::setErrorLevel(int errorLevel)
{
	this->errorLevel = errorLevel;
}

int OurException::getErrorLevel() const
{
	return this->errorLevel;
}

const char * OurException::what() const
{
	std::string &s2 = const_cast<std::string&>(s);
	s2 += exception::what();
	s2 += " Error level ";
	s2 += std::to_string(errorLevel);
	return s2.c_str();
}