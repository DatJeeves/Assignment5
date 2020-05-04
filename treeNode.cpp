#include "treeNode.h"
#include <cstddef>

using namespace std;

//treenode implementation
TreeNode::TreeNode() {
	key = 0;
	value;
	color = false;
	left = NULL;
	right = NULL;
}
TreeNode::TreeNode(Student* s) {
	key = s->studentID;
	value = s;
	color = false;
	left = NULL;
	right = NULL;
}
TreeNode::~TreeNode() {
	//have delete for diff types
	//in this test we delete student
	delete value;
}