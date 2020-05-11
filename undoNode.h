#ifndef UNDONODE_H
#define UNDONODE_H

using namespace std;


class UndoNode {
public:
	//Constructors & Destructor
	UndoNode();
	~UndoNode();
	
	// The following are used to store what needs to be done to undo action
	// The action is:
	//    - a = add
	//    - d = delete
	//    - c = change
	// isStudent tells you if the record applies to student or faculty
	// record is the record to utilize for the data input
	char action;
	bool isStudent;
	string record;
};

#endif