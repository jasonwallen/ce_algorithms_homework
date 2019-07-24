#include "Student.h"

//constructor
Student::Student(){}

//destructor
Student::~Student(){}

//first calls the base class function "readPersonInfo()" then
//asks for keyboard inputs of the student's three private attributes
void Student::readStudentInfo(std::ifstream* sf)
{
	//reads Person attributes from the file
	this->readPersonInfo(sf);

	//temperary string for the GPA
	std::string tempStr;
	try{
		getline(*sf, ID); //read ID
		getline(*sf, major); //read major
		getline(*sf, tempStr); gpa = std::stof(tempStr); //read GPA as string and convert to float
	}
	//error flag for when the file doesn't have enough data
	catch(std::ifstream::failure e){
		std::cerr << "Error: File does not have enough data\n";
		exit(1);
	}
	//error flag for when the file contains invalid data
	catch(std::invalid_argument e){
		std::cerr << "Error: File contains invalid data\n";
		exit(1);
	}
}

//first invokes the base class function "printPersonInfo()"
//then prints the student's three private attributes
void Student::printStudentInfo()
{
	this->printPersonInfo();

	printElement(ID, numWidth);
	printElement(major, nameWidth);
	printElement(gpa, numWidth);
	std::cout << '\n';
}

//just calls "printStudentInfo()". Added as a generic print fucntion
//to be called from the "anyList.h" template
void Student::printInfo()
{
	this->printStudentInfo();
}

//returns the student's GPA
float Student::studentGPA()
{
	return gpa;
}
