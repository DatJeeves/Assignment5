#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student {
public:
	Student();
	Student(int studentID, int advisorID, double gpa, std::string name, std::string level, std::string major);
	~Student();
	/*Parameters added with different types to overload isEqual.
	They are not used in the functions, just to distinguish each
	one.*/
	bool isEqual(Student* s);
	bool isEqual(int studentID);
	bool isEqual(int advisorID, int a);
	bool isEqual(double gpa);
	bool isEqual(std::string name);
	bool isEqual(std::string level, int a);
	bool isEqual(std::string major, bool a);
	
	

	//student vars
	int studentID;
	int advisorID;
	double gpa;
	std::string name;
	std::string level;
	std::string major;
	
	
};

#endif
