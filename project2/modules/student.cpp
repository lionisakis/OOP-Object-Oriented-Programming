#pragma once 
#include <iostream>
#include <string>
#include "../include/student.h"


// Costruct Student
Student::Student(const std::string nameStudent,const std::string sexStudent,const int classStudent):
    name(nameStudent),
    sex(sexStudent),
    messy(false),
    theClass(classStudent)
{}

// return the class in which the student is in
int Student::getClass()const{
    return theClass;
}

// return the sex of the student
const std::string Student::getSex() const{
    return sex;
}

// return if the student is naughty or not
bool Student::getMessy()const{
    return messy;
}

// set if the student is naughty or not
void Student::setMessy(bool newMessy){
    messy=newMessy;
}

// print the student
void Student::print() const{
    std::cout<<"Student Name: "<<name<<std::endl;
    std::cout<<"Student Sex: "<<sex<<" Class: "<<theClass<<std::endl;
    std::cout<<"Is mess:"<<messy<<std::endl;
}


