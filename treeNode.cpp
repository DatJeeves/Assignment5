#include "treeNode.h"
#include <iostream>
#include <cstddef>

using namespace std;

//treenode implementation
template<typename T>
TreeNode<T>::TreeNode() {
	key = 0;
	data;
	color = false;
	left = NULL;
	right = NULL;
}

template<typename T>
TreeNode<T>::TreeNode(int k, T* record) {
	key = k;
	data = record;
	color = false;
	left = NULL;
	right = NULL;
}

template<typename T>
TreeNode<T>::~TreeNode() {
	//have delete for diff types
	//in this test we delete student
	delete data;
}