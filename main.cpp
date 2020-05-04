#include "treeNode.cpp"
#include "student.cpp"
/* #include "bst.cpp" */

using namespace std;

int main(int argc, char** argv) {
	Student* s = new Student(1234, 2345, 3.8, "Jeevan Acharya", "Big man", "Computer");
	Student* tempStudent;
//	BST* testTree = new BST();
	TreeNode<Student> testNode(s->studentID,s);
	cout << testNode.key << " is your key" << endl;
	tempStudent = testNode.data;

	cout << "Student name is "<< tempStudent->name << endl;
//	delete testTree;
	//TreeNode test = new 
	return 0;
}
