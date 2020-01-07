#include <cstdlib>
#include <iostream>
#include <string>
#include "student.h"
//#include "degree.h"

using namespace std;

// default constructor, all set to default 0s or empty strings
Student::Student() {
    setStudentID("");
    setFirstName("");
    setLastName("");
    setEmail("");
    setAge(0);
    setDaysToCompletion("()");
}

// destructor
Student::~Student() {}

// overloaded constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, string daysToCompletion, Degree degreeType)
{
    setStudentID(studentID);
    setFirstName(firstName);
    setLastName(lastName);
    setEmail(email);
    setAge(age);
    setDegreeType(degreeType);
    setDaysToCompletion(daysToCompletion);
}

// getter & setter function for each variable
string Student::getStudentID() const
{
    return studentID;
}

void Student::setStudentID(string studentID)
{
    this->studentID = studentID;
}

string Student::getFirstName() const
{
    return firstName;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

string Student::getLastName() const
{
    return lastName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

string Student::getEmail() const
{
    return email;
}

void Student::setEmail(string email)
{
    this->email = email;
}

int Student::getAge() const
{
    return age;
}

void Student::setAge(int age)
{
    this->age = age;
}

string Student::getDaysToCompletion() const
{
    return daysToCompletion;
}

void Student::setDaysToCompletion(string daysToCompletion)
{
    this->daysToCompletion = daysToCompletion;
}

Degree Student::getDegreeType() const
{
    return degreeType;
}

void Student::setDegreeType(Degree degreeType)
{
    degreeType = degreeType;
}

// virtual print() for student data
void Student::print()
{
    cout << "\t#" << getStudentID();
    cout << "\tFirst Name: " << getFirstName();
    cout << "\tLast Name: " << getLastName();
    cout << "\tEmail: " << getEmail();
    cout << "\tAge: " << getAge();
    cout << "\tDays Left in Courses: " << getDaysToCompletion();
    cout << "\tDegree: ";
    if (getDegreeProgram() == Degree::SECURITY)
    {
        cout << "Security" << endl;
    }
    else if (getDegreeProgram() == Degree::NETWORKING)
    {
        cout << "Networking" << endl;
    }
    else if (getDegreeProgram() == Degree::SOFTWARE)
    {
        cout << "Software" << endl;
    }
    else
    {
        cout << "Unspecified" << endl;
    }
}

// virtual getDegreeProgram(), leave empty per reqs
Degree Student::getDegreeProgram(){}