#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include "list.h"

using namespace std;
class Input {
public:
    Input();
    ~Input();
    void printStudentLevel();
    void printFacultyLevel();
    void printMajors();

    //Variables
    List<string> FacultyLevels;
    List<string> StudentLevels;
    List<string> Majors;

private:
    void setFacultyLevel(string fname);
    void setStudentLevel(string fname);
    void printList(List<string> myList);
    void setMajors(string fname);

    string flFilename = "facultyLevels.txt";
    string slFilename = "studentLevels.txt";;
};

#endif
