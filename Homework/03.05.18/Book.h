#pragma once
#include "String_.h"
class Book
{
private:
	String_ author;
	String_ title;
	String_ publishingHouse;
	int year;
	int numberOfPages;
public:
	Book(String_ author = "Author", String_ title = "Title", String_ publishingHouse = "Publishing House", int year = 2018, int numberOfPages = 200);
	~Book();
	//setters
	void setAuthor(String_ author);
	void setTitle(String_ title);
	void setPublishingHouse(String_ publishingHouse);
	void setYear(int year);
	void setNumberOfPages(int numberOfPages);
	//getters
	String_ getAuthor() const;
	String_ getTitle() const;
	String_ getPublishingHouse() const;
	int getYear() const;
	int getNumberOfPages() const;

	Book& operator=(const Book &a);

	friend std::ostream& operator<<(std::ostream &out, const Book &a);
};

std::ostream& operator<<(std::ostream &out, const Book &a);
