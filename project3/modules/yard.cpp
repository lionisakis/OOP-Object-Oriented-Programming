#include <iostream>

#include <room.h>
#include <yard.h>


Yard::Yard():
    Room(1){
    std::cout<<"A new schoolyard is being created\n";
}

Yard::~Yard(){
    std::cout <<"A schoolyard to be destroyed\n";
}

void Yard::enter(Student* student){
    Room::enter(student);
    student->printEnter("schoolyard");
}

Student* Yard::exit(){
    Student* student=Room::getStudent(0);
    Room::enter(NULL);
    student->printExit("schoolyard");
    return student;
}

void Yard::print() const{
    std::cout<<"Schoolyard:\n";
    Room::print(); 
}