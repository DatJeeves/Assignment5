#ifndef TREENODE_H
#define TREENODE_H
#include "student.h"
#include "list.h"

using namespace std;
template<typename T>
class TreeNode {
public:
	//vars for node data and to search on
	int key;
	T* data;

	//Constructors & Destructor 
	TreeNode();
	/*has a key-value pair so can search on id number
	and have it's particular data*/
	//TreeNode(int k, int value);
	TreeNode(int k, T* record);
	void print();
	string serialize();
	~TreeNode();
	//have virtual destructor for student/faculty


	

	/* 
	******SUPER IMPORTANT**********
		FALSE = RED
		TRUE = BLACK
	*/
	bool color;
	TreeNode* left;
	TreeNode* right;
};

#endif