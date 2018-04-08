#include <iostream>
#include <string>
#include <vector>

int subtraction(std::vector<int> a, std::vector<int> b, std::vector<int> c, int length)
{
	if (a == b)
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < length - 1; i++)
		{
			if (i < length - 1)
			{
				--a[i + 1];
				c[i] += 10 + a[i];
			}
			else
			{
				c[i] += a[i];
			}
			c[i] -= b[i];
			if (c[i] / 10 > 0)
			{
				++c[i + 1];
				c[i] %= 10;
			}
		}
	}
	std::reverse(c.begin(), c.end());

	for (auto i : c)
	{
		std::cout << i;
	}
	std::cout << std::endl;
	return 0;
}

int main()
{
	std::string numOne, numTwo;
	std::cin >> numOne >> numTwo;

	//comparison of numbers
	int k = 3; // if k = 3, numbers have the same length	
	int length = numOne.length();
	if (numOne.length() > numTwo.length())
	{
		length = numOne.length();
		k = 1; // if k = 1, the first number is longer than the second
	}
	else
	{
		if (numTwo.length() > numOne.length())
		{
			length = numTwo.length();
			k = 2; // if k = 2, the second number is longer than the first
		}
		else
		{
			for (int i = 0; i < length; ++i)
			{
				if (numOne[i] > numTwo[i])
				{
					k = 1; // the first number is longer than the second
					break;
				}
				if (numTwo[i] > numOne[i])
				{
					k = 2; // the second number is longer than the first
					break;
				}
			}
		}
	}

	if (numOne.size() > numTwo.size())
	{
		while (numTwo.size() != numOne.size())
		{
			numTwo = "0" + numTwo;
		}
	}
	if (numOne.size() < numTwo.size())
	{
		while (numTwo.size() != numOne.size())
		{
			numOne = "0" + numOne;
		}
	}
	std::reverse(numOne.begin(), numOne.end());
	std::reverse(numTwo.begin(), numTwo.end());

	//converting strings to vectors of ints
	std::vector<int> a;
	std::vector<int> b;
	std::vector<int> c;
	for (int i = 0; i < numOne.size(); i++)
	{
		a.push_back(numOne[i] - 48);
	}
	for (int i = 0; i < numTwo.size(); i++)
	{
		b.push_back(numTwo[i] - 48);
	}
	for (int i = 0; i < length; i++)
	{
		c.push_back(0);
	}

	if (k == 1 || k == 3)
	{
		subtraction(a, b, c, length);
	}

	if (k == 2)
	{
		std::cout << "-";
		subtraction(b, a, c, length);
	}

	return 0;
}