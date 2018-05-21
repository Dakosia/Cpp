#include "Stack_.h"



template<class T>
int Stack_<T>::size() const
{
	return s.getSize();
}

template<class T>
T & Stack_<T>::getTop()
{
	return s.back();
}

template<class T>
void Stack_<T>::push(const T & val)
{
	s.push_back(val);
}

template<class T>
void Stack_<T>::pop()
{
	s.pop_back();
}

template<class T>
bool Stack_<T>::empty() const
{
	return s.empty();
}