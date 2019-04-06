all: exe
	g++ gradebook.cpp Students.cpp Student.cpp Courses.cpp Course.cpp Enrollment.cpp Enrollments.cpp

exe: gradebook.o Students.o Student.o Courses.o Course.o Enrollment.o Enrollments.o
	g++ gradebook.o Students.o Student.o Courses.o Course.o Enrollment.o Enrollments.o -o exe

gradebook.o: gradebook.cpp
	g++ -c gradebook.cpp

Students.o: Students.cpp Students.h Student.h
	g++ -c Students.cpp

Student.o: Student.cpp Student.h
	g++ -c Student.cpp

Course.o: Course.cpp Course.h
	g++ -c Course.cpp

Courses.o: Courses.cpp Courses.h Course.h
	g++ -c Courses.cpp

Enrollment.o: Enrollment.cpp Enrollment.h
	g++ -c Enrollment.cpp

Enrollments.o: Enrollments.cpp Enrollments.h Enrollment.h
	g++ -c Enrollments.cpp

clean:
	rm -rf *o hello
