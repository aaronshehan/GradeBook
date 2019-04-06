#include "Student.h"

class Students
{
	private:
		int studentCount;
		int studentCap;
		Student* studentList;
	public:
		Students(); //constructor
		~Students(); //destructor
		void addStudent();
		void printStudents();
		int findStudent(std::string nm);
		void storeStudents();
		void loadStudents();
};