#include <iostream>
#include <string>
using namespace std;
void printRecursively(string s) 
{
	if (s.empty()) {
		return;
	}
	cout << s[0];
	printRecursively(s.substr(1, s.length() - 1));
}
string reverse(string s)
{
	if (s.length() <= 1) {
		return s;
	}
	return s[s.length() - 1] + reverse(s.substr(0, s.length() - 1));
}
int main() 
{
	string s;
	cin >> s;
	//printRecursively(s);
	cout << reverse(s);
	system("pause");
	return 0;
}
