#pragma once
#include <string>
#include <iostream>
#include "../include/yard.h"
#include "../include/school.h"
#include "../include/stair.h"
//////////////////////////////////////////////////////////

// a function which swaps a random student with the last
// student returns the random student
Student* Yard::takeRandomStudentYard(Student** student,int size){

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

// Costruct Yard
Yard::Yard(const int maxPeople,School* schoolOfYard){
    maxStudents=maxPeople;
    students=new Student*[maxStudents];
    size=0;
    std::cout << "A Yard has been created!\n";
    school = schoolOfYard;
}

// Decostruct Yard
Yard::~Yard(){
    delete[] students;
    std::cout << "A Yard to be destroyed!\n";
}

// put the student in Yard
bool Yard::put(Student* student){
    if (!hasRoom())
        return false;
    students[size]=student;
    size++;
    student->setWhereEnter("scholyard");
    return true;
}

// remove a student in yard
Student* Yard::remove(){   
    if (size == 0){
        return NULL;
    }
    bool entered=school->getStair().hasRoom();
    // if there is room then take a student
    if (entered){
        Student* student=takeRandomStudentYard(students,size-1);
        
        size--;
        // Student* student=students[size];
        students[size]=NULL;
            
        return student;
    }
    return NULL;
    
}

// print Yard
void Yard::print()const{
    std::cout<<"People in schoolyard are:\n";
    for (int i=0;i<size;i++){
        std::cout<<students[i]->Name()<<"\n";
    }
    std::cout<<"\n";
}

// see if there is room
bool Yard::hasRoom() const{
    if (maxStudents<=size)
        return false;
    return  true;
}