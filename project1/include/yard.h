#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>

#include "student.h"
#include "school.h"

class Student;
class School;

class Yard{
    private:
        // viriables
        School* school;
        Student** students;
        int maxStudents;
        int size;

        // a helpfull function which swaps a random student with the last
        // student returns the random student
        Student* takeRandomStudentYard(Student** student,int size);
    public:
        // Costruct Yard
        Yard(const int maxPeople,School*);
        
        // Decostruct Yard
        ~Yard();
        
        // put the student in Yard
        bool put(Student*);
        
        // remove a student in yard
        Student* remove();
        
        // print Yard
        void print()const;
        
        // see if there is room
        bool hasRoom() const;
};
