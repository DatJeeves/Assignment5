#include "treeNode.cpp"
//#include "bst.cpp"
#include "student.cpp"

using namespace std;

int main(int argc, char** argv) {
	Student* s = new Student();
//	BST* testTree = new BST();
	TreeNode<Student> testNode(s->studentID,s);
//	delete testTree;
	//TreeNode test = new 
	return 0;
}
