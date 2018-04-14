#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
int n;
//void bubble_sort(int *a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - 1; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				swap(a[j], a[j + 1]);
//			}
//		}
//	}
//}
int partition(int *a, int l, int h)
{
	int pivot = a[h];
	int x = l - 1;
	for (int i = l; i < h; ++i) {
		if (a[i] < pivot) {
			++x;
			swap(a[i], a[x]);
		}
		for (int y = 0; y < n; ++y)
		{
			cout << a[y] << ' ';
		}
		cout << endl;
	}
	swap(a[x + 1], a[h]);
	for (int y = 0; y < n; ++y)
	{
		cout << a[y] << ' ';
	}
	cout << endl;
	return x + 1;
}
void inner_quick_sort(int *a, int l, int h)
{
	if (l < h)
	{
		int pivot = partition(a, l, h);
		cout << "partition is done" << endl;
		inner_quick_sort(a, l, pivot - 1);
		inner_quick_sort(a, pivot + 1, h);
	}
}	
void quick_sort(int *a, int n)
{
	inner_quick_sort(a, 0, n - 1);
}
int main()
{
	cin >> n;
	srand(time(NULL));
	int *a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	quick_sort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	delete[] a;
	system("pause");
	return 0;
}