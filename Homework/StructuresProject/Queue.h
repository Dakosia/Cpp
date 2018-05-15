#pragma once
#include "vector_.h"
#include <queue>
template<class T>
class Queue
{
private:
	vector_<T> q;
public:
	void push(T val);
	void pop();
	bool empty() const;
	int size() const;
	T& back();
	T& front();
};
