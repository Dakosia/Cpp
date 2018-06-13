#include "Field.h"

Field::Field()
{
	std::vector<int> v;
	for (int i = 0; i < size + 2; i++)
		v.push_back(0);
	for (int i = 0; i < size + 2; i++)
	{
		userField.push_back(v);
		pcField.push_back(v);
	}
}

bool Field::check(int x, int y, std::vector<std::vector<int>>& field) const
{
	if (x == 0 || y == 0 || x == 11 || y == 11)
		return false;
	for (size_t i = x - 1; i < x + 2; i++)
	{
		for (size_t j = y - 1; j < y + 2; j++)
		{
			/*if (i < 0 || j < 0 || i > 11 || j > 11)
			return false;*/
			if (field[i][j] != shoot_control::EMPTY)
				return false;
		}
	}
	return true;
}

//check for killed ships
bool Field::killingCheck(int x, int y, std::vector<std::vector<int>>& field) const
{
	if (field[x + 1][y] == shoot_control::SHIP ||
		field[x - 1][y] == shoot_control::SHIP ||
		field[x][y + 1] == shoot_control::SHIP ||
		field[x][y - 1] == shoot_control::SHIP)
		return false;

	if (field[x - 1][y] == shoot_control::HIT ||
		field[x + 1][y] == shoot_control::HIT)
	{
		while (field[x - 1][y] != shoot_control::MISS &&
			field[x - 1][y] != shoot_control::EMPTY)
			--x;

		while (field[x][y] != shoot_control::MISS &&
			field[x][y] != shoot_control::EMPTY)
		{
			if (field[x][y] == shoot_control::SHIP ||
				field[x - 1][y] == shoot_control::SHIP ||
				field[x + 1][y] == shoot_control::SHIP
				)
				return false;

			++x;
		}
	}

	if (field[x][y - 1] == shoot_control::HIT ||
		field[x][y + 1] == shoot_control::HIT)
	{
		while ((field[x][y - 1] != shoot_control::MISS &&
			field[x][y - 1] != shoot_control::EMPTY))
			--y;

		while (field[x][y] != shoot_control::MISS &&
			field[x][y] != shoot_control::EMPTY)
		{
			if (field[x][y] == shoot_control::SHIP ||
				field[x][y - 1] == shoot_control::SHIP ||
				field[x][y + 1] == shoot_control::SHIP)
				return false;

			++y;
		}
	}

	return true;
}

void Field::printField() const
{
	userMap();
	pcMap();
}

void Field::generation()
{
	/*
	4 - 1
	3 - 2
	2 - 3
	1 - 4
	*/
	//user map
	while (!addShip(ship::FOUR, userField));
	for (int i = 0; i < 2; i++)
		while (!addShip(ship::THREE, userField));
	for (int i = 0; i < 3; i++)
		while (!addShip(ship::TWO, userField));
	for (int i = 0; i < 4; i++)
		while (!addShip(ship::ONE, userField));

	//PC map
	while (!addShip(ship::FOUR, pcField));
	for (int i = 0; i < 2; i++)
		while (!addShip(ship::THREE, pcField));
	for (int i = 0; i < 3; i++)
		while (!addShip(ship::TWO, pcField));
	for (int i = 0; i < 4; i++)
		while (!addShip(ship::ONE, pcField));
}

bool Field::addShip(ship s, std::vector<std::vector<int>>& field)
{
	int x = rand() % 10 + 1;
	int y = rand() % 10 + 1;
	bool direction = rand() % 2;
	//if r1 = true > down
	for (size_t i = 0; i < s; i++)
	{
		if (direction)
		{
			if (!check(x + i, y, field))
				return false;
		}
		else if (!check(x, y + i, field))
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
	for (auto i : userField)
		for (auto j : i)
			j = 0;

	for (auto i : pcField)
		for (auto j : i)
			j = 0;
}

void Field::shoot(int x, int y, std::vector<std::vector<int>>& field)
{
	if (field[x][y] == shoot_control::EMPTY)
		field[x][y] = shoot_control::MISS;
	if (field[x][y] == shoot_control::SHIP ||
		field[x][y] == shoot_control::HIT)
	{
		field[x][y] = shoot_control::HIT;
		if (killingCheck(x, y, field))
		{
			field[x][y] = shoot_control::KILL;
			fillKilledShip(x, y, field);
		}
	}
	return;
}

void Field::fillKilledShip(int x, int y, std::vector<std::vector<int>>& field)
{
	// Окружить одну ячейку
	if ((field[x + 1][y] == shoot_control::EMPTY ||
		field[x + 1][y] == shoot_control::MISS)
		&&
		(field[x - 1][y] == shoot_control::EMPTY ||
			field[x - 1][y] == shoot_control::MISS)
		&&
		(field[x][y + 1] == shoot_control::EMPTY ||
			field[x][y + 1] == shoot_control::MISS)
		&&
		(field[x][y - 1] == shoot_control::EMPTY ||
			field[x][y - 1] == shoot_control::MISS))
	{
		for (int i = x - 1; i < x + 2; i++)
		{
			for (int j = y - 1; j < y + 2; j++)
			{
				if (field[i][j] == shoot_control::HIT ||
					field[i][j] == shoot_control::KILL)
					continue;

				field[i][j] = shoot_control::MISS;
			}
		}
	}

	//Левая или правая ячейка
	if (field[x][y + 1] == shoot_control::HIT ||
		field[x][y - 1] == shoot_control::HIT)
	{
		//Добежать до крайней ячейки корабля
		while (field[x][y - 1] != shoot_control::EMPTY &&
			field[x][y - 1] != shoot_control::MISS)
			--y;

		//Проставить мимо вокруг убитого корабля
		while (field[x][y] != shoot_control::EMPTY &&
			field[x][y] != shoot_control::MISS)
		{
			for (int i = x - 1; i < x + 2; i++)
			{
				for (int j = y - 1; j < y + 2; j++)
				{
					if (field[i][j] == shoot_control::HIT)
						field[i][j] = shoot_control::KILL;
					else if (field[i][j] == shoot_control::KILL);
					else
						field[i][j] = shoot_control::MISS;
				}
			}
			++y;
		}
	}

	//Верхняя или нижняя ячейка
	if (field[x - 1][y] == shoot_control::HIT ||
		field[x + 1][y] == shoot_control::HIT)
	{
		//Добежать до крайней ячейки корабля
		while (field[x - 1][y] != shoot_control::EMPTY &&
			field[x - 1][y] != shoot_control::MISS)
			--x;

		//Проставить мимо вокруг убитого корабля
		while (field[x][y] != shoot_control::EMPTY &&
			field[x][y] != shoot_control::MISS)
		{
			for (int i = x - 1; i < x + 2; i++)
			{
				for (int j = y - 1; j < y + 2; j++)
				{
					if (field[i][j] == shoot_control::HIT)
						field[i][j] = shoot_control::KILL;
					else if (field[i][j] == shoot_control::KILL);
					else
						field[i][j] = shoot_control::MISS;
				}
			}
			++x;
		}
	}
	return;
}

void Field::userAttack()
{
	int x, y, flag = 0;

	while (flag != 1)
	{
		printField();

		std::cin >> x >> y;
		while (x < 0 || y < 0 || x > 11 || y > 11)
			std::cin >> x >> y;

		if (pcField[x][y] == shoot_control::EMPTY)
			flag = 1;

		if (pcField[x][y] == shoot_control::SHIP)
			--pcCnt;

		shoot(x, y, pcField);
	}
}

void Field::pcAttack()
{
	int x, y, flag = 0;

	while (flag != 1)
	{
		printField();

		x = rand() % 10 + 1;
		y = rand() % 10 + 1;

		if (userField[x][y] == shoot_control::EMPTY)
			flag = 1;

		if (userField[x][y] == shoot_control::SHIP)
			--userCnt;

		shoot(x, y, userField);
	}
}

void Field::game()
{
	generation();

	while (true)
	{
		userAttack();
		pcAttack();
		if (pcCnt == 0 || userCnt == 0)
			break;
	}
	system("cls");
	if (pcCnt == 0)
		std::cout << "You won!" << std::endl;
	if (userCnt == 0)
		std::cout << "PC won!" << std::endl;
}

void Field::userMap() const
{
	system("cls");
	std::cout << "    1  2  3  4  5  6  7  8  9  10\n";
	std::cout << "  _______________________________";
	for (int i = 1; i < userField.size() - 1; i++)
	{
		std::cout << std::endl;
		for (int j = 1; j < userField.size() - 1; j++)
		{
			if (i == 1 && j == 1) std::cout << " 1|";
			else if (i == 2 && j == 1) std::cout << " 2|";
			else if (i == 3 && j == 1) std::cout << " 3|";
			else if (i == 4 && j == 1) std::cout << " 4|";
			else if (i == 5 && j == 1) std::cout << " 5|";
			else if (i == 6 && j == 1) std::cout << " 6|";
			else if (i == 7 && j == 1) std::cout << " 7|";
			else if (i == 8 && j == 1) std::cout << " 8|";
			else if (i == 9 && j == 1) std::cout << " 9|";
			else if (i == 10 && j == 1) std::cout << "10|";

			if (userField[i][j] == shoot_control::EMPTY)
				std::cout << " 0 ";
			else if (userField[i][j] == shoot_control::HIT)
				std::cout << " 2 ";
			else if (userField[i][j] == shoot_control::KILL)
				std::cout << " 3 ";
			else if (userField[i][j] == shoot_control::MISS)
				std::cout << " 4 ";
			else
				std::cout << " 1 ";
		}
	}
	std::cout << std::endl;
}

void Field::pcMap() const
{
	std::cout << std::endl;
	std::cout << "    1  2  3  4  5  6  7  8  9  10\n";
	std::cout << "  _______________________________";
	for (int i = 1; i < pcField.size() - 1; i++)
	{
		std::cout << std::endl;
		for (int j = 1; j < pcField.size() - 1; j++)
		{
			if (i == 1 && j == 1) std::cout << " 1|";
			else if (i == 2 && j == 1) std::cout << " 2|";
			else if (i == 3 && j == 1) std::cout << " 3|";
			else if (i == 4 && j == 1) std::cout << " 4|";
			else if (i == 5 && j == 1) std::cout << " 5|";
			else if (i == 6 && j == 1) std::cout << " 6|";
			else if (i == 7 && j == 1) std::cout << " 7|";
			else if (i == 8 && j == 1) std::cout << " 8|";
			else if (i == 9 && j == 1) std::cout << " 9|";
			else if (i == 10 && j == 1) std::cout << "10|";

			if (pcField[i][j] == shoot_control::EMPTY || pcField[i][j] == shoot_control::SHIP)
				std::cout << " 0 ";
			else if (pcField[i][j] == shoot_control::HIT)
				std::cout << " 2 ";
			else if (pcField[i][j] == shoot_control::KILL)
				std::cout << " 3 ";
			else if (pcField[i][j] == shoot_control::MISS)
				std::cout << " 4 ";
		}
	}
	std::cout << std::endl;
}