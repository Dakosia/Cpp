#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node *right = nullptr, *left = nullptr;
};

struct Tree
{
	Node *root = nullptr;
};
void addToTree(Node *root, int x) {
	if (!root) {
		root = new Node();
		root->value = x;
	}
	else {
		addToExistingTree(root, x);
	}
}
void addToExistingTree(Node *root, int x) {
	if (root->value > x) {
		if (!root->left) {
			root->left = new Node();
			root->left->value = x;
		}
		else {
			addToExistingTree(root->left, x);
		}
	}
	else {
		if (!root->right) {
			root->right = new Node();
			root->right->value = x;
		}
		else {
			addToExistingTree(root->right, x);
		}
	}
}
void deleteFromTree(Node *root, int x) {
	if (root) {
		if (root->left) {
			if (root->left->value == x) {
				Node *temp = nullptr;
				if(root->left->left){
					temp = root->left->left;
				}
				if (root->left->right) {
					root->left = root->left->right;
				}
				root->left->left = temp;
			}
		}
		if (root->right) {
			if (root->right->value == x) {
				Node *temp = nullptr;
				if (root->right->left) {
					temp = root->right->left;
				}
				if (root->right->right) {
					root->right = root->right->right;
				}
				root->right->left = temp;
			}
		}
		if (root->value < x) {
			deleteFromTree(root->right, x);
		}
		else {
			deleteFromTree(root->left, x);
		}
	}
}
void displayTreeByDFS(Node *root) {
	if (root) {
		cout << root->value;
	}
	if (root->left) {
		cout << root->left->value;
		displayTreeByDFS(root->left);
	}
	if (root->right) {
		cout << root->right->value;
		displayTreeByDFS(root->right);
	}
}
void displayTreeByBFS(Node *root, int depth) {
	if (root) {
		cout << root->value;
	}
	if (root->left) {
		cout << root->left->value;
	}
	if (root->right) {
		cout << root->right->value;
	}
	if (root->left) {
		if(depth == 0)
		displayTreeByBFS(root->left, depth + 1);
	}
	if (root->right) {
		if (depth == 0)
			displayTreeByBFS(root->left, depth + 1);
	}
	displayTreeByBFS(root->left, 0);
}

int main() {
	Tree tree;
	addToTree(tree.root, 5);
	return 0;
}