#include "Stack.h"



template<class T>
Stack<T>::Stack(int size)
{
	this->top = 0
	this->size = size;
	this->stackPtr = new T[size];
}

template<class T>
Stack<T>::Stack(const Stack<T>& obj)
{
	this->size = obj.size;
	this->top = obj.top;
	this->stackPtr = new T[this->size];
	for (size_t i = 0; i < top; i++)
	{
		this->stackPtr[i] = obj.stackPtr[i];
	}
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& obj)
{
	if (&obj == this)
		return *this;
	delete[] stackPtr;
	this->size = obj.size;
	this->top = obj.top;
	this->stackPtr = new T[this->size];
	for (size_t i = 0; i < top; i++)
	{
		this->stackPtr[i] = obj.stackPtr[i];
	}
	return *this;
}

template<class T>
void Stack<T>::push(const T & val)
{
	if (top < size)
		stackPtr[top++] = val;
	else
		std::cout << "Stack overflow";
}

template<class T>
void Stack<T>::pop()
{
	if (top > 0)
		stackPtr[top--];
	else
		std::cout << "Stack is empty";
}

template<class T>
bool Stack<T>::empty() const
{
	return this->size == 0;
}

template<class T>
Stack<T>::~Stack()
{
	delete[] stackPtr;
	this->size = 0;
	this->top = 0;
}