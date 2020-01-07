#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include <iostream>
#include<string>
#include "student.h"
#include"degree.h"

using namespace std;

class NetworkStudent: public Student {
    public:
        using Student::Student;
        virtual Degree getDegreeProgram();
    private:
        Degree degreeType = Degree::NETWORKING;
};

#endif /* NETWORKSTUDENT_H */