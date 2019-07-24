#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iomanip>

class Person
{

	//private attributes
	std::string name;
	std::string address;
	int age;

public:

	const int numWidth = 10;
	const int nameWidth = 20;
	const char separator = ' ';
	
	//constructor
	Person();

	//destructor
	~Person();

	//read the person's three private attributes from the text file
	//pointed to by pf
	void readPersonInfo(std::ifstream* pf);

	//displays the person's three private attributes
	void printPersonInfo();

	//returns the person's age
	int personAGE();

	//returns the person's name
	std::string personName();
	
	//template function to format the output
	template<typename T> void printElement(T t, const int& width)
	{
		std::cout << std::left << std::setw(width) << std::setfill(separator) << t;
	}
};

#endif
