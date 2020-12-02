#pragma once
#include <iostream>
#include <string>
#include "student.h"

class Student;
struct Pair{
    private:
        // virialbes 
        Student* studentA;
        Student* studentB;
    public:
        // Costruct a new Pair
        Pair(Student*,Student*);

        // Decostructor is not needed
        // as the class Pair has not to
        // delete any node
        
        // Return the first Student
        Student* getStudentA()const;

        // Return the second Student
        Student* getStudentB()const;
        
        // Change the students
        void changeStudents(Student*,Student*);
        
        // check if the Pair is messy or not
        bool isMessy()const;

        // print the Pair
        void print() const;
};
