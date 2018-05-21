#include "PriorityQueue_.h"



template<class T>
int PriorityQueue_<T>::size() const
{
	return pq.getSize();
}

template<class T>
T & PriorityQueue_<T>::back()
{
	return pq.back();
}

template<class T>
T & PriorityQueue_<T>::front()
{
	return pq.front();
}

template<class T>
void PriorityQueue_<T>::push(const T& val, int prior)
{
	int pos = 0;
	for (size_t i = 0; i < pq.getSize(); i++)
	{
		if (prior > pq[i].second)
			break;
		pos++;
	}
	pq.insert(pos, std::make_pair(val, prior));
}

template<class T>
void PriorityQueue_<T>::pop()
{
	pq.pop_front();
}

template<class T>
bool PriorityQueue_<T>::empty() const
{
	return pq.empty();
}