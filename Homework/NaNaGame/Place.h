#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
class Place
{
private:
	std::vector<std::vector<int>> matrix;
public:
	Place();

	void game(int id, int player);
	void print();
	void push(int id, int player);
	bool check();
};

