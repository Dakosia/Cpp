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
	Student s;
	s.setLastName("Qwerty");
	s.setFirstName("Ytrewq");
	s.setMiddleName("Qweytr");
	s.setDateOfBirth("1990");
	s.setPhoneNumber("12345678910");
	s.setAddress("Nfjskfvfdsa");
	s.setFaculty("IT");
	s.setCourse(2);
	s.setRating(1);
	s.print();

}

int main()
{
	//time();
	fraction();
	//student();

	system("pause");
	return 0;
}