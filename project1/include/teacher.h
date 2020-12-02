#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "theClass.h"
#include "floor.h"

class TheClass;
class Floor;

class Teacher{
    private:
        // viriables
        std::string nameTeacher;
        TheClass* teacherClass;
        bool inClass; 
        
    public:
        //  Costruct Teacher
        Teacher(const std::string,TheClass*);
        
        // Decostruct Teacher
        ~Teacher();
        
        // return if teacher is in class
        const bool getInClass() const;
        
        // put teacher in class
        bool put();
        
        // return Name teacher
        std::string Name() const;
};