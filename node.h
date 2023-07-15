#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

#include <iostream>

class Node {
private:
	Node* left;
	Node* right;
	int data;

public:
	Node();
	Node(int num);
	~Node();

	Node* insert(Node* parent, int num);
	void printRange(Node* parent, int k1, int k2);
	void inOrder(Node* root);
};

#endif