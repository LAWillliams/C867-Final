#include <iostream>
#include "Roster.h"
using namespace std;

int main() {
	//Print out course information.
	cout << "Class: Scripting and Programming - Applications - C867" << endl;
	cout << "Langauge Used: C++" << endl;
	cout << "Student ID: #001474242" << endl;
	cout << "Student Name: Luke Williams" << endl;

	//Instantiate class roster
	const int NumStudents = 5;
	Roster ClassRoster;

	const string StudentData[] = {
		"A1,John,Smith,John1989@g mail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_Lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Luke,Williams,lwi1731@wgu.edu,30,15,11,9,SOFTWARE"
	};

	cout << "Adding students to the roster." << endl;

	//Parses then adds students to roster
	for (int i = 0; i < NumStudents; i++) {
		ClassRoster.Parse(StudentData[i]);
	}
	//Prints the entire class roster
	cout << "Printing class roster" << endl;
	ClassRoster.PrintAll();
	//Prints all emails that are not correct
	cout << "Printing invalid emails" << endl;
	ClassRoster.PrintInvalidEmails();

	//Loops through roster and prints average days
	cout << "Average number of days spent in the classes for each student are; " << endl;
	for (int i = 0; i < NumStudents; i++) {
		ClassRoster.PrintAverageDaysInCourse(ClassRoster.ClassRosterArray[i]->getStudentID());
	}

	cout << "Displaying by degree program;" << endl;
	ClassRoster.PrintByDegreeProgram(Software);

	cout << "Removing student A3" << endl;
	ClassRoster.Remove("A3");

	cout << "Printing class roster" << endl;
	ClassRoster.PrintAll();

	cout << "Removing student A3 again" << endl;
	ClassRoster.Remove("A3");
}