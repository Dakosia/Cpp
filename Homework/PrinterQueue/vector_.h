#pragma once
#include <iostream>
template<class T>
class vector_
{
private:
	int size;
	T *arr;
public:
	vector_()
	{
		this->size = 0;
		this->arr = nullptr;
	}
	vector_(const vector_<T>&obj)
	{
		this->size = obj.size;
		if (this->size == 0)
			this->arr = nullptr;
		else
		{
			this->arr = new T[size];
			for (size_t i = 0; i < this->size; i++)
			{
				this->arr[i] = obj.arr[i];
			}
		}
	}
	vector_<T> & operator=(const vector_<T> & obj)
	{
		if (&obj == this)
			return *this;
		this->~vector_();
		this->size = obj.size;
		if (this->size == 0)
			return *this;
		this->arr = new T[obj.size];
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = obj.arr[i];
		}
		return *this;
	}
	~vector_()
	{
		if (this->arr != nullptr)
		{
			delete[] this->arr;
			this->arr = nullptr;
		}
		this->size = 0;
	}

	int getSize() const { return this->size; }
	T* data() { return this->arr; }
	const T* data() const { return this->arr; }
	void clear() { this->~vector_(); }
	bool empty() const { return this->size == 0; }
	void push_back(const T &b)
	{
		T *new_arr;
		if (this->size == 0)
		{
			new_arr = new T[1];
			new_arr[0] = b;
		}
		else
		{
			new_arr = new T[size + 1];
			for (size_t i = 0; i < size; i++)
			{
				new_arr[i] = this->arr[i];
			}
			new_arr[size] = b;
		}
		++size;
		delete[] this->arr;
		this->arr = new_arr;
	}
	void pop_back()
	{
		if (this->size == 0) return;
		if (this->size == 1)
		{
			this->~vector_();
			return;
		}
		T *new_arr = new T[size - 1];
		for (size_t i = 0; i < this->size - 1; i++)
		{
			new_arr[i] = this->arr[i];
		}
		--size;
		delete[] this->arr;
		this->arr = new_arr;
	}
	void reverse()
	{
		for (size_t i = 0; i < this->size / 2; i++)
		{
			std::swap(this->arr[i], this->arr[size - i - 1]);
		}
	}
	void erase(int pos)
	{
		if (pos >= 0 && pos < this->size)
		{
			for (size_t i = pos; i < this->size - 1; i++)
			{
				std::swap(this->arr[i], this->arr[i + 1]);
			}
			this->pop_back();
		}
	}
	void insert(int pos, const T value)
	{
		T *new_arr = new T[size + 1];
		int mark = 0;
		for (size_t i = 0; i < size + 1; i++)
		{
			if (i == pos)
			{
				new_arr[i] = value;
				mark = 1;
			}
			else
				new_arr[i] = this->arr[i - mark];
		}
		++size;
		if (this->arr != nullptr)
			delete[] this->arr;
		this->arr = new_arr;
	}
	vector_<T>& operator+=(const vector_<T> &obj)
	{
		int s = obj.size;
		if (obj.empty())
			return *this;
		for (size_t i = 0; i < s; i++)
		{
			this->push_back(obj.arr[i]);
		}
		return *this;
	}
	//T at(int pos);
	T& operator[](int pos) { return arr[pos]; }
	T& operator[](int pos) const { return arr[pos]; }
	template<class TT>
	friend std::ostream& operator<<(std::ostream &out, const vector_<TT> &a);
	template<class TT>
	friend std::istream& operator >> (std::istream &in, vector_<TT> &a);

};
template<class TT>
std::ostream& operator<<(std::ostream &out, const vector_<TT> &a)
{
	for (size_t i = 0; i < a.size; i++)
	{
		out << a.arr[i] << ' ';
	}
	out << std::endl;
	return out;
}
template<class TT>
std::istream& operator >> (std::istream &in, vector_<TT> &a)
{
	a.clear();
	std::cout << "Enter size\n";
	int size;
	while (size <= 0)
		in >> size;
	std::cout << "Enter array\n";
	T obj;
	for (size_t i = 0; i < size; i++)
	{
		in >> obj;
		a.push_back(obj);
	}
	return in;
}
