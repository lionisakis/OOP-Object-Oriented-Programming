#pragma once
#include <string>
#include <iostream>
#include "../include/stair.h"
#include "../include/school.h"
//////////////////////////////////////////////////////////

// a function which swaps a random student with the last
// student returns the random student
Student* Stair::takeRandomStudentStair(Student** student,int size){

    // no more students
    if(size<0)
        return NULL;

    // the last student to return
    if(size==0){
        return student[0];
    }

    // which student
    int random = (int) (size)*((double)rand()/((double)RAND_MAX));

    // swap
    Student* temp;
    temp=student[size];    
    student[size]=student[random];
    student[random]=temp;

    // return the last student 
    return student[size];
}

// Costruct Stair
Stair::Stair(const int maxPeople,School* schoolOfStair){
    maxStudents=maxPeople;
    students=new Student*[maxStudents];
    size=0;
    std::cout<<"A New Stair has been created!\n";
    school=schoolOfStair;
}

// Decostruct Stair
Stair::~Stair(){
    delete[] students;
    std::cout<<"A Stair to be destroyed!\n";
}

// put the student in Stair
bool Stair::put(Student* student){
    if (!hasRoom())
        return false;
    students[size]=student;
    size++;
    student->setWhereEnter("stair");
    return true;
}

// remove a student in stairs
Student* Stair::remove(){
    if (size == 0)
        return NULL;
        
    // take a random student
    Student* student= takeRandomStudentStair(students,size-1);
    
    int indexFloor,indexClass;
    student->getClass().getTheClass(&indexFloor,&indexClass);
    bool entered=school->getFloor(indexFloor).getCorridor().hasRoom();
    // if there is room then take a student
    if (entered){
        size--;
        students[size]=NULL;
        return student;
    }
    return NULL;
}

// print stairs
void Stair::print()const{
    std::cout<<"People in stair are:\n";
    for (int i=0;i<size;i++){
        std::cout<<students[i]->Name()<<"\n";
    }
    std::cout<<"\n";
}

// see if there is room
bool Stair::hasRoom() const{
    if (maxStudents<=size)
        return false;
    return  true;
}