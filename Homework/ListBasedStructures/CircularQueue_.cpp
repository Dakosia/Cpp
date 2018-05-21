#include "CircularQueue_.h"



template<class T>
int CircularQueue_<T>::size() const
{
	return cq.getSize();
}

template<class T>
T & CircularQueue_<T>::back()
{
	return cq.back();
}

template<class T>
T & CircularQueue_<T>::front()
{
	return cq.front();
}

template<class T>
void CircularQueue_<T>::push(T val)
{
	cq.push_back(val);
}

template<class T>
void CircularQueue_<T>::pop()
{
	cq.pop_front();
}

template<class T>
bool CircularQueue_<T>::empty() const
{
	return cq.empty();
}

template<class T>
void CircularQueue_<T>::frontToBack()
{
	T tmp = this->front();
	this->pop();
	this->push(tmp);
}
