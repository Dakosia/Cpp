#include <vector>
#include <iostream>
int main()
{
	std::vector<int> source = { 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1 };
	for (int i = 1; i < source.size(); ++i)
	{
		std::cout << source[i] << ' ';
	}
	std::cout << std::endl;

	for (int i = 1; i <= 8; i *= 2)
	{
		source.insert(source.begin() + i, 0);
	}

	std::cout << "with empty bits: " << std::endl;
	for (int i = 1; i < source.size(); ++i)
	{
		std::cout << source[i] << ' ';
	}
	std::cout << std::endl;

	std::cout << "counting..." << std::endl;
	for (int i = 1; i <= 8; i *= 2)
	{
		int sum = 0;
		for (int j = i; j < source.size(); j += i)
		{
			for (int k = 0; k < i && j < source.size(); ++k)
			{
				sum += source[j];
				++j;
			}
		}
		if (sum % 2 != 0)
		{
			source[i] = 1;
		}
		else
		{
			source[i] = 0;
		}
		sum = 0;
	}

	std::cout << "with managing bits: " << std::endl;
	for (int i = 1; i < source.size(); ++i)
	{
		std::cout << source[i] << ' ';
	}
	std::cout << std::endl;

	std::vector<int> error = { 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0 };

	for (int i = 1; i <= 8; i *= 2)
	{
		int sum = 0;
		for (int j = i; j < error.size(); j += i)
		{
			for (int k = 0; k < i && j < error.size(); ++k)
			{
				sum += error[j];
				++j;
			}
		}
		int temp = 0;
		if (sum % 2 != 0)
		{
			temp = 1;
		}
		else
		{
			temp = 0;
		}
		if (temp != error[i])
		{
			std::cout << i << std::endl;
		}
		sum = 0;
	}

	system("pause");
	return 0;
}