#include <iostream>

void sieve(int n, int m) {
	bool *a = new bool[n + 1];
	int *b = new int[m];
	for (int i = 2; i < n + 1; ++i) {
		a[i] = true;
	}

	for (int i = 2; i * i <= n; ++i) {
		if (a[i]) {
			for (int j = i * i; j <= n; j += i) {
				a[j] = false;
			}
		}
	}

	int j = 0;
	for (int i = 2; i < n + 1; ++i) {
		if (a[i]) {
			std::cout << i << ' ';
			b[j] = i;
			++j;
		}
	}
	std::cout << std::endl;
	std::cout << b[m - 1] << std::endl;
	delete[] a;
	delete[] b;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	sieve(n, m);

	return 0;
}