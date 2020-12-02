#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <time.h> 

#include "../include/student.h"
#include "../include/teacher.h"
#include "../include/theClass.h"
#include "../include/school.h"
#include "../include/yard.h"

#define FLOORS 3
#define CLASSES 6

// a function which swaps a random student with the last
// student returns the random student
Student* takeRandomStudent(Student** student,int* size){

    // no more students
    if((*size)<0)
        return NULL;

    // the last student to return
    if((*size)==0){
        return student[0];
    }

    // which student
    int random = (int) (*size)*((double)rand()/((double)RAND_MAX));

    // swap
    Student* temp;
    temp=student[(*size)];    
    student[(*size)]=student[random];
    student[random]=temp;

    // return the last student 
    return student[(*size)];
}

// a function which swaps a random teacher with the last
// teacher returns the random teacher
Teacher* takeRandomTeacher(Teacher** teacher,int* size){
    
    // no more teachers
    if((*size)<0)
        return NULL;

    // the last teacher to return
    if((*size)==0){
        return teacher[0];
    }

    // random teacher
    int random = (int) (*size)*((double)rand()/((double)RAND_MAX));
    
    // swap
    Teacher* temp;
    temp=teacher[(*size)];
    teacher[(*size)]=teacher[random];
    teacher[random]=temp;

    // return the last teacher
    return teacher[(*size)];
}

int main(int argc,char* argv[]){
    // see if we have the enough arguments
    if (argc!=5){
        std::cout<<"Not the right arguments.\n";
        std::cout<<"Arguments needed:\n";
        std::cout<<"./file peopleInClass peopleInCoridol poepleInYard peopleInStairs\n";
	return 1;
    }

    const int peopleInClass=atoi(argv[1]);

    // create School
    School school(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
    
    // creating all the teachers
    Teacher** teachers=new Teacher*[FLOORS*CLASSES];
    int sizeTeacher=0;
    // for all the floors and classes
    for(int i=0;i<FLOORS;i++)
        for (int j=0;j<CLASSES;j++){
            // I am using the replace so we have a diffrend teacher all the time 
            std::string name;
            std::cin>>name;
            if(std::cin.fail()){
                std::cout <<"Problem with the names\n";
                return -1;
            }
            teachers[sizeTeacher]=(new Teacher(name,&school.getClass(i,j)));
            sizeTeacher++;

        }

    // creating all the students
    Student** students=new Student*[FLOORS*CLASSES*peopleInClass];
    // the name of the students: student {floor} {class} {num}
    int sizeStudent=0;
    // for all the floors and classes and poeple in each class
    for(int i=0;i<FLOORS;i++)
        for (int j=0;j<CLASSES;j++)
            for(int k=0;k<peopleInClass;k++){
                // I am using the replace so we have a diffrend student all the time 
                std::string name;
                std::cin>>name;
                if(std::cin.fail()){
                    std::cout <<"Problem with the names\n";
                    return -1;
                }
                students[sizeStudent]=(new Student(name,&school.getClass(i,j)));
                sizeStudent++;
            }

    std::cout<<"\n";
    
    // define the srand
    srand(time(NULL));

    // sizes of student and teachers that have
    // not enterd the class to use in the
    // replace function that have been 
    // defined above
    int studentsNotIn=sizeStudent-1;
    int teachersNotIn=sizeTeacher-1;
    bool flage=false;
    while(true){

        //  check if all students have enterd
        int countStudent=0;
        for (int i=0;i<FLOORS*CLASSES*peopleInClass;i++)
            if(students[i]->inClass())
                countStudent++;
        if (countStudent==FLOORS*CLASSES*peopleInClass)
            break;
        
        //  check if all teachers have enterd
        int countTeachers=0;
        for (int i=0;i<FLOORS*CLASSES;i++){
            if(teachers[i]->getInClass())
                countTeachers++;
        }
        if(countTeachers==FLOORS*CLASSES)
            break;
        
        // see if students move or teachers
        int whoMoves=(int)(peopleInClass*((double)rand()/(double)RAND_MAX));
        if (whoMoves<peopleInClass-1){

            // which Corridor to move
            int whichCorridor=0;
            while(true){
                Student* enterd=school.getFloor(whichCorridor).getCorridor().remove();
                if (enterd!=NULL){
                    // if there is room and has been removed
                    // from Corridor then enter Class
                    int indexFloor,indexClass;
                    // find the Floor and Class
                    enterd->getClass().getTheClass(&indexFloor,&indexClass);
                    school.getFloor(indexFloor).getClass(indexClass).putStudent(enterd);           

                }
                else{
                    whichCorridor++;
                }
                if(whichCorridor>=FLOORS)
                    break;
            }
            
             // move from stairs
            while(true){
                Student* enterd=school.getStair().remove();
                if (enterd!=NULL){

                    // if there is room and has been removed
                    // from Stair then enter Corridor
                    int indexFloor,indexClass;
                    // find the Floor and Class(only Floor matters here)
                    enterd->getClass().getTheClass(&indexFloor,&indexClass);
                    school.getFloor(indexFloor).getCorridor().put(enterd);
                }  
                else
                    break;
            } 

            // move from schoolyard
            while(true){
                Student* entered=school.getYard().remove();
                if (entered!=NULL){
                    // if there is room and has been removed
                    // from Yard then enter Stairs
                    school.getStair().put(entered);
                }
                else 
                    break;
            }

               
            // move from out of school
            while(true){
                Student* temp= takeRandomStudent(students,&studentsNotIn);
                if(temp==NULL){
                    // all students have enterd
                    flage=true;
                    break;
                }
                // enter the student
                bool is=school.enterSchool(temp);
                if(is){
                    // did enterd
                    studentsNotIn--;
                }
                else{
                    break;
                }
            }

            
        }
        // move teacher
        else{
            Teacher* temp=takeRandomTeacher(teachers,&teachersNotIn);
            
            if(temp==NULL){
                // all the teachers have been playced
                continue;
            }
            // put the teacher
            bool is=temp->put();
            if (is){
                // if not in then dont
                // remove him from the set
                teachersNotIn--;
            }  
        } 
        

    }
    std::cout<<"\n";

    // print school
    school.print();
    std::cout<<"\n";
    
    // delete all the students
    for (int i=0;i<FLOORS*CLASSES*peopleInClass;i++)
        delete students[i];
    delete[] students;
    std::cout<<"\n";
    
    // delete all the teachers
    for (int i=0;i<FLOORS*CLASSES;i++)
        delete teachers[i];
    delete[] teachers;
    std::cout<<"\n";
    
    return 0;
}
