#include "Fraction.h"



Fraction::Fraction()
{
}


Fraction::~Fraction()
{
}

void Fraction::setNumerator(int _numerator)
{
	numerator = _numerator;
}

void Fraction::setDenominator(int _denominator)
{
	if (_denominator == 0)
		denominator = 1;
	else
		denominator = _denominator;
}

int Fraction::getNumerator()
{
	return numerator;
}

int Fraction::getDenominator()
{
	return denominator;
}

void Fraction::Input()
{
	std::cin >> numerator >> denominator;
}

double Fraction::getDecimal()
{
	return (double)numerator / denominator;
}

int Fraction::getIntegralPart()
{
	return (int)numerator / denominator;
}

