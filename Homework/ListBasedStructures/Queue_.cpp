#include "Queue_.h"



template<class T>
int Queue_<T>::size() const
{
	return q.getSize();
}

template<class T>
T & Queue_<T>::back()
{
	return q.back();
}

template<class T>
T & Queue_<T>::front()
{
	return q.front();
}

template<class T>
void Queue_<T>::push(T val)
{
	q.push_back(val);
}

template<class T>
void Queue_<T>::pop()
{
	q.pop_front();
}

template<class T>
bool Queue_<T>::empty() const
{
	return q.empty();
}
