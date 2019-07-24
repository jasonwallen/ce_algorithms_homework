#include "Person.h"
#include "Student.h"
#include "Course.h"
#include "CourseSection.h"
#include "AnyList.h"

int main()
{
	int num, cr;
	std::string id, tl;

	//get course id
	std::cout << "Course ID: ";
	std::cin >> id;

	//get course title
	std::cout << "Course Title: ";
	std::cin.get(); getline(std::cin, tl); //allows for spaces in the title

	//get course credits
	std::cout << "Course Credits: ";
	std::cin >> cr;

	//get the section size
	std::cout << "How many students in the course section? ";
	std::cin >> num; std::cout << '\n';

	//create CourseSection object
	CourseSection sec(id, tl, cr, num);

	//fill the roster info
	std::cout << "Input the info of all students in the section:\n";
	sec.fillRosterInfo(); std::cout << '\n';

	//print the section info
	std::cout << "The following is the section info:\n";
	sec.printSectionInfo(); std::cout << '\n';

	//print the top student's GPA
	std::cout << "The student with the highest GPA:\n";
	sec.printTopGPAStudent(); std::cout << '\n';

	/*
	*	EXTRA CREDIT CODE
	*/

	//temporary student object used to fill the lists
	Student temp;

	//initialize all three lists
	anyList<std::string> nameList(num);
	anyList<int> ageList(num);
	anyList<float> gpaList(num);

	//fill all the lists with appropriate attributes
	for(int i = 0; i < num; i++)
	{
		temp = sec.getStudent(i);
		nameList.insert(i, temp.personName());
		ageList.insert(i, temp.personAGE());
		gpaList.insert(i, temp.studentGPA());
	}

	//sort and print all student's names in ascending order
	nameList.sortList();
	nameList.dispList();

	//sort and print all student's ages in ascending order	
	ageList.sortList();
	ageList.dispList();

	//sort and print all student's GPAs in ascending order	
	gpaList.sortList();
	gpaList.dispList();

	return 0;
}