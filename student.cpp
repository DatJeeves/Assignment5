#include "student.h"
#include <string>

using namespace std;

Student::Student() {
	//should I make this able to take user input?
	int advisorID = 0;
	double gpa = 0.0;	
	string major = "";
	this->setPerson(0, "", "");
	
}

Student:: Student (int studentID, int advisorID, double gpa, string name, string level, string major)
{
	this->setPerson(studentID, name, level);
	this->major = major;
	this->gpa = gpa;
	this->advisorID = advisorID;
}

Student::~Student() {

}

bool Student::isEqual(Student* s) {
	if (this->getId() == s->getId() && this->getName() == s->getName() && this->getLevel() == s->getLevel() && major == s->major && gpa == s->gpa && advisorID == s->advisorID)
		return true;
	else
		return false;
}

bool Student::isEqual(int studentID) {
	if (this->getId() == studentID)
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
	if (this->getName() == name)
		return true;
	else
		return false;
}

bool Student::isEqual(std::string level, int a) {
	if (this->getLevel() == level)
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



