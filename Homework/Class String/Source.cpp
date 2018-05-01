#include "String_.h"

void string()
{
	String_ s("ggg");
	String_ s2("Hello!");
	s += s2;
	std::cout << s;
}

int main()
{
	string();
	return 0;
}