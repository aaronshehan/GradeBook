#include <iostream>
#include <string>
#include <fstream>
#include "Courses.h"

#define SIZE 2

//create array of objects, type Course, named courseList
Courses::Courses() 
{
	courseCount = 0;
	courseCap = SIZE;
	courseList = new Course[SIZE];
}

Courses::~Courses() //deletes courseList array when program is finished
{
	delete [] courseList;
}


//Adds course to courseList array
void Courses::addCourse()
{
	int id; 	//course id
	int roomNum;	//store user input for room number
	std::string temp;	//stores user input for course name
	std::string time;	//stores user input for course time

	if (courseCount == courseCap) //creates to array with updated size
	{
		Course* temp;
		temp = new Course[courseCap + SIZE];
	
		for (int i = 0; i < courseCount; i++)
		{
			temp[i] = courseList[i];
		}

		delete [] courseList;
		courseCap += SIZE;
		courseList = temp;
	}

	/*std::cout << "Enter course ID: "; std::cin >> id; std::cout << std::endl; */
	std::cout << "Enter course NAME (one word, no spaces): "; std::cin >> temp; std::cin.ignore(); std::cout << std::endl;
	std::cout << "Enter course MEATING TIME (ex. 12:30, no spaces): "; std::cin >> time; std::cin.ignore(); std::cout << std::endl;
	std::cout << "Enter course LOCATION (Room Number, ex. 101): "; std::cin >> roomNum; std::cin.ignore(); std::cout << std::endl;
	
	courseList[courseCount].setCourseID(courseCount + 10000);	//sets course id
	courseList[courseCount].setCourseName(temp);			//sets course name
	courseList[courseCount].setCourseTime(time);			//sets course time
	courseList[courseCount].setRoomNumber(roomNum);			//sets course location
	courseCount += 1;
}

void Courses::printCourses() //prints courses
{
	for (int i = 0; i < courseCount; i++)
	{
		std::cout << "Course ID: " << courseList[i].getID() << "    NAME: " << courseList[i].getName();
		std::cout << "    TIME: " << courseList[i].getTime() << "    ROOM: #" << courseList[i].getRoomNumber() << std::endl;
	}
}

int Courses::findCourse(std::string nm) //finds course using course name and returns course id
{
	int index = 0;
	for (index = 0; courseList[index].getName() != nm; index++);
	if (index == courseCount) { return -1; }
	else { return courseList[index].getID(); }
}

void Courses::storeCourses() //file ouput
{
	std::ofstream fout;
	fout.open("courses.dat");

	fout << courseCount << std::endl;
	for (int i = 0; i < courseCount; i++)
	{
		fout << courseList[i].getID() << " " << courseList[i].getName() << " " << courseList[i].getTime();
		fout << " " <<  courseList[i].getRoomNumber() << std::endl;
	}
	fout.close();
}

void Courses::loadCourses() //file input
{
	std::ifstream fin;
	int id;
	std::string name;
	std::string time;
	int location;
	
	fin.open("courses.dat");
	fin >> courseCount; fin.ignore();
	courseList = new Course[courseCount + 2];

	for (int i = 0; i < courseCount; i++)
	{
		fin >> id >> name >> time >> location;
		courseList[i].setCourseID(id);
		courseList[i].setCourseName(name);
		courseList[i].setCourseTime(time);
		courseList[i].setRoomNumber(location);
	}
	fin.close();
}
