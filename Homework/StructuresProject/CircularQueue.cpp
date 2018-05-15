#include "CircularQueue.h"



template<class T>
int CircularQueue<T>::size() const
{
	return cq.getSize();
}

template<class T>
T & CircularQueue<T>::back()
{
	return cq[cq.getSize() - 1];
}

template<class T>
T & CircularQueue<T>::front()
{
	return cq[0];
}

template<class T>
void CircularQueue<T>::push(T val)
{
	cq.push_back(val);
}

template<class T>
void CircularQueue<T>::pop()
{
	cq.erase(0);
}

template<class T>
bool CircularQueue<T>::empty() const
{
	return cq.empty();
}

template<class T>
void CircularQueue<T>::frontToBack()
{
	T tmp = this->front();
	this->pop();
	this->push(tmp);
}
