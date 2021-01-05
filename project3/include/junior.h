#pragma once
#include <string>

#include "student.h"

class Junior:public Student {
    public:
        Junior(const std::string, const unsigned int ,const unsigned int,const unsigned int);
};