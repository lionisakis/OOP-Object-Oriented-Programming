#pragma once

#include <string>
#include <stdlib.h>
#include <iostream>

#include "../include/corridor.h"
#include "../include/school.h"
#include "../include/student.h"
//////////////////////////////////////////////////////////

// a function which swaps a random student with the last
// student returns the random student
Student* Corridor::takeRandomStudentCorridor(Student** student,int size){

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

// Costruct Corridor
Corridor::Corridor(const int maxPeople,School* schoolOfCorridor){
    maxStudents=maxPeople;
    students=new Student*[maxStudents];
    size=0;
    std::cout<<"A Corridor has been created!\n";
    school = schoolOfCorridor;
}

// Decostruct Corridor
Corridor::~Corridor(){
    delete[] students;
    std::cout<<"A Corridor to be destroyed!\n";
}

// put a student in Corridor
bool Corridor::put(Student* student){
    if (!hasRoom())
        return false;
    students[size]=student;
    size++;
    student->setWhereEnter("Corridor");
    return true;
}

// remove a student in Corridor
Student* Corridor::remove(){
    if (size == 0)
        return NULL;
    
    // take a random student
    Student* student=takeRandomStudentCorridor(students,size-1);
    
    // see if the class has room
    int indexFloor, indexClass;
    student->getClass().getTheClass(&indexFloor,&indexClass);    
    bool entered=school->getFloor(indexFloor).getClass(indexClass).hasRoom();
    if (entered){
        size--;
        students[size]=NULL;
        return student;
    }
    return NULL;
}


// print 
void Corridor::print()const{
    std::cout<<"People in corridor are:\n";
   
    for (int i=0;i<size;i++){
        std::cout<<students[i]->Name()<<"\n";
    }
    std::cout<<"\n";
}

// if has room
bool Corridor::hasRoom() const{
    if (maxStudents<=size)
        return false;
    return  true;
}