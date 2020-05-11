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

	BST<TreeNode<Student>> studentTree;
	BST<TreeNode<Faculty>> facultyTree;

	GenStack<List<string>*> undoStack;
	int MAXUNDO = 5;
	Input config;
};
#endif
