#include <iostream>
#include <string>
#include <fstream>
#include "Students.h"

#define SIZE 2

Students::Students() //creates array of objects, type Student, named studentList
{
	studentCount = 0;
	studentCap = SIZE;
	studentList = new Student[SIZE];
}

Students::~Students() //deletes studentList when program is finished
{
	delete [] studentList;
}

void Students::addStudent() //adds student to array studentList
{
	int id;			//student id
	std::string temp;	//stores user input for name of student
	std::string classification;	//stores user input for student classification

	if (studentCount == studentCap) //creates new studentList array with updated size
	{
		Student* temp;
		temp = new Student [studentCap + SIZE];
		
		for (int i = 0; i < studentCount; i++)
		{
			temp[i] = studentList[i];
		}
		
		studentCap += 1;
		delete [] studentList;
		studentList = temp;
	}
	
	/*std::cout << "Enter student ID: "; std::cin >> id; std::cin.ignore();*/
	std::cout << "Enter student NAME (first and last name seperated by a space): "; getline(std::cin,temp);
	std::cout << "Enter student CLASSIFICATION: "; std::cin >> classification; std::cin.ignore();

	studentList[studentCount].setStudentName(temp);	//sets student name
	studentList[studentCount].setStudentID(studentCount + 10000000);	//sets student id
	studentList[studentCount].setStudentClass(classification);	//sets student classification
	studentCount += 1;
}

void Students::printStudents() //prints students
{
	for (int i = 0; i < studentCount; i++)
	{
		std::cout << "Student ID: "<< studentList[i].getStID() << "    NAME: " << studentList[i].getStName();
		std::cout << "    CLASSIFICATION: " << studentList[i].getStClass() << std::endl;
	}
}

int Students::findStudent(std::string nm) //finds student using student name, returns student id
{
	int index = 0;
	for (index = 0; studentList[index].getStName() != nm; index++);
	if (index == studentCount) { return -1; }
	else { return studentList[index].getStID(); }
}	

void Students::storeStudents() //file ouput
{
	std::ofstream fout;
	fout.open("students.dat");

	fout << studentCount << std::endl;
	for (int i = 0; i < studentCount; i++)
	{
		fout << studentList[i].getStID() << "\t";
		fout << studentList[i].getStName() << "\t\t" << studentList[i].getStClass() << std::endl;

	}
	fout.close();
}

void Students::loadStudents() //file input
{
	std::ifstream fin;
	int id;
	std::string name;
	std::string classification;
	
	fin.open("students.dat");
	fin >> studentCount; fin.ignore();
	studentList = new Student[studentCount + 2];

	for (int i = 0; i < studentCount; i++)
	{
		fin >> id; fin.ignore();
		std::getline(fin,name,'\t');
		fin >> classification;
		studentList[i].setStudentName(name);
		studentList[i].setStudentID(id);
		studentList[i].setStudentClass(classification);
	}
	fin.close();
}
