#pragma once
#include <iostream>

class Fraction
{
private:
	int numerator; //числитель
	int denominator; //знаменатель
public:
	explicit Fraction(int numerator = 0, int denominator = 1);

	void setNumerator(int numerator = 0);
	void setDenominator(int denominator = 1);
	int getNumerator() const;
	int getDenominator() const;

	const Fraction& operator+=(const Fraction &a); //this += a
	const Fraction& operator-=(const Fraction &a); //this -= a
	const Fraction& operator*=(const Fraction &a); //this *= a
	const Fraction& operator/=(const Fraction &a); //this /= a
	void operator+=(int a);
	void operator-=(int a);
	void operator*=(int a);
	void operator/=(int a);

	//prefix
	const Fraction& operator++();
	const Fraction& operator--();
	//postfix
	const Fraction& operator++(int);
	const Fraction& operator--(int);

	double getDouble() const;
	operator double() const;
	operator int() const;

	//перегрузка операции + в виде метода класса
	//Fraction operator+(const Fraction &a);
};

//перегрузка операции + в виде глобальной функции
Fraction operator+(const Fraction &a, const Fraction &b);
Fraction operator-(const Fraction &a, const Fraction &b);
Fraction operator*(const Fraction &a, const Fraction &b);
Fraction operator/(const Fraction &a, const Fraction &b);
bool operator>(const Fraction &a, const Fraction &b);
bool operator<(const Fraction &a, const Fraction &b);
bool operator>=(const Fraction &a, const Fraction &b);
bool operator<=(const Fraction &a, const Fraction &b);
bool operator!=(const Fraction &a, const Fraction &b);
bool operator==(const Fraction &a, const Fraction &b);

Fraction operator+(const Fraction &a, int b);
Fraction operator-(const Fraction &a, int b);
Fraction operator*(const Fraction &a, int b);
Fraction operator/(const Fraction &a, int b);
bool operator>(const Fraction &a, int b);
bool operator<(const Fraction &a, int b);
bool operator>=(const Fraction &a, int b);
bool operator<=(const Fraction &a, int b);
bool operator!=(const Fraction &a, int b);
bool operator==(const Fraction &a, int b);

Fraction operator+(int a, const Fraction &b);
Fraction operator-(int a, const Fraction &b);
Fraction operator*(int a, const Fraction &b);
Fraction operator/(int a, const Fraction &b);
bool operator>(int a, const Fraction &b);
bool operator<(int a, const Fraction &b);
bool operator>=(int a, const Fraction &b);
bool operator<=(int a, const Fraction &b);
bool operator!=(int a, const Fraction &b);
bool operator==(int a, const Fraction &b);

Fraction operator-(Fraction b);
Fraction inverseFraction(Fraction b); //обратная дробь

std::ostream& operator<<(std::ostream &out, const Fraction &a);
std::istream& operator >> (std::istream &in, Fraction &a);