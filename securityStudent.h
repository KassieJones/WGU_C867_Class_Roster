#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <iostream>
#include<string>
#include "student.h"
#include"degree.h"

using namespace std;

class SecurityStudent: public Student {
    public:
        using Student::Student;
        virtual Degree getDegreeProgram();
    private:
        Degree degreeType = Degree::SECURITY;
};

#endif /* SECURITYSTUDENT_H */