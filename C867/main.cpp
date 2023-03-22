
#include <iostream>
#include <string>
using namespace std;
#include "roster.h"

int main() {
	// F. 1: Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 00*******" << endl;
	cout << "Name: Kyrah J" << endl;
	cout << endl;

	// A.: Modify the “studentData Table” to include your personal information as the last item
	const string studentData[5] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
		"A5,Kyrah,Johnson,kj@wgu.edu,22,21,33,36,SOFTWARE" 
	};

	
	const static int rosterSize = 5;
	// F. 2: Create an instance of the Roster class called classRoster.
	Roster classRoster;

	// F. 3: Add each student to classRoster.
	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}

	// F. 4:  Convert the following pseudo code to complete the rest of the  main() function
	cout << "Displaying all students: " << endl;
	classRoster.printAll();

	cout << endl;
	cout << "Displaying all invalid emails:" << endl;
	cout << endl;
	classRoster.printInvalidEmails();

	cout << endl;

	for (int i = 0; i < rosterSize; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}

	cout << endl;

	cout << "Showing students in degree program: SOFTWARE" << endl;
	cout << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;
	
	cout << "Removing A3" << endl;
	cout << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << "Removing A3 again" << endl;
	cout << endl;
	classRoster.remove("A3");
	cout << endl;

	return 0;
}