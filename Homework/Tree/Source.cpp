#include "Tree.h"
#include <string>

void tree()
{
	setlocale(0, "");
	Tree<int, std::string> tree;
	tree.add(100, "Сто");
	tree.add(0, "Ноль");
	tree.add(-30, "Минус тридцать");
	tree.add(77, "Семьдесят семь");
	tree.add(101, "Сто один");
	tree.add(25, "Двадцать пять");
	tree.add(9, "Девять");
	tree.add(7, "Семь");

	/*Tree<int, std::string> t2 = tree;
	t2.print();
	std::cout << std::endl;*/

	tree.print();
	std::cout << std::endl;
	tree.del(25);
	tree.print();

	//std::cout << tree.search(-30) << std::endl;
	/*while (true)
	{
	Tree<int, std::string> tree;
	tree.~Tree();
	}*/
	system("pause");

}

int main()
{
	tree();

	system("pause");
	return 0;
}