#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <iostream>
#include<string>
#include "student.h"
#include"degree.h"

using namespace std;

class SoftwareStudent: public Student {
    public:
        using Student::Student;
        virtual Degree getDegreeProgram();
    private:
        Degree degreeType = Degree::SOFTWARE;
};

#endif /* SOFTWARESTUDENT_H */