#include "Tank.h"

void tank()
{
	Tank t("T 85", 50, 5, 1000, 100);
	t.info();

}

int main()
{
	tank();
	system("pause");
	return 0;
}