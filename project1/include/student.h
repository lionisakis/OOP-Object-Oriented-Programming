#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "theClass.h"

class TheClass;
class Student{
    private:
        // viriables
        std::string nameStudent;
        TheClass* theclass;
        std::string  where;
        bool enterSchool;
        bool exitSchool;
    public:
        // Costruct Student
        Student(const std::string,TheClass *);
        
        // Decostruct Student
        ~Student();
        
        //  get where student is
        std::string getWhere() const;
        
        // set where students enter
        void setWhereEnter(const std::string );
        
        // reutrn the Name
        std::string Name()const;
        
        // return the class
        const TheClass& getClass() const;
        
        // return if the student is in class
        bool inClass() const;
};
