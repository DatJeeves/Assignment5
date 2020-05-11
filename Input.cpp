#include "Input.h"
#include <fstream>
#include <exception>

using namespace std;

Input::Input() {
	setFacultyLevel("facultyLevels.txt");
	setStudentLevel("studentLevels.txt");
	setMajors("majors.txt");
}

Input::~Input() {

}


void Input::setFacultyLevel(string fname) {
	// This will read in the different levels for a faculty from a file
	// each level is on a new line
	fstream stream(fname);
	string line;

	/*Checks whether the file exists and is good to read as well as if it is blank.
	Next it reads in the first line of the file.*/
	if (stream.good()) {
		while (!stream.eof()) {
			stream >> line;
			//getline(stream, line);
			FacultyLevels.AddToHead(line);
		}
	}
	else {
		throw invalid_argument ("Invalid file name");
	}
}

void Input::setStudentLevel(string fname) {
	// This will read in the different levels for a faculty from a file
	// each level is on a new line
	fstream stream(fname);
	string line;

	/*Checks whether the file exists and is good to read as well as if it is blank.
	Next it reads in the first line of the file.*/
	if (stream.good()) {
		while (!stream.eof()) {
			stream >> line;
			//getline(stream, line);
			StudentLevels.AddToHead(line);
		}
	}
	else {
		throw invalid_argument("Invalid file name");
	}
}

void Input::printStudentLevel() {
	// This will print out the student levels
	printList(StudentLevels);
}

void Input::printFacultyLevel() {
	// This will print out the student levels
	printList(FacultyLevels);
}

void Input::printMajors() {
	// This will print out the majors
	printList(Majors);
}

void Input::printList(List<string> myList) {
	// This will print out the student levels
	int listSize = myList.GetListSize();
	string temp;

	for (int i = 0; i < listSize; ++i) {
		temp = myList.popHead();
		cout << "     Option " << i << ": " << temp << endl;
		myList.AddToTail(temp);
	}
	cout << endl;
}

void Input::setMajors(string fname) {
	// This will read in the different levels for a faculty from a file
	// each level is on a new line
	fstream stream(fname);
	string line;

	/*Checks whether the file exists and is good to read as well as if it is blank.
	Next it reads in the first line of the file.*/
	if (stream.good()) {
		while (!stream.eof()) {
			stream >> line;
			//getline(stream, line);
			Majors.AddToHead(line);
		}
	}
	else {
		throw invalid_argument("Invalid file name");
	}
}

