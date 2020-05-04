#include "bst.h"
#include <iostream>

using namespace std;

BST::BST(){
	//enpty tree
	root = NULL;
};

BST::~BST() {
	//we do this to leverage reccursion
	TreeNode* curr;
	deleteTree(curr);
}

void BST::deleteTree(TreeNode* curr) {
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

void BST::printTree(TreeNode* node) {
	if (node == NULL) {
		return;
	}
	printTree(node->left);
	cout << node->key << endl;
	printTree(node->right);
}

TreeNode* BST::getMax() {
	//go all the way to the right
	if (root == NULL) {
		return NULL;
	}
	TreeNode* curr = root;
	while (curr->right != NULL) {
		curr = curr->right;
	}
	return curr; // can return curr-> key
}

TreeNode* BST::getMin() {
	//go all the way to the left
	if (root == NULL) {
		return NULL;
	}
	TreeNode* curr = root;
	while (curr->left != NULL) {
		curr = curr->left;
	}
	return curr; // can return curr-> key
}

bool BST::isEmpty() {
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
void BST::insert(int key, int value) {
	TreeNode* node = new TreeNode(key, value);
	if (search(key)) {
		cout << "Value already exists." << endl;
		return;
	}
	//can't have duplicate keys so check for it
	if (isEmpty()) {
		//empty tree
		root = node;
	}
	else {
		//not an empty tree
		TreeNode* curr = root; //start at the root
		TreeNode* parent;

		while (true) {
			parent = curr;
			if (value < curr->value) {
				//go left
				curr = curr->left;
				if (curr == NULL) {
					parent->left = node;
					break;
				}
			}
			else {
				//go right
				curr = curr->right;
				if (curr == NULL) {
					parent->right = node;
					break;
				}
			}

		}
	}
}

//***HAVE TO OVERLOAD FOR DIFF TYPES
bool BST::search(int value) {
	if (isEmpty())
		return false;
	else {
		//not an empty tree
		TreeNode* current = root;
		//***HAVE TO IMPLEMENT = FOR DIFF TYPES
		while (current->value != value) {
			if (value < current->value)
				current = current->left;
			else
				current = current->right;
			//didn't find the value
			if (current == NULL) { 
				cout << "Did not find the value: " << 
					value << "." << endl;
				return false;
			}
		}
	}
	return true;
}

bool BST::deleteNode(int k) {
	if (isEmpty())
		return false;
	TreeNode* parent = root;
	TreeNode* current = root;
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

		TreeNode* successor = getSuccessor(current);
		if (current == root) {
			root = successor;
		}
			
		else if (isLeft) {
			parent->left = successor;
		}
			
		else{ 
			parent->right = successor;
		}
			

		//commect/link successor to current's (d) left child
		successor->left = current->left;

		return true;

	}
}

TreeNode* BST::getSuccessor(TreeNode* d) {
	//the parameter d represents the node to be deleted
	TreeNode* current = d->right;
	TreeNode* sp = d;
	TreeNode* successor = d;

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