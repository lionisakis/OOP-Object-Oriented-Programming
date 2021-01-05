#pragma once
#include <string>

#include "person.h"

class Student:public Person {
    public:
        Student(const std::string, const unsigned int ,const unsigned int,const unsigned int);
        ~Student();
        
};