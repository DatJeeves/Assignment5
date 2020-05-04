#include "treeNode.cpp"
#include "student.cpp"
/* #include "bst.cpp" */

using namespace std;

int main(int argc, char** argv) {
	Student* s = new Student();
//	BST* testTree = new BST();
	TreeNode<Student> testNode(s->studentID,s);
	cout << testNode.key << " is your key" << endl;
//	delete testTree;
	//TreeNode test = new 
	return 0;
}
