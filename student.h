// Ensure compiler includes file once
#pragma once
// Include specified libraries and class definitions
#include "degree.h"
#include <iostream>
#include <string>
// Use the standard namespace
using namespace std;

// Define class
class Student {
public: 
	// Static constant for size of the array holding days to complete courses
	const static int tableSize = 3;
private:
	// Private member variables to hold student information
	string studentID;				// Unique identifier
	string firstName;				// Student's first name
	string lastName;				// Student's last name
	string emailAddress;			// Student's email address
	int age;						// Student's age
	int* arrDaysToComplete;			// Pointer to array holding number of days to complete each course
	DegreeProgram degPro;			// Enumeration of the degree program

public:
	// Default constructor, initializes a new Student object with default values
	Student();
	// Full constructor, initialized a new Student object with specified values for each member variable
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int arrDaysToComplete[], DegreeProgram degPro); //full constructor
	
	// Accessor declarations, provide read access to private member variables
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysToComplete();			// Returns a pointer to array of days to complete courses
	DegreeProgram getDegreeProgram();

	// Mutator declarations, allow modification of private member variables
	void setID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysToComplete(int arrDaysToComplete[]);	
	void setDegreeProgram(DegreeProgram degPro);		
	void print();										

	// Destructor declaration
	~Student();
};
