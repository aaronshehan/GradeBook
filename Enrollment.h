class Enrollment
{
	private:
		int enrollID; //enrollment id
		int courseLoc; //location of course
		int studentLoc; //location of student 
		int grdCount; //grade count
		int studentGrades[10];//students grades
		double average; //students average
		char letterGrade; //student letter grade
	public:
		void setID(int id);
		void setCourseID(int id);
		void setStudentID(int id);
		void setGrades(int grade, int count);
		void setGradeCount(int count);
		void printStudentGrades(int count);
		double findStudentAverage(int count);
		int getEnrollID() { return enrollID; }
		int getCourseID() { return courseLoc; }
		int getStudentID() { return studentLoc; }
		int getGrdCount() { return grdCount; }
		int storeGrades(int index);
		char getLetterGrade() { return letterGrade; }

		
};
		