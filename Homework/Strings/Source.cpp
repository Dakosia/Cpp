#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string s1, s2;
	std::getline(std::cin, s1);
	std::getline(std::cin, s2);

	bool b = true;
	if (s1.length() != s2.length())
	{
		b = false;
	}
	else
	{
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		for (int i = 0; i < s1.length(); ++i)
		{
			if (s1[i] != s2[i])
			{
				b = false;
			}
		}
	}

	if (!b)
	{
		std::cout << "no" << std::endl;
	}
	else
	{
		std::cout << "yes" << std::endl;
	}

	return 0;
}