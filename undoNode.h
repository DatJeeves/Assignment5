#ifndef TREENODE_H
#define TREENODE_H

using namespace std;

class UndoNode {
public:
	//Constructors & Destructor
	UndoNode();
	UndoNode(string cmd, string setFile);
	~UndoNode();

	string command;
	string filename;
};

#endif