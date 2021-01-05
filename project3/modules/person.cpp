#include <iostream>

#include <person.h>
// #include "../include/person.h"

Person::Person(const std::string namePerson, const unsigned int floorClass ,const unsigned int numberClass,const unsigned int tirednessPerson):
floor(floorClass),number(numberClass),inside(false),fatige(0),tiredness(tirednessPerson){
    name=namePerson;
    print();
}

Person::~Person(){
    print();
}

const std::string& Person::getName() const{
    return name;
}

void Person::getClass(int* floorClass,int* numberClass) const{
    *floorClass=floor;
    *numberClass=number;
}

unsigned int Person::getFatige() const{
    return fatige;
}

bool Person::getInside() const{
    return inside;
}

void Person::setFatige(int addFatige){
    fatige+=addFatige;
}

void Person::setInside(bool newInside){
    inside=newInside;
}

void Person::print() const{
    std::cout<<"Name: "<<name<<" ";
    std::cout<<"His Class floor: "<<floor<<" number:"<<number<<"\n";
    std::cout<<"Inside: "<<inside<<" fatige:"<<fatige<<"\n";
}

void Person::printName() const{
    std::cout<<"Name: "<<name<<"\n";
    std::cout<<"Fatige: "<<fatige<<"\n";
}

void Person::printEnter(std::string roomName,int index) const{
    if(index!=-1)
        std::cout<<name<<" enters "<<roomName <<index<<"\n";
    else
        std::cout<<name<<" enters "<<roomName<<"\n";
}

void Person::Person::printExit(std::string roomName) const{
    std::cout<<name<<" exits "<<roomName <<"\n";
}

void Person::operate(int hours){
    setFatige(tiredness*hours);
}