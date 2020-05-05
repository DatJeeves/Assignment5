#include "bst.h"
#include <iostream>

using namespace std;

template<typename T>
BST<T>::BST() {
	//enpty tree
	root = NULL;
};

template<typename T>
BST<T>::~BST() {
	//we do this to leverage reccursion
	T* curr;
//	deleteTree(curr);
}

template<typename T>
void BST<T>::deleteTree(T* curr) {
	//referenced: https://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/
	//traversial var
	curr = root;

	if (curr == NULL) {

	}
	else {
		/*We go to the left all the way, then we go to it's right node.
		After we go up a generation and delete each node.*/
		deleteTree(curr->left);
		deleteTree(curr->right);

		//actual deletion of the node.
		delete curr;
	}


}

//will have to change for self balancing
template<typename T>
void BST<T>::printTree(T* node) {
	if (node == NULL) {
		return;
	}
	printTree(node->left);
	cout << node->key << endl;
	printTree(node->right);
}

template<typename T>
T* BST<T>::getMax() {
	//go all the way to the right
	if (root == NULL) {
		return NULL;
	}
	T* curr = root;
	while (curr->right != NULL) {
		curr = curr->right;
	}
	return curr; // can return curr-> key
}

template<typename T>
T* BST<T>::getMin() {
	//go all the way to the left
	if (root == NULL) {
		return NULL;
	}
	T* curr = root;
	while (curr->left != NULL) {
		curr = curr->left;
	}
	return curr; // can return curr-> key
}

template<typename T>
bool BST<T>::isEmpty() {
	if (root == NULL) {
		return true;
	}
	else {
		return false;
	}
}

//***A FAILED SEARCH***
//***HAVE TO OVERLOAD FOR DIFF TYPES
//have to change for self balancing
template<typename T>
void BST<T>::insert(T node) {
	cout << " In insert with the node key is " << node.key << endl;
	if (search(node.key)) {
		cout << "Value already exists." << endl;
		return;
	}


	//can't have duplicate keys so check for it
	if (isEmpty()) {
		cout << "Its empty tree " << endl;
		//empty tree
		root = &node;
		cout << "set the root to this node " << endl;
	}
	else {
		cout << "Its not an empty tree " << endl;
		//not an empty tree
		T* curr = root; //start at the root
		T* parent;

		while (true) {
			parent = curr;
			if (node.key < curr->key) {
				//go left
				curr = curr->left;
				if (curr == NULL) {
					parent->left = &node;
					break;
				}
			}
			else {
				//go right
				curr = curr->right;
				if (curr == NULL) {
					parent->right = &node;
					break;
				}
			}

		}
	}
}

template<typename T>
bool BST<T>::search(int k) {
	if (isEmpty())
		return false;
	else {
		//not an empty tree
		T* current = root;
		cout << "current node key = " << current->key << " looking for " << k << endl;
		while (current->key != k) {
			cout << "current node key = " << current->key << " looking for " << k << endl;
			if (k < current->key)
				current = current->left;
			else
				current = current->right;
			//didn't find the value
			if (current == NULL) {
				cout << "Did not find the ID: " <<
					k << "." << endl;
				return false;
			}
		}
	}
	return true;
}

template<typename T>
bool BST<T>::deleteNode(int k) {
	if (isEmpty())
		return false;
	T* parent = root;
	T* current = root;
	bool isLeft = true;

	while (current->key != k) {
		parent = current;
		if (k < current->key) {
			isLeft = true;
			current = current->left;
		}
		else {
			isLeft = false;
			current = current->right;
		}
		if (current == NULL)
			return false;
	}
	//if we make it here, we found the value, now we delete
		//check leaf node, children and L or R node

		//node is a leaf
	if (current->left == NULL && current->right == NULL) {
		//then have a leaf treenode
		if (current == root) {
			root = NULL;
		}
		else if (isLeft) {
			parent->left = NULL;

		}
		else {
			parent->right == NULL;
		}
	}
	//here is whether on left or right, inside it is ab the children
	else if (current->right == NULL) { //no right child, so must have a left chile
		if (current == root) {
			root = current->left;
		}
		else if (isLeft)
			parent->left = current->left;
		else
			parent->right = current->left;
	}
	else if (current->left == NULL) { //no left child, so must have a right chile
		if (current == root) {
			root = current->right;
		}
		else if (isLeft)
			parent->left = current->right;
		else
			parent->right = current->right;
	}
	else {
		//node to be deleted has two children

		T* successor = getSuccessor(current);
		if (current == root) {
			root = successor;
		}

		else if (isLeft) {
			parent->left = successor;
		}

		else {
			parent->right = successor;
		}


		//commect/link successor to current's (d) left child
		successor->left = current->left;

		return true;

	}
}

//****Assumes you already called search to see if the node exists****
template<typename T>
T* BST<T>::returnNode(int k) {
	T* current = root;
	while (current->key != k) {
		if (k < current->key)
			current = current->left;
		else
			current = current->right;
		//didn't find the value
		if (current == NULL) {
			cout << "Did not find the ID: " <<
				k << "." << endl;
			return false;
		}
	}
	return current;
}

template<typename T>
void BST<T>::reColor(T* node, bool c) {
	//Black -> Red
	if (c == true)
		c = false;

	//Red->Black
	else
		c = true;
}

template<typename T>
T* BST<T>::getSuccessor(T* d) {
	//the parameter d represents the node to be deleted
	T* current = d->right;
	T* sp = d;
	T* successor = d;

	while (current != NULL) {
		sp = successor;
		successor = current;
		current = current->left;
	}

	if (successor != d->right) {
		sp->left = successor->right;
		successor->right = d->right;
	}
	return successor;
}