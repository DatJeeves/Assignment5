#ifndef SIM_H
#define SIM_H
#include <iostream>
#include "treeNode.h"
#include "student.h"
#include "faculty.h"
#include "Input.h"
#include "bst.h"
#include "undoNode.cpp"
#include "genstack.cpp"

#include "list.h"

using namespace std;

class Sim {
public:
	Sim();
	~Sim();

	void Start();
	void SetUpSim();

private:
	int DisplayMenu();
	int GetId(string type);
	double GetDouble(string prompt);
	string GetString(string prompt);
	void DisplayStudents();
	void DisplayFaculty();
	void FindStudent();
	void FindStudent(int id);
	void FindFaculty();
	void ShowFacultyForStudent();
	void ShowFacultyAdvisees();
	void ChangeAdvisor(List<string>* mylist);
	void ChangeAdvisor(List<string>* mylist,int sid, int newfid);
	void RemoveAdvisee(List<string>* mylist);
	void AddStudent(List<string>* mylist);
	void AddStudent(List<string>* mylist, int sid, string naem, int newfid, double gpa, string level, string major);
	void DelStudentById(List<string>* mylist);
	void DelStudentById(List<string>* mylist, int sid);
	void DelAdvisorById(List<string>* mylist);
	void AddToAdvisor(List<string>* mylist, int studentId, int advisorID);
	void DelAdvisee(List<string>* mylist,int sid, int fid);
	void AddFaculty(List<string>* mylist);
	void AddFaculty(List<string>* mylist, int fid, string name, string level, string dept);
	void AddtoUndo(List<string>* mylist, string action, int isStudent, string record);
	void OutputTables();
	void Undo();
	List<string>* GetNewUndoList();
	void Commit(List<string>* undoRecords);


	// New methods
	GenStack<string>* GetNewUndoStack();

	void ChangeAdvisor(GenStack<string>* mylist);
	void ChangeAdvisor(GenStack<string>* mylist, int sid, int newfid);
	void RemoveAdvisee(GenStack<string>* mylist);
	void AddStudent(GenStack<string>* mylist);
	void AddStudent(GenStack<string>* mylist, int sid, string naem, int newfid, double gpa, string level, string major);
	void DelStudentById(GenStack<string>* mylist);
	void DelStudentById(GenStack<string>* mylist, int sid);
	void DelAdvisorById(GenStack<string>* mylist);
	void AddToAdvisor(GenStack<string>* mylist, int studentId, int advisorID);
	void DelAdvisee(GenStack<string>* mylist, int sid, int fid);
	void AddFaculty(GenStack<string>* mylist);
	void AddFaculty(GenStack<string>* mylist, int fid, string name, string level, string dept);
	void AddtoUndo(GenStack<string>* mylist, string action, int isStudent, string record);
	void Undo2();
	void Commit(GenStack<string>* undoRecords);

	BST<TreeNode<Student>> masterStudent;
	BST<TreeNode<Faculty>> masterFaculty;

	GenStack<List<string>*> undoStack;
	List<GenStack<string>*> undoList2;
	GenStack<string>* myUndoStack;
	int MAXUNDO = 5;
	Input config;
};
#endif
