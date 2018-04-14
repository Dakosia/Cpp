#include <iostream>
#include <string>
using namespace std;

//pure function
int sum(int n)
{
	if (n <= 1)
	{
		return n;
	}
	return n + sum(n - 1);
}

//higher-order function
int sumAndMultiply(int(*counter)(int), int n)
{
	int a = counter(n);
	return a * n;
}

template <typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}

int sumOfSquaresToN(int n)
{
	if (n <= 1) {
		return n;
	}
	return n * n + sumOfSquaresToN(n - 1);
}

int fib(int n, int cnt = 0, int prev = 0, int cur = 1) {
	if (cnt > n) {
		return cur;
	}
	return fib(n, cnt + 1, cur, prev + cur);
}

int factors(int n, int cnt = 2) 
{
	if (!(n % cnt)) {
		return cnt;
	}
	return factors(n, cnt + 1);
}

string replicate(string str, int n) {
	if (n < 2) {
		return str;
	}
	return str + replicate(str, n - 1);
}

int sumOfList(int a[], int n) {
	if (n < 1) {
		return 1;
	}
	return a[n - 1] * sumOfList(a, n - 1);
}

int main()
{
	int x = 1, y = 0;
	int z = x ^ y;
	cout << z << endl;
	system("pause");
	return 0;
}
