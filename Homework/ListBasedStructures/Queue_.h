#pragma once
#include "doubleLinkedList.h"
template<class T>
class Queue_
{
private:
	doubleLinkedList<T> q;
public:
	int size() const;
	T& back();
	T& front();
	void push(T val);
	void pop();
	bool empty() const;
};
