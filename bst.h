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
	void insert(TreeNode<T>* node);
	bool search(int k);
	bool deleteNode(int key);
	void deleteTree(TreeNode<T>* curr);
	TreeNode<T>* returnNode(int key);

	//red-black functions
	void reColor(TreeNode<T>* node, bool color);

	//functions to check the tree metrics
	TreeNode<T>* getMin();
	TreeNode<T>* getMax();
	bool isEmpty();

	//extra help functions
	TreeNode<T>* getSuccessor(TreeNode<T>* next);
	void printTree(TreeNode<T>* node);
private:
	TreeNode<T>* root;

};

#endif