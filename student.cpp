#include <iostream>
#include <string>

#include "student.h"

using namespace std;

//Constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->studentAge = 0;
	for (int i = 0; i < 3; i++) {
		this->daysCourseArray[i] = 0;
	}
	this->studentDegree = DegreeProgram::SECURITY;
}


Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysCourseArray[], DegreeProgram studentDegree) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	for (int i = 0; i < 3; i++) {
		this->daysCourseArray[i] = daysCourseArray[i];
	}
	this->studentDegree = studentDegree;

	return;
}


//Prints specficic student data
void Student::print() {
	cout << this->GetStudentID() << '\t';
	cout << this->GetFirstName() << '\t';
	cout << this->GetLastName() << '\t';
	cout << this->GetStudentAge() << '\t';
	cout << this->GetDaysCourseArray()[0] << ", ";
	cout << this->GetDaysCourseArray()[1] << ", ";
	cout << this->GetDaysCourseArray()[2] << '\t';
	
	if (this->GetStudentDegree() == DegreeProgram::SECURITY) {
		strStudentDegree = "SECURITY";
	}
	else if (this->GetStudentDegree() == DegreeProgram::NETWORK) {
		strStudentDegree = "NETWORK";
	}
	else if (this->GetStudentDegree() == DegreeProgram::SOFTWARE) {
		strStudentDegree = "SOFTWARE";
	}
	cout << strStudentDegree << endl;

	return;
};


//Email Checker

bool Student::hasValidEmail() {
	if (Student::GetEmailAddress().find('@') == string::npos || Student::GetEmailAddress().find(' ') != string::npos || Student::GetEmailAddress().find('.') == string::npos) {
		return false;
	}
	else return true;
}

//Course days average

int Student::averageDaysInCourse() {
	int avg = 0;
	avg = (Student::GetDaysCourseArray()[0] + Student::GetDaysCourseArray()[1] + Student::GetDaysCourseArray()[2]) / 3;

	return avg;
}





//Accessor/Getters
string Student::GetStudentID() {
	return this->studentID;
}

string Student::GetFirstName() {
	return this->firstName;
}

string Student::GetLastName() {
	return this->lastName;
}

string Student::GetEmailAddress() {
	return this->emailAddress;
}

int Student::GetStudentAge() {
	return this->studentAge;
}

int* Student::GetDaysCourseArray() {
	return this->daysCourseArray;
}

DegreeProgram Student::GetStudentDegree() {
	return this->studentDegree;
}


//Mutator/Setters
void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}

void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::SetStudentAge(int studentAge) {
	this->studentAge = studentAge;
}

void Student::SetDaysCourseArray(int daysCourseArray[]) {
	for (int i = 0; i < 3; i++) {
		this->daysCourseArray[i] = daysCourseArray[i];
	}
}

void Student::SetStudentDegree(DegreeProgram studentDegree) {
	this->studentDegree = studentDegree;
}