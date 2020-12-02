#include <string>
#include <iostream>
#include "../include/student.h"
//////////////////////////////////////////////////////////

// Costruct Student
Student::Student(const std::string name,TheClass* studentClass){
    nameStudent=name; 
    theclass=studentClass;

    where="out of School";
    
    enterSchool=false;
    exitSchool=false;

    std::cout<<"A New Student has been created!\n";
    std::cout<<"Name: "<<nameStudent<<"\nClass: \n";
    theclass->printTheName();
    std::cout<<"Student is "<<where<<"\n";
    
}

// Decostruct Student
Student::~Student(){
    std::cout<<"A Student to be destroyed!\n";
    std::cout<<"Name: "<<nameStudent<<"\nClass:\n";
    theclass->printTheName();
    std::cout<<"Student is "<<where<<"\n";
}

//  get where student is
std::string Student::getWhere()const{
    return where;
}

// set where students enter
void  Student::setWhereEnter(const std::string whereToGo){
    // print from where it exits
    // we dont want to print 
    // student exits school or out of school
    if(!(where=="school"||where=="out of School"))
        std::cout<< nameStudent << " exits "<<where<<std::endl;
    
    // replace where
    where.assign(whereToGo);

    // print where it enters
    std::cout<< nameStudent <<" enters "<<where<<std::endl;    
}

// reutrn the Name
std::string Student::Name()const{
    return nameStudent;
}

// return the class
const TheClass& Student::getClass()const {
    return *theclass;
}

// return if the student is in class
bool Student::inClass() const{
    return theclass->checkStudent(this);;
}