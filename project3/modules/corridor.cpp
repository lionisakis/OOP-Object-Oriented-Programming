#include <iostream>

#include <room.h>
#include <corridor.h>


Corridor::Corridor(const unsigned numberFloor):
    Room(1),floor(numberFloor){
    std::cout<<"A new corridor is being created\n";
}


Corridor::~Corridor(){
    std::cout <<"A corridor to be destroyed\n";
}

void Corridor::enter(Student* student){
    Room::enter(student);
    student->printEnter("foor with number: ",floor);
    student->printEnter("corridor");
}

Student* Corridor::exit(){
    Student* student=Room::getStudent(0);
    Room::enter(NULL);
    student->printExit("corridor");
    return student;
}

void Corridor::print() const{
    std::cout<<"Corridor (floor: "<<floor<<"):\n";
    Room::print(); 
}