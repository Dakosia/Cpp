#pragma once
#include <iostream>
#include <vector>

enum ship { ONE = 1, TWO = 2, THREE = 3, FOUR = 4 };
enum shoot_control { EMPTY, SHIP, HIT, KILL, MISS };
class Field
{
public:
	/*
	0 - пустая ячейка
	1 - корабль
	2 - подбил
	3 - убил
	4 - мимо
	*/
	std::vector<std::vector<int>> userField;
	std::vector<std::vector<int>> pcField;
	int size = 10;
	int userCnt = 20, pcCnt = 20;

	Field();
	bool check(int x, int y, std::vector<std::vector<int>>& field) const;
	bool killingCheck(int x, int y, std::vector<std::vector<int>>& field) const;

	void printField() const;
	void generation();
	bool addShip(ship s, std::vector<std::vector<int>>& field);
	void clear();

	void shoot(int x, int y, std::vector<std::vector<int>>& field);
	void fillKilledShip(int x, int y, std::vector<std::vector<int>>& field);
	void userAttack();
	void pcAttack();

	void game();
	void userMap() const;
	void pcMap() const;
};
