#include "Person.h"

//constructor
Person::Person(){}

//destructor
Person::~Person(){}

//asks for keyboard inputs of the person's three private attributes
void Person::readPersonInfo()
{

	//insert name 
	std::cout << "Name: ";
	std::cin.get(); getline(std::cin, name);

	//insert address
	std::cout << "Address: ";
	std::cin.get(); getline(std::cin, address);

	//insert age
	std::cout << "Age: ";
	std::cin >> age;
}

//displays the person's three private attributes
void Person::printPersonInfo()
{

	std::cout << name << " lives at " << address << " and is " << 
		age << " years old.\n";
}

//returns the person's age
int Person::personAGE()
{
	return age;
}

std::string Person::personName()
{
	return name;
}