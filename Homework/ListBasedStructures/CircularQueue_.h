#pragma once
#include "doubleLinkedList.h"
template<class T>
class CircularQueue_
{
private:
	doubleLinkedList<T> cq;
public:
	int size() const;
	T& back();
	T& front();
	void push(T val);
	void pop();
	bool empty() const;
	void frontToBack();
};
