#include <string>
#include "degree.h"

using namespace std;

class Student {
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int studentAge;
		int daysCourseArray[3];
		DegreeProgram studentDegree;
		
		string strStudentDegree;

	public:
		//constructor
		Student();
		Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysCourseArray[], DegreeProgram studentDegree);

		//Print Function
		void print();

		//Email Checker
		bool hasValidEmail();

		//Average Days in Course
		int averageDaysInCourse();


		//Accessor/Getters
		string GetStudentID();
		string GetFirstName();
		string GetLastName();
		string GetEmailAddress();
		int GetStudentAge();
		int* GetDaysCourseArray();
		DegreeProgram GetStudentDegree();

		//Mutator/Setters
		void SetStudentID(string studentID);
		void SetFirstName(string firstName);
		void SetLastName(string lastName);
		void SetEmailAddress(string emailAddress);
		void SetStudentAge(int studentAge);
		void SetDaysCourseArray(int daysCourseArray[]);
		void SetStudentDegree(DegreeProgram studentDegree);


};