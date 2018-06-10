#include "Field.h"



bool Field::check(int x, int y) const
{
	if (x == 0 || y == 0 || x == 11 || y == 11)
		return false;
	for (size_t i = x - 1; i < x + 2; i++)
	{
		for (size_t j = y - 1; j < y + 2; j++)
		{
			/*if (i < 0 || j < 0 || i > 11 || j > 11)
			return false;*/
			if (this->field[i][j] != shoot_control::EMPTY)
				return false;
		}
	}
	return true;
}
//check for killed ships
bool Field::killingCheck(int x, int y) const
{
	for (size_t i = x - 1; i < x + 2; i++)
	{
		for (size_t j = y - 1; j < y + 2; j++)
		{
			if (x == i && y == j)
				continue;
			if (this->field[i][j] == shoot_control::SHIP)
				return false;
		}
	}
	return true;
}

Field::Field()
{
	field = std::vector<std::vector<int>>(12);
	for (size_t i = 0; i < field.size(); i++)
	{
		for (size_t j = 0; j < field.size(); j++)
		{
			field[i].push_back(0);
		}
	}
}

void Field::printField() const
{
	for (size_t i = 0; i < field.size(); i++)
	{
		for (size_t j = 0; j < field.size(); j++)
		{
			std::cout << field[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void Field::generation()
{
	/*
	4 - 1
	3 - 2
	2 - 3
	1 - 4
	*/
	while (!addShip(ship::FOUR)) {}
	for (size_t i = 0; i < 2; i++)
	{
		while (!addShip(ship::THREE)) {}
	}
	for (size_t i = 0; i < 3; i++)
	{
		while (!addShip(ship::TWO)) {}
	}
	for (size_t i = 0; i < 4; i++)
	{
		while (!addShip(ship::ONE)) {}
	}
}

bool Field::addShip(ship s)
{
	int x = rand() % 10 + 1;
	int y = rand() % 10 + 1;
	bool direction = rand() % 2;
	//if r1 = true > down
	for (size_t i = 0; i < s; i++)
	{
		if (direction)
		{
			if (!check(x + i, y))
				return false;
		}
		else if (!check(x, y + i))
			return false;
	}
	for (size_t i = 0; i < s; i++)
	{
		if (direction)
			field[x + i][y] = shoot_control::SHIP;
		else
			field[x][y + i] = shoot_control::SHIP;
	}
	return true;
}

void Field::clear()
{
	for (size_t i = 0; i < field.size(); i++)
	{
		for (size_t j = 0; j < field.size(); j++)
		{
			field[i][j] = shoot_control::EMPTY;
		}
	}
}

int Field::shoot(int x, int y)
{
	if (field[x][y] == shoot_control::EMPTY)
	{
		field[x][y] = shoot_control::MISS;
		return shoot_control::MISS;
	}
	if (field[x][y] == shoot_control::SHIP)
	{
		if (killingCheck(x, y))
		{
			//значит убили
			fillKilledShip(x, y);
			return shoot_control::KILL;
		}
		else
		{
			field[x][y] = shoot_control::HIT;
			return shoot_control::HIT;
		}
	}
	return shoot_control::MISS;
}

void Field::fillKilledShip(int x, int y)
{
	/*if (field[x][y] != shoot_control::HIT)
	return;*/
	for (size_t i = x - 1; i < x + 2; i++)
	{
		for (size_t j = y - 1; j < y + 2; j++)
		{
			if (x == i && y == j)
				continue;
			if (field[i][j] == shoot_control::HIT)
			{
				fillKilledShip(i, j);
				field[i][j] = shoot_control::KILL;
			}
			else
				field[i][j] = shoot_control::MISS;
		}
	}
}