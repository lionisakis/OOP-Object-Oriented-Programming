#pragma once
#include <iostream>
#include <string>
#include "yard.h"
#include "floor.h"
#include "stair.h"
#include "theClass.h"

class Stair;
class Floor;
class Yard;
class TheClass;

class School{
    private:
        // viriables
        Floor** floor;
        Student** students;
        Stair* stair;
        Yard* yard;
    public:
        
        // Costruct School
        School(const int ,const int,const int,const int);
        
        // Decostruct School
        ~School();
        
        // returns the floor of the int
        Floor& getFloor(const int&);
        
        // returns the stairs
        Stair& getStair();
        
        // returns the yard
        Yard& getYard();
        
        // return the class with those Level and id
        TheClass& getClass(const int&,const int&);
        
        // put a student in the school
        bool  enterSchool(Student* );

        // print all school life
        void print() const;
};
