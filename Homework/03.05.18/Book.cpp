#include "Book.h"



Book::Book(String_ author, String_ title, String_ publishingHouse, int year, int numberOfPages)
{
	this->setAuthor(author);
	this->setTitle(title);
	this->setPublishingHouse(publishingHouse);
	this->setYear(year);
	this->setNumberOfPages(numberOfPages);
}

Book::~Book()
{
	this->author.~String_();
	this->title.~String_();
	this->publishingHouse.~String_();
}

void Book::setAuthor(String_ author)
{
	this->author = author;
}

void Book::setTitle(String_ title)
{
	this->title = title;
}

void Book::setPublishingHouse(String_ publishingHouse)
{
	this->publishingHouse = publishingHouse;
}

void Book::setYear(int year)
{
	this->year = year;
}

void Book::setNumberOfPages(int numberOfPages)
{
	this->numberOfPages = numberOfPages;
}

String_ Book::getAuthor() const
{
	return this->author;
}

String_ Book::getTitle() const
{
	return this->title;
}

String_ Book::getPublishingHouse() const
{
	return this->publishingHouse;
}

int Book::getYear() const
{
	return this->year;
}

int Book::getNumberOfPages() const
{
	return this->numberOfPages;
}

Book & Book::operator=(const Book & a)
{
	if (&a == this)
		return *this;
	this->~Book();
	this->author = a.author;
	this->title = a.title;
	this->publishingHouse = a.publishingHouse;
	this->year = a.year;
	this->numberOfPages = a.numberOfPages;
	return *this;
}

std::ostream & operator<<(std::ostream & out, const Book & a)
{
	out << a.author << std::endl << a.title << std::endl << a.publishingHouse << std::endl;
	out << a.year << std::endl << a.numberOfPages << std::endl;
	return out;
}
