#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person {
public:
	Person();
	Person(int ID, string name, string level);
	~Person();
	/*Parameters added with different types to overload isEqual.
	They are not used in the functions, just to distinguish each
	one.*/
	bool isEqual(int ID);
	int getId();
	void setId(int Id);
	string getName();
	void setName(string name);
	string getLevel();
	void setLevel(string level);
	
private:	
	//Person vars
	int PersonID;
	string name;
	string level;
};

#endif
