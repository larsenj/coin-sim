#include "Cells.h"
#include <time.h>
#include <stdlib.h>

Cells::Cells(int name){
    ID = name;
    members = 5;
    cellType = line;
    srand(time(NULL) + ID);//cellNumber is added to avoid multiple cells having the same seed
}

Cells::Cells(int name, cell type, int numMembers, int pwr){
    ID = name;
    cellType = type;
    members = numMembers;
    power = pwr;
    srand(time(NULL) + ID);
}

//Fix this, or make virtual, or move
bool Cells::event(int chance){
    randNum = rand() % 9 + 1;
/*    
    //return false if unable to conduct operations
    if(!leader || supplies < 33 || members < 3 || randNum < chance) {
        //if unable to conduct ops, and logistics available, then resupply
        if(supplies < 33 && isSupplied())
            supplies += 10;        
        //if (isSupplied())
            //supplies += 10;
        return false;
    }

    supplies -= 30;
    return true;*/
}
