/*
 * Aaron Shehan
 * aaronshehan@my.unt.edu
 * ats0109
 * CSCE 1040
 * Description: This program acts as a gradebook. This program allows the user to add student, add courses, add students to courses, compute averages, print data,
 * save to file, and load from file.
 */


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Courses.h"
#include "Students.h"
#include "Enrollments.h"

Courses courses; 	//declares object of type Courses
Students students;	//declares object of type Students
Enrollments enrollments;	//declares object of type Enrollments

int main()
{

	std::cout << "                      Aaron Shehan	aaronshehan@my.unt.edu" << std::endl;
	std::cout << "              Computer Science and Engineering	CSCE 1040.002" << std::endl;
	int choice = -1; //stores user choice to decide what to do with program, initialied to -1 to enter while loop
	std::string st_name; //stores user input for student name, used in function calls to find student id
	std::string c_name;  //stores user input for course name, used in function calls to find course id
	int st_ID;	//stores student id when function is called to find student
	int c_ID;	//stores course id when function is called to find course
	int enr_ID;	//stores enrollment id when funciton is called to find enrollment
	
	while (choice != 0)
	{
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "0 - quit" << std::endl << "1 - Add Course" << std::endl << "2 - Add Student" << std::endl;
		std::cout << "3 - Add Enrollment" << std::endl << "4 - Add Grades" << std::endl << "5 - Print Grades for a Student in a Course" << std::endl;
		std::cout << "6 - Print Students in a Course" << std::endl << "7 - Student Average in a Course" << std::endl << "8 - Print All Courses" << std::endl;
		std::cout << "9 - Print All Students" << std::endl << "10 - Average for a Course" << std::endl << "11 - Store" << std::endl << "12 - Load" << std::endl;
		std::cout << "Enter Your Selection: "; std::cin >> choice; std::cin.ignore();
		
		switch (choice)
		{
			case 1:
			{
				courses.addCourse(); //adds course
				break;
			}
			case 2:
			{
				students.addStudent(); //adds student
				break;
			}
			case 3:
			{
				std::cout << "Enter name of the student you would like to enroll: "; getline(std::cin, st_name);
				st_ID = students.findStudent(st_name); //function returns student id
				if (st_ID != -1)
				{
					std::cout << "Enter the name of the course you would like to add student to: "; std::cin >> c_name; std::cin.ignore();
					c_ID = courses.findCourse(c_name); //function returns course id
					
					if (c_ID != -1)
					{
						enrollments.addEnroll(st_ID,c_ID); //adds enrollment
					}
					else
					{
						std::cout << "This course does not exist." << std::endl;
					}
				}
				else
				{
					std::cout << "This student does not exist." << std::endl;
				}
						
			
				break;
			}
			case 4:
			{

				std::cout << "Enter name of the course you would like to add grades: "; std::cin >> c_name; std::cin.ignore(); 

				c_ID = courses.findCourse(c_name); //returns course id
		
				if (c_ID == -1)
				{
					std::cout << "This course does not exist." << std::endl;
				}
				else
				{
					std::cout << "Enter the name of the student you would like to enter grades for: ";  getline(std::cin, st_name); //std::cin.ignore();
					st_ID = students.findStudent(st_name); //returns student id
					if (st_ID == -1)
					{
						std::cout << "This student does not exist." << std::endl;
					}
				}

				if (c_ID != -1 && st_ID != -1)
				{
					enr_ID = enrollments.findEnroll(c_ID, st_ID); //returns enrollment id
					if (enr_ID != -1)
					{
						enrollments.addGrades(enr_ID); //adds a grade to enrollment
					}
					else
					{
						std::cout << "Enrollment could not be found." << std::endl;
					}
				}
				break;
			}
			case 5:
			{
				std::cout << "Enter name of the course you would like to print grades for: "; std::cin >> c_name; std::cin.ignore();

				c_ID = courses.findCourse(c_name); //returns course id
		
				if (c_ID == -1)
				{
					std::cout << "This course does not exist." << std::endl;
				}
				else
				{
					std::cout << "Enter the name of the student you would like to print grades for: ";  getline(std::cin, st_name); //std::cin.ignore();
					st_ID = students.findStudent(st_name); //returns student id
					if (st_ID == -1)
					{
						std::cout << "This student does not exist." << std::endl;
					}
				}

				if (c_ID != -1 && st_ID != -1)
				{
					enr_ID = enrollments.findEnroll(c_ID, st_ID); //returns enrollment id
					if (enr_ID != -1)
					{
						enrollments.printGrades(enr_ID); //prints grades in course
					}
					else
					{
						std::cout << "Enrollment could not be found." << std::endl;
					}
				}
	
				break;
			}
			case 6:
			{
				std::cout << "Enter name of the course you would like to print students for: "; std::cin >> c_name; std::cin.ignore();

				c_ID = courses.findCourse(c_name); //returns course id
		
				if (c_ID == -1)
				{
					std::cout << "This course does not exist." << std::endl;
				}
				else
				{
					enrollments.printStudentsEnroll(c_ID); //prints students in a course
				}

				break;
			}
			case 7:
			{
				std::cout << "Enter name of the student you would like to compute average for: "; getline(std::cin, st_name); //std::cin.ignore();

				st_ID = students.findStudent(st_name); //returns student id
		
				if (st_ID == -1)
				{
					std::cout << "This student does not exist." << std::endl;
				}
				else
				{
					std::cout << "Enter the name of the course the student is in that you would like to compute average for: "; std::cin >> c_name; std::cin.ignore();
					c_ID = courses.findCourse(c_name); //returns course id
					if (c_ID == -1)
					{
						std::cout << "This course does not exist." << std::endl;
					}
				}

				if (c_ID != -1 && st_ID != -1)
				{
					enr_ID = enrollments.findEnroll(c_ID, st_ID); //returns enrollment id
					if (enr_ID != -1)
					{
						std::cout << "Student Average: " << std::setprecision(2) << std::fixed << enrollments.computeStudentAvg(enr_ID) << std::endl; //outputs student average in a course
					}
					else
					{
						std::cout << "Enrollment could not be found." << std::endl;
					}
				}

				break;
			}
			case 8:
			{
				courses.printCourses(); //prints courses
				break;
			}
			case 9:
			{
				students.printStudents(); //prints students
				break;
			}
			case 10:
			{
				std::cout << "Enter the name of the course you would like to compute average for: "; std::cin >> c_name; std::cin.ignore();
				c_ID = courses.findCourse(c_name); //returns course id

				if (c_ID == -1)
				{
					std::cout << "This course does not exist." << std::endl;
				}
				else
				{
					std::cout << "The average for this course is: " << std::setprecision(2) << std::fixed << enrollments.computeCourseAvg(c_ID) << std::endl; //prints course average
				}


				break;
			}
			case 11:
			{
				students.storeStudents();		//stores students in a file
				courses.storeCourses();			//stores courses in a file	
				enrollments.storeEnrollments();		//stores enrollments in a file
				break;
			}
			case 12:
			{
				students.loadStudents();		//loads students from a file
				courses.loadCourses();			//loads courses from a file
				enrollments.loadEnrollments();		//loads enrollments from a file
				break;
			}
			default:
			{
				std::cout << "Pleas try again." << std::endl;
				break;
			}
		}
	}

	return 0;
}