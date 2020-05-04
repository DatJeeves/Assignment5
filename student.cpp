#include "student.h"
#include <string>

using namespace std;

Student::Student() {
	//should I make this able to take user input?
	int studentID = 0;
	int advisorID = 0;
	double gpa = 0.0;	
	std::string name = "";
	std::string level = "";
	std::string major = "";
	
}

Student::Student(int studentID, int advisorID, double gpa, string name, string level, string major)
{

	this->studentID = studentID;
	this->name = name;
	this->level = level;
	this->major = major;
	this->gpa = gpa;
	this->advisorID = advisorID;
}

Student::~Student() {

}

bool Student::isEqual(Student* s) {
	if (studentID == s->studentID && name == s->name && level == s->level && major == s->major && gpa == s->gpa && advisorID == s->advisorID)
		return true;
	else
		return false;
}

bool Student::isEqual(int studentID) {
	if (this->studentID == studentID)
		return true;
	else
		return false;
}

bool Student::isEqual(int advisorID, int a) {
	if (this->advisorID == advisorID)
		return true;
	else
		return false;
}

bool Student::isEqual(double gpa) {
	if (this->gpa == gpa)
		return true;
	else
		return false;
}

bool Student::isEqual(std::string name) {
	if (this->name == name)
		return true;
	else
		return false;
}

bool Student::isEqual(std::string level, int a) {
	if (this->level == level)
		return true;
	else
		return false;
}

bool Student::isEqual(std::string major, bool a) {
	if (this->major == major)
		return true;
	else
		return false;
}



