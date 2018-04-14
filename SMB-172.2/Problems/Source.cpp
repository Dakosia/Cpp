#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;

void fillArray(int *, int);
void fill2DArray(int **, int, int);
int findMax(int **, int, int);
int findMin(int **, int, int);
int f1()
{
	int n, m;
	cin >> n >> m;
	int *a = new int[n], *b = new int[m];
	fillArray(a, n);
	fillArray(b, m);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < m; ++i)
	{
		cout << b[i] << ' ';
	}
	cout << endl;
	delete[] a;
	delete[] b;
	system("pause");
	return 0;
}
int f2() {
	int **a = new int*[5];
	for (int i = 0; i < 5; ++i)
	{
		a[i] = new int[5];
	}
	fill2DArray(a, 5, 5);
	cout << findMax(a, 5, 5) << ' ' << findMin(a, 5, 5) << endl;
	for (int i = 0; i < 5; ++i)
	{
		delete[] a[i];
	}
	delete[] a;
	system("pause");
	return 0;
}
int f3() {
	srand(time(0));
	int a[4], b[4];
	for (int i = 0; i < 2; ++i)
	{
		a[i] = rand() % 6 + 1;
		b[i] = rand() % 6 + 1;
		cout << a[i] << ' ' << b[i] << endl;
	}
	Sleep(2000);
	for (int i = 2; i < 4; ++i)
	{
		a[i] = rand() % 6 + 1;
		b[i] = rand() % 6 + 1;
		cout << a[i] << ' ' << b[i] << endl;
	}
	int me = 0, pc = 0;
	for (int i = 0; i < 4; ++i)
	{
		me += a[i];
		pc += b[i];
	}
	cout << me << ' ' << pc << endl;
	system("pause");
	return 0;
}
int f4() {
	int n, m;
	cin >> n >> m;
	int **a = new int*[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[m];
	}
	fill2DArray(a, n, m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < n; ++i) {
		delete[] a[i];
	}
	delete[] a;
	system("pause");
	return 0;
}
int main()
{
	return f4();
}
void fillArray(int *a, int n)
{
	for (int i = 0; i < n; ++i) {
		a[i] = rand();
	}
}
void fill2DArray(int **a, int n, int m)
{
	//seed rand - зерно, "счетчик"
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			a[i][j] = rand() % 31 + 30;
		}
	}
}
int findMax(int **a, int n, int m)
{
	int max = a[0][0];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (max < a[i][j])
			{
				max = a[i][j];
			}
		}
	}
	return max;
}
int findMin(int **a, int n, int m) {
	int min = a[0][0];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (min > a[i][j])
			{
				min = a[i][j];
			}
		}
	}
	return min;
}
