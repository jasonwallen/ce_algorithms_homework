#include "Course.h"

//constructor
Course::Course(std::string ID, std::string title, int credits)
{
	this->ID = ID;
	this->title = title;
	this->credits = credits;
}

//destructor
Course::~Course(){}

//displays the course's three private attributes
void Course::printCourseInfo()
{
	std::cout << "Course title: " << title << '\n';
	std::cout << "Course ID: " << ID << '\n';
	std::cout << "Course Credits: " << credits << '\n';
}