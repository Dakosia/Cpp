#pragma once
#include <iostream>
template<class T>
class vector_
{
private:
	int size;
	T *arr;
public:
	vector_();
	vector_(const vector_<T>&obj);
	vector_<T> & operator=(const vector_<T> & obj);
	~vector_();

	int getSize() const;
	T* data();
	const T* data() const;
	void clear();
	bool empty() const;
	void push_back(const T &b);
	void pop_back();
	void reverse();
	void erase(int pos);
	void insert(int pos, const T value);
	vector_<T>& operator+=(const vector_<T> &obj);
	//T at(int pos);
	T& operator[](int pos);
	T& operator[](int pos) const;
	template<class TT>
	friend std::ostream& operator<<(std::ostream &out, const vector_<TT> &a);
	template<class TT>
	friend std::istream& operator >> (std::istream &in, vector_<TT> &a);

};
template<class TT>
std::ostream& operator<<(std::ostream &out, const vector_<TT> &a);
template<class TT>
std::istream& operator >> (std::istream &in, vector_<TT> &a);
