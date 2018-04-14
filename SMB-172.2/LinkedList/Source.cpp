#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node *next = nullptr, *prev = nullptr;
};

//добавление - O(n) от head
//добавление - O(1) от tail
struct DoubleLinkedList
{
	Node *head, *tail;
};
void addToTail(DoubleLinkedList &, int);
//void deleteFromTail(DoubleLinkedList &);
void f1() {
	DoubleLinkedList x;
	Node y;
	y.value = 5;
	Node z;
	z.value = 6;
	y.next = &z;
	z.prev = &y;
	x.head = &y;
	x.tail = &z;
	Node a;
	a.value = -1;
	z.next = &a;
	a.prev = &z;
	x.tail = &a;
	Node * temp = x.head;
	while (temp->next != nullptr) {
		cout << temp->value << endl;
		temp = temp->next;
	}
}
struct stack {
	int data[100000];
	int top = 0;
};
void push(stack &, int);
int pop(stack &);
int peek(stack &);
int main()
{
	stack x;
	push(x, 3);
	push(x, 4);
	push(x, 5);
	push(x, 6);
	cout << pop(x) << endl << peek(x);
	system("pause");
	return 0;
}

void push(stack & s, int x)
{
	s.data[s.top++] = x;
}

int pop(stack & s) 
{
	return s.data[--s.top];
}

int peek(stack & s) 
{
	return s.data[s.top - 1];
}

void addToTail(DoubleLinkedList & d, int x) 
{
	Node a;
	a.value = x;
	d.tail->next = &a;
	a.prev = d.tail;
	d.tail = d.tail->next;
}
