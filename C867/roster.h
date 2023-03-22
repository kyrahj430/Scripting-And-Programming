
#ifndef roster_h
#define roster_h
#include "student.h"
#include <sstream>
#include <string>
using namespace std;

class Roster {
public:
	void parse(string row);
	void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree);
	// E. 1: Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
	Student* classRosterArray[5];
	~Roster();

private:
	int lastIndex = -1;
	const static int rosterSize = 5;

};

#endif /* roster_h */