#pragma once
#include <string>
#include <iostream>
class Human
{
protected:
	std::string name;
	int age;
	std::string password;
public:
	Human();
	Human(std::string, std::string, int);
	~Human();
	void setPassword(std::string);
	void saySomething();
protected:
	std::string getPassword();
};
