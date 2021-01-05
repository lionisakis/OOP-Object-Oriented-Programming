#include <iostream>
#include <stdlib.h> 
#include <time.h> 

#include <student.h>
#include <junior.h>
#include <senior.h>
#include <teacher.h>

#include <school.h>

#define FLOORS 3
#define CLASSES 6

int main(int argc,char* argv[]){
    // see if we have the enough arguments
    if (argc!=6){
        std::cout<<"Not the right arguments.\n";
        std::cout<<"Arguments needed:\n";
        std::cout<<"./file Cclass Lj Ls Lt N\n";
        return 1;
    }

    const int poepleInClass=atoi(argv[1]);
    const int fatigeJ=atoi(argv[2]);
    const int fatigeS=atoi(argv[3]);
    const int fatigeT=atoi(argv[4]);
    const int hours=atoi(argv[5]); 
    School school(poepleInClass);
    std::cout<<"\n";

    std::vector<Student*> students;

    for (int i=0;i<FLOORS;i++)
        for(int j=0;j<CLASSES;j++)
            for(int k=0;k<poepleInClass;k++){
                std::string name;
                std::cin>>name;
                if(std::cin.fail()){
                    std::cout <<"Problem with the names\n";
                    return -1;
                }
                if(j<3)
                    students.push_back(new Junior(name,i,j,fatigeJ));
                else
                    students.push_back(new Senior(name,i,j,fatigeS));
            }

    
    std::cout<<"\n";

    std::vector<Teacher*> teachers;

    for (int i=0;i<FLOORS;i++)
        for(int j=0;j<CLASSES;j++){
            std::string name;
            std::cin>>name;
            if(std::cin.fail()){
                std::cout <<"Problem with the names\n";
                return -1;
            }
            teachers.push_back(new Teacher(name,i,j,fatigeT));
        }

    std::cout<<"\n";

    srand(time(NULL));

    while(true){
        int which=(int)(poepleInClass+1)*((double)rand()/((double)RAND_MAX));
        int i;
        for(i=0;i<students.size();i++){
            if(!students.at(i)->getInside())
                break;
        }
        if(i>=students.size()){
            int j=-1;
            for(j=0;j<teachers.size();j++){
                if(!teachers.at(j)->getInside())
                    break;
            }
            if(j>=teachers.size()){
                break;
            }
        }
        
        
        if(which<poepleInClass){

            int whichStudent=(int)(students.size())*((double)rand()/((double)RAND_MAX));
            
            Student* student =students.at(whichStudent);
            
            if(student->getInside())
                continue;

            school.enter(student);
            student=school.getYard().exit();
            school.getStairs().enter(student);
            student=school.getStairs().exit();
            
            int floor;
            int number;
            
            student->getClass(&floor,&number);
            school.getCorridor(floor).enter(student);
            student=school.getCorridor(floor).exit();
            school.getClass(floor,number).enter(student);
            
            
        }
        else{
            int whichTeacher=(int)(teachers.size())*((double)rand()/((double)RAND_MAX));
            
            Teacher* teacher = teachers.at(whichTeacher);
            
            if(teacher->getInside())
                continue;
            
            int floor;
            int number;
            teacher->getClass(&floor,&number);
            school.getClass(floor,number).enter(teacher);
            
        }
        
        
    }

    std::cout<<"\n";

    school.operate(hours);

    school.print();

    std::cout<<"\n";

    int size=students.size();
    for(int i=0;i<size;i++){
        delete students.back();
        students.pop_back();
    }

    size=teachers.size();
    for(int i=0;i<size;i++){
        delete teachers.back();
        teachers.pop_back();
    }

    return 0;
}
