#include <iostream>
#include <string>

#include "roster.h"

//parse student data
void Roster::parse(string studentData) {

	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int studentAge = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string studentDegreeString = studentData.substr(lhs, rhs - lhs);

	DegreeProgram studentDegree = DegreeProgram::SECURITY;
	if (studentDegreeString == "SECURITY") {
		studentDegree = DegreeProgram::SECURITY;
	}
	if (studentDegreeString == "NETWORK") {
		studentDegree = DegreeProgram::NETWORK;
	}
	if (studentDegreeString == "SOFTWARE") {
		studentDegree = DegreeProgram::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, studentAge, daysCourse1, daysCourse2, daysCourse3, studentDegree);

	return;
}

//add student
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysCourse1, int daysCourse2, int daysCourse3, DegreeProgram studentDegree) {
	int daysCourseArray[] = { daysCourse1, daysCourse2, daysCourse3 };
	classRosterArray[++rosterIndex] = new Student(studentID, firstName, lastName, emailAddress, studentAge, daysCourseArray, studentDegree);
	
	return;
}

//removes student
void Roster::remove(string studentID) {
	cout << "Removing " << studentID << ":" << endl;

	bool removed = false;
	
	for (int i = 0; i <= Roster::rosterIndex; i++) {
		//bool removed = false;
		if (classRosterArray[i]->GetStudentID() == studentID) {
			
			for (int j = i; j <= Roster::rosterIndex; j++) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			Roster::rosterIndex--;
			removed = true;
		}
	}
	if (removed == false) {
		cout << endl;
		cout << "The student with the ID: " << studentID << " was not found." << endl;

	}
	
	cout << endl;

	return;
}

//print all
void Roster::printAll() {
	for (int i = 0; i <= Roster::rosterIndex; i++) {
		classRosterArray[i]->print();
	}
	cout << endl;
	return;
}

//print average days in course
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::rosterIndex; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			cout << "Student ID: " << studentID << ", average days in course is: " << classRosterArray[i]->averageDaysInCourse() << endl;
		}
	}
	
}

//prints bad email addresses
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:" << endl;
	cout << endl;
	for (int i = 0; i <= Roster::rosterIndex; i++) {
		if (classRosterArray[i]->hasValidEmail() == false) {
			cout << classRosterArray[i]->GetEmailAddress() << " - is invalid." << endl;
		}
	}
	cout << endl;
}

//prints by degree program
void Roster::printByDegreeProgram(DegreeProgram studentDegree) {
	if (studentDegree == DegreeProgram::SECURITY) {
		strDegree = "SECURITY";
	}
	else if (studentDegree == DegreeProgram::NETWORK) {
		strDegree = "NETWORK";
	}
	else if (studentDegree == DegreeProgram::SOFTWARE) {
		strDegree = "SOFTWARE";
	}
	cout << "Showing students in degree program: " << strDegree << endl;
	cout << endl;

	for (int i = 0; i <= Roster::rosterIndex; i++) {
		if (classRosterArray[i]->GetStudentDegree() == studentDegree) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;

}

//Destructor
Roster::~Roster() {
	for (int i = 0; i <= rosterIndex; i++) {
		delete classRosterArray[i];
	}
}















































/*
E.Create a Roster class (roster.cpp) by doing the following :

1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”

2.  Create a student object for each student in the data tableand populate classRosterArray.

a.Parse each set of data identified in the “studentData Table.”

b.Add each student object to classRosterArray.

3.  Define the following functions :

a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.

b.  public void remove(string studentID)  that removes students from the roster by student ID.If the student ID does not exist, the function prints an error message indicating that the student was not found.

c. public void printAll() that prints a complete tab - separated list of student data in the provided format : A1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program : Security.The printAll() function should loop through all the students in classRosterArrayand call the print() function for each student.

d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses.The student is identified by the studentID parameter.

e.  public void printInvalidEmails() that verifies student email addressesand displays all invalid email addresses to the user.


Note : A valid email should include an at sign('@') and period('.') and should not include a space(' ').


f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.*/