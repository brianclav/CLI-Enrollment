#include <iostream>
#include "roster.h"

using namespace std;

int main() {
	const int NUM_STUDENTS = 5;

	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 001647881" << endl;
	cout << "Name: Brian Clavadetscher" << endl;
	cout << endl;

	const string studentData[] = {
       "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	   "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	   "A5,Brian,Clavadetscher,bclavad@wgu.edu,32,30,44,30,SOFTWARE"
	};
	
	Roster classRoster;
	
	for (int i = 0; i < NUM_STUDENTS; i++) {
		classRoster.parse(studentData[i]);
	}

	cout << "Displaying all students:" << endl;

	classRoster.printAll();

	classRoster.printInvalidEmails();

	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (i < 4) {
			classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
		}
		else {
			classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
			cout << endl;
		}
	}

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");

	cout << "DONE.";

}

