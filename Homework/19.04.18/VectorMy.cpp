
#include "VectorMy.h"



VectorMy::VectorMy()
{
	this->size = 0;
	this->arr = nullptr;
}

VectorMy::VectorMy(int size, int num)
{
	this->size = size;
	this->arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = num;
	}
}

VectorMy::VectorMy(const VectorMy & ad)
{
	this->size = ad.size;
	if (this->size == 0)
	{
		this->arr = nullptr;
	}
	else
	{
		this->arr = new int[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			this->arr[i] = ad.arr[i];
		}
	}
}


VectorMy::~VectorMy()
{
	delete[] this->arr;
	this->arr = nullptr;
	size = 0;
}

const VectorMy & VectorMy::operator=(const VectorMy & a)
{
	if (&a == this)
		return *this;
	this->clear();
	if (a.size == 0)
		return *this;
	this->size = a.size;
	this->arr = new int[a.size];
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = a.arr[i];
	}
	return *this;
}

const VectorMy & VectorMy::operator+=(const VectorMy & a)
{
	for (size_t i = 0; i < a.size; i++)
	{
		this->push_back(a[i]);
	}
	return *this;
}

void VectorMy::push_back(int num)
{
	int *new_arr;
	if (size == 0)
	{
		new_arr = new int[1];
		new_arr[0] = num;
	}
	else
	{
		new_arr = new int[size + 1];
		for (int i = 0; i < size; i++)
		{
			new_arr[i] = this->arr[i];
		}
		new_arr[size] = num;
	}
	++size;
	delete[] this->arr;
	this->arr = new_arr;
}

void VectorMy::pop_back()
{
	//если нет элементов, выходим из метода
	if (size == 0) return;
	if (size == 1)
	{
		delete[] this->arr;
		this->arr = nullptr;
		size = 0;
		return;
	}
	int *new_arr = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		new_arr[i] = this->arr[i];
	}
	--size;
	delete[] this->arr;
	this->arr = new_arr;
}

void VectorMy::print()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << this->arr[i] << ' ';
	}
	std::cout << std::endl;
}

int VectorMy::getSize() const
{
	return this->size;
}

void VectorMy::clear()
{
	delete[] this->arr;
	this->arr = nullptr;
	size = 0;
}

bool VectorMy::isEmpty()
{
	return size == 0;
}

void VectorMy::insert(int position, int value)
{
	int *new_arr;
	if (size == 0 || position >= size) return;
	new_arr = new int[size + 1];
	for (int i = 0; i < position; i++)
	{
		new_arr[i] = this->arr[i];
	}
	new_arr[position] = value;
	for (int i = position + 1; i < size + 1; i++)
	{
		new_arr[i] = this->arr[i - 1];
	}
	++size;
	delete[] this->arr;
	this->arr = new_arr;
}

void VectorMy::erase(int position)
{
	/*if (size == 0 || position >= size) return;
	int *new_arr = new int[size - 1];
	for (int i = 0; i < position; i++)
	{
		new_arr[i] = this->arr[i];
	}
	for (int i = position; i < size; i++)
	{
		new_arr[i] = this->arr[i + 1];
	}
	--size;
	delete[] this->arr;
	this->arr = new_arr;*/

	if (size == 0) {
		return;
	}
	if (size == 1 && position == 0) {
		clear();
	}
	for (size_t i = position; i < size - 1; i++)
	{
		std::swap(this->arr[i], this->arr[i + 1]);
	}
	--size;
}

void VectorMy::reverse()
{
	/*if (size == 0) return;
	int *new_arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		new_arr[i] = this->arr[size - 1 - i];
	}
	delete[] this->arr;
	this->arr = new_arr;*/
	for (size_t i = 0; i < this->size / 2; i++)
	{
		std::swap(this->arr[i], this->arr[size - i - 1]);
	}
}

int& VectorMy::operator[](int ind)
{
	return arr[ind];
}

int & VectorMy::operator[](int ind) const
{
	return arr[ind];
}

std::ostream & operator<<(std::ostream & out, const VectorMy & a)
{
	for (size_t i = 0; i < a.getSize(); i++)
	{
		out << a[i] << ' ';
	}
	out << std::endl;
	return out;
}

std::istream & operator >> (std::istream & in, VectorMy & a)
{
	a.clear();
	std::cout << "Enter size\n";
	int size;
	in >> size;
	if (size > 0)
	{
		std::cout << "Enter array\n";
		for (size_t i = 0; i < size; i++)
		{
			int tmp;
			in >> tmp;
			a.push_back(tmp);
		}
	}
	return in;
}

VectorMy& operator+(const VectorMy & a, const VectorMy & b)
{
	VectorMy s = a;
	s += b;
	return s;
}

bool operator>(const VectorMy & a, const VectorMy & b)
{
	if (a.getSize() > b.getSize())
		return true;
	if (a.getSize() == b.getSize())
	{
		for (size_t i = 0; i < a.getSize(); i++)
		{
			if (a[i] > b[i])
				return true;
		}
		return false;
	}
	return false;
}

bool operator<(const VectorMy & a, const VectorMy & b)
{
	if (a.getSize() < b.getSize())
		return true;
	if (a.getSize() == b.getSize())
	{
		for (size_t i = 0; i < a.getSize(); i++)
		{
			if (a[i] < b[i])
				return true;
		}
		return false;
	}
	return false;
}

bool operator>=(const VectorMy & a, const VectorMy & b)
{
	if (a.getSize() > b.getSize())
		return true;
	if (a.getSize() == b.getSize())
	{
		for (size_t i = 0; i < a.getSize(); i++)
		{
			if (a[i] > b[i])
				return true;
			if (a[i] < b[i])
				return false;
		}
		return true;
	}
	return false;
}

bool operator<=(const VectorMy & a, const VectorMy & b)
{
	if (a.getSize() < b.getSize())
		return true;
	if (a.getSize() == b.getSize())
	{
		for (size_t i = 0; i < a.getSize(); i++)
		{
			if (a[i] < b[i])
				return true;
			if (a[i] > b[i])
				return false;
		}
		return true;
	}
	return false;
}

bool operator!=(const VectorMy & a, const VectorMy & b)
{
	if (a.getSize() != b.getSize())
		return true;
	for (size_t i = 0; i < a.getSize(); i++)
	{
		if (a[i] != b[i])
			return true;
	}
	return false;
}

bool operator==(const VectorMy & a, const VectorMy & b)
{
	if (a.getSize() != b.getSize())
		return false;
	for (size_t i = 0; i < a.getSize(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

