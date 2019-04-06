#include "Enrollment.h"

class Enrollments
{
	private:
		int enrollCount;
		int enrollCap;
		int* gradeCount;
		Enrollment* enrollList;
	public:
		Enrollments(); //constructor
		~Enrollments(); //destructor
		void addEnroll(int stID, int cID);
		void printEnrolls();
		void addGrades(int e_ID);
		void printGrades(int id);
		void printStudentsEnroll(int id);
		int findEnroll(int cID, int stID);
		double computeStudentAvg(int e_ID);
		double computeCourseAvg(int c_ID);
		void storeEnrollments();
		void loadEnrollments();
};
