#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

class Course
{

	//private attributes
	std::string ID;
	std::string title;
	int credits;

public:

	//constructor
	Course(std::string ID, std::string title, int credits);

	//destructor
	~Course();

	//displays the course's three private attributes
	void printCourseInfo();

};

#endif