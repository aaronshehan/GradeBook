#include "Enrollment.h"
#include <iostream>
#include <string>

void Enrollment::setID(int id) //sets enrollment id
{
	enrollID = id;
}

void Enrollment::setCourseID(int id) //sets course id 
{
	courseLoc = id;
}

void Enrollment::setStudentID(int id) //sets student id
{
	studentLoc = id;
}

void Enrollment::setGradeCount(int count) //sets grade count
{
	grdCount = count;
}

void Enrollment::setGrades(int grade, int count) //sets grades
{
	studentGrades[count - 1] = grade;
	
}

void Enrollment::printStudentGrades(int count) //prints student grades in a course
{
	std::cout << "Student Grades: " << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << studentGrades[i] << std::endl;
	}
}

double Enrollment::findStudentAverage(int count) //computes student average in a course
{
	average = 0.0;
	for (int i = 0; i < count; i++)
	{
		average += studentGrades[i];
	}
	average = average / count;

	if (average >= 90)
	{
		letterGrade = 'A';
	}
	else if (average >= 80)
	{
		letterGrade = 'B';
	}
	else if (average >= 70)
	{
		letterGrade = 'C';
	}
	else if (average >= 60)
	{
		letterGrade = 'D';
	}
	else
	{
		letterGrade = 'F';
	}

	return (average);
}


int Enrollment::storeGrades(int index) //used to store grades from file input
{
	return (studentGrades[index]);
}