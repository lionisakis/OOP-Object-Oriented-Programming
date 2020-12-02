#pragma once 
#include <iostream>
#include <string>
#include "../include/student.h"
#include "../include/pair.h"

// Costruct Pair
Pair::Pair(Student* thisStudentA,Student* thisStudentB){
    studentA= thisStudentA;
    studentB= thisStudentB;
}

// Return the first Student
Student* Pair::getStudentA()const{
    return studentA;
}

// Return the second Student
Student* Pair::getStudentB()const{
    return studentB;
}

// Change the students
void Pair::changeStudents(Student* newA,Student* newB){
    studentA=newA;
    studentB=newB;
}

// check if the Pair is messy or not
bool Pair::isMessy()const{
    if(studentA==NULL||studentB==NULL)
        return false;
    if(studentA->getMessy()&&studentB->getMessy())
        return true;
    return false;
}

// print the Pair
void Pair::print() const{
    std::cout<<"Pair:\n";
    std::cout<<"Student 1: ";
    if(studentA!=NULL)
        studentA->print();
    else
        std::cout<<"\n";
    std::cout<<"Student 2:";
    if(studentB!=NULL)
        studentB->print();
    else
        std::cout<<"\n";
}
