#include <string>

class Course
{
	private:
		std::string courseName;
		int courseID;
		std::string courseTime;
		int roomNumber;
	public:
		void setCourseID (int id);
		void setCourseName(std::string name);
		void setCourseTime (std::string time);
		void setRoomNumber (int roomNum);
		int getID() { return courseID; }
		std::string getName() { return courseName; }
		std::string getTime() { return courseTime; }
		int getRoomNumber() { return roomNumber; }	
};