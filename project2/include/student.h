#pragma once
#include <iostream>
#include <string>
#include "kindergarden.h"

class Student{
    private:
        // viriables
        const std::string name;
        const std::string sex;
        bool messy;
        const int theClass;
    public:
        // Costruct Student
        Student(const std::string,const std::string,const int);

        // Decostructor is not needed
        // as the class does not 
        // delete any pointer 

        // return the class in which the student is in
        int getClass()const;

        // return the sex of the student
        const std::string getSex() const;

        // return if the student is naughty or not
        bool getMessy()const;
                
        // set if the student is naughty or not
        void setMessy(bool);
        
        // print the student
        void print()const;

};

