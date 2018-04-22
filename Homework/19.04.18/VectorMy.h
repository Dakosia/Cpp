#pragma once
#include <iostream>
class VectorMy
{
private:
	int *arr;
	int size;
public:
	VectorMy();
	VectorMy(int size, int num);
	VectorMy(const VectorMy &ad);
	~VectorMy();

	void push_back(int num);
	void pop_back();
	void print();
	int getSize();
	void clear();
	bool isEmpty();

	void insert(int position, int value);
	void erase(int position);
	void reverse();
};