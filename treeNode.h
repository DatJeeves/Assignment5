#ifndef TREENODE_H
#define TREENODE_H
#include "student.h"

using namespace std;

class TreeNode {
public:
	//Constructors & Destructor
	TreeNode();
	/*has a key-value pair so can search on id number
	and have it's particular data*/
	//TreeNode(int k, int value);
	TreeNode(Student* s);
	~TreeNode();
	//have virtual destructor for student/faculty

	//vars for node data and to search on
	int key;
	Student* value;
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