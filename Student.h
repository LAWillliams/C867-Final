#pragma once
#include <string>
#include "Degree.h"
using std::string;


//Defines what a Student is by creating a class
class Student {



public://Originally made this private, but decided that was not needed. SO now these are public
	//Full constructor to initialize objects defined in this class
	Student(string StudentID, string FirstName, string LastName, string Email, int Age, int Days[], DegreeProgram degreeProgram);

	string StudentID;
	string FirstName;
	string LastName;
	string Email;
	int Age;
	DegreeProgram degreeProgram;//Allows the Student class access to the data type values from DegreeProgram 
	//Defines accessors for instance fields
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDays();
	DegreeProgram getdegreeProgram();
	string getdegreeProgram(string str);

	//setters for instance fields
	void setStudentID(string StudentID);
	void setFirstName(string FirstName);
	void setLastName(string LastName);
	void setEmail(string Email);
	int VerifyEmail();
	int Days[3];
	void setAge(int Age);
	void setDays(int Days[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print();

	//Destructor (deallocates)

};



