#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

#include "degree.h"

class Student {
    public:    
        // constructors
        Student();
        Student(string studentID, string firstName, string lastName, string email,
        int age, string daysToCompletion, Degree degreeType);

        // destructor
        ~Student();

        // getter exposed methods
        string getStudentID() const;
        string getFirstName() const;
        string getLastName() const;
        string getEmail() const;
        int getAge() const;
        string getDaysToCompletion() const;
        Degree getDegreeType() const;

        // setter exposed methods
        void setStudentID(string studentID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmail(string email);
        void setAge(int age);
        void setDaysToCompletion(string daysToCompletion);
        void setDegreeType(Degree degreeType);

        // other exposed methods
        virtual void print();
        virtual Degree getDegreeProgram() = 0;

    protected:
        string studentID;
        string firstName;
        string lastName;
        string email;
        int age;
        string daysToCompletion;
        Degree degreeType;
};

#endif /* STUDENT_H */

