#include "bst.h"
#include <iostream>
#include <sstream>

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
void BST<T>::printPrettyTree(T* p, string tab)
{
	if (p != NULL) {
		if (p->right) {			
			printPrettyTree(p->right, tab+"    ");
		}
		
		cout << tab << ' ';
		
		if (p->right) cout << " /\n" << tab << ' ';
		std::cout << p->key << "\n ";
		if (p->left) {
			cout << tab << ' ' << " \\\n";
			
			printPrettyTree(p->left, tab+"    ");
		}
	}
}

template<typename T>
void BST<T>::printTree() {
	if (isEmpty()) {
		return;
	}

	printPrettyTree(root, "  ");
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
void BST<T>::insert(T* node) {
	cout << " In insert with the node key is " << node->key << endl;
	if (search(node->key)) {
		cout << "Value already exists." << endl;
		return;
	}
	cout << "Did not find the key in search" << endl;

	//can't have duplicate keys so check for it
	if (isEmpty()) {
		cout << "Its empty tree " << endl;
		//empty tree
		root = node;
		node->left = NULL;
		node->right = NULL;
		cout << "Set the root to this node key value is " << node->key << endl << endl;
	}
	else {		
		//not an empty tree
		T* curr = root; //start at the root
		T* parent;

		cout << endl << "Finding where to insert starting at the root with key " << root->key << endl;
		while (true) {
			parent = curr;
			if (node->key < curr->key) {
				//go left	
				cout << "Going left as current key is " << curr->key << " and I am " << node->key << endl;
				curr = curr->left;
				if (curr == NULL) {
					cout << "Added to the left " << node->key << endl << endl;
					parent->left = node;
					node->left = NULL;
					node->right = NULL;
					break;
				}
				
			}
			else {
				//go right
				cout << "Going right as current key is " << curr->key << " and I am " << node->key << endl;
				curr = curr->right;
				if (curr == NULL) {
					cout << "Added to the right " << node->key<< endl;
					parent->right = node;
					node->left = NULL;
					node->right = NULL;
					break;
				}
			}

		}
	}
}

template<typename T>
bool BST<T>::search(int k) {

	cout << endl << "IN SEARCH " << endl;
	if (isEmpty()) {
		cout << "empty tree so return false on search" << endl;
		return false;
	}
	else {
		//not an empty tree
		T* current = root;		
		while (current->key != k) {
			if (k < current->key) {
				cout << " My current key is " << current->key << " input key is " << k << endl;
				current = current->left;
				cout << "going left  " << endl;
			}
			else {
				cout << " My current key is " << current->key << " input key is " << k << endl;
				current = current->right;
				cout << "going right " << endl;
			}
			//didn't find the value
			if (current == NULL) {
				cout << "Did not find the ID: " <<
					k << "." << endl;
				return false;
			}
			cout << "next value will be " << current->key << endl;
		}
		cout << "I am out of the while loop " << current->key << " was looking for " << k << endl;
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
			return NULL;
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