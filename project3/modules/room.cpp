#include <room.h>
#include <student.h>

Room::Room(const int maxSize): max(maxSize){}

void Room::enter(Student* newStudent){
    if(newStudent==NULL){
        students.pop_back();
        return;
    }

    students.push_back(newStudent);
    
}

void Room::print() const{
    if(students.size()!=0)
        for(int i=0;i<students.size();i++){
            std::cout<<"Student:\n"; 
            students.at(i)->printName();
        }
    
}

Student* Room::getStudent(int index)const{
    if(index>=max||index<0||index>=students.size())
        return NULL;
    return students.at(index);
}