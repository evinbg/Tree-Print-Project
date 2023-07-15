#include <iostream>
#include "node.h"

Node::Node() {
	this->data = 0;
	this->left = NULL;
	this->right = NULL;
}

Node::Node(int num) {
	this->data = num;
	this->left = NULL;
	this->right = NULL;
}

Node::~Node() {
}

Node* Node::insert(Node* parent, int num) {
	if (parent == NULL) { // reaches end of recursion where it should be entered
		Node* node = new Node(num); // creates a new node for the data
		return node;
	}
	if (num < parent->data) {
		parent->left = insert(parent->left, num); // recursively going left
	}
	else if (num > parent->data) {
		parent->right = insert(parent->right, num); // recursively going right
	}
	return parent; // keeps pointers from messing up when recursive stack is being emptied
}

 /*
 This function is like a the basic inOrder traversal function, but only 
 related nodes are accessed becuase of the added if statements
 */
void Node::printRange(Node* parent, int k1, int k2) {
	if (parent == NULL) { // if it hits a null pointer
		return;
	}

	if (k1 < parent->data) {
		printRange(parent->left, k1, k2); // keeps going left until first number less than lower limit or NULL is found within left subtrees
	}
	
	if (k1 <= parent->data && k2 >= parent->data) { // if the node is within the range
		std::cout << parent->data << std::endl;
	}

	if (k2 > parent->data) {
		printRange(parent->right, k1, k2); // keeps going right until first number larger than upper limit or NULL is found within right subtrees
	}
}

void Node::inOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->left);
	std::cout << root->data << std::endl;
	inOrder(root->right);
}