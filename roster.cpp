#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"

int main() {
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Scripting and Programming (WGU C867)\nWritten in C++\nKassondra Jones\n#001245407" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    Roster classRoster;
    Degree degree;

    string data, dataContainer[9];

    // iterate over array to build roster from student data
    for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); i++)
    {
        // single out individual data row
	std::istringstream singleStudentData(studentData[i]);
        // iterate over each piece of data separated by , delimiter
	for (int j = 0; j < 9; ++j) {
		std::getline(singleStudentData, data, ',');
		dataContainer[j] = data;
	}
        // check value of degree type to convert from string to Degree
        if (dataContainer[8] == "SECURITY") {
                    degree = Degree::SECURITY;
        }
        else if (dataContainer[8] == "NETWORKING") {
                    degree = Degree::NETWORKING;
        }
        else if (dataContainer[8] == "SOFTWARE") {
                    degree = Degree::SOFTWARE;
        }
        
        // add current row data into the roster structure
	classRoster.add(dataContainer[0], dataContainer[1], dataContainer[2], dataContainer[3], std::stoi(dataContainer[4]), std::stoi(dataContainer[5]), std::stoi(dataContainer[6]), std::stoi(dataContainer[7]), degree);
    }
    
    // create calls for the functions
    classRoster.printAll();
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << "INVALID EMAIL ADDRESSES:" << endl;
    classRoster.printInvalidEmails();
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << "AVERAGE DAYS IN COURSE (BY STUDENT ID):" << endl;
    for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); i++) {
	classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << "STUDENTS IN SOFTWARE DEGREE PROGRAM:" << endl;
    classRoster.printByDegreeProgram(Degree::SOFTWARE);
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    classRoster.remove("A3");
    classRoster.remove("A3");
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    classRoster.printAll();
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    classRoster.~Roster();

    return 0;
}

void Roster::add(string studentId, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {
        // create a formatted string of days per course ints for easy visibility in printed roster
        string formattedDaysInCourse = to_string(daysInCourse1) + "," + to_string(daysInCourse2) + "," + to_string (daysInCourse3);
        
	Student* student = nullptr;
        
        // construct a new student based on the degree type
        if(degree == Degree::SECURITY) {
            student = new SecurityStudent(studentId, firstName, lastName, email, age, formattedDaysInCourse, degree);
        }
        else if (degree == Degree::NETWORKING){
            student = new NetworkStudent(studentId, firstName, lastName, email, age, formattedDaysInCourse, degree);
        }
        else if (degree == Degree::SOFTWARE) {
            student = new SoftwareStudent(studentId, firstName, lastName, email, age, formattedDaysInCourse, degree);
        }

        // add student to the classRosterArray
	for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = student;
			break;
		}
	}
};

void Roster::remove(string studentId) {
	cout << "REMOVAL OF STUDENT WITH ID #" << studentId << " IN PROGRESS..." << endl;
        // iterate over class roster in search of student ID
	for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); i++) {
		if (classRosterArray[i] == nullptr) {
			cout << "\tERROR: No Student Found" << endl;
			break;
		}
		else if (studentId == classRosterArray[i]->getStudentID()) {
                        // sets pointer to matching studentID to null, making it no longer show up in the roster
			classRosterArray[i] = nullptr;
			cout << "\tSUCCESS: Student Removal Complete" << endl;
		}
	}
};

void Roster::printAll() {
    cout << "CLASS ROSTER:" << endl;
    
    // iterate over class roster and use the virtual print to display student data
    for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); i++) {
	if (classRosterArray[i] != nullptr) {
		classRosterArray[i]->print();
        }
    }
};

void Roster::printAverageDaysInCourse(string studentID) {
        // iterate over class roster
	for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); i++) {
                // find the student in the roster with the matching student ID
		if (studentID == classRosterArray[i]->getStudentID()) {
                    int total = 0;
                    string daysToCompletionString = classRosterArray[i]->getDaysToCompletion();
                    string result;
                    stringstream stream(daysToCompletionString);
                    // split the string of days to completion by the comma delimiter
                    while (getline(stream, result, ',')) {
                        // string to int
                        int resultNum = stoi(result);
                        // aggregated total of days
                        total = total + resultNum;
                    }
                    // logic to find average, used 3.0 since the students all only have 3 classes
                    double average = total / 3.0;
                    cout << "\t#" << studentID << "\t" << average << " days" << endl;
		}
	}
};

void Roster::printInvalidEmails() {
    // iterate over class roster
    for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); i++) {
        string email = classRosterArray[i]->getEmail();
        string studentID = classRosterArray[i]->getStudentID();
        // establish valid email regex
        const regex pattern
            ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        
        // if email matches, continue through iteration
        if (regex_match(email, pattern)) {
            continue;
        }
        // if email doesn't match, print student information
        else {
            cout << "\t#" << studentID << "\t" << email << endl;
        }
    }
};

void Roster::printByDegreeProgram(Degree degree) {
        // iterate over the class roster
	for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); i++) {
            // set your current student
            Student* student = classRosterArray[i];
            Degree tempType;
            // enum returns 0-2 for the degree types, compare values to determine degree type
            if (student->getDegreeProgram() == 0) {
                tempType = Degree::SECURITY;
            }
            else if (student->getDegreeProgram() == 1) {
                tempType = Degree::NETWORKING;
            }
            else if (student->getDegreeProgram() == 2) {
                tempType = Degree::SOFTWARE;
            }
            
            // print the student data only if the input degree and the student degree type match
            if (tempType == degree) {
		student->print();
            }
	}
};

Roster::~Roster() {

};