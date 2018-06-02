#include "Crossroad.h"

void crossroad()
{
	Crossroad r(10, 15, 40, 30);
	while (true)
	{
		r.redLightOn();
		r.greenLightOn();
	}
}

int main()
{
	crossroad();

	system("pause");
	return 0;
}