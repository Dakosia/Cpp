#pragma once
#include "doubleLinkedList.h"
template<class T>
class PriorityQueue_
{
private:
	doubleLinkedList<std::pair<T, int>> pq;
public:
	int size() const;
	T& back();
	T& front();
	void push(const T& val, int prior);
	void pop();
	bool empty() const;
};