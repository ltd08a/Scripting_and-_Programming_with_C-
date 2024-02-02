// Include specified libraries and class definitions
#include "roster.h"
#include <iostream>
// Use the standard namespace
using namespace std;

// Default constructor, initializes a Roster object with default size and values
Roster::Roster() {
	this->defSize = 0;	// Set default size to 0
	this->lastIndex = -1;	// Initializes lastIndex to -1, indicating no students added yet
	this->classRosterArray = nullptr;	// Initializes the roster array to null
}

// Full constructor, initializes a Roster object with a specified size
Roster::Roster(int defSize) {
	this->defSize = defSize;	// Set the roster size to the specified value
	this->lastIndex = -1;	// Initializes lastIndex to -1
	this->classRosterArray = new Student * [defSize];	// Dynamically allocate memory for an array of Student pointers with the specified size 
}
// Function to parse student data from a string and add the student to the roster
void Roster::parseThenAdd(string row) {
	int parseArr[Student::tableSize];	//Temporary array to hold days to complete courses
	DegreeProgram degreeprogram{};	// Variable to store the degree program enum value

	// Increase lastIndex for the new student entry
	if (lastIndex < defSize) {
		lastIndex++;
	}

	// Allocate a new Student object for the next index
	this->classRosterArray[lastIndex] = new Student();

	// Parse and set the following attributes
	// studentID
	int long stud = row.find(",");
	classRosterArray[lastIndex]->setID(row.substr(0, stud));
	// firstName
	int long fn = stud + 1;
	stud = row.find(",", fn);
	classRosterArray[lastIndex]->setFirstName(row.substr(fn, stud - fn));
	// lastName
	fn = stud + 1;
	stud = row.find(",", fn);
	classRosterArray[lastIndex]->setLastName(row.substr(fn, stud - fn));
	// emailAddress
	fn = stud + 1;
	stud = row.find(",", fn);
	classRosterArray[lastIndex]->setEmailAddress(row.substr(fn, stud - fn));
	// age
	fn = stud + 1;
	stud = row.find(",", fn);
	int a = stoi(row.substr(fn, stud - fn));
	classRosterArray[lastIndex]->setAge(a);
	// Days to complete course 1
	fn = stud + 1;
	stud = row.find(",", fn);
	parseArr[0] = stoi(row.substr(fn, stud - fn));
	// Days to complete course 2
	fn = stud + 1;
	stud = row.find(",", fn);
	parseArr[1] = stoi(row.substr(fn, stud - fn));
	// Days to complete course 3
	fn = stud + 1;
	stud = row.find(",", fn);
	parseArr[2] = stoi(row.substr(fn, stud - fn));
	// Set the days to complete each of the 3 courses for current Student object
	classRosterArray[lastIndex]->setDaysToComplete(parseArr);
	// Parse and set degree program based on character matching
	// 'S' for Security, 'N' for Network, 'O' for Software
	fn = stud + 1;
	if (row[fn] == 'S') {
		if (row[fn + 1] == 'E') {
			classRosterArray[lastIndex]->setDegreeProgram(SECURITY);
		}
		else if (row[fn + 1] == 'O') {
			classRosterArray[lastIndex]->setDegreeProgram(SOFTWARE);
		}
		else {
			cerr << "INVALID DEGREE PROGRAM. NOW EXITING..." << endl;
			exit(-1);	// Exit the program if degree program is invalid
		}
	}
	else if (row[fn] == 'N') {
		classRosterArray[lastIndex]->setDegreeProgram(NETWORK);
	}
	else {
		cerr << "INVALID DEGREE PROGRAM. NOW EXITING..." << endl;
		exit(-1);	// Exit the program if degree program is invalid
	}
}
// Function to add a new Student object to the class roster with provided details
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysForCourse1, int daysForCourse2, int daysForCourse3, DegreeProgram degreeprogram) {
	int arrDaysToComplete[Student::tableSize];
	arrDaysToComplete[0] = daysForCourse1;
	arrDaysToComplete[1] = daysForCourse2;
	arrDaysToComplete[2] = daysForCourse3;
	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, arrDaysToComplete, degreeprogram);
}

// Returns a pointer to the Student object at the specified index
Student* Roster::getStudent(int index) {
	return classRosterArray[index];
}
// Prints all student data in the roster
void Roster::printAll() {
	cout << "Displaying all students: \n" << endl;
	for (int i = 0; i <= this->lastIndex; ++i) {
		(this->classRosterArray)[i]->print();	
	}
	cout << endl;
}
// Removes a student from the roster by their ID and maintains roster continuity
bool Roster::remove(string ID) {
	bool found = false;		// Flag to indicate if the student was found and removed
	cout << "Removing " << ID << ":" << endl;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getStudentID() == ID) {
			found = true;	
			delete this->classRosterArray[i];	
			this->classRosterArray[i] = this->classRosterArray[lastIndex];	
			lastIndex--;	
			break;	
		}
	}
	if (!found) {
		cout << "\nStudent with ID " << ID << " not found." << endl;
	}
	cout << endl;
	return found;	// Return true if student was found and removed, otherwise false
}
// Print the average number of days in course for a given studentID
void Roster::printAverageDaysInCourse(string sID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getStudentID() == sID) {
			found = true;
			int* dic = classRosterArray[i]->getDaysToComplete();	// Retrieve array of days to complete courses
			// Calculate and print the average of the days in the 3 courses
			cout << "Student ID: " << sID << ", average days in course is: " << ((dic[0] + dic[1] + dic[2]) / 3) << "\n";
			break; 
		}
	}
	if (!found) {
		cout << "Student not found.\n";
	}
}
// Prints all invalid email addresses found within the roster
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:\n" << endl;
	for (int i = 0; i < 5; ++i) {
		string email = classRosterArray[i]->getEmailAddress();
		// Check for invalid email criteria, absence of '@', '.', or presence of spaces
		if ((email.find("@") == string::npos || email.find(".") == string::npos) || (email.find(" ") != string::npos)) {
			cout << email << " - is invalid." << endl;
		}
	}
	cout << endl;
}
// Prints information for all students enrolled in a specific degree program
void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
	cout << "Showing students in degree program: " << DegreeProgramStr[degreeprogram] << "\n" << endl;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeprogram) {
			this->classRosterArray[i]->print();		
		}
	}
	cout << endl;
}

// Destructor definition
Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
		delete this->classRosterArray[i];
	}
	delete this;
}