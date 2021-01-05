#include <iostream>

#include <student.h>
#include <teacher.h>
#include <class.h>
#include <room.h>


TheClass::TheClass(const unsigned classFloor,const unsigned classNumber,const unsigned classSize):
    Room(classSize),floor(classFloor),number(classNumber),size(classSize){
    std::cout<<"A new class is being created\n";
    std::cout<<"Floor: "<<floor<<" Number: "<<number<<"\n";
    teacher=NULL;
    indexStudents=0;
}


TheClass::~TheClass(){
    std::cout <<"A class to be destroyed\n";
    std::cout<<"Floor: "<<floor<<" Number: "<<number<<"\n";
}

void TheClass::enter(Student* student){
    Room::enter(student);
    student->setInside(true);
    student->printEnter("class");
}

void TheClass::enter(Teacher* teacherClass){
    teacher=teacherClass;
    teacher->setInside(true);
}

void TheClass::print() const{
    std::cout<<"The Class (floor: "<<floor<<" Number: "<<number<<"):\n";
    
    Room::print();

    if(teacher!=NULL){
        std::cout<<"Teacher:\n";
        teacher->printName();
        std::cout<<"\n";
    }

}

void TheClass::operate(int hours){
    int i=0;
    while(true){
        Student* student=Room::getStudent(i);
        if(student==NULL)
            break;
        i++;
        student->operate(hours);
    }
    if(teacher!=NULL)
        teacher->operate(hours);
}