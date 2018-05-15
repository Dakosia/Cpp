#include "vector_.h"

void vector()
{
	vector_<int> v;
	for (size_t i = 0; i < 15; i++)
	{
		v.push_back(i);
	}
	std::cout << v;
	vector_<int> v2 = v;
	std::cout << v2;
	v.erase(5);
	std::cout << v;

	v += v;
	std::cout << v;
}

int main()
{
	vector();

	return 0;
}