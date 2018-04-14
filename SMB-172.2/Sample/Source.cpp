#include "Book.h"
#include <vector>
#include <algorithm>

bool compare(const Book & b1, const Book & b2) 
{
	return b1.name < b2.name;
}
void sample() 
{
	bool(*comparator)(const Book &, const Book &) = compare;
	std::vector<Book> books;
	books.push_back(Book("rty", "asd", "123456", 100));
	books.push_back(Book("ert", "asd", "123456", 100));
	books.push_back(Book("wer", "asd", "123456", 100));
	books.push_back(Book("qwe", "asd", "123456", 100));
	
	for (int i = 0; i < books.size(); ++i)
	{
		std::cout << books[i].name << std::endl;
	}
	std::cout << std::endl;

	std::sort(books.begin(), books.end(), comparator);

	for (int i = 0; i < books.size(); ++i)
	{
		std::cout << books[i].name << std::endl;
	}
}

int main()
{
	sample();
	system("pause");
	return 0;
}
