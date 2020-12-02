#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "school.h"

class Student;
class School;


class Corridor{
    private:
        // viriables

        Student** students;
        int maxStudents;
        School* school;
        int size;

        // a function which swaps a random student with the last
        // student returns the random student
        Student* takeRandomStudentCorridor(Student** student,int size);
    
    public:
        
        // Costruct Corridor
        Corridor(const int maxPeople,School* schoolOfCorridor);

        // Decostruct Corridor
        ~Corridor();

        // put a student in Corridor
        bool put(Student*);
        
        // remove a student in Corridor
        Student* remove();
        
        // print 
        void print()const;
        
        // if has room
        bool hasRoom() const;
};
