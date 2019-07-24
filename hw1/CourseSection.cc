#include "CourseSection.h"

//constructor
CourseSection::CourseSection(std::string ID, std::string title, int credits,
								int sectionSize) : Course(ID, title, credits)
{
	this->sectionSize = sectionSize;
	roster = new Student[sectionSize];
}

//constructor
CourseSection::~CourseSection()
{
	delete[] roster;
}

//read the info of all students in the section and
//store them in the roster
void CourseSection::fillRosterInfo()
{
	for(int i = 0; i < sectionSize; i++)
	{
		roster[i].readStudentInfo();
	}
}

//prints the section info starting with its course info,
//followed by printing the info of all students in the section
void CourseSection::printSectionInfo()
{
	this->printCourseInfo();
	std::cout << '\n';

	for(int i = 0; i < sectionSize; i++)
		{
			roster[i].printStudentInfo();
			std::cout << '\n';
		}
}

//prints the info of student with the highest GPA
void CourseSection::printTopGPAStudent()
{
	//placeholder for top student
	Student* topStudent = roster;

	//traverses the array and finds the highest GPA
	for(int i = 0; i < sectionSize; i++)
	{
		if(topStudent->studentGPA() < roster[i].studentGPA())
		{
			topStudent = &(roster[i]);
		}
	}

	topStudent->printStudentInfo();	

}

//return a Student object based on index
Student CourseSection::getStudent(int index)
{
	return roster[index];
}