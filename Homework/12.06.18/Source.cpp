#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <fstream>
#include <ctime>

bool moreThan500(const int &val)
{
	return (val > 500);
}

int main()
{
	//Задание 1
	std::vector<int> v;
	for (size_t i = 0; i < 10; i++)
		v.push_back(i * i);
	/*std::ofstream file("1.txt");
	std::ostream_iterator<int> os(file, " ");
	copy(v.rbegin(), v.rend(), os);
	file.close();*/
	for (std::vector<int>::reverse_iterator rIt = v.rbegin(); rIt != v.rend(); rIt++)
	{
		std::cout << *rIt << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	//Задание 2
	std::vector<int> v1;
	for (size_t i = 0; i < 10; i++)
		v1.push_back(i);
	v1.insert(v1.begin() + 9, 3, 50);
	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	//Задание 3
	srand(time(NULL));
	std::list<int> l;
	for (size_t i = 0; i < 20; i++)
		l.push_back(rand() % 1001);
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	l.remove_if(moreThan500);
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	system("pause");
	return 0;
}