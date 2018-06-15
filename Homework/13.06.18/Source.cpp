#include <iostream>
#include <map>
#include <string>

int main()
{
	std::multimap<std::string, std::string> m;
	m.insert(std::make_pair("Dragneel", "+77016695843"));
	m.insert(std::make_pair("Heartfilia", "+77073652000"));
	m.insert(std::make_pair("Fullbuster", "+77015608815"));
	m.insert(std::make_pair("Dragneel", "+77023267580"));
	m.insert(std::make_pair("Scarlet", "+77478000008"));
	m.insert(std::make_pair("Redfox", "+77003206620"));
	m.insert(std::make_pair("Dreyar", "+77029959599"));
	m.insert(std::make_pair("Dreyar", "+77010124578"));

	std::string str;
	std::cout << "Enter surname" << std::endl;
	std::cin >> str;
	auto it = m.equal_range(str);
	for (auto i = it.first; i != it.second; i++)
	{
		std::cout << i->first << " " << i->second << std::endl;
	}


	system("pause");
	return 0;
}