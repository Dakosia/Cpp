#include <iostream>
#include <vector>
using namespace std;

struct index
{
	int i;
	int j;
};

int main() 
{
	int n, m;
	cin >> n >> m;
	int ** a = new int *[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = new int[m];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	int max;
	vector<index> maxs;
	for (int j = 0; j < m; ++j)
	{
		max = a[0][j];
		for (int i = 0; i < n; ++i)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (a[i][j] == max)
			{
				maxs.push_back({ i, j });
			}
		}
	}
	int min;
	vector<index> mins;
	for (int i = 0; i < n; ++i)
	{
		min = a[i][0];
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] < min)
			{
				min = a[i][j];
			}
		}
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == min)
			{
				mins.push_back({ i, j });
			}
		}
	}
	vector<index> res;
	for (int x = 0; x < maxs.size(); ++x)
	{
		for (int y = 0; y < mins.size(); ++y)
		{
			if (maxs[x].i == mins[y].i && maxs[x].j == mins[y].j)
			{
				res.push_back(maxs[x]);
			}
		}
	}
	if (res.empty())
	{
		cout << 0;
	}
	else
	{
		for (int x = 0; x < res.size(); ++x)
		{
			cout << res[x].i + 1<< ' ' << res[x].j + 1 << ' ';
		}
	}
	for (int i = 0; i < n; ++i)
	{
		delete[] a[i];
	}
	delete[] a;
	return 0;
}
