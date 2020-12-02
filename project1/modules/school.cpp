#include <string>
#include <iostream>
#include "../include/school.h"

#define FLOORNUMBERS 3

class Stair;
class Floor;
class Yard;
//////////////////////////////////////////////////////////

// Costruct School
School::School(const int peopleInClass,const int peopleInCoridol,const int poepleInYard,const int peopleInStairs){
    // create school
    std::cout<<"A New School has been created!\n";
    
    // create floors
    floor= new Floor*[FLOORNUMBERS];
    for(int i=0;i<FLOORNUMBERS;i++){
        Floor* schoolFloor=new Floor (i,peopleInClass,peopleInCoridol,this);
        floor[i]=schoolFloor;
    }
    
    // create stairs
    Stair* schoolStair =new Stair(peopleInStairs,this);
    stair=schoolStair;

    // create Yard
    Yard* schoolYard= new Yard(poepleInYard,this);
    yard=schoolYard;
}

// Decostruct School
School::~School(){
    // delete floors
    for(int i=0;i<3;i++){
        Floor* schoolfloor=floor[i];
        delete schoolfloor;
    }
    delete[] floor;

    // delete stairs
    delete stair;

    // delete yard
    delete yard;

    // delete School
    std::cout<<"A School to be destroyed!\n";
}

// returns the floor of the index
Floor& School::getFloor(const int& index){
    return *(floor[index]);
}

// returns the stairs
Stair& School::getStair(){
    return *stair;
}

// returns the yard
Yard& School::getYard(){
    return *yard;
}

// return the class with those Level and id
TheClass& School::getClass(const int& floorLevel,const int& number){
    return floor[floorLevel]->getClass(number);
}

// put a student in the school
bool  School::enterSchool(Student* student){
    // the student is in school
    if (student->getWhere()!="out of School")
        return false;

    // if yard has room
    bool entered=yard->hasRoom();
    if (entered){
        // students is in school
        student->setWhereEnter("school");
        // students in yard
        yard->put(student);
    }
    return entered;
}

// print all school life
void School::print()const { 
    std::cout<<"School life consists of:\n";
    
    // print yard
    yard->print();
    
    // print stair
    stair->print();

    // print all floors
    for(int i=0;i<FLOORNUMBERS;i++)
        floor[i]->print();
}