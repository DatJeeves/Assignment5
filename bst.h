#ifndef BST_H
#define BST_H
#include "treeNode.h"

using namespace std;
template<typename T>
class BST {
public:
	//Constructor
	BST();
	//assumes template class has a virtual destructor
	~BST();
	//functions to augment the tree
	void insert(T node);
	bool search(int k);
	bool deleteNode(int key);
	void deleteTree(T* curr);
	T* returnNode(int key);

	//red-black functions
	void reColor(T* node, bool color);

	//functions to check the tree metrics
	T* getMin();
	T* getMax();
	bool isEmpty();

	//extra help functions
	T* getSuccessor(T* next);
	void printTree(T* node);
private:
	T* root;

};

#endif