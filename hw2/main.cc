#include "Person.h"
#include "Student.h"
#include "Course.h"
#include "CourseSection.h"
#include "AnyList.h"

int main()
{
	//initialize variables
	int num, cr;
	std::string id, tl;
	std::ifstream inf;

	//open file and check to see if it opened
	inf.open("/Users/Student/jallen9/Algorithms/hw2/section01.txt");
	if(inf.fail()){
		std::cerr << "Error: Could not open input file\n";
		exit(1);
	}

	//activate the exception handling of inf stream
	inf.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	//get course id
	std::cout << "Course ID: ";
	std::cin >> id; std::cin.get();

	//get course title
	std::cout << "Course Title: ";
	getline(std::cin, tl); //allows for spaces in the title

	//get course credits
	std::cout << "Course Credits: ";
	std::cin >> cr; std::cin.get(); 

	//get the section size
	std::cout << "How many students in the course section? ";
	std::cin >> num; std::cin.get(); std::cout << '\n';

	//create CourseSection object
	CourseSection sec(id, tl, cr, num);

	//reads the information from the file
	sec.fillRosterInfo(&inf);

	//prints information about the course and the students in a table
	std::cout << "The following is the section info (course and student info):\n";
	sec.printSectionInfo();

	inf.close(); //close the file stream


	//Displaying the students sorted by name
	anyList<std::string, Student*> nameList(num);
	for(int i = 0; i < num; i ++)
		nameList.addListKey(sec.getStudent(i)->personName(), sec.getStudent(i));
	nameList.sortList();
	std::cout << "\nThe students sorted by name:\n"; nameList.dispList();

	//Displaying the students sorted by age
	anyList<int, Student*> ageList(num);
	for(int i = 0; i < num; i ++)
		ageList.addListKey(sec.getStudent(i)->personAGE(), sec.getStudent(i));
	ageList.sortList();
	std::cout << "\nThe students sorted by age:\n"; ageList.dispList();

	//Displaying the students sorted by GPA
	anyList<float, Student*> gpaList(num);
	for(int i = 0; i < num; i ++)
		gpaList.addListKey(sec.getStudent(i)->studentGPA(), sec.getStudent(i));
	gpaList.sortList();
	std::cout << "\nThe students sorted by GPA:\n"; gpaList.dispList();

	std::cout << '\n';
	return 0;
}
