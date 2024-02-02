// Include specified libraries and class definitions
#include "student.h"
#include <string>
#include <iostream>
// Use the standard namespace
using namespace std;

// Default contructor, initializes a Student object with default values
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	// Dynamically allocate memory for the array to strore days to complete courses
	this->arrDaysToComplete = new int[tableSize];
	// Initialize the array elements to 0
	for (int i = 0; i < tableSize; ++i) {
		this->arrDaysToComplete[i] = 0;
	}
	// Default degree program set to SOFTWARE
	this->degPro = SOFTWARE;
}

// Full constructor, initializes a Student object with specified values
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int arrDaysToComplete[], DegreeProgram degPro) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	// Dynamically allocate memory for the array to store days to complete courses
	this->arrDaysToComplete = new int[tableSize];
	// Copy the values from the input array to the member array
	for (int i = 0; i < tableSize; ++i) {
		this->arrDaysToComplete[i] = arrDaysToComplete[i];
	}
	// Set the degree program
	this->degPro = degPro;
}

// Accessor definitions
string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmailAddress() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
// Returns a pointer to array containing days to complete courses
int* Student::getDaysToComplete() {
	return arrDaysToComplete;
}
DegreeProgram Student::getDegreeProgram() {
	return degPro;
}

// Mutator definitions
void Student::setID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
// Sets the days to complete courses by copying from input array to member array
void Student::setDaysToComplete(int arrDaysToComplete[]) {
	for (int i = 0; i < tableSize; ++i) {
		this->arrDaysToComplete[i] = arrDaysToComplete[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degPro) {
	this->degPro = degPro;
}
// Print function, outputs student's data in tab-separated format
void Student::print() {
	cout << getStudentID() << '\t' << getFirstName() << '\t' << getLastName() << '\t' << getAge() << '\t';
	int* arrDaysToComplete = getDaysToComplete();
	cout << '\t' << "{" << arrDaysToComplete[0] << ", " << arrDaysToComplete[1] << ", " << arrDaysToComplete[2] << "}" << '\t' << DegreeProgramStr[getDegreeProgram()] << endl;
}

// Destructor definition
Student::~Student() {
	if (arrDaysToComplete != nullptr) {
		delete[] arrDaysToComplete;
		arrDaysToComplete = nullptr;
	}
}