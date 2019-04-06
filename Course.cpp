#include <iostream>
#include <string>
#include "Course.h"

void Course::setCourseID (int id) //sets course id
{
	courseID = id;
}

void Course::setCourseName(std::string name) //sets course name
{
	courseName = name;
}

void Course::setCourseTime (std::string time) //sets course time
{
	courseTime = time;
}

void Course::setRoomNumber (int roomNum) //sets course location
{
	roomNumber = roomNum;
}
