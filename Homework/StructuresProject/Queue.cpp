#include "Queue.h"



template<class T>
void Queue<T>::push(T val)
{
	q.push_back(val);
}

template<class T>
void Queue<T>::pop()
{
	q.erase(0);
}

template<class T>
bool Queue<T>::empty() const
{
	return q.empty();
}

template<class T>
int Queue<T>::size() const
{
	return q.getSize();
}

template<class T>
T & Queue<T>::back()
{
	return q[q.getSize() - 1];
}

template<class T>
T & Queue<T>::front()
{
	return q[0];
}
