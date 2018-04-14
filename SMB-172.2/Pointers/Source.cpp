#include <iostream>
#include <assert.h>
using namespace std;

int sumToN(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return sumToN(n - 1) + n;
}
void test1() {
	assert(sumToN(1) == 1);
}
int main()
{
	int(*a)(int);
	void(*b[])(void) = { test1 };
	for (auto x : b) {
		x();
	}
	a = sumToN;
	cout << a(5) << endl;
	auto x = 5;
	system("pause");
	return 0;
}