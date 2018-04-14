#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char * s, s1[10];
	s = new char[10];
	strcat(s, s1);
	cout << s;
	delete[] s;
	system("pause");
	return 0;
}