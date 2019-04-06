#include "Course.h"

class Courses
{
	private:
		int courseCount;
		int courseCap;
		Course* courseList;
	public:
		Courses(); //constructor
		~Courses(); //destructor
		void addCourse();
		void printCourses();
		int findCourse(std::string nm);
		void storeCourses();
		void loadCourses();
};