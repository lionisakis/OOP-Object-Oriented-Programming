#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "school.h"

class Student;
class School;

class Stair{
    private:
        // viriables 
        Student** students;
        int maxStudents;
        int size;
        School* school;
        
        // a helpfull function which swaps a random student with the last
        // student returns the random student
        Student* takeRandomStudentStair(Student** student,int size);
    public:
        // Costruct Stair
        Stair(const int maxPeople,School*);
        
        // Decostruct Stair
        ~Stair();
        
        // put the student in Stair
        bool put(Student*);
        
        // remove a student in stairs
        Student* remove();
        
        // print stairs
        void print()const;
        
        // see if there is room
        bool hasRoom() const;
};
