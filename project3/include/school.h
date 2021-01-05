#pragma once
#include <iostream>
#include "floor.h"
#include "stairs.h"
#include "yard.h"
#include "corridor.h"
#include "class.h"


class School{
    private:
        Floor** floors;
        Stairs* stairs;
        Yard* yard; 
    public:
        School(const unsigned);
        ~School();
        
        Yard& getYard() const;
        Stairs& getStairs()const;
        const Floor& getFloor(int ) const;
        Corridor& getCorridor(int )const;
        TheClass& getClass(int , int) const;

        void print() const;

        void enter(Student*);

        void operate(int );
};