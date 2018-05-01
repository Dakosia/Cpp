#include "Fraction.h"



Fraction::Fraction(int numerator, int denominator)
{
	setNumerator(numerator);
	setDenominator(denominator);
}

Fraction::~Fraction()
{
}

void Fraction::setNumerator(int numerator)
{
	this->numerator = numerator;
}

void Fraction::setDenominator(int denominator)
{
	if (denominator == 0)
		this->denominator = 1;
	else
		this->denominator = denominator;
}

int Fraction::getNumerator()
{
	return this->numerator;
}

int Fraction::getDenominator()
{
	return this->denominator;
}

void Fraction::Input()
{
	std::cin >> this->numerator >> this->denominator;
}

double Fraction::getDecimal() const
{
	return (double)this->numerator / this->denominator;
}

int Fraction::getIntegralPart()
{
	return (int)this->numerator / this->denominator;
}

const Fraction& Fraction::operator+=(const Fraction &a)
{
	this->numerator = this->numerator*a.denominator + this->denominator*a.numerator;
	this->denominator = this->denominator*a.denominator;
	return *this;
}

const Fraction& Fraction::operator-=(const Fraction &a)
{
	this->numerator = this->numerator*a.denominator - this->denominator*a.numerator;
	this->denominator = this->denominator*a.denominator;
	return *this;
}

const Fraction& Fraction::operator*=(const Fraction &a)
{
	this->numerator = this->numerator*a.numerator;
	this->denominator = this->denominator*a.denominator;
	return *this;
}

const Fraction& Fraction::operator/=(const Fraction &a)
{
	this->numerator = this->numerator*a.denominator;
	this->denominator = this->denominator*a.numerator;
	return *this;
}

void Fraction::operator+=(int a)
{
	this->numerator += this->denominator * a;
}

void Fraction::operator-=(int a)
{
	this->numerator -= this->denominator * a;
}

void Fraction::operator*=(int a)
{
	this->numerator *= a;
}

void Fraction::operator/=(int a)
{
	this->denominator *= a;
}

const Fraction & Fraction::operator++()
{
	this->numerator += this->denominator;
	return *this;
}

const Fraction & Fraction::operator--()
{
	this->numerator -= this->denominator;
	return *this;
}

const Fraction & Fraction::operator++(int)
{
	//this - 3/2
	//1
	/*Fraction tmp;
	tmp.numerator = this->numerator;
	tmp.denominator = this->denominator;*/
	//2
	//Fraction tmp(this->numerator, this->denominator);
	Fraction tmp(*this); //copy constructor
	this->numerator += this->denominator;
	return tmp;
}

const Fraction & Fraction::operator--(int)
{
	Fraction tmp(*this); //copy constructor
	this->numerator -= this->denominator;
	return tmp;
}

//Fraction Fraction::operator+(const Fraction & a)
//{
//	//Fraction c(*this);
//	Fraction c;
//	c.numerator = this->numerator;
//	c.denominator = this->denominator;
//	c += a;
//	return c;
//}

Fraction operator+(const Fraction &a, const Fraction &b)
{
	Fraction c = a;
	c += b;
	return c;
}

Fraction operator-(const Fraction &a, const Fraction &b)
{
	Fraction c = a;
	c -= b;
	return c;
}

Fraction operator*(const Fraction &a, const Fraction &b)
{
	Fraction c = a;
	c *= b;
	return c;
}

Fraction operator/(const Fraction &a, const Fraction &b)
{
	Fraction c = a;
	c /= b;
	return c;
}

Fraction operator+(const Fraction &a, int b)
{
	Fraction c = a;
	c += b;
	return c;
}

Fraction operator-(const Fraction & a, int b)
{
	Fraction c = a;
	c -= b;
	return c;
}

Fraction operator*(const Fraction & a, int b)
{
	Fraction c = a;
	c *= b;
	return c;
}

Fraction operator/(const Fraction & a, int b)
{
	Fraction c = a;
	c /= b;
	return c;
}

bool operator>(const Fraction &a, const Fraction &b)
{
	return a.getDecimal() > b.getDecimal();
}

bool operator<(const Fraction &a, const Fraction &b)
{
	return a.getDecimal() < b.getDecimal();
}

bool operator>=(const Fraction &a, const Fraction &b)
{
	return a.getDecimal() >= b.getDecimal();
}

bool operator<=(const Fraction &a, const Fraction &b)
{
	return a.getDecimal() <= b.getDecimal();
}

bool operator!=(const Fraction &a, const Fraction &b)
{
	return a.getDecimal() != b.getDecimal();
}

bool operator==(const Fraction &a, const Fraction &b)
{
	return a.getDecimal() == b.getDecimal();
}

Fraction operator-(Fraction b)
{
	Fraction tmp(b);
	tmp.setNumerator(tmp.getNumerator() * -1);
	return tmp;
}

std::ostream& operator<<(std::ostream &out, const Fraction & a)
{
	out << a.getDecimal();
	return out;
}

std::istream& operator>>(std::istream &in, Fraction & a)
{
	int x, y;
	std::cout << "Введите числитель\n";
	in >> x;
	std::cout << "Введите знаменатель\n";
	in >> y;
	a.setNumerator(x);
	a.setDenominator(y);
	return in;
}
