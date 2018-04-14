#include "Book.h"



Book::Book(std::string _name, std::string _author, std::string _publishDate, int _pages)
{
	name = _name;
	author = _author;
	publishDate = _publishDate;
	pages = _pages;
}

Book::Book()
{
}


Book::~Book()
{
}
