#include "Cell.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Cell::Cell(int name){
    ID = name;
    members = 5;
    cType = line;
    srand(time(NULL) + ID);//cellNumber is added to avoid multiple cells having the same seed
}

Cell::Cell(int name, CellType type, int numMembers, int pwr){
    ID = name;
    cType = type;
    members = numMembers;
    power = pwr;
    srand(time(NULL) + ID);
    //std::cout << "Creating cell " << name << std::endl;
}

//Fix this, or make virtual, or move
bool Cell::event(int chance){
    randNum = rand() % 9 + 1;
    //return false if unable to conduct operations
    //if(!leader || supplies < 33 || members < 3 || randNum < chance) {
    if(randNum < chance) {
        //if unable to conduct ops, and logistics available, then resupply
        //if(supplies < 33 && isSupplied())
        //    supplies += 10;        
        //if (isSupplied())
            //supplies += 10;
        std::cout << cellName[cType] << " cell " << ID << " did nothing." << std::endl;
        return false;
    }

    //supplies -= 30;
    std::cout << cellName[cType] << " cell " << ID << " performed an action." << std::endl;
    return true;
}

Cell::~Cell(){
        std::cout << "Deleting "  << cellName[cType] << " Cell " << getID() << std::endl;
    }

