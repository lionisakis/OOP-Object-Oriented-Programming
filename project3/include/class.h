#pragma once
#include <iostream>
#include "student.h"
#include "teacher.h"
#include "room.h"

class TheClass: public Room{
    private:
        const unsigned floor;
        const unsigned number;
        const unsigned size;
        unsigned indexStudents;
        
        Teacher* teacher;
    public:
        TheClass(const unsigned,const unsigned,const unsigned);
        ~TheClass();
        
        void enter(Student*) ;
        void enter(Teacher*) ;
        
        void operate(int);

        void print() const;
};