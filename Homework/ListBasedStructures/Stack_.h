#pragma once
#include "doubleLinkedList.h"
template<class T>
class Stack_
{
private:
	doubleLinkedList<T> s;
public:
	int size() const;
	T& getTop();
	void push(const T & val);
	void pop();
	bool empty() const;
};

