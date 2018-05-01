#include "Time_.h"
#include <Windows.h>
#include "Fraction.h"
#include "Student.h"
#include "Date_.h"

void time()
{
	/*Time_ t;
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
	}*/
	Time_ t1; //00:00:00
	Time_ t2(5); //05:00:00
	Time_ t3(17, 8); //17:08:00
	Time_ t4(10, 45, 20); //10:45:20
	t1.printTime();
	t1.reduceHour(5);
	t1.printTime();
	t2.printTime();
	t2.reduceMinute(17);
	t2.printTime();
	t3.printTime();
	t3.reduceMinute(130);
	t3.printTime();
	t4.printTime();
	t4.reduceSecond(140);
	t4.printTime();
}

void date()
{
	Date_ d; //01.01.1990
	Date_ d1(15); //15.01.1990
	Date_ d2(7, 3); //07.03.1990
	Date_ d3(5, 8, 2018); //05.08.2018
	/*d.setDay(17);
	d.setMonth(4);
	d.setYear(2018);*/
	d.printDate();
	d1.printDate();
	d2.printDate();
	d3.printDate();
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
	time();
	//date();
	//fraction();
	//student();
	
	system("pause");
	return 0;
}