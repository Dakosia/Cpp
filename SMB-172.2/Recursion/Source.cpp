#include <iostream>
#include <string>

using namespace std;

string toHex(long long n) {
	char a;
	if (n < 16) {
		switch (n) {
		case 10:
			return "A";
		case 11:
			return "B";
		case 12:
			return "C";
		case 13:
			return "D";
		case 14:
			return "E";
		case 15:
			return "F";
		default:
			return to_string(n);
		}
	}
	switch (n % 16) {
	case 10:
		a = 'A';
		break;
	case 11:
		a = 'B';
		break;
	case 12:
		a = 'C';
		break;
	case 13:
		a = 'D';
		break;
	case 14:
		a = 'E';
		break;
	case 15:
		a = 'F';
		break;
	default:
		return toHex(n / 16) + to_string(n % 16);
	}
	return toHex(n / 16) + a;
}

int main() {
	long long n;
	cin >> n;
	if (n < 0) {
		cout << "-" << toHex(-n);
	}
	else {
		cout << toHex(n);
	}
	return 0;
}