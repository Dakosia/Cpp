#pragma once
#include <iostream>

template<class T>
class elem
{
public:
	T obj;
	elem<T> *next;
	//friend class singleLinkedList<T>;
};

template<class T>
class singleLinkedList
{
private:
	int size;
	elem<T> *head;
	elem<T> *tail;
public:
	singleLinkedList();
	singleLinkedList(const singleLinkedList<T>& obj);
	singleLinkedList<T>& operator=(const singleLinkedList<T>& obj);

	int getSize() const;
	void push_back(const T& obj);
	void push_front(const T& obj);
	void pop_back();
	void pop_front();
	void erase(int pos);
	void insert(int pos, const T& a);
	void clear();
	bool empty() const;

	void print()
	{
		elem<T> *tmp = head;
		while (tmp != nullptr)
		{
			std::cout << tmp->obj << " ";
			tmp = tmp->next;
		}
	}

	~singleLinkedList();
};
