#pragma once
template<class T>
class Stack
{
private:
	int size;
	T *stackPtr;
	int top;
public:
	Stack(int size = 5);
	Stack(const Stack<T> &obj);
	Stack<T> & operator=(const Stack<T> & obj);

	int getSize() const { return this->size; }
	T& getTop() { return stackPtr[top]; }
	void push(const T & val);
	void pop();
	bool empty() const;
	
	~Stack();
};