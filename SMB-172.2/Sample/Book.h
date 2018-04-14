#include <iostream>
#include <string>
#pragma once
class Book
{
public:
	std::string name, author, publishDate;
	int pages;
	Book(std::string _name, std::string _author, std::string _publishDate, int _pages);
	Book();
	~Book();
};
