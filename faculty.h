#ifndef FACULTY_H
#define FACULTY_H
#include <string>
#include "person.h"

using namespace std;

// Inherits a base class Person
class Faculty : public Person {
public:
	Faculty();
	Faculty(int FacultyID,std::string name, std::string level, std::string dept /* , list of students*/);
	~Faculty();
	/*Parameters added with different types to overload isEqual.
	They are not used in the functions, just to distinguish each
	one.*/
	bool isEqual(int FacultyID);	

	//Faculty vars
	string dept;

	// list of students ;
	
	
};

#endif
