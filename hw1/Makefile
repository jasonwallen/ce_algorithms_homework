main: Person.o Student.o Course.o CourseSection.o main.o
	g++ Person.o Student.o Course.o CourseSection.o main.o -o main

Person.o: Person.h Person.cc
	g++ -c Person.cc

Student.o: Person.h Student.h Student.cc
	g++ -c Student.cc

Course.o: Course.h Course.cc
	g++ -c Course.cc

CourseSection.o: Course.h CourseSection.h CourseSection.cc 
	g++ -c CourseSection.cc 

main.o: main.cc
	g++ -c main.cc

clean:
	rm -f *.o main