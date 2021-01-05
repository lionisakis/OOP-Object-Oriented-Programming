#include <iostream>

#include <student.h>
#include <person.h>


Student::Student(const std::string name, const unsigned int floorClass,const unsigned int numberClass,const unsigned int tiredness):
    Person(name, floorClass,numberClass,tiredness){
    std::cout<<"A new student is being created\n";
}

Student::~Student(){
    std::cout <<"A student to be destroyed\n";
}
