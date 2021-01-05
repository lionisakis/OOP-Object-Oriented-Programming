#pragma once
#include <iostream>
#include <vector>
#include "student.h"

class Room {
    private:
        const int max;
        std::vector<Student*> students;
    public:
        Room(int);
        virtual void enter(Student*);
        virtual void print() const;
        Student* getStudent(int index=0)const;
};
