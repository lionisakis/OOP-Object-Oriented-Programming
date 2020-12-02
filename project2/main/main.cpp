
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "../include/student.h"
#include "../include/kindergarden.h"

#define PEOPOLEINCLASS 4

int main(int argc,char* argv[]){
    if(argc!=5){
        std::cout<<"Not the right arguments.\n";
        std::cout<<"Arguments needed:\n";
        std::cout<<"./file Classes TimesOfDisorder NumberQuiet NumberMessy\n";
        return -1;
    }
    const int numClasses=atoi(argv[1]);
    const int messyTimes=atoi(argv[2]);
    srand(time(NULL));

    Kindergarden kindergarden(atoi(argv[3]),atoi(argv[4]),PEOPOLEINCLASS,numClasses);

    // creating all the students
    Student** students=new Student*[numClasses*PEOPOLEINCLASS];

    int sizeStudent=0;
    // for all the floors and classes and poeple in each class
    int sex=0;
    for(int i=0;i<numClasses;i++){
        for (int j=0;j<PEOPOLEINCLASS;j++){
            // I am using the replace so we have a diffrend student all the time 
            std::string str_sex;
            if(sex){
                sex--;
                str_sex="female";
            }
            else{
                sex++;
                str_sex="male";
            }

            std::string name;
            std::cin>>name;
            if(std::cin.fail()){
                std::cout <<"Problem with the names\n";
                return -1;
            }
            students[sizeStudent]=(new Student(name,str_sex,i));
            bool enterd=kindergarden.putStudent(students[sizeStudent],i);
            sizeStudent++;
            if(!enterd){
                std::cout<<"Too many poeple\n";
                return-2;
            }
        }
    }

    kindergarden.createSequence();

    kindergarden.print();
    std::cout<<"\n\n";
    kindergarden.createMess(messyTimes);
    std::cout<<"\n\n";

    kindergarden.print();

    for(int i=0;i<sizeStudent;i++)
        delete students[i];
    delete[] students;

    return 0;
}