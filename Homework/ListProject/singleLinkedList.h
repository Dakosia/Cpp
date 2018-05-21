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
	singleLinkedList()
	{
		size = 0;
		head = tail = nullptr;
	}
	singleLinkedList(const singleLinkedList<T>& obj)
	{
		size = 0;
		head = tail = nullptr;
		elem<T> *tmp = obj.head;
		while (tmp != nullptr)
		{
			push_back(tmp->obj);
			tmp = tmp->next;
		}
	}
	singleLinkedList<T>& operator=(const singleLinkedList<T>& obj)
	{
		if (this == &obj)
			return *this;
		this->~singleLinkedList();
		elem<T> *tmp = obj.head;
		while (tmp != nullptr)
		{
			push_back(tmp->obj);
			tmp = tmp->next;
		}
		return *this;
	}

	int getSize() const { return size; }
	void push_back(const T& obj)
	{
		elem<T> *newElem = new elem<T>;
		newElem->obj = obj;
		newElem->next = nullptr;
		if (tail == nullptr)
			head = tail = newElem;
		else
		{
			tail->next = newElem;
			tail = newElem;
		}
		++size;
	}
	void push_front(const T& obj)
	{
		elem<T> *newElem = new elem<T>;
		newElem->obj = obj;
		if (head == nullptr)
			head = tail = newElem;
		else
		{
			newElem->next = head;
			head = newElem;
		}
		++size;
	}
	void pop_back()
	{
		if (tail == nullptr)
			return;
		if (size == 1) //tail == head
		{
			delete head;
			head = tail = nullptr;
			size = 0;
			return;
		}
		elem<T> *tmp = head;
		while (tmp->next != tail)
			tmp = tmp->next;
		delete tail;
		tail = tmp;
		tail->next = nullptr;
		--size;
	}
	void pop_front()
	{
		if (head == nullptr)
			return;
		if (size == 1) //tail == head
		{
			delete head;
			head = tail = nullptr;
			size = 0;
			return;
		}
		elem<T> *tmp = head;
		head = head->next;
		delete tmp;
		--size;
	}
	void erase(int pos)
	{
		if (pos >= size)
			return;
		if (pos == 0)
		{
			pop_front();
			return;
		}
		if (pos == size - 1)
		{
			pop_back();
			return;
		}
		elem<T> *tmp = head;
		for (size_t i = 0; i < pos - 1; i++)
		{
			tmp = tmp->next;
		}
		elem<T> *r = tmp->next;
		tmp->next = tmp->next->next;
		delete r;
		--size;
	}
	void insert(int pos, const T& a)
	{
		if (pos > size)
			return;
		if (pos == 0)
		{
			push_front(a);
			return;
		}
		if (pos == size)
		{
			push_back(a);
			return;
		}
		elem<T> *newElem = new elem<T>;
		elem<T> *tmp = head;
		for (size_t i = 0; i < pos - 1; i++)
		{
			tmp = tmp->next;
		}
		newElem->obj = a;
		newElem->next = tmp->next;
		tmp->next = newElem;
		++size;
	}
	void clear()
	{
		if (size != 0)
			this->~singleLinkedList();
	}
	bool empty() const { return size == 0; }

	void print()
	{
		elem<T> *tmp = head;
		while (tmp != nullptr)
		{
			std::cout << tmp->obj << " ";
			tmp = tmp->next;
		}
	}

	~singleLinkedList()
	{
		while (size != 0) //tail != nullptr
			pop_front();
	}
};
