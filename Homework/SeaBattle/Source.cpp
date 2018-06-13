#include "Field.h"
#include <ctime>

int main() {
	srand(time(NULL));

	Field f;
	f.game();

	system("pause");
	return 0;
}