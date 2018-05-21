//#include "doubleLinkedList.h"
//
//
//
//template<class T>
//doubleLinkedList<T>::doubleLinkedList()
//{
//	size = 0;
//	head = tail = nullptr;
//}
//
//template<class T>
//doubleLinkedList<T>::doubleLinkedList(const doubleLinkedList<T>& obj)
//{
//	if (obj.size == 0)
//	{
//		size = 0;
//		head = tail = nullptr;
//	}
//	else
//	{
//		element<T> *tmp = obj.head;
//		for (size_t i = 0; i < obj.size; i++)
//		{
//			push_back(tmp->data);
//			tmp = tmp->next;
//		}
//	}
//}
//
//template<class T>
//doubleLinkedList<T>& doubleLinkedList<T>::operator=(const doubleLinkedList<T>& obj)
//{
//	if (this == &obj)
//		return *this;
//	this->clear();
//	element<T> *tmp = obj.head;
//	for (int i = 0; i < obj.size; i++)
//	{
//		push_back(tmp->data);
//		tmp = tmp->next;
//	}
//	return *this;
//}
//
//template<class T>
//int doubleLinkedList<T>::getSize() const
//{
//	return size;
//}
//
//template<class T>
//void doubleLinkedList<T>::push_back(const T & l)
//{
//	element<T> *newElem = new element<T>;
//	newElem->data = l;
//	if (size == 0)
//		head = tail = newElem;
//	else
//	{
//		tail->next = newElem;
//		newElem->prev = tail;
//		tail = newElem;
//	}
//	++size;
//}
//
//template<class T>
//void doubleLinkedList<T>::push_front(const T & l)
//{
//	element<T> *newElem = new element<T>;
//	newElem->data = l;
//	if (size == 0)
//		head = tail = newElem;
//	else
//	{
//		head->prev = newElem;
//		newElem->next = head;
//		head = newElem;
//	}
//	++size;
//}
//
//template<class T>
//void doubleLinkedList<T>::pop_back()
//{
//	if (size == 0)
//		return;
//	if (size == 1)
//	{
//		delete head;
//		head = tail = nullptr;
//		size = 0;
//		return;
//	}
//	tail = tail->prev;
//	delete tail->next;
//	tail->next = nullptr;
//	--size;
//}
//
//template<class T>
//void doubleLinkedList<T>::pop_front()
//{
//	if (size == 0)
//		return;
//	if (size == 1)
//	{
//		delete head;
//		head = tail = nullptr;
//		size = 0;
//		return;
//	}
//	head = head->next;
//	delete head->prev;
//	head->prev = nullptr;
//	--size;
//}
//
//template<class T>
//void doubleLinkedList<T>::insert(int pos, const T & obj)
//{
//	if (pos > size)
//		return;
//	if (size == 0)
//	{
//		push_front(obj);
//		return;
//	}
//	if (pos == size)
//	{
//		push_back(obj);
//		return;
//	}
//	int dis = size / 2;
//	element<T> *tmp;
//	if (dis > pos)
//	{
//		tmp = head;
//		for (int i = 0; i < pos - 1; i++)
//		{
//			tmp = tmp->next;
//		}
//	}
//	else
//	{
//		tmp = tail;
//		for (int i = 0; i < size - pos; i++)
//		{
//			tmp = tmp->prev;
//		}
//	}
//	element<T> *newElem = new element<T>;
//	newElem->data = obj;
//	newElem->prev = tmp;
//	newElem->next = tmp->next;
//	tmp->next = newElem;
//	newElem->next->prev = newElem;
//	++size;
//}
//
//template<class T>
//void doubleLinkedList<T>::erase(int pos)
//{
//	if (pos < 0)
//		return;
//	if (pos >= size)
//		return;
//	if (pos == 0)
//	{
//		pop_front();
//		return;
//	}
//	if (pos == size - 1)
//	{
//		pop_back();
//		return;
//	}
//	int dis = size / 2;
//	element<T> *tmp;
//	if (dis < pos)
//	{
//		tmp = tail;
//		for (int i = 0; i < size - pos - 1; i++)
//		{
//			tmp = tmp->prev;
//		}
//	}
//	else
//	{
//		tmp = head;
//		for (int i = 0; i < pos; i++)
//		{
//			tmp = tmp->next;
//		}
//	}
//	tmp->prev->next = tmp->next;
//	tmp->next->prev = tmp->prev;
//	delete tmp;
//	--size;
//}
//
//template<class T>
//void doubleLinkedList<T>::reverse()
//{
//	if (size > 1)
//	{
//		element<T> *tmp = head;
//		for (int i = 0; i < size; i++)
//		{
//			swap(tmp->prev, tmp->next);
//			tmp = tmp->prev;
//		}
//		tmp = head;
//		head = tail;
//		tail = tmp;
//	}
//}
//
//template<class T>
//void doubleLinkedList<T>::clear()
//{
//	if (size > 0)
//	{
//		element<T> *tmp = head;
//		while (tmp != nullptr)
//		{
//			element<T> *toDelete = tmp;
//			tmp = tmp->next;
//			delete toDelete;
//		}
//		head = tail = nullptr;
//		size = 0;
//	}
//}
//
//template<class T>
//bool doubleLinkedList<T>::empty() const
//{
//	return size == 0;
//}
//
//template<class T>
//T & doubleLinkedList<T>::front()
//{
//	return head->data;
//}
//
//template<class T>
//const T & doubleLinkedList<T>::front() const
//{
//	return head->data;
//}
//
//template<class T>
//T & doubleLinkedList<T>::back()
//{
//	return tail->data;
//}
//
//template<class T>
//const T & doubleLinkedList<T>::back() const
//{
//	return tail->data;
//}
//
//template<class T>
//doubleLinkedList<T>::~doubleLinkedList()
//{
//	this->clear();
//}