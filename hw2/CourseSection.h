#ifndef COURSESECTION_H
#define COURSESECTION_H

#include "Course.h"
#include "Student.h"

class CourseSection : public Course
{

	//private attributes
	int sectionSize; //number of students enrolled in the section
	Student *roster; //to store a list of the students' objects enrolled in the section

public:

	//attributes for printing the output
	const int numWidth = 10;
	const int nameWidth = 20;
	const char separator = ' ';

	//constructor
	CourseSection(std::string ID, std::string title, int credits, int sectionSize);

	//destructor
	~CourseSection();

	//read the info of all students in the section and
	//store them in the roster. The students' info is stored
	//in the text file whose stream is pointed to by rf
	void fillRosterInfo(std::ifstream *rf);

	//prints the section info starting with its course info,
	//followed by printing the info of all students in the section
	void printSectionInfo();

	//prints the info of student with the highest GPA
	void printTopGPAStudent();

	//returns a Student object based on index
	Student* getStudent(int index);

	//template to print the output in a table	
	template<typename T> void printElement(T t, const int& width)
	{
		std::cout << std::left << std::setw(width) << std::setfill(separator) << t;
	}
};

#endif