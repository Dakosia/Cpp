#include "CitiesGame.h"

CitiesGame::CitiesGame(std::string dir)
{
	this->dir = dir;
	std::fstream f(dir + "\\city.csv", std::ios::in);
	std::string str;
	while (!f.eof())
	{
		getline(f, str);
		cities.insert(make_pair(str, 0));
	}
	f.close();
}

void CitiesGame::play()
{
	std::string city;
	int i_player = 1;
	while (true)
	{

		if (i_player == 3)
			i_player = 1;
		system("cls");
		std::cout << i_player << " игрок ходит";
		std::cout << "\nВведите город на букву " << nextWord << std::endl;
		std::cin >> city;
		try
		{

			check_city(city);

			nextWord = (char)toupper(city[city.size() - 1]);

			if (nextWord == 'Ъ' || nextWord == 'Ь' || nextWord == 'Ы' || nextWord == 'Э')
			{
				nextWord = (char)toupper(city[city.size() - 2]);
			}
			++i_player;
			//cities[city] = 1;
			cities.find(city)->second = 1;

		}
		catch (const std::exception&e)
		{
			std::cout << e.what() << std::endl;
			Sleep(3000);
		}
	}
}

void CitiesGame::check_city(std::string city) const
{
	//указатель на найденный узел

	if (cities.find(city) == cities.end())
		throw std::exception("Город не найден");
	if (cities.find(city)->second == 1)
		throw std::exception("Город уже был");
	if (city[0] != nextWord && nextWord != '.')
		// c_str возвращает указатель на строку
		throw std::exception(("Введите город начинающийся с буквы " + std::to_string(nextWord)).c_str());
}

void CitiesGame::multiplay(int pos)
{
	while (1) {
		std::fstream file(dir + "\\" + std::to_string(pos) + ".csv", std::ios::in);
		while (file.fail()) {
			file.open(dir + "\\" + std::to_string(pos) + ".csv", std::ios::in);
			std::cout << "Ожидаем своей очереди\n";
			Sleep(1000);
			system("cls");
		}
		std::vector<std::string> oldCities;
		std::string c;
		while (!file.eof()) {
			getline(file, c);
			oldCities.push_back(c);
		}
		file.close();
		char lastChar = '.';
		if (oldCities.size() > 0) {
			std::string lastCity = oldCities[oldCities.size() - 1];
			if (lastCity.size()>0)
				lastChar = (char)toupper(lastCity[lastCity.size() - 1]);
		}
		std::cout << "\nВведите город на букву \n" << lastChar << std::endl;
		getline(std::cin, c);
		try {
			check_city(c);
			for (size_t i = 0; i < oldCities.size(); i++)
				if (oldCities[i] == c)
					throw std::exception("Город уже был!");
			if (oldCities.size() > 0) {

				if (c[0] != lastChar&&lastChar != '.')
					throw std::exception("Неверная буква!");
			}
			file.open(dir + "\\" + std::to_string(pos) + ".csv", std::ios::app);
			file << "\n" << c;
			file.close();
			if (pos == 9)
			{
				std::string rename = "ren " + dir + "\\" + std::to_string(9) + ".csv " + std::to_string(1) + ".csv";
				system(rename.c_str());
			}
			else {
				std::string rename = "ren " + dir + "\\" + std::to_string(pos) + ".csv " + std::to_string(pos + 1) + ".csv";
				system(rename.c_str());
			}

		}
		catch (std::exception&e) {
			std::cout << e.what();
		}

	}
}



