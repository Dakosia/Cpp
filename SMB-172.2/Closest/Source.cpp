#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main() {
	srand(time(NULL));
	int n, m;
	cin >> n >> m;
	int **a = new int *[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[m];
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = ++cnt;
		}
	}

	int **b = new int *[n];
	for (int i = 0; i < n; ++i) {
		b[i] = new int[m];
	}
	b[0][0] = a[0][0];
	for (int i = 1; i < n; ++i) {
		b[i][0] = b[i - 1][0] + a[i][0];
		
	}
	for (int i = 1; i < m; ++i) {
		b[0][i] = b[0][i - 1] + a[0][i];
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}

	int x1, y1, x2, y2;
	cin >> y1 >> x1 >> y2 >> x2;
	int sum = 0;
	for (int i = x1; i < x2; ++i) {
		for (int j = y1; j < y2; ++j) {
			sum += b[i][j];
		}
	}
	cout << sum << endl;
	cout << b[x2][y2] << ' ' << b[x1][y2 - 1] << ' ' << b[x1 - 1][y1] << endl;
	sum = b[x2][y2] - b[x1][y2 - 1] - b[x1 - 1][y1] + b[x1 - 1][y1 - 1];
	cout << sum << endl;
	for (int i = 0; i < n; ++i) {
		delete[] b[i];
		delete[] a[i];
	}
	delete[] a;
	delete[] b;
	system("pause");
	return 0;
}