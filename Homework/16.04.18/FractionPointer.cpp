#include "FractionPointer.h"



FractionPointer::FractionPointer(Fraction *a)
{
	d = a;
}


FractionPointer::~FractionPointer()
{
	delete d;
}