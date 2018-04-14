#include <iostream>
#include "Human.h"
#include "Worker.h"

void sample() 
{
	Human h("qwerty", "lol", 3);
	h.saySomething();
}

int main() 
{
	sample();
	system("pause");
	return 0;
}