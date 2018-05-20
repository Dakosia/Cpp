#include "singleLinkedList.h"

void list()
{
	singleLinkedList<int> t;
	for (size_t i = 0; i < 10; i++)
	{
		t.push_back(i);
	}
	for (size_t i = 0; i < 10; i++)
	{
		t.push_front(i * i);
	}
	t.print();

}

int main()
{
	list();

	return 0;
}