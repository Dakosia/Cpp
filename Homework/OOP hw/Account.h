#pragma once
#include <string>
#include <iostream>
class Account
{
private:
	std::string id;
	std::string name;
	int balance = 0;
public:
	Account();
	Account(std::string, std::string);
	Account(std::string, std::string, int);
	~Account();

	std::string getID();
	std::string getName();
	int getBalance();
	int credit(int);
	int debit(int);
	int transferTo(Account, int);
	std::string toString();
};

