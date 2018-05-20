#include "vector_.h"



template<class T>
vector_<T>::vector_()
{
	this->size = 0;
	this->arr = nullptr;
}

template<class T>
vector_<T>::vector_(const vector_<T>& obj)
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

template<class T>
vector_<T>& vector_<T>::operator=(const vector_<T>& obj)
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

template<class T>
vector_<T>::~vector_()
{
	if (this->arr != nullptr)
	{
		delete[] this->arr;
		this->arr = nullptr;
	}
	this->size = 0;
}

template<class T>
int vector_<T>::getSize() const
{
	return this->size;
}

template<class T>
T * vector_<T>::data()
{
	return this->arr;
}

template<class T>
const T * vector_<T>::data() const
{
	return this->arr;
}

template<class T>
void vector_<T>::clear()
{
	this->~vector_();
}

template<class T>
bool vector_<T>::empty() const
{
	return this->size == 0;
}

template<class T>
void vector_<T>::push_back(const T & b)
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

template<class T>
void vector_<T>::pop_back()
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

template<class T>
void vector_<T>::reverse()
{
	for (size_t i = 0; i < this->size / 2; i++)
	{
		std::swap(this->arr[i], this->arr[size - i - 1]);
	}
}

template<class T>
void vector_<T>::erase(int pos)
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

template<class T>
void vector_<T>::insert(int pos, const T value)
{
	T *new_arr = new T[size + 1];
	int mark = 0;
	for (size_t i = 0; i < size + 1; i++)
	{
		if (i == pos)
		{
			new_arr[i] = val;
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

template<class T>
vector_<T>& vector_<T>::operator+=(const vector_<T>& obj)
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

template<class T>
T & vector_<T>::operator[](int pos)
{
	return arr[pos];
}

template<class T>
T & vector_<T>::operator[](int pos) const
{
	return arr[pos];
}

template<class TT>
std::ostream & operator<<(std::ostream & out, const vector_<TT>& a)
{
	for (size_t i = 0; i < a.size; i++)
	{
		out << a.arr[i] << ' ';
	}
	out << std::endl;
	return out;
}

template<class TT>
std::istream & operator >> (std::istream & in, vector_<TT>& a)
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