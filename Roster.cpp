#pragma once
#include "Roster.h"
#include <iostream>
#include <string>

using namespace std;


Roster::~Roster()//Destroys the roster so that the students can be added to the roster array later
{
	int i = 0;
	for (i = 0; i < NumStudents; i++) {
		delete ClassRosterArray[i];
		ClassRosterArray[i] = nullptr;
	}
}

//Function to add students to roster
void Roster::Add(string StudentID, string FirstName, string LastName, string Email, int Age, int Days1, int Days2, int Days3, DegreeProgram degreeProgram) {
	int Days[3] = { Days1, Days2, Days3 }; //Places days array into single int
	bool flag = false;
	int i = 0;

	//Loops through array to add students
	while((i < NumStudents) && (flag == false)) {
		if (ClassRosterArray[i] == nullptr) {
			ClassRosterArray[i] = new Student(StudentID, FirstName, LastName, Email, Age, Days, degreeProgram);
			flag = true;
		}
		
		i++;
	}
	
}

//Function to remove students from roster via student ID and print error if not found
void Roster::Remove(string StudentID) {
	bool o = false;
	int i = 0;
	
	for (i = 0; i < NumStudents; i++) {
		if(ClassRosterArray[i] == nullptr){}
		else if (ClassRosterArray[i]->getStudentID() == StudentID) {
			delete ClassRosterArray[i];
			ClassRosterArray[i] = nullptr;
			o = true;
		}
	}
	if (o == false) {
		cout << "Error: Student ID, " << StudentID << " could not be found." << endl;
	}
}

void Roster::PrintAll() {
	
	for (int i = 0; i < NumStudents; i++) {
		if (ClassRosterArray[i] != nullptr)
		ClassRosterArray[i]->print();
	}
}

void Roster::PrintAverageDaysInCourse(string StudentID) {
	
	int StudentIndex;

	for (int i = 0; i < NumStudents; i++) {
		if (ClassRosterArray[i]->getStudentID() == StudentID) {
			StudentIndex = i;
		}
	}
	int* Days = ClassRosterArray[StudentIndex]->getDays();

	cout << "Student " << ClassRosterArray[StudentIndex]->getStudentID() << " has been in classes an average of " << (Days[0] + Days[1] + Days[2]) / 3 << " days in their last three courses." << endl;
}//prints average amount of days spent in courses

void Roster::PrintInvalidEmails() {
	int i = 0;
	cout << "The invalid emails are;" << endl;
	//Loops through array and prints out any invalid emails. 
	for (i = 0; i < NumStudents; i++){
		if (ClassRosterArray[i]->VerifyEmail() == 1) {
			cout << ClassRosterArray[i]->getEmail() << endl;
		}
	}
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < NumStudents; i++) {
		if (ClassRosterArray[i]->getdegreeProgram() == degreeProgram) {
			ClassRosterArray[i]->print();
		}//cout << "Student " << ClassRosterArray[i]->getStudentID() <<
	}	//Loop goes through the class roster and prints out by degree program
}

void Roster::Parse(string StudentData)
{
	DegreeProgram degreeProgram = Software;
	if (StudentData.back() == 'Y') degreeProgram = Security;// checks last char
	else if (StudentData.back() == 'K') degreeProgram = Network; 
	//Parses through the studentdata
	int rhs = StudentData.find(",");
	string StudentID = StudentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	string FirstName = StudentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	string LastName = StudentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	string Email = StudentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	int Age = stoi(StudentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	int Days1 = stoi(StudentData.substr(lhs, rhs - lhs));


	lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	int Days2 = stoi(StudentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = StudentData.find(",", lhs);
	int Days3 = stoi(StudentData.substr(lhs, rhs - lhs));


	Roster::Add(StudentID, FirstName, LastName, Email, Age, Days1, Days2, Days3, degreeProgram); //Adds a student as an object

}//Parses then adds students to the class roster. To be used in main function.