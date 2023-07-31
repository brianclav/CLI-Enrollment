#include <string>
#include "student.h"

using namespace std;

class Roster {
	private:
		string strDegree;
		const static int NUM_STUDENTS = 5;
		int rosterIndex = -1;



	public:
		Student* classRosterArray[NUM_STUDENTS];
		
		void parse(string studentData);
		void add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysCourse1, int daysCourse2, int daysCourse3, DegreeProgram studentDegree);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram studentDegree);

		~Roster();
};
