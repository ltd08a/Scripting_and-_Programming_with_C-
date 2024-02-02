// Ensure compiler includes file once
#pragma once
// Include specified libraries and class definitions
#include "student.h"
#include <iostream>
#include <string>

// Define class
class Roster {
public:
	int lastIndex;				// Index of last student in roster
	int defSize = 5;			// Default size of roster
	Student** classRosterArray;	// Pointer to an array of pointers to Student objects

	// Default contructor, initializes a Roster object with default values
	Roster(); 
	// Full constructor, initializes a Roster object with a specified size
	Roster(int defSize); 

	// Function declarations
	
	// Parses a string row of student data, then adds the student to the roster
	void parseThenAdd(string row);

	// Add a new student to the roster with detailed information
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysForCourse1, int daysForCourse2, int daysForCourse3, DegreeProgram degreeprogram);
	Student* getStudent(int index);

	// Prints all students' data using their print() method
	void printAll();

	// Removes a student from the roster by their student ID, returns true if successful
	bool remove(string studentID);

	// Prints the average number of days in course for the student identified by studentID
	void printAverageDaysInCourse(string studentID);

	// Prints all invalid email addresses found in the roster
	void printInvalidEmails();

	// Prints information for all students in the specified degree program
	void printByDegreeProgram(DegreeProgram degreeprogram);

	// Destructor declaration
	~Roster();
};