#include <iostream>

#include <teacher.h>
#include <person.h>

Teacher::Teacher(const std::string name, const unsigned int floorClass,const unsigned int numberClass,const unsigned int tiredness):
    Person(name, floorClass,numberClass,tiredness){
        std::cout <<"A new teacher is being created\n";
        print();
}

Teacher::~Teacher(){
    std::cout <<"A teacher to be destroyed\n";
    print();
}
