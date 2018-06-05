#pragma once
#include <iostream>
#include <string>
class OurException :
	public std::exception
{
	int errorLevel;
	std::string s;
public:
	OurException(std::string error, int errorLevel);

	void setErrorLevel(int errorLevel);
	int getErrorLevel() const;

	const char* what() const override;
};