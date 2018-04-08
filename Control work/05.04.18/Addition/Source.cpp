#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string numOne, numTwo;
	std::getline(std::cin, numOne);
	std::getline(std::cin, numTwo);

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

	numOne = numOne + "0";
	numTwo = numTwo + "0";


	//converting strings to vectors of ints
	std::vector<int> a;
	std::vector<int> b;
	for (int i = 0; i < numOne.size(); i++)
	{
		a.push_back(numOne[i] - 48);
	}
	for (int i = 0; i < numTwo.size(); i++)
	{
		b.push_back(numTwo[i] - 48);
	}

	//addition
	for (int i = 0; i < a.size() - 1; i++)
	{
		b[i] += a[i];
		b[i + 1] += (b[i] / 10);
		b[i] %= 10;
	}
	std::reverse(b.begin(), b.end());

	for (auto i : b)
	{
		std::cout << i;
	}
	std::cout << std::endl;

	return 0;
}