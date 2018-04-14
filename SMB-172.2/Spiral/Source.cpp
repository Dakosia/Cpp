#include <iostream>
using namespace std;
int cnt = 1, depth = 0;
void fillSpirally(int **a, int n, int i, int j, int d) {
	if (d == 0) 
	{
		while (j < n && a[i][j] == -1) 
		{
			a[i][j] = cnt++;
			j++;
		}
		d = 1;
	}
	else if (d == 1) 
	{
		j--;
		i++;
		while (i < n && a[i][j] == -1) 
		{
			a[i][j] = cnt++;
			i++;
		}
		d = 2;
	}
	else if (d == 2) {
		while (j >= 0 && a[i][j] == -1) 
		{
			a[i][j] = cnt++;
			j--;
		}
		d = 3;
	}
	else if (d == 3) {
		while (i >= 0 && a[i][j] == -1) 
		{
			a[i][j] = cnt++;
			i--;
		}
		d = 0;
	}
	if (depth < 3) {
		++depth;
		fillSpirally(a, n, i, j, d);
	}
}
int main() {
	int n;
	cin >> n;
	int **a = new int *[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[n];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = -1;
		}
	}
	fillSpirally(a, n, 0, 0, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}