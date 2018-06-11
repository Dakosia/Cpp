#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <iterator>
#include <fstream>

int main()
{
	//Домашняя работа
	//Задание 1
	std::vector<double> v = { 1.1,2.5,3.3,4.9, 172.34, 30, 0.9834 };
	std::ofstream file("1.txt");

	std::ostream_iterator<double> os(file, "\t");
	copy(v.begin(), v.end(), os);
	file.close();

	//Задание 2
	std::vector<double> v1;
	std::ifstream f("1.txt");
	std::istream_iterator<double> it(f);
	copy(it, std::istream_iterator<double>(), back_inserter(v1));
	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << " ";
	}


	/*int *arr = new int[4]{ 1,2,3,4 };
	for (size_t i = 0; i < 4; i++)
	{
	std::cout << arr[i] << " ";
	}
	for (int *a = arr; a < (arr + 4); a++)
	{
	std::cout << *a << " ";
	}

	std::vector<int> v = { 1,2,3,4 };
	for (std::vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
	std::cout << *it << " ";
	}

	std::list<int> l = { 1,2,3,4 };
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
	std::cout << *it << " ";
	}
	distance(l.end(), l.begin());*/


	/*std::vector<int> v = { 1,2,3,4 };
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::reverse_iterator rit = v.rbegin();
	std::vector<int>::const_iterator cit = v.cbegin();
	std::vector<int>::const_reverse_iterator crit = v.crbegin();
	for (std::vector<int>::reverse_iterator rIt = v.rbegin(); rIt != v.rend(); rIt++)
	{
	std::cout << *rIt << "";
	}*/

	/*std::vector<int> v = { 1,2,3,4 };
	std::ofstream file("1.txt");

	std::ostream_iterator<int> os(file, " ");
	copy(v.begin(), v.end(), os);
	file.close();*/

	//std::ifstream file("1.txt");
	//std::vector<int> v;
	//std::istream_iterator<int> it(file);
	//copy(it, std::istream_iterator<int>(), back_inserter(v));
	//for (size_t i = 0; i < v.size(); i++)
	//{
	//	std::cout <<  << " ";
	//}

	//char c;
	//wchar_t c1; //2 байта, вмещает около 64к символов
	///*std::string str;
	//str.reserve(150);
	//std::cout << "size = " << str.size() << std::endl;
	//std::cout << "max size = " << str.max_size() << std::endl;
	//std::cout << "capacity = " << str.capacity() << std::endl;
	//std::cout << "length = " << str.length() << std::endl;
	//str.push_back('q');*/

	/*std::string str;
	getline(std::cin, str);
	std::string str2 = str;
	reverse(str.begin(), str.end());
	std::cout << std::boolalpha << (str == str2);*/

	system("pause");
	return 0;
}