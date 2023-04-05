#pragma once
#include <string>
#include "Student.h"


class Roster{

	public:
		const int NumStudents = 5; //Max size of table
		Student* ClassRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr }; //Array of pointers back to Students, the * sets the size to 5
		void Add(string StudentID, string FirstName, string LastName, string Email, int Age, int Days1, int Days2, int Days3, DegreeProgram degreeProgram);
		void Remove(string StudentID);
		void PrintAll();
		void PrintAverageDaysInCourse(string StudentID);
		void PrintInvalidEmails();
		void PrintByDegreeProgram(DegreeProgram degreeProgram);
		void Parse(string StudentData);
		~Roster();

};

