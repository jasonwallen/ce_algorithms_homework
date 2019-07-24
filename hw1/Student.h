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
	//asks for keyboard inputs of the student's three private attributes
	void readStudentInfo();

	//first invokes the base class function "printPersonInfo()"
	//then prints the student's three private attributes
	void printStudentInfo();

	//returns the student's GPA
	float studentGPA();

};

#endif