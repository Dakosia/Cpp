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

	VectorMy& operator=(const VectorMy &a);
	const VectorMy& operator+=(const VectorMy &a);

	void push_back(int num);
	void pop_back();
	void print();
	int getSize() const;
	void clear();
	bool isEmpty();

	void insert(int position, int value);
	void erase(int position);
	void reverse();

	int& operator[](int ind);
	int& operator[](int ind) const;

	friend std::istream& operator>>(std::istream &in, VectorMy &a);
};

std::ostream& operator<<(std::ostream &out, const VectorMy &a);
std::istream& operator>>(std::istream &in, VectorMy &a);

VectorMy& operator+(const VectorMy &a, const VectorMy &b);

bool operator>(const VectorMy &a, const VectorMy &b);
bool operator<(const VectorMy &a, const VectorMy &b);
bool operator>=(const VectorMy &a, const VectorMy &b);
bool operator<=(const VectorMy &a, const VectorMy &b);
bool operator!=(const VectorMy &a, const VectorMy &b);
bool operator==(const VectorMy &a, const VectorMy &b);