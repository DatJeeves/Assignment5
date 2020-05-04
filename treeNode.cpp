#include "treeNode.h"
#include <cstddef>

using namespace std;

//treenode implementation
TreeNode::TreeNode() {
	key = 0;
	value = 10;
	left = NULL;
	right = NULL;
}
TreeNode::TreeNode(int k, int v) {
	key = k;
	value = v;
	left = NULL;
	right = NULL;
}
TreeNode::~TreeNode() {
	//have delete for diff types
}