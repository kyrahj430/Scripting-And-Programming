#include "student.h"
#include <iostream>
#include <string>
using namespace std;

// constructors

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degree) {
	SetStudentID(studentID);
	SetFirstName(firstName);
	SetLastName(lastName);
	SetEmail(email);
	SetAge(age);
	SetDays(daysInCourse);
	SetDegree(degree);
	daysInCourse = new int[daysInCourseSize];
	for (int i = 0; i < daysInCourseSize; i++) {
		daysInCourse[i] = 0;
	}
}

Student::~Student() {};

// mutators

void Student::SetStudentID(string newStudentID) {
	studentID = newStudentID;
	return;
}

void Student::SetFirstName(string newFirstName) {
	firstName = newFirstName;
	return;
}

void Student::SetLastName(string newLastName) {
	lastName = newLastName;
	return;
}

void Student::SetEmail(string newEmail) {
	email = newEmail;
	return;
}

void Student::SetAge(int newAge) {
	age = newAge;
	return;
}

void Student::SetDays(int daysInCourse[]) {
	this->daysInCourse = new int[daysInCourseSize];
	for (int i = 0; i < daysInCourseSize; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	return;
}

void Student::SetDegree(DegreeProgram newDegree) {
	degree = newDegree;
	return;
}

string Student::enumStr(DegreeProgram degree) {
	if (degree == DegreeProgram::SOFTWARE) {
		return "Software";
	}
	else if (degree == DegreeProgram::SECURITY) {
		return "Security";
	}
	else if (degree == DegreeProgram::NETWORK) {
		return "Network";
	}

}

// accessors

string Student::GetStudentID() {
	return studentID;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmail() {
	return email;
}

int Student::GetAge() {
	return age;
}

int* Student::GetDays() {
	return daysInCourse;
}

DegreeProgram Student::GetDegree() {
	return degree;
}

void Student::Print() {
	cout << GetStudentID() << '\t';
	cout << GetFirstName() << '\t';
	cout << GetLastName() << '\t';
	cout << GetEmail() << '\t';
	cout << GetAge() << '\t';
	cout << "{" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}" << '\t';
	cout << enumStr(GetDegree()) << '\t';
	cout << endl;
	return;
}