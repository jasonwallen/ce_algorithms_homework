#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person
{

	//private attributes
	std::string ID;
	std::string major;
	float gpa;

public:

	//constructor
	Student();

	//destructor
	~Student();

	//first calls the base class function "readPersonInfo()" then
	//reads the student's three private attributes from
	//the text file pointed to by sf
	void readStudentInfo(std::ifstream* sf);

	//first invokes the base class function "printPersonInfo()"
	//then prints the student's three private attributes
	void printStudentInfo();

	//just calls "printStudentInfo()". Added as a generic print fucntion
	//to be called from the "anyList.h" template
	void printInfo();

	//returns the student's GPA
	float studentGPA();

};

#endif