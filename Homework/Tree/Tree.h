#pragma once
#include <iostream>

template <class T1, class T2>
class Node
{
public:
	T1 key;
	T2 value;
	Node<T1, T2> *parent = nullptr;
	Node<T1, T2> *left = nullptr;
	Node<T1, T2> *right = nullptr;
};

template <class T1, class T2>
class Tree
{
private:
	Node<T1, T2> *root;
	int size;
public:
	Tree()
	{
		root = nullptr;
		size = 0;
	}
	Tree(const Tree<T1, T2> &obj)
	{
		this->root = copyTree(obj.root);
	}
	Tree<T1, T2>& operator=(const Tree<T1, T2> &obj)
	{
		if (this == &obj)
			return *this;
		this->~Tree();
		this->root = copyTree(obj.root);
		return *this;
	}
	Node<T1, T2>* copyTree(Node<T1, T2> *node)
	{
		if (node == nullptr)
			return nullptr;
		Node<T1, T2> *newNode = new Node<T1, T2>;
		newNode->key = node->key;
		newNode->value = node->value;
		newNode->left = copyTree(node->left);
		newNode->right = copyTree(node->right);
		return newNode;
	}

	void add(const T1& key, const T2& value)
	{
		Node<T1, T2> *node = new Node<T1, T2>;
		node->key = key;
		node->value = value;
		Node<T1, T2> *tmp = root;
		Node<T1, T2> *y = nullptr;
		while (tmp != nullptr)
		{
			y = tmp;
			if (tmp->key < node->key)
				tmp = tmp->right;
			else
				tmp = tmp->left;
		}
		if (y == nullptr)
		{
			root = node;
			size = 1;
		}
		else
		{
			node->parent = y;
			if (y->key > node->key)
				y->left = node;
			else
				y->right = node;
			++size;
		}
	}
	void printNode(Node<T1, T2> *node)
	{
		if (node != nullptr)
		{
			printNode(node->left);
			std::cout << node->key << " " << node->value << std::endl;
			printNode(node->right);
		}
	}
	void print()
	{
		printNode(root);
	}
	T2 search(const T1& key)
	{
		Node<T1, T2> *tmp = root;
		while (tmp != nullptr && tmp->key != key)
		{
			if (tmp->key > key)
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		if (tmp == nullptr)
			return T2();
		else return tmp->value;
	}
	
	Node<T1, T2>* findMin(Node<T1, T2>* node) {
		if (node != nullptr)
		{
			if (node->left != nullptr) {
				return findMin(node->left);
			}
		}
		return node;
	}
	void del(const T1& key)
	{
		deleteNode(root, key);
	}
	Node<T1, T2>* deleteNode(Node<T1, T2> *node, const T1& key)
	{
		if (node != nullptr)
		{
			if (key < node->key)
				node->left = deleteNode(node->left, key);
			else if (key > node->key)
				node->right = deleteNode(node->right, key);
			else
			{
				if (node->left == nullptr && node->right == nullptr)
				{
					delete node;
					node = nullptr;
				}
				else if (node->left == nullptr)
				{
					Node<T1, T2> *tmp = node;
					node = node->right;
					delete tmp;
				}
				else if (node->right == nullptr)
				{
					Node<T1, T2> *tmp = node;
					node = node->left;
					delete tmp;
				}
				else
				{
					Node<T1, T2> *tmp = findMin(node->right);
					node->key = tmp->key;
					node->right = deleteNode(node->right, key);
				}
			}
			return node;
		}
		return node;
	}

	void destroyRecursively(Node<T1, T2> *node)
	{
		if (node != nullptr)
		{
			destroyRecursively(node->left);
			destroyRecursively(node->right);
			delete node;
		}
	}
	~Tree()
	{
		destroyRecursively(root);
	}
};