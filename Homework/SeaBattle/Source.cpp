#include "Field.h"
#include <ctime>

void field()
{
	Field f;
	//f.field[2][1] = 1;
	f.clear();
	f.generation();
	f.printField();
	while (true)
	{
		int x, y;
		std::cin >> x >> y;
		f.shoot(x, y);
		f.printField();
		system("pause");
	}
	//std::cout << f.check(2, 3) << std::endl;
}

int main()
{
	srand(time(NULL));
	field();

	system("pause");
	return 0;
}