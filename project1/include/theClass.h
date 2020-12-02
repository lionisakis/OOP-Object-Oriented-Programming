#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "teacher.h"
#include "school.h"


class Teacher;
class Student;
class School;

class TheClass{
    private:
        // viriables
        Student** students;
        Teacher* teacherClass;
        School* school;
        
        const int maxStudents;
        const int floorClass;
        const int numClass;
        int size;
    public:
        
        // Costruct class
        TheClass(const int,const int,const int,School* school);
        
        // Decostruct class
        ~TheClass();
        
        //  get the floor and id of class
        void getTheClass(int* ,int* ) const;
        
        //  set who is the Teacher
        void setTeacher(Teacher*);

        // put a student in the Class
        bool putStudent(Student* );
        
        // see if a student is in class
        bool checkStudent(const Student*)const; 
        
        // print all the class
        void printAllTheClass() const;

	// print the name of the class
	void printTheName()const;
                
        // see if the class has room
        bool hasRoom() const;       
};
