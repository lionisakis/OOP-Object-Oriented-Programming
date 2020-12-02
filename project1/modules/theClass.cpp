#pragma once
#include <string>
#include <iostream>
#include "../include/theClass.h"
#include "../include/student.h"
#include "../include/teacher.h"
#include "../include/school.h"
//////////////////////////////////////////////////////////

// Costruct class
TheClass::TheClass(const int floor,const int number,const int maxStudentsInClass,School* schoolOfClass):
    floorClass(floor),numClass(number),
    maxStudents(maxStudentsInClass)
    {
    students=new Student*[maxStudents];
    size=0;
    teacherClass=NULL;
    school=schoolOfClass;
    std::cout<<"A class (floor:"<<floorClass<<" number:"<<numClass<<") has been created!\n";
}

// Decostruct class
TheClass::~TheClass(){
    delete[] students;
    std::cout<<"A class (floor:"<<floorClass<<" number:"<<numClass<<") to be destroyed!\n";
}

//  get the floor and id of class
void TheClass::getTheClass(int* floor,int* number) const {
    *floor=floorClass;
    *number=numClass;
}

//  set who is the Teacher
void TheClass::setTeacher(Teacher* theteacher){
    teacherClass=theteacher;
}

// put a student in the Class
bool TheClass::putStudent(Student* student){
    if (hasRoom()){
        students[size]=(student);
        student->setWhereEnter("class");
        size++;
        return true;
    }
    return false;
}

// see if a student is in class
bool TheClass::checkStudent(const Student* student)const{
    for(int i=0;i<size;i++)
        if(students[i]==student)
            return true;
    return false;
}

// print all the Class
void TheClass::printAllTheClass() const{
    std::cout<<"People in class"<<numClass<<" are:\n";
   
    // print student
    for (int i=0;i<size;i++)
        std::cout<<students[i]->Name()<<"\n";
    
    // print Teacher
    if(teacherClass->getInClass()){
        std::cout<<"The teacher is :\n";
        std::cout<<teacherClass->Name()<<"\n";
    }
    std::cout<<"\n";
}

// print the name of the class
void TheClass::printTheName()const{
    std::cout<<"The class is at the floor: "<<floorClass<<"\n";
    std::cout<<"and the number of the class is: "<<numClass<<"\n";
}

// see if the class has room
bool TheClass::hasRoom() const{
    if (teacherClass!=NULL)
        if (!teacherClass->getInClass())
            if(maxStudents>size)
                return true;
    return false;
}