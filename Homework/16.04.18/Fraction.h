#pragma once
#include <iostream>
class Fraction
{
private:
	int numerator; //числитель
	int denominator; //знаменатель
public:
	Fraction();
	~Fraction();

	void setNumerator(int);
	void setDenominator(int);
	int getNumerator();
	int getDenominator();
	

	void Input();
	double getDecimal();
	int getIntegralPart();

};

