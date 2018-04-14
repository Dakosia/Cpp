#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
//int min(int, int);
int findLevensteinDistance(string s1, string s2)
{
	int ** d = new int *[s1.length()];
	for (int i = 0; i < s1.length(); ++i)
	{
		d[i] = new int[s2.length()];
	}
	//algorithm itself
	d[0][0] = 0;
	for (int i = 1; i < s1.length(); ++i)
	{
		d[i][0] = i;
	}
	for (int j = 1; j < s2.length(); ++j)
	{
		d[0][j] = j;
	}
	for (int i = 1; i < s1.length(); ++i)
	{
		for (int j = 1; j < s2.length(); ++j)
		{
			int temp1 = min(d[i][j - 1] + 1, d[i - 1][j] + 1);
			int temp2;
			if (s1[i] == s2[j])
			{
				temp2 = d[i - 1][j - 1];
			}
			else {
				temp2 = d[i - 1][j - 1] + 1;
			}
			d[i][j] = min(temp1, temp2);
		}
	}
	int distance = d[s1.length() - 1][s2.length() - 1];
	for (int i = 0; i < s1.length(); ++i)
	{
		delete[] d[i];
	}
	delete[] d;
	return distance;
}
struct Student
{
	int id;
	string name;
	int distance;
};
bool compare(Student & s1, Student & s2) {
	return s1.distance < s2.distance;
}
int main()
{
	bool(*func)(Student &, Student &) = compare;
	Student *students = new Student[5];
	students[0].id = 0;
	students[0].name = "Klark";
	students[1].id = 1;
	students[1].name = "Bruce";
	students[2].id = 2;
	students[2].name = "Barry";
	students[3].id = 3;
	students[3].name = "Diana";
	students[4].id = 4;
	students[4].name = "Arthur";

	string s;
	cin >> s;
	for (int i = 0; i < 5; ++i)
	{
		students[i].distance = findLevensteinDistance(s, students[i].name);
	}
	sort(students, students + 5, func);

	for (int i = 0; i < 5; ++i)
	{
		cout << students[i].name << endl;
	}
	delete[] students;
	system("pause");
	return 0;
}

//int min(int a, int b)
//{
//	if (a == 0) {
//
//	}
//	return ((a / b) * b + (b / a) * a) / (a / b + b / a);
//}