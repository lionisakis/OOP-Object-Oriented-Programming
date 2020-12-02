#include <string>
#include <vector>
#include <iostream>
#include "../include/teacher.h"

//////////////////////////////////////////////////////////

//  Costruct Teacher
Teacher::Teacher(const std::string name,TheClass* theclass){
    nameTeacher=name;
    inClass=false;
    teacherClass=theclass;
    
    // set the teacher's class
    int x,y;
    teacherClass->getTheClass(&x,&y);    
    teacherClass->setTeacher(this);
    
    std::cout << "A New Teacher has been created\n";
    std::cout << "Name: "<<nameTeacher<<"\n";
    std::cout<<"Class:\n";
    teacherClass->printTheName();
}


// Decostruct Teacher
Teacher::~Teacher(){
    std::cout<<"A Teacher to be destroyed!\n";
    std::cout <<"Name: "<< nameTeacher<<"\n";
    std::cout<<"Class:\n";
    teacherClass->printTheName();
}

// return if teacher is in class
const bool Teacher::getInClass()const {
    return inClass;
}

// put teacher in calss
bool Teacher::put(){
    if (inClass)
        return true;
    inClass= true;
    return true;
}

// return Name teacher
std::string Teacher::Name() const{
    return  nameTeacher;
}