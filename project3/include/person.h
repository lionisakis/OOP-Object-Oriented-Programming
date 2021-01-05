#pragma once
#include <string>

class Person {
    private:
        std::string name;
        const unsigned int floor;
        const unsigned int number;
        bool inside;
        unsigned int fatige;
        const int tiredness;
    public:
        Person(const std::string, const unsigned int ,const unsigned int,const unsigned int);
        virtual ~Person();

        const std::string& getName() const;
        void getClass(int*,int*) const;
        unsigned int getFatige() const;
        bool getInside() const;

        void setFatige(int);
        void setInside(bool);

        void print() const; 

        void printName() const;

        void printEnter(std::string,int index=-1) const;
        void printExit(std::string) const;

        void operate(int hours);
};