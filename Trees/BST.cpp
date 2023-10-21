// Test1.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream> //import header files that includes IO functions such as cin and cout
#include <cstdlib>
#include <limits>

using namespace std; //define the namespace

class Node {
public:
	int key;
	Node* parent;
	Node* left;
	Node* right;

	Node() {
		key = -1;
		parent = NULL;
		left = NULL;
		right = NULL;
	}

	Node(int val) { //overloaded constructor
		key = val;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
};

class BST {
private:
	Node* root;
	int size;

public:
	BST() {
		root = NULL;
		size = 0;
	}

	void insert(int key) {
		//Create the node
		Node* temp = new Node(key);
		Node* current = root;
		Node* previous = NULL;

		//search the position to insert the node
		while (current != NULL) {
			previous = current;
			if (key > current->key) {
				current = current->right;
			}
			else if (key < current->key) {
				current = current->left;
			}
			else if (key == current->key) {
				cout << "Duplicate keys are not allowed" << endl;
				return;
			}
		}

		if (previous == NULL) //tree is empty;
			root = temp;
		else if (key > previous->key) {
			previous->right = temp;
			temp->parent = previous;
		}
		else if (key < previous->key) {
			previous->left = temp;
			temp->parent = previous;
		}
		size++;
	}

	bool search(int key) { //search whether a given key exist in the tree
		if (root == NULL) {
			cout << "Tree is empty" << endl;
		}
		else {
			Node* current = root;
			while (current != NULL) {
				if (current->key == key) {
					cout << "The key exists" << endl;
					return true;
				}
				else if (key < current->key) {
					current = current->left;
				}
				else if (key > current->key) {
					current = current->right;
				}
			}
			cout << "Searched key does not exist" << endl;
		}
		return false;
	}

	void preOrder(Node* node) {
		if (node != NULL) {
			cout << " | " << node->key; //Root node is printed
			preOrder(node->left); //Left node is printed
			preOrder(node->right); //Right node is printed
			return;
		}

	}

	void inOrder(Node* node) {
		if (node != NULL) {
			inOrder(node->left); //Left node is printed
			cout << " | " << node->key; //Root node is printed
			inOrder(node->right); //Right node is printed
			return;
		}
	}

	void postOrder(Node* node) {
		if (node != NULL) {
			postOrder(node->left); //Right node is printed
			postOrder(node->right); //Left node is printed
			cout << " | " << node->key; //Root node is printed
			return;
		}
	}

	void traverse(int method) {
		switch (method) {
			case 0: cout << "Pre order traverse : "; preOrder(root); cout << endl; break; //Printing Pre-Order traversal
			case 1: cout << "In order traverse : "; inOrder(root); cout << endl; break; //Printing In-Order traversal
			case 2: cout << "Post order traverse : "; postOrder(root); cout << endl; break; //Printing Post-Order traversal
		}
	}
	

};


int main() {

	BST tree;

	tree.insert(80);
	tree.insert(70);
	tree.insert(60);
	tree.insert(95);
	tree.insert(67);
	tree.insert(120);
	tree.insert(105);
	tree.insert(50);

	tree.search(99);

	tree.traverse(0);
	tree.traverse(1);
	tree.traverse(2);

	return 0;
}
