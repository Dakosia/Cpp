#pragma once
#include <iostream>

template<class T>
class element
{
public:
	T data;
	element<T> *next = nullptr;
	element<T> *prev = nullptr;
};

template<class T>
class doubleLinkedList
{
private:
	int size;
	element<T> *head;
	element<T> *tail;
public:
	doubleLinkedList()
	{
		size = 0;
		head = tail = nullptr;
	}
	doubleLinkedList(const doubleLinkedList<T>& obj)
	{
		if (obj.size == 0)
		{
			size = 0;
			head = tail = nullptr;
		}
		else
		{
			element<T> *tmp = obj.head;
			for (int i = 0; i < obj.size; i++)
			{
				push_back(tmp->data);
				tmp = tmp->next;
			}
		}
	}
	doubleLinkedList<T>& operator=(const doubleLinkedList<T>& obj)
	{
		if (this == &obj)
			return *this;
		this->clear();
		element<T> *tmp = obj.head;
		for (int i = 0; i < obj.size; i++)
		{
			push_back(tmp->data);
			tmp = tmp->next;
		}
		return *this;
	}

	int getSize() const { return size; }
	void push_back(const T& l)
	{
		element<T> *newElem = new element<T>;
		newElem->data = l;
		if (size == 0)
			head = tail = newElem;
		else
		{
			tail->next = newElem;
			newElem->prev = tail;
			tail = newElem;
		}
		++size;
	}
	void push_front(const T& l)
	{
		element<T> *newElem = new element<T>;
		newElem->data = l;
		if (size == 0)
			head = tail = newElem;
		else
		{
			head->prev = newElem;
			newElem->next = head;
			head = newElem;
		}
		++size;
	}
	void pop_back()
	{
		if (size == 0)
			return;
		if (size == 1)
		{
			delete head;
			head = tail = nullptr;
			size = 0;
			return;
		}
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
		--size;
	}
	void pop_front()
	{
		if (size == 0)
			return;
		if (size == 1)
		{
			delete head;
			head = tail = nullptr;
			size = 0;
			return;
		}
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
		--size;
	}
	void insert(int pos, const T& obj)
	{
		if (pos > size)
			return;
		if (size == 0)
		{
			push_front(obj);
			return;
		}
		if (pos == size)
		{
			push_back(obj);
			return;
		}
		int dis = size / 2;
		element<T> *tmp;
		if (dis > pos)
		{
			tmp = head;
			for (int i = 0; i < pos - 1; i++)
			{
				tmp = tmp->next;
			}
		}
		else
		{
			tmp = tail;
			for (int i = 0; i < size - pos; i++)
			{
				tmp = tmp->prev;
			}
		}
		element<T> *newElem = new element<T>;
		newElem->data = obj;
		newElem->prev = tmp;
		newElem->next = tmp->next;
		tmp->next = newElem;
		newElem->next->prev = newElem;
		++size;
	}
	void erase(int pos)
	{
		if (pos < 0)
			return;
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
		int dis = size / 2;
		element<T> *tmp;
		if (dis < pos)
		{
			tmp = tail;
			for (int i = 0; i < size - pos - 1; i++)
			{
				tmp = tmp->prev;
			}
		}
		else
		{
			tmp = head;
			for (int i = 0; i < pos; i++)
			{
				tmp = tmp->next;
			}
		}
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		delete tmp;
		--size;
	}
	void reverse()
	{
		if (size > 1)
		{
			element<T> *tmp = head;
			for (int i = 0; i < size; i++)
			{
				std::swap(tmp->prev, tmp->next);
				tmp = tmp->prev;
			}
			tmp = head;
			head = tail;
			tail = tmp;
		}
	}
	void clear()
	{
		if (size > 0)
		{
			element<T> *tmp = head;
			while (tmp != nullptr)
			{
				element<T> *toDelete = tmp;
				tmp = tmp->next;
				delete toDelete;
			}
			head = tail = nullptr;
			size = 0;
		}
	}
	bool empty() const { return size == 0; }
	T& front() { return head->data; }
	const T& front() const { return head->data; }
	T& back() { return tail->data; }
	const T& back() const { return tail->data; }

	void print() {

	}
	~doubleLinkedList()
	{
		this->clear();
	}

	template<class TT>
	friend std::ostream& operator<<(std::ostream&os, const doubleLinkedList<TT>&obj);
};

template<class TT>
std::ostream& operator<<(std::ostream&os, const doubleLinkedList<TT>&obj)
{
	element<TT> *tmp = obj.head;
	while (tmp != nullptr)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	return os;
}