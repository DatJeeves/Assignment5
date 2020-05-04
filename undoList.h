#ifndef UNDO_H
#define UNDO_H
#include "undoNode.cpp"
#include "genstack.cpp"

using namespace std;

class UndoList {
public:
	//Constructor
	UndoList();
	//assumes template class has a virtual destructor
	~UndoList();
	//functions to augment the tree
	void tempdo(string cmd);
	string undo();
	bool isEmpty();

	void showUndo();
private:
	GenStack<UndoNode> stack;
	string command;
	string filename;
	int undoCount;
	int maxUndo;
};

#endif