#pragma once
#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>

class CitiesGame {
	std::map < std::string, int > cities;
	char nextWord = '.';
	std::string dir;
	std::vector<int> players;
public:
	CitiesGame(std::string dir, int players);
	void play();
	void check_city(std::string city) const;
	void multiplay(int pos);
};


