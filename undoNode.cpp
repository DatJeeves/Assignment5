#include "undoNode.h"
#include <cstddef>

using namespace std;

UndoNode::UndoNode() {
	command = "";
	filename = "";
}

UndoNode::UndoNode(string cmd, string setFile) {
	command = cmd;
	filename = setFile;
}
UndoNode::~UndoNode() {
	//have delete for diff types
}