#include "Account.h"



Account::Account()
{
}

Account::Account(std::string _id, std::string _name)
{
	id = _id;
	name = _name;
}

Account::Account(std::string _id, std::string _name, int _balance)
{
	id = _id;
	name = _name;
	balance = _balance;
}


Account::~Account()
{
}

std::string Account::getID()
{
	return id;
}

std::string Account::getName()
{
	return name;
}

int Account::getBalance()
{
	return balance;
}

int Account::credit(int _amount)
{
	balance += _amount;
	return balance;
}

int Account::debit(int _amount)
{
	if (_amount <= balance)
	{
		balance -= _amount;
	}
	else
	{
		std::cout << "Amount exceeded balance" << std::endl;
	}
	return balance;
}

int Account::transferTo(Account _another, int _amount)
{
	if (_amount <= balance)
	{
		_another.balance += _amount;
		balance -= _amount;
	}
	else
	{
		std::cout << "Amount exceeded balance" << std::endl;
	}
	return balance;
}

std::string Account::toString()
{
	return "Account[id=" + id + ", name=" + name + ", balance=" + std::to_string(balance) + "]";
}
