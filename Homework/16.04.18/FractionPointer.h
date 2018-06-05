#pragma once
#include "Fraction.h"
class FractionPointer
{
private:
	Fraction *d;
public:
	FractionPointer(Fraction *a);
	~FractionPointer();
	Fraction& operator*() {
		return *d;
	}
	Fraction* operator->()
	{
		return d;
	}

	//unique_ptr
	//FractionPointer(const Fraction&) = delete;
	//FractionPointer& operator=(const Fraction&) = delete;

};