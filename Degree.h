#pragma once

#include <string>

//Defines different value types for DegreeProgram that are constant. Makes code more readable and efficient. Efficiency! 
enum DegreeProgram {
	Security, Network, Software //Three types of degree programs
};

//Creates an array that can be used for printing text equivalent to enum values.
//const char degreeProgramStrings[][100] = {
//	"Security", "Network", "Software"
//};
