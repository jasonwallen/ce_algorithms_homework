#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{

	//private attributes
	std::string name;
	std::string address;
	int age;

public:

	//constructor
	Person();

	//destructor
	~Person();

	//asks for keyboard inputs of the person's three private attributes
	void readPersonInfo();

	//displays the person's three private attributes
	void printPersonInfo();

	//returns the person's age
	int personAGE();

	//returns the person's name
	std::string personName();

};

#endif