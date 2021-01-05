#include <iostream>

#include <stairs.h>
#include <room.h>


Stairs::Stairs():
    Room(1){
    std::cout<<"A new stair is being created\n";
}


Stairs::~Stairs(){
    std::cout <<"A stair to be destroyed\n";
}

void Stairs::enter(Student* student){
    Room::enter(student);
    student->printEnter("stairs");
}

Student* Stairs::exit(){
    Student* student=Room::getStudent(0);
    Room::enter(NULL);
    student->printExit("stairs");
    return student;
}

void Stairs::print() const{
    std::cout<<"Stairs:\n";
    Room::print(); 
}