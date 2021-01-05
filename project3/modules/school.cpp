#include <iostream>

#include <floor.h>
#include <stairs.h>
#include <yard.h>
#include <corridor.h>
#include <class.h>
#include <school.h>

#define FLOORS 3
#define CLASSES 6

School::School(const unsigned sizeClass){
    std::cout<<"A new school is being created\n";
    
    yard= new Yard();
    stairs= new Stairs();

    floors =new Floor*[3];
    for(int i=0;i<FLOORS;i++)
        floors[i]= new Floor(i,sizeClass);

}

School::~School(){
    for(int i=0;i<FLOORS;i++)
        delete floors[i];
    delete[] floors;
    delete stairs;
    delete yard;
    std::cout <<"A school to be destroyed\n";
}

Yard& School::getYard() const{
    return *yard;
}
Stairs& School::getStairs()const{
    return *stairs;
}
const Floor& School::getFloor(int floor) const{
    return *floors[floor];
}  
Corridor& School::getCorridor(int floor)const{
    return floors[floor]->getCorridor();
}
TheClass& School::getClass(int floor, int number) const{
    return floors[floor]->getClass(number);
}

void School::print() const{
    std::cout<<"Schoollife consists of: \n";
    yard->print();
    stairs->print();
    for(int i=0;i<FLOORS;i++)
        floors[i]->print();
}

void School::enter(Student* student) {
    yard->enter(student);
}

void School::operate(int hours){
    for(int i=0;i<FLOORS;i++)
        for(int j=0;j<CLASSES;j++)
            floors[i]->getClass(j).operate(hours);
}