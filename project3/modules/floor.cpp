#include <iostream>
#include <floor.h>

#define NUMCLASS 6

Floor::Floor(const unsigned numberFloor,const unsigned sizeClass):
    floor(numberFloor){
    std::cout<<"A new Floor with number " <<floor<<" is being created\n";
    classes=new TheClass*[NUMCLASS];
    for (unsigned i=0;i<NUMCLASS;i++){
        if(i<3)
            classes[i]= new TheClass(floor,i,sizeClass);
        else
            classes[i]= new TheClass(floor,i,sizeClass);
    }
    corridor=new Corridor(numberFloor);
}


Floor::~Floor(){
    for (int i=0;i<NUMCLASS;i++)
        delete classes[i];
    delete[] classes;
    delete corridor;
    std::cout<<"A Floor with number " <<floor<<" to be destroyed\n";
}

TheClass& Floor::getClass(int index) const{
    return *(classes[index]);
}

Corridor& Floor::getCorridor() const{
    return *corridor;
}

void Floor::print()const{
    std::cout<<"Floor number "<<floor<<" contains:\n";
    for(int i=0;i<NUMCLASS;i++)
        classes[i]->print();
    corridor->print();

}