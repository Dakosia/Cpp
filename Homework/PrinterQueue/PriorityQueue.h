#pragma once
#include "vector_.h"
template<class T>
class PriorityQueue
{
private:
	vector_<std::pair<T, int>> mas;
public:
	int size() const { return mas.getSize(); }
	T& back() { return mas[mas.getSize() - 1]; }
	T& front() { return mas[0]; }
	void push(const T& val, int prior)
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
	void pop() { mas.erase(0); }
	bool empty() const { return mas.empty(); }
	void showQueue()
	{
		for (int i = 0; i < mas.getSize(); i++)
			std::cout << mas[i].first << " " << mas[i].second << std::endl;
	}
};