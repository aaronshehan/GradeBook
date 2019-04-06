#include <iostream>
#include <string>
#include <fstream>
#include "Enrollments.h"
#include "Students.h"
#include "Courses.h"

#define SIZE 2

Enrollments::Enrollments() //creates array of type Enrollment, called enrollList, and creates array that stores grade count for students, called gradeCount
{
	enrollCount = 0;
	enrollCap = SIZE;
	enrollList = new Enrollment[SIZE];
	gradeCount = new int[SIZE];
	gradeCount[0] = 0;
}

Enrollments::~Enrollments() //deletes enrollList and gradeCount arrays when program is finished
{
	delete [] enrollList;
	delete [] gradeCount;
}


void Enrollments::addEnroll(int stID, int cID) //adds enrollment
{
	int id; //enrollment id
	int c_count = 1; //course count initialized to 1, counts students in a course
	int st_count = 1; //student count initialized to 1, counts amount of courses a student is enrolled in
	
	if (enrollCount == enrollCap) //creates new enrollList array with updated size, also creates gradeCount array with new size
	{
		Enrollment* temp;
		int* gradeTemp;
		temp = new Enrollment[enrollCount + SIZE];
		gradeTemp = new int[enrollCount + SIZE];
		
		for (int i = 0; i < enrollCount; i++)
		{
			temp[i] = enrollList[i];
			gradeTemp[i] = gradeCount[i];
		}
		
		delete [] enrollList;
		delete [] gradeCount;
		enrollCap += SIZE;
		gradeCount = gradeTemp;
		enrollList = temp;
	}

	for (int i = 0; i < enrollCount; i++) //counts students in a course
	{
		if (cID == enrollList[i].getCourseID())
		{
			c_count += 1;
		}
	} 

	if (c_count <= 48)
	{
		
		for (int i = 0; i < enrollCount; i++) //counts amount of courses student is in
		{
			if (stID == enrollList[i].getStudentID())
			{
				st_count += 1;
			}
		}

		if (st_count <= 5)
		{
			enrollList[enrollCount].setCourseID(cID);
			enrollList[enrollCount].setStudentID(stID);
			enrollList[enrollCount].setID(enrollCount + 1000000);
			enrollCount += 1;
			gradeCount[enrollCount] = 0;
		}
		else 
		{
			std::cout << "This student is already enrolled in 5 courses." << std::endl;
		}

		
	}
	else
	{
		std::cout << "This course is at capacity." << std::endl;
	}	

}

void Enrollments::printEnrolls() //prints enrollments, not used in the actual program. This was used to test if enrollments were stored properly
{
	for (int i = 0; i < enrollCount; i++)
	{
		std::cout << "Enrollment ID: " << enrollList[i].getEnrollID();
		std::cout << "    Student ID: " << enrollList[i].getStudentID();
		std::cout << "    Course ID: " << enrollList[i].getCourseID();
		std::cout << std::endl;
	}
}

int Enrollments::findEnroll(int cID, int stID) //finds enrollment based on student id and course id, returns enrollment id if match found
{
	int index = 0;
	for (index = 0; index < enrollCount; index++)
	{
		if (enrollList[index].getCourseID() == cID && enrollList[index].getStudentID() == stID)
		{
			return enrollList[index].getEnrollID();
		}
	}
	if (index == enrollCount) { return -1; }

}


void Enrollments::addGrades(int e_ID) //adds grade for a student in a course
{
	int grade; //user input for grade
	int index; //index for location of enrollment to store grade in
	std::cout << "Enter grade: "; std::cin >> grade; std::cin.ignore();
	
	for (int i = 0; i < enrollCount; i++) //finds correct enrollment to enter grade
	{
		if (e_ID == enrollList[i].getEnrollID())
		{
			index = i;
			break;
		}
	}
	if (gradeCount[index] < 10)
	{
		gradeCount[index] += 1;
		enrollList[index].setGradeCount(gradeCount[index]);
		enrollList[index].setGrades(grade,gradeCount[index]);
	}
	else	
	{
		std::cout << "This student already has 10 grades." << std::endl;
	}

}

void Enrollments::printGrades(int id) //prints grades
{
	int index;
	
	for (int i = 0; i < enrollCount; i++)
	{
		if (id == enrollList[i].getEnrollID())
		{
			index = i;
			break;
		}
	}

	enrollList[index].printStudentGrades(gradeCount[index]);
}

void Enrollments::printStudentsEnroll(int id) //prints students enrolled in a course
{
	for (int i = 0; i < enrollCount; i++)
	{
		if (enrollList[i].getCourseID() == id)
		{
			std::cout << "Student ID: " << enrollList[i].getStudentID() << std::endl;
		}
	}

}

double Enrollments::computeStudentAvg(int e_ID) //finds student average in course and returns value
{
	int index;
	
	for (int i = 0; i < enrollCount; i++)
	{
		if (e_ID == enrollList[i].getEnrollID())
		{
			index = i;
			break;
		}
	}

	return enrollList[index].findStudentAverage(gradeCount[index]);
}

double Enrollments::computeCourseAvg(int c_ID) //computes average for a course and returns value
{
	double avg = 0.0;
	int count = 0;
	for (int i = 0; i < enrollCount; i++)
	{
		if (c_ID == enrollList[i].getCourseID())
		{
			avg += enrollList[i].findStudentAverage(gradeCount[i]);
			count += 1;
		}
	}
	return avg / count;
}


void Enrollments::storeEnrollments() //file output
{
	std::ofstream fout;
	fout.open("enrollments.dat");
	fout << enrollCount << std::endl;
	for (int i = 0; i < enrollCount; i++)
	{
		fout << enrollList[i].getEnrollID() << " " <<  enrollList[i].getStudentID() << " " <<  enrollList[i].getCourseID() << " ";
		fout << gradeCount[i] << " ";
		for (int j = 0; j < gradeCount[i]; j++)
		{
			fout << enrollList[i].storeGrades(j) << " ";
		}
		fout << std::endl;
	}
	fout.close();
}

void Enrollments::loadEnrollments() //file input
{
	std::ifstream fin;
	int grade;
	int eID;
	int cID;
	int stID;
	int gCount;

	fin.open("enrollments.dat");

	fin >> enrollCount; fin.ignore();
	enrollList = new Enrollment[enrollCount + 2];
	gradeCount = new int[enrollCount];
	
	for (int i = 0; i < enrollCount; i++)
	{
		fin >> eID >> stID >> cID >> gCount;
		enrollList[i].setStudentID(stID);
		enrollList[i].setCourseID(cID);
		enrollList[i].setID(eID);
		gradeCount[i] = gCount;
		enrollList[i].setGradeCount(gradeCount[i]);

		for (int j = 0; j < gCount; j++)
		{
			fin >> grade;
			enrollList[i].setGrades(grade, j + 1);
		}
	}
	fin.close();
}