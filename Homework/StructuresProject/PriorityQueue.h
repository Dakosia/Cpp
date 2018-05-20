#pragma once
#include "vector_.h"
template<class T>
class PriorityQueue
{
private:
	vector_<std::pair<T, int>> mas;
public:
	int size() const;
	T& back();
	T& front();
	void push(const T& val, int prior);
	void pop();
	bool empty() const;
};