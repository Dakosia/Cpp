#include "Crossroad.h"
#include "VehicleStore.h"

void crossroad()
{
	Crossroad r(10, 15, 40, 30);
	while (true)
	{
		r.redLightOn();
		r.greenLightOn();
	}
}

void vehicleStore()
{
	VehicleStore vs("Whatever name");
	/*vs.addVehicle(new Bike("Black", "Caloi", 200, 1, 200000, 0, 100));
	vs.addVehicle(new Car("Red", "Alfa Romeo", 300, 4, 500000, 700, 4));
	vs.addVehicle(new Boat("Blue", "Bombardier", 250, 2, 400000, "Good", "Sailboat"));
	vs.addVehicle(new Plane("White", "Airbus", 1000, 800, 1500000, 2000, "D5"));
	vs.getInfo();
	vs.saveToFile();*/

	vs.readFromFile();
	vs.getInfo();
}

int main()
{
	//crossroad();
	vehicleStore();

	system("pause");
	return 0;
}