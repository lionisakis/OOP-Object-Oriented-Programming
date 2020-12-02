#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "pair.h"
class Student;
class Pair;
class Kindergarden{
    private:
        // variables
        const unsigned int Tquiet;
        const unsigned int Tmessy;
        int* T;

        const unsigned int classes;
        const unsigned int maxStudents;
        Student*** students;
        int* size;

        int* PairSize;
        Pair*** list;

        // helpfull function for the code
        // not intanted for the user but for the class alone
        
        // change the Pair
        void changePairs(Pair*,Student* ,Student* );
        
        // Find a student to replace the naughty
        void replaceStudent(int ,int ,Student* );
        
        // Find the Pair in which student is a part
        Pair* findPair(Student*);
    
        // find a student that has an opossite sex and put him in the Pair
        Student* findStudent(int ,int ,std::string );
        
        // put a Student in the Sequence
        bool putStudentInSequence(Pair** ,int ,int );

    public:

        // Costruct Kindergarden
        Kindergarden(const unsigned int,const unsigned int,const unsigned int,const unsigned int);
        
        // Decostruct Kindergarden
        ~Kindergarden();

        // Put a new student in a class
        bool putStudent(Student *,int);

        // create a sequence for the Kindergarden to go on a trip
        void createSequence();

        // takes random students and makes them naughty
        // then the function change their location
        void createMess(int);
        
        // print the Seqeunce for each class
        void print()const;
        
        // change Places of The naughty Students
        // it is in public because maybe the user 
        // wants to put a specific student that 
        // has made a mess 
        void changeNaughtyStudents();
};

