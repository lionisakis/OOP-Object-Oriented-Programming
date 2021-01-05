#pragma once
#include <iostream>
#include "room.h"

class Corridor: public Room{
    private:
        const unsigned floor;
    public:
        Corridor(const unsigned);
        ~Corridor();
        
        void enter(Student*) override;

        Student* exit();

        void print() const;
};