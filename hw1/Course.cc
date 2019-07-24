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
	std::cout << title << " is " << credits << " credits and the ID is " <<
		ID << ".\n";
}