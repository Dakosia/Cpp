#include <iostream>
using namespace std;
int cnt = 0;
void countArea(int **a, int x, int y, int n) 
{
	if (x >= n || y >= n || x < 0 || y < 0) {
		return;
	}
	if (a[x][y] == 1) 
	{
		++cnt;
		a[x][y] = 0;
		countArea(a, x + 1, y, n);
		countArea(a, x - 1, y, n);
		countArea(a, x, y - 1, n);
		countArea(a, x, y + 1, n);
	}
	return;
}
int main() {
	int n;
	cin >> n;
	int **a = new int*[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[n];
	}
	char temp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> temp;
			if (temp == '.') {
				a[i][j] = 1;
			}
			else {
				a[i][j] = 0;
			}
		}
	}
	int x, y;
	cin >> x >> y;
	countArea(a, x - 1, y - 1, n);
	cout << cnt;
	return 0;
}
