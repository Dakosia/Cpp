#include "VectorMy.h"



VectorMy::VectorMy()
{
	this->size = 0;
	this->arr = nullptr;
}

VectorMy::VectorMy(int size, int num)
{
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

int VectorMy::getSize()
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
	if (size == 0 || position > size) return;
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
	if (size == 0 || position > size) return;
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
	this->arr = new_arr;
}

void VectorMy::reverse()
{
	if (size == 0) return;
	int *new_arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		new_arr[i] = this->arr[size - 1 - i];
	}
	delete[] this->arr;
	this->arr = new_arr;
}

