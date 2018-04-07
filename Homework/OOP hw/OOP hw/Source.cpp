#include "Circle.h"

void circle()
{
	Circle c1 = Circle();
	std::cout << "Radius: " << c1.getRadius() << std::endl;
	std::cout << "Color: " << c1.getColor() << std::endl;
	std::cout << "Area: " << c1.getArea() << std::endl;
	std::cout << std::endl;

	Circle c2(5, "yellow");
	std::cout << "Radius: " << c2.getRadius() << std::endl;
	std::cout << "Color: " << c2.getColor() << std::endl;
	std::cout << "Area: " << c2.getArea() << std::endl;
	std::cout << std::endl;

	Circle c3;
	c3.setRadius(3.5);
	c3.setColor("orange");
	std::cout << c3.toString() << std::endl;
	std::cout << "Area: " << c3.getArea() << std::endl;

}

int main()
{
	circle();

	system("pause");
	return 0;
}