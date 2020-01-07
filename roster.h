#pragma once
#include <string>
#include "degree.h"
#include <regex>
using std::string;
using namespace std;

const string studentData[] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORKING",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Kassondra,Jones,kjon723@my.wgu.edu,30,20,30,40,SOFTWARE"
};

class Roster {
public:
	Student* classRosterArray[sizeof(studentData)/sizeof(studentData[0])] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	
	void add(
		string studentId,
		string firstName,
		string lastName,
		string email,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		Degree degree
	);
	void remove(string studentId);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degree);

	~Roster();
};

