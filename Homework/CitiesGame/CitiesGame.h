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
public:
	CitiesGame(std::string dir);
	void play();
	void check_city(std::string city) const;
	void multiplay(int pos);
};


