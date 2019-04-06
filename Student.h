#include <string>

class Student
{
	private:
		int studentID;
		std::string studentName;
		std::string studentClass;
	public:
		void setStudentName(std::string name);
		void setStudentID(int id);
		void setStudentClass(std::string classification);
		int getStID() { return studentID; }
		std::string getStName() { return studentName; }
		std::string getStClass() { return studentClass; }
};
		