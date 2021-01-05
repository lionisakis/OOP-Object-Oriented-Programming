#pragma once
#include <iostream>
#include "room.h"

class Stairs: public Room{
    public:
        Stairs();
        ~Stairs();
        
        void enter(Student*);

        Student* exit();

        void print() const;
};