main: Person.o Student.o Course.o CourseSection.o main.o
	g++ -std=c++11 Person.o Student.o Course.o CourseSection.o main.o -o main

Person.o: Person.h Person.cc
	g++ -std=c++11 -c Person.cc

Student.o: Person.h Student.h Student.cc
	g++ -std=c++11 -c Student.cc

Course.o: Course.h Course.cc
	g++ -std=c++11 -c Course.cc

CourseSection.o: Course.h CourseSection.h CourseSection.cc 
	g++ -std=c++11 -c CourseSection.cc 

main.o: main.cc
	g++ -std=c++11 -c main.cc

clean:
	rm -f *.o main
