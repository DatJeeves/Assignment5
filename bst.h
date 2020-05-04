#ifndef BST_H
#define BST_H
#include "treeNode.h"

using namespace std;

class BST {
public:
	//Constructor
	BST();
	//assumes template class has a virtual destructor
	~BST();
	//functions to augment the tree
	void insert(Student* s);
	bool search(int k);
	bool deleteNode(int key);
	void deleteTree(TreeNode* curr);

	//red-black functions
	void reColor(TreeNode* node, bool color);

	//functions to check the tree metrics
	TreeNode* getMin();
	TreeNode* getMax();
	bool isEmpty();

	//extra help functions
	TreeNode* getSuccessor(TreeNode* next);
	void printTree(TreeNode* node);
private:
	TreeNode* root;

};

#endif