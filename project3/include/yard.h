#pragma once
#include <iostream>
#include "room.h"

class Yard: public Room{
    public:
        Yard();
        ~Yard();
        
        void enter(Student*);

        Student* exit();
        
        void print() const;
};