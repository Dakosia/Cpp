#include "Time_.h"
#include <Windows.h>
#include "Fraction.h"
#include "Student.h"

void time()
{
	Time_ t;
	t.setHour(23);
	t.setMinute(59);
	t.setSecond(58);
	t.printTime();

	while (1)
	{
		Sleep(1000);
		t.addSecond();
		system("cls");
		t.printTime();
	}
}

void fraction()
{
	Fraction a, b;
	a += b; //a.operator+=(b);
	a += 55; //a.operator+=(55);


	/*Fraction f;
	f.setNumerator(5);
	f.setDenominator(15);
	std::cout << f.getDecimal() << std::endl;
	std::cout << f.getIntegralPart() << std::endl;
	f.Input();
	std::cout << f.getDecimal() << std::endl;
	std::cout << f.getIntegralPart() << std::endl;*/
}

void student()
{
	int *arr = new int[5]{ 5, 1, 5, 8, 12 };
	Student s1("Vasya", 18, "SMP-172.2", arr);
	s1.print();
	/*Student s2 = s1;
	s2.print();*/

}

int main()
{
	//time();
	fraction();
	//student();

	system("pause");
	return 0;
}