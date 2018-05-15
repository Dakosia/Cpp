#pragma once
#include "vector_.h"
template<class T>
class CircularQueue
{
private:
	vector_<T> cq;
public:
	int size() const;
	T& back();
	T& front();
	void push(T val);
	void pop();
	bool empty() const;
	void frontToBack();
};
