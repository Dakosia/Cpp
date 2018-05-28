#include "Dragon.h"

void dragon()
{
	Dragon d("Golden", "Smaug", 1, 1, 1, 500, 2000);
	d.info();
}

int main()
{
	dragon();

	system("pause");
	return 0;
}