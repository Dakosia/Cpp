#include "singleLinkedList.h"
#include "doubleLinkedList.h"

void list()
{
	singleLinkedList<int> t;
	for (int i = 0; i < 10; i++)
	{
		t.push_back(i);
	}
	for (int i = 0; i < 10; i++)
	{
		t.push_front(i * i);
	}
	t.print();

}

void doubleList()
{
	doubleLinkedList<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);
	}
	std::cout << l << std::endl;
	l.clear();
	for (int i = 0; i < 10; i++)
	{
		l.push_front(i * i);
	}
	std::cout << l << std::endl;
	l.reverse();
	std::cout << l << std::endl;
	for (int i = 10; i > 0; i--)
	{
		l.insert(i, 777);
	}
	std::cout << l << std::endl;
	for (int i = 20; i > 0; i -= 2)
	{
		l.erase(i);
	}
	std::cout << l << std::endl;

}

int main()
{
	//list();
	doubleList();

	system("pause");
	return 0;
}