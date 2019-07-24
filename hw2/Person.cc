#include "Person.h"

//constructor
Person::Person(){}

//destructor
Person::~Person(){}

//asks for keyboard inputs of the person's three private attributes
void Person::readPersonInfo(std::ifstream* pf)
{

	std::string tempStr;
	try{
		getline(*pf, name);
		if(name == "\n" || name == "\r" || name == "")
		{
			getline(*pf, name);
		}
		getline(*pf, address);
		getline(*pf, tempStr); age = std::stoi(tempStr);
	}
	catch(std::ifstream::failure e){
		std::cerr << "Error: File does not have enough data\n";
		exit(1);
	}
	catch(std::invalid_argument e){
		std::cerr << "Error: File contains invalid data\n";
		exit(1);
	}

}

//displays the person's three private attributes in a table
void Person::printPersonInfo()
{
	printElement(name, nameWidth);
	printElement(address, nameWidth);
	printElement(age, numWidth);
}

//returns the person's age
int Person::personAGE()
{
	return age;
}

//returns the person's name
std::string Person::personName()
{
	return name;
}
