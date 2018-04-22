#include "VectorMy.h"
#include <ctime>

void vectorMy() {

	srand(time(NULL));

	VectorMy v;
	for (size_t i = 0; i < 9; i++)
	{
		v.push_back(rand() % 10);
	}
	v.print();
	std::cout << "-------------\n";

	v.insert(4, 9);
	v.print();
	std::cout << "-------------\n";

	v.erase(2);
	v.print();
	std::cout << "-------------\n";

	v.reverse();
	v.print();


	/*VectorMy vec;
	vec.push_back(150);
	vec.print();
	for (size_t i = 0; i < 9; i++)
	{
	vec.push_back(rand() % 10);
	}

	VectorMy v2 = vec;
	std::cout << "-------------\n";
	vec.print();
	std::cout << "-------------\n";
	v2.print();
	std::cout << "-------------\n";

	vec.print();
	for (size_t i = 0; i < 15; i++)
	{
	vec.pop_back();
	vec.print();
	}*/

	
}

int main()
{
	vectorMy();

	return 0;
}