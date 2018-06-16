#include "CitiesGame.h"


int main(int argc, char*argv[]) {

	setlocale(0, "");
	system("chcp 1251");
	system("cls");
	// \\dc\Студенты\ПКО\SMB - 172.2\city.csv
	//CitiesGame t("\\\\dc\\Студенты\\ПКО\\SMB-172.2");
	CitiesGame t("C:\\Users\\Dakosia\\source\\repos\\Cpp\\Homework\\CitiesGame", atoi(argv[2]));
	t.multiplay(atoi(argv[1]));
	return 0;
}