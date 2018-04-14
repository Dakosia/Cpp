#include <iostream>
#include <algorithm>
int findMostON(int *a, int n) 
{
	int temp[10];
	for (int i = 0; i < 10; ++i) {
		temp[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		temp[a[i]]++;
	}
	int max = temp[0];
	int most = 0;
	for (int i = 1; i < 10; ++i)
	{
		if (temp[i] > temp[i - 1])
		{
			max = temp[i];
			most = i;
		}
	}
	return most;
}
int findMostONLogN(int *a, int n) 
{
	int cnt, max = 0, most = 0;
	std::sort(a, a + n);
	cnt = 1;
	for (int i = 1; i < n; ++i) 
	{
		if (a[i] == a[i - 1]) 
		{
			++cnt;
		}
		else {
			if (cnt > max) {
				most = a[i - 1];
				max = cnt;
				cnt = 0;
			}
		}
	}
	return most;
}

int main()
{
	int n;
	std::cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 10;
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << findMostONLogN(a, n);
	delete[] a;
	system("pause");
	return 0;
}