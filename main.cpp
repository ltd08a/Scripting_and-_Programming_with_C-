// Include specified libraries and class definitions
#include "roster.h"
#include <iostream>
// Use the standard namespace
using namespace std;

int main() {

	// Number of students in the data array
	int numStudents = 5;
	// Array containing student data as strings
	const string studentData[5] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Logan,Donlan,ldonlan@wgu.edu,31, 16, 25, 49,SOFTWARE" };

	// Dynamically allocate a new Roster object with the specified number of students
	Roster* rosterClass = new Roster(numStudents);

	// Display program header information
	cout << "C867 - Scripting and Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 2470457" << endl;
	cout << "Name: Logan Donlan\n" << endl;

	// Parse each student's data and add them to the roster
	for (int i = 0; i < numStudents; ++i) {
		rosterClass->parseThenAdd(studentData[i]);
	}

	// Print information for all students in the roster
	rosterClass->printAll();

	// Print all invalid email addresses found in the roster
	rosterClass->printInvalidEmails();

	// Print the average number of days in courses for each student
	for (int i = 0; i < numStudents; ++i) {
		rosterClass->printAverageDaysInCourse(rosterClass->getStudent(i)->getStudentID());
	}
	cout << endl;

	// Print information for students in the SOFTWARE degree program
	rosterClass->printByDegreeProgram(DegreeProgram::SOFTWARE);

	// Remove a student by ID and attempt to remove them again to demonstrate the removal functionality
	rosterClass->remove("A3");
	rosterClass->printAll();
	rosterClass->remove("A3");

	// Pause the console output to view the results
	system("pause");

	return 0; // End of program
}