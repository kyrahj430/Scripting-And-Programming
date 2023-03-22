#pragma once
#ifndef student_h
#define student_h
#include "degree.h"
#include <string>
using namespace std;

// D. 1 & 2.
class Student {
public:
	// array declaration & constructors
	const static int daysInCourseSize = 3;
	Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degree);
	~Student();
	// mutators
	void SetStudentID(string newStudentID);
	void SetFirstName(string newFirstName);
	void SetLastName(string newLastName);
	void SetEmail(string newEmail);
	void SetAge(int newAge);
	void SetDays(int daysInCourse[]);
	void SetDegree(DegreeProgram newDegree);
	string enumStr(DegreeProgram degree);
	// accessors
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	int GetAge();
	int* GetDays();
	DegreeProgram GetDegree();
	// print
	void Print();

private: 
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int* daysInCourse;
	DegreeProgram degree;

};

#endif /* student_h */
