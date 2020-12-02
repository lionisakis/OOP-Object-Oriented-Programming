#pragma once
#include <iostream>
#include <string>
#include "theClass.h"
#include "corridor.h"
#include "school.h"

class TheClass;
class Corridor;
class School;

class Floor{
    private:
        // viriables
        TheClass** classes;
        Corridor* corridor;
        School* school;
        const int level;
    public:
        
        // Costruct the Floor
        Floor(const int ,const int,const int,School*);

        // Decostruct the Floor
        ~Floor();
        
        // returns the class with that int
        TheClass& getClass(const int&);
        
        // returns the Corridor of the floor
        Corridor& getCorridor();
        
        // prints the floor
        void print() const;
};
