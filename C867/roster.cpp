
#include <iostream>
#include <string>
#include <regex>
#include "roster.h"
using std::regex;
using namespace std;

// E. 2a: Parse each set of data identified in the “studentData Table.” 
void Roster::parse(string row) {
	size_t rhs = row.find(",");
	string studentID = row.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string email = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int age = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string strDegree = row.substr(lhs, rhs - lhs);

	DegreeProgram degree;
	if (strDegree == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	} 
	else if (strDegree == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}
	else if (strDegree == "SOFTWARE") {
		degree = DegreeProgram::SOFTWARE;
	}
	// E. 2b: Add each student object to classRosterArray.
	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
	
	return;

}

// E. 3: Define the following functions:
//
// E. 3a: 
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree) {
	int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

	lastIndex++;


	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degree);

	return;
}

// E. 3b:
void Roster::remove(string studentID) {
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			success = true;
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[rosterSize - 1];
			classRosterArray[rosterSize - 1] = temp;
			Roster::lastIndex--;
		}
		else {
			i++;
		}
	}
	if (success) {
		printAll();
	}
	else {
		cout << "Student with the ID: " << studentID << " was not found." << endl;

	}
	return;
}


// E. 3c:
void Roster::printAll() {

	for (int i = 0; i < 5; i++) {
		classRosterArray[i]->Print();
	}
	return;
}

// E. 3d:
void Roster::printAverageDaysInCourse(string studentID) {

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			cout << "Student ID: " << studentID << ", average days in course is: ";
			cout << (classRosterArray[i]->GetDays()[0] + classRosterArray[i]->GetDays()[1] + classRosterArray[i]->GetDays()[2]) / 3 << endl;

		}
	}
	return;
}

// E. 3e:
void Roster::printInvalidEmails() {

	for (int i = 0; i <= Roster::lastIndex; i++) {

		string emails = classRosterArray[i]->GetEmail();
		if (emails.find(' ') != string::npos || emails.find('@') == string::npos || emails.find('.') == string::npos) {
			cout << emails << " is invalid" << endl;
		}

	}
	return;
}

// E. 3f:
void Roster::printByDegreeProgram(DegreeProgram degree) {

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->GetDegree() == degree) classRosterArray[i]->Print();
	}
	return;
}

// F. 5:
Roster::~Roster() {
	for (int i = 0; i < rosterSize; i++) {
		cout << "Destructor called for " << classRosterArray[i]->GetStudentID() << endl;
		classRosterArray[i] = nullptr;
	}
	return;
}