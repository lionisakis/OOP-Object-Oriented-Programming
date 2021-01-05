#pragma once
#include <string>

#include "person.h"

class Teacher:public Person {
    public:
        Teacher(const std::string, const unsigned int ,const unsigned int,const unsigned int);
        ~Teacher();
};