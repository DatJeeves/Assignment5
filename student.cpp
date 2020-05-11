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

void Student:: setStudent (int studentID, int advisorID, double gpa, string name, string level, string major)
{
	setPerson(studentID, name, level);
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

void Student::updateAdvisor(int fid) {
	advisorID = fid;
}

void Student::printDetails() {
	cout << endl;
	cout << "Student ID: " << getId() << endl;
	cout << "Student:    " << getName() << endl;
	cout << "GPA:        " << gpa << endl;
	cout << "Level:      " << getLevel() << endl;
	cout << "Major:      " << major << endl;
	cout << "Advisor ID: " << advisorID << endl;
	cout << endl;
}

string Student::getCSV() {
	string csvRec;

	csvRec = (to_string(getId()) + "," +
		getName() + "," +
		to_string(gpa) + "," +
		getLevel() + "," +
		major + "," +
		to_string(advisorID) + ",");

	return csvRec;
}


