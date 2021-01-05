#pragma once
#include <iostream>
#include "class.h"
#include "corridor.h"

class Floor{
    private:
        const unsigned floor;
        TheClass** classes;
        Corridor* corridor;

    public:
        Floor(const unsigned,const unsigned );
        ~Floor();

        TheClass& getClass(int) const;
        Corridor& getCorridor() const;

        void print()const;
};