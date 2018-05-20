#include "PriorityQueue.h"



template<class T>
int PriorityQueue<T>::size() const
{
	return mas.getSize();
}

template<class T>
T & PriorityQueue<T>::back()
{
	return mas[mas.getSize() - 1];
}

template<class T>
T & PriorityQueue<T>::front()
{
	return mas[0];
}

template<class T>
void PriorityQueue<T>::push(const T& val, int prior)
{
	int pos = 0;
	for (size_t i = 0; i < mas.getSize(); i++)
	{
		if (prior > mas[i].second)
			break;
		pos++;
	}
	mas.insert(pos, std::make_pair(val, prior));
}

template<class T>
void PriorityQueue<T>::pop()
{
	mas.erase(0);
}

template<class T>
bool PriorityQueue<T>::empty() const
{
	return mas.empty();
}