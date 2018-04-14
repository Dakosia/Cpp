#include <iostream>
#include <string>

using namespace std;

//1. decltype
//2. function arguments

void func(int & x) 
{
	++x;
}

int main() 
{
	auto x = 5;
	decltype(x) y = 6;
	func(x);
	cout << x << ' ' << y << endl;
	system("pause");
	return 0;
}