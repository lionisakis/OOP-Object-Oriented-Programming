#pragma once 
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "../include/kindergarden.h"

// Costruct Kindergarden
Kindergarden::Kindergarden(const unsigned int TquietClass,const unsigned int TmessyClass,const unsigned int numStudentsClass,const unsigned int numClasses):
    // initializer list 
    Tquiet(TquietClass),Tmessy(TmessyClass),
    classes(numClasses),maxStudents(numStudentsClass)
{
    // create a new array for the Pairs for each class
    list=new Pair**[classes];

    // create a new array for the students in each class
    students=new Student**[classes];

    // complite the arrays
    int i;
    for(i=0;i<classes;i++){
        list[i]=new Pair*[maxStudents/2+1];
        students[i]=new Student*[numStudentsClass];
    }
    
    // create a new array for the size of each class
    size=new int[classes];

    // create a new array for the size of Pair in each class
    PairSize=new int[classes];

    // create a new array for the Messyness in each class
    T=new int[classes];
    
    // initialize what is needed
    for(i=0;i<classes;i++){
        T[i]=0;
        PairSize[i]=0;
        size[i]=0;
    }
}

// Decostruct Kindergarden
Kindergarden::~Kindergarden(){
     int i;
     for(i=0;i<classes;i++){
        for(int j=0;j<PairSize[i];j++){
            delete list[i][j];
	}
        delete[] students[i];
        delete[] list[i];
    }
    delete[] list;
    delete[] students;

    // delete each array that has been created
    delete[] PairSize;
    delete[] size;
    delete[] T;

}

// Put a new student in a class
bool Kindergarden::putStudent(Student* student,int index){
    // see if there is the class
    if(index<0||index>=classes)
        return false;
    // see if there is room
    if(size[index]>=maxStudents)
        return false;
    
    // put student in class
    students[index][size[index]]=student;
    size[index]++;

    return true;
}

// find a student that has an opossite sex and put him in the Pair
Student* Kindergarden::findStudent(int theClass,int begin,std::string sex){
    int end;

    // find him and replace him with the next student 
    // of the student we want to Pair him with
    int i;
    for(i=begin+1;i<size[theClass];i++){
        if(students[theClass][i]->getSex()!=sex){
            // swap
            Student* temp;
            temp=students[theClass][i];    
            students[theClass][i]=students[theClass][begin+1];
            return students[theClass][begin+1]=temp;
        }
    }    
    return NULL;
}

// put a Student in the Sequence
bool Kindergarden::putStudentInSequence(Pair** previous,int i,int j){
    // find a second student
    Student* secondStudent=findStudent(i,j,students[i][j]->getSex());
    
    // see if there is a previous student 
    // if there is not then we can but them as we like it
    if(*previous==NULL){
        list[i][PairSize[i]]=new Pair(students[i][j],secondStudent);
    }
    // if theres is we have to put them acordinly
    else{
        if((*previous)->getStudentA()!=NULL){
            if((*previous)->getStudentA()->getSex()!=students[i][j]->getSex()){
                list[i][PairSize[i]]= new Pair(students[i][j],secondStudent);
            }
            else{
                list[i][PairSize[i]]= new Pair(secondStudent,students[i][j]);
            }
        }
        else if((*previous)->getStudentB()!=NULL){
            if((*previous)->getStudentB()->getSex()!=students[i][j]->getSex()){
                list[i][PairSize[i]]= new Pair(secondStudent,students[i][j]);
            }
            else{
                list[i][PairSize[i]]= new Pair(students[i][j],secondStudent);
            }
        }
    }

    *previous=list[i][PairSize[i]];
    PairSize[i]++;
    // we have to sse if there is a second Student or not
    if(secondStudent==NULL)
        return false;
    return true;
}

// create a sequence for the Kindergarden to go on a trip
void Kindergarden::createSequence(){

    Pair* previous=NULL;
    // for each class
    int i;
    for(i=0;i<classes;i++){
        // the flage is if there is no room for the
        // last odd student
        bool flage2=true;
        
        // there is a previous Pair in which 
        // the last studen might have a place to go
        if(previous!=NULL){
            Student* previousA=previous->getStudentA();
            Student* previousB=previous->getStudentB();
            
            // check if there is not a studentA  
            if(previousA==NULL){
                // there is no student A so there is room

                // check if they have opposite sex 
                if(previousB->getSex()!=students[i][size[i]-1]->getSex()){
                    // they do so put it 
                    previous->changeStudents(students[i][size[i]-1],previousB);
                    flage2=false;
                }
            }
            else if(previousB==NULL){
                // there is no student B so there is room

                // check if they have opposite sex 
                if(previousA->getSex()!=students[i][size[i]-1]->getSex()){
                    // they do so put it
                    previous->changeStudents(previousA,students[i][size[i]-1]);
                    flage2=false;
                }
            }
            
        }

        // put the remaining without the last one
        int j;
        for(j=0;j<size[i]-1;j++){

            bool studentsEnterd=putStudentInSequence(&previous,i,j);
            if(studentsEnterd)
                j++;
        }

        // the last student has not a room for him
        if(flage2&&j==size[i]-1){
            // put him in the opposite sex
            if(previous!=NULL){
                if(previous->getStudentA()!=NULL){
                    if(previous->getStudentA()->getSex()!=students[i][size[i]-1]->getSex())
                        list[i][PairSize[i]]= new Pair(students[i][size[i]-1],NULL);
                    else
                        list[i][PairSize[i]]= new Pair(NULL,students[i][size[i]-1]);   
                }
                else
                    if(previous->getStudentB()->getSex()!=students[i][size[i]-1]->getSex())
                        list[i][PairSize[i]]= new Pair(NULL,students[i][size[i]-1]);
                    else
                        list[i][PairSize[i]]= new Pair(students[i][size[i]-1],NULL);   
            
                previous=list[i][PairSize[i]];
                PairSize[i]++;
            }
            else{
                list[i][PairSize[i]]= new Pair(students[i][size[i]-1],NULL);
                previous=list[i][PairSize[i]];
                PairSize[i]++;
            }
        }
    }

}

// print the Seqeunce for each class
void Kindergarden::print()const{
    int i;
    for(i=0;i<classes;i++){
        // print the Seqeunce of the class
        for(int j=0;j<PairSize[i];j++){
            list[i][j]->print();
        }
        if(list[i][0]==NULL)    
            std::cout<<"There is no sequence in this class\n";
        
        // print if there were naughty or not
        if(T[i]<Tquiet*maxStudents)
            std::cout<<"what a quiet class!\n";
        else if(T[i]>Tmessy*maxStudents)
            std::cout<<"what a mess!\n";
        else 
            std::cout<<"Please, be quiet!\n";
    }
}


// change the Pair
void Kindergarden::changePairs(Pair* Pair,Student* current,Student* change){
    bool flage=false;
    // see if there is a StudentA
    if(Pair->getStudentA()!=NULL){
        // see if the StudentA is the student with whom we want to change
        if(Pair->getStudentA()->getSex()==current->getSex()){
            flage=true;
            Pair->changeStudents(change,Pair->getStudentB());
            return;
        }
            
    }

    // see if there is a StudentB
    if(Pair->getStudentB()!=NULL){
        // see if the StudentB is the student with whom we want to change
        if(Pair->getStudentB()->getSex()==current->getSex()){
            Pair->changeStudents(Pair->getStudentA(),change);
            return;
        }
    }

}


// Find the Pair in which student is a part
Pair* Kindergarden::findPair(Student* student){
    // go for every Pair and see if the student is one of the Students of the Pair
    // There is a more efficient way if you set the student to have a Pair
    // but in the description it was said that the Pair is somewhat headen (could not understand)
    int i;
    for(i=0;i<classes;i++)
        for(int j=0;j<PairSize[i];j++)
            if(list[i][j]->getStudentA()==student||list[i][j]->getStudentB()==student){
                return list[i][j];
            }
    return NULL;
}

// Find a student to replace the naughty
void Kindergarden::replaceStudent(int theClass,int naughtyClass,Student* naughty){
    // search for infinite
    int k=0;
    while(true){
        // take a randomStudent
        int randomStudent=(int)size[theClass]*((double)rand()/((double)RAND_MAX));
        Student* student=students[theClass][randomStudent];
        // if the student is the same with the naughty then we dont want it
        if(student==naughty)
            continue;
	//if(k>20){
          //  std::cout<<"There is no student avalaible to change\n";
           // return ;
        //}
        k++;
        // if the student has a the same sex then it is the student that we want 
        if(student->getSex()==naughty->getSex()&&naughty!=student){
            // find each Pair
            Pair* Pair1=findPair(naughty);
            Pair* Pair2=findPair(student);
            
            std::cout<<"\nThe naughty kid:\n";
            naughty->print();
            std::cout<<"Changes with the kid:\n";
            student->print();
	    std::cout<<"\n";

            std::cout<<"The Pairs which are being changed are:\n";
            Pair1->print();
            Pair2->print();

            // change the Pairs 
            changePairs(Pair1,naughty,student);
            changePairs(Pair2,student,naughty);

            // the student is not anymore Naughty
            naughty->setMessy(false);
            break;
        }
    }
    // The class had mess
    T[theClass]++;
}

//  change Places of The naughty Students
void Kindergarden::changeNaughtyStudents(){
    // check if there is a Sequence
    for(int i=0;i<classes;i++)
        if(size[i]==0){
            // if there is not then create one
            createSequence();
            break;
        }

    // put in an array of naughty poeple the naughty poeple
    // so it is easier to find them
    int naughtySize=0;
    Student** naughty= new Student*[classes*maxStudents];
    int* naughtyClass= new int[classes];
    for(int i=0;i<classes;i++){
        naughtyClass[i]=0;
        for(int j=0;j<size[i];j++)
            if(students[i][j]->getMessy()){
                naughty[naughtySize]=students[i][j];
                naughtyClass[i]++;
                naughtySize++;
            }
    }

    int j=0;
    int whichClass=0;
    bool flage=false;
    // for every naughty poeple
    std::cout<<"Naughty kids:\n";
    for(int i=0;i<naughtySize;i++)
        naughty[i]->print();
    std::cout<<"\n";
    for(int i=0;i<naughtySize;i++){

        Pair* current=findPair(naughty[i]);
        // if the have a diffrence class
        // then find the class in which he naughty is in
        if(naughty[i]->getClass()!=j){
            i--;
            j++;
            continue;
        }

        // if the Pair of the naughty is not naughty
        // then only the student has to move
        if(!current->isMessy()){
            replaceStudent(j,j,naughty[i]);
        }
        // all the Pair is naughty
        else{
            // fidnd the next Pair
            Pair* next;
            bool tempFlage=false;

            for(int k=0;k<classes;k++){
                for(int l=0;l<PairSize[k];l++){
                    // find the current Pair
                    if(current==list[k][l]){
                        // and see if it is the last or not
                        // if it is not then there is a next
                        // if it is then there is not a next
                        if( l<PairSize[k]-1)
                            next=list[k][l+1];
                        else
                            next=NULL;
                        tempFlage=true;
                        break;
                    }
                }
                // we have found the Pair then go out
                if(tempFlage)
                    break;
            }

            if(next==NULL)
                next=current;
            // check if the next Pair is messy or the previous Pair
            // was messy( it is not anymore because we have moved them)
            if(next->isMessy()||flage==true){
                // if the previous was messy
                if (flage){
                    // if there is not a next or the next is not messy
                    // then the next and propably the following Pairs 
                    // should not use this function 
                    if(next==current)
                        flage=false;
                    else if(!next->isMessy())
                        flage=false;
                }
                else{
                    // first time in this function
                    // so we begin from the 0 class
                    whichClass=0;
                    flage=true;
                }
                
                // check if there a sequence at the class 
                // whichClass
                // They might have all left (this is in case
                // if the students are only 1)
                while(list[whichClass][0]==NULL) 
                    if(whichClass>=classes)
                        whichClass=0;
                    else
                        whichClass++;

                // replayce the first naughty
                replaceStudent(whichClass,j,naughty[i]);
                
                // find the next class to replace the following naughty
                if(whichClass>=classes-1)
                    whichClass=0;
                else 
                    whichClass++;

                // check if there a sequence at the class 
                // whichClass
                // They might have all left (this is in case
                // if the students are only 1)
                while(list[whichClass][0]==NULL) 
                    if(whichClass>=classes)
                        whichClass=0;
                    else
                        whichClass++;

                // replace the following naughty which is 
                // the second student of Pair
                replaceStudent(whichClass,j,naughty[i+1]);
                
                // find the next class to replace the following naughty
                if(whichClass>=classes-1)
                    whichClass=0;
                else 
                    whichClass++;              


                // we have seen 2 naughty not 1 so i must go up by 2
                i++;
            }
            else {
                // the Pair was naughty alone
                
                // find a the next class which has a sequence 
                int nextClass=j;
                do{
                   nextClass++;
                   if(nextClass>=classes)
                       nextClass=0;
	        }while(list[nextClass][0]==NULL);

                // replayce the first naughty
                replaceStudent(nextClass,j,naughty[i]);
                                
                // replace the following naughty which is 
                // the second student of Pair
                replaceStudent(nextClass,j,naughty[i+1]);

                // we have seen 2 naughty not 1 so i must go up by 2
                i++;
            }
        }
    }

    // delete the arrays that we have created 
    delete[] naughtyClass;
    delete[] naughty;
}

// takes random students and makes them naughty
// then the function change their location
void Kindergarden::createMess(int times){
    srand(time(NULL));
    // find a random student and say that he has made a mess 
    for(int i=0;i<times;i++){
        int whichStudent;
        int whichClass;
        do{
            whichClass=(int)classes*((double)rand()/((double)RAND_MAX));
            whichStudent=(int)size[whichClass]*((double)rand()/((double)RAND_MAX));
        }while (students[whichClass][whichStudent]->getMessy());
        students[whichClass][whichStudent]->setMessy(true);
    }

    // change the naughty Students
    changeNaughtyStudents();
}
