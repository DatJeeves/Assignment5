#include "faculty.h"
#include <string>

using namespace std;

Faculty::Faculty() {
	int advisorID = 0;
	double gpa = 0.0;	
	string major = "";
	this->setPerson(0, "", "");
	
}

Faculty::Faculty(int FacultyID, string name, string level, string dept)
{
	this->setPerson(FacultyID, name, level);
	this->dept = dept;
}

Faculty::~Faculty() {

}


bool Faculty::isEqual(int FacultyID) {
	if (this->getId() == FacultyID)
		return true;
	else
		return false;
}




