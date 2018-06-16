#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <ctime>
#include <iterator>
void interface(std::map<std::string, std::string> &m);
void engToRu(std::map<std::string, std::string> &m);
void ruToEng(std::map<std::string, std::string> &m);

void interface(std::map<std::string, std::string> &m)
{
	std::cout << "Choose an option/Выберите вариант: " << std::endl;
	std::cout << "0. Exit/Выйти" << std::endl;
	std::cout << "1. Translate word from English to Russian" << std::endl;
	std::cout << "2. Перевести слово с русского на английский" << std::endl;
	int choose = 0;
	std::cin >> choose;
	switch (choose)
	{
	case 1:
		engToRu(m);
		break;
	case 2:
		ruToEng(m);
		break;
	default:
		break;
	}
}
void engToRu(std::map<std::string, std::string> &m)
{
	system("cls");
	std::cout << "Please, enter the word you want to translate" << std::endl;
	std::string word;
	std::cin >> word;
	std::ifstream file("engToRu.csv");
	std::string str1, str2;
	while (!file.eof())
	{
		str1.clear();
		str2.clear();
		getline(file, str1, ';');
		getline(file, str2, ';');
		if (str1[0] == '\n')
			str1.erase(0, 1);
		m.insert(std::make_pair(str1, str2));
	}
	auto it = m.find(word);
	if (it == m.end())
	{
		std::cout << "Word not found" << std::endl;
	}
	else
		std::cout << word << " - " << it->second << std::endl;
	std::cout << std::endl;
	interface(m);
}
void ruToEng(std::map<std::string, std::string> &m)
{
	system("cls");
	std::cout << "Пожалуйста, введите слово, которое вы хотите перевести" << std::endl;
	std::string word;
	std::cin >> word;
	std::ifstream file("engToRu.csv");
	std::string str1, str2;
	while (!file.eof())
	{
		str1.clear();
		str2.clear();
		getline(file, str1, ';');
		getline(file, str2, ';');
		if (str1[0] == '\n')
			str1.erase(0, 1);
		m.insert(std::make_pair(str1, str2));
	}
	auto it = m.find(word);
	if (it == m.end())
	{
		std::cout << "Слово не найдено" << std::endl;
	}
	else
		std::cout << word << " - " << it->second << std::endl;
	std::cout << std::endl;
	interface(m);
}

int main()
{
	setlocale(0, "");
	system("chcp 1251");
	system("cls");

	std::map<std::string, std::string> m;
	interface(m);

	system("pause");
	return 0;
}

