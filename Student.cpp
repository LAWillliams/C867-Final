#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;

//Full constructor used to instantiate values 
Student::Student(string StudentID, string FirstName, string LastName, string Email, int Age, int Days[], DegreeProgram degreeProgram) {
	//Set incoming objects to the corresponding parameters
	this->StudentID = StudentID;
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->Email = Email;
	this->Age = Age;
	for (int i = 0; i < Days[i]; i++) this->Days[i] = Days[i]; //For loop enables parameter input to store multiple values in this object's array
	this->degreeProgram = degreeProgram;

}

//Getters
string Student::getStudentID()
{
	return this->StudentID;
}
string Student::getFirstName()
{
	return this->FirstName;
}
string Student::getLastName()
{
	return this->LastName;
}
string Student::getEmail()
{
	return this->Email;
}
int Student::getAge()
{
	return this->Age;
}
int* Student::getDays()
{
	return this->Days;
}
DegreeProgram Student::getdegreeProgram()
{
	return this->degreeProgram;
}

string Student::getdegreeProgram(string str) {
	if (degreeProgram == Security) {
		return "Security";
	}
	else if (degreeProgram == Network) {
		return "Network";
	}
	else if (degreeProgram == Software) {
		return "Software";
	}
	else { 
		return "Invalid";
	}
}

//Setters (set internal field inside objects)

void Student::setStudentID(string StudentID) 
{
	this->StudentID = StudentID; 
}
void Student::setFirstName(string FirstName) 
{
	this->FirstName = FirstName;
}
void Student::setLastName(string LastName)
{
	this->LastName = LastName;
}
void Student::setEmail(string Email)
{
	this->Email = Email;
}
int Student::VerifyEmail() {
	if (Email.find("@") == string::npos) { // checks the string for the @ symbol
		return 1;
	}
	if (Email.find(".") == string::npos) { // checks the string for the . symbol
		return 1;
	}
	if (Email.find(" ") != string::npos) { // checks for whitespace in the email
		return 1;
	}
	return 0;
}
void Student::setAge(int Age)
{
	this->Age = Age;
}
void Student::setDays(int Days[])
{
	for(int i = 0; i < Days[i]; i++) this->Days[i] = Days[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

//Print function to display the information 

void Student::print()
{
	/*cout << left << setw(113) << "StudentID | First Name | Last Name |              Email                  | Age | Days In Course | Degree Program" << endl;
	cout << left << setw(11) << StudentID;
	cout << left << setw(13) << FirstName;
	cout << left << setw(13) << LastName;
	cout << left << setw(37) << Email;
	cout << left << setw(10) << Age;
	cout << left << setw(10) << Days[0] << ", " << Days[1] << ", " << Days[2];
	cout << left << setw(10) << degreeProgram;*/

	int i = 0;
	string woo = "woo";

	cout << StudentID << "\t" <<
		"First Name: " << FirstName << "\t" <<
		"Last Name: " << LastName << "\t" <<
		"Age: " << Age << "\t" <<
		"Days in course: {" << "\t";
	cout << Days[i];
	for (int i = 1; i < 3; i++) {
		cout << ", " << Days[i];
	}
	cout << "}\tDegree Program: " << getdegreeProgram(woo) << "." << endl;

}