#pragma once
#include <iostream>
#include <vector>

enum ship { ONE = 1, TWO = 2, THREE = 3, FOUR = 4 };
enum shoot_control { EMPTY = 0, SHIP = 1, HIT = 2, KILL = 3, MISS = 4 };
class Field
{
public:
	std::vector<std::vector<int>> field;
	bool check(int x, int y) const;
	bool killingCheck(int x, int y) const;
	/*
	0 - пустая ячейка
	1 - корабль
	2 - подбил
	3 - убил
	4 - мимо
	*/

public:
	Field();

	void printField() const;
	void generation();
	bool addShip(ship s);
	void clear();
	int shoot(int x, int y);
	void fillKilledShip(int x, int y);
};