// Ensure compiler includes file once
#pragma once
// Include specified libraries
#include <iostream>
#include <string>

//Define an enumeration for different degree programs
enum DegreeProgram {SECURITY, NETWORK, SOFTWARE};
// Define a static constant array of strings corresponding to the DegreeProgram enum values
static const std::string DegreeProgramStr[] = { "SECURITY", "NETWORK", "SOFTWARE" };