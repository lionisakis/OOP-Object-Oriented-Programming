#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "../include/theClass.h"
#include "../include/corridor.h"
#include "../include/floor.h"
#include "../include/school.h"
//////////////////////////////////////////////////////////

#define NUMCLASS 6

// The costructor of the Floor
Floor::Floor(const int levelFloor,const int peopleInClass,const int peopleInCorridor,School* schoolOfFloor):
    level(levelFloor)
    {

    school=schoolOfFloor;
    std::cout << "A Floor ("<<level<<") has been created!\n";

    // create the Corridors
    corridor=new Corridor(peopleInCorridor,school);
    
    // create the classes
    classes=new TheClass*[NUMCLASS];
    for (int i=0;i<6;i++){
        TheClass* floorClass=new TheClass(level,i,peopleInClass,school);
        classes[i]=floorClass;
    }
    
}

// Decostruct the floor
Floor::~Floor(){
    // delete all the classes of the florr
    for (int i=0;i<NUMCLASS;i++){
        TheClass* floorClass=classes[i];
        delete  floorClass;
    }
    delete[] classes;

    // delete the Corridor 
    delete corridor;
    std::cout << "A Floor ("<<level<<") to be destroyed!\n";
}

// returns the class with that index
TheClass& Floor::getClass(const int& index){
    return  *(classes[index]);
}

// returns the Corridor of the floor
Corridor& Floor::getCorridor(){
    return *(corridor);
}

// prints the floor
void Floor::print()const{
    std::cout<<"Floor number "<<level<<" contains:\n";
    for(int i=0;i<NUMCLASS;i++)
        classes[i]->printAllTheClass();
    corridor->print();
}   