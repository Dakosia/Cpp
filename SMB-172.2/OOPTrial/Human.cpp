#include "Human.h"

Human::Human()
{
	std::cout << "Human created" << std::endl;
}

Human::Human(std::string _name, std::string _password, int _age)
{
	name = _name;
	password = _password;
	age = _age;
}

Human::~Human()
{
	std::cout << "Human deleted" << std::endl;
}

void Human::saySomething()
{
	std::cout << "I'm human: " << name << ' '  << password << ' ' << age << std::endl;
}

std::string Human::getPassword() {
	return password;
}

void Human::setPassword(std::string _password) {
	if (_password.length() < 8) {

	}
	else {
		password = _password;
	}
}