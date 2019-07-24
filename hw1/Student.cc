#include "Student.h"

//constructor
Student::Student(){}

//destructor
Student::~Student(){}

//first calls the base class function "readPersonInfo()" then
//asks for keyboard inputs of the student's three private attributes
void Student::readStudentInfo()
{
	this->readPersonInfo();

	//insert ID
	std::cout << "ID: ";
	std::cin >> ID;

	//insert major
	std::cout << "Major: ";
	std::cin.get(); getline(std::cin, major);

	//insert GPA
	std::cout << "GPA: ";
	std::cin >> gpa;

	std::cout << '\n';
}

//first invokes the base class function "printPersonInfo()"
//then prints the student's three private attributes
void Student::printStudentInfo()
{
	this->printPersonInfo();

	std::cout << "Their ID is " << ID << ", their major is " << 
		major << ", and their GPA is " << gpa << ".\n";
}

//returns the student's GPA
float Student::studentGPA()
{
	return gpa;
}