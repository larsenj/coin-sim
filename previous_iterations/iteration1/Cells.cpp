#include "Cells.h"
#include <time.h>
#include <stdlib.h>

Cells::Cells(int name){
    cellNumber = name;
    members = 5;
    supplies = 100;
    leader = true;
    supplier = true;
    srand(time(NULL) + cellNumber);//cellNumber is added to avoid multiple cells having the same seed
}

Cells::Cells(int name, int numMembers, int stock){
    cellNumber = name;
    members = numMembers;
    supplies = stock;
    leader = true;
    supplier = true;
    srand(time(NULL) + cellNumber);
}

bool Cells::hasLeadership(){
    if (leader)
        return true;
    return false;
}

bool Cells::isSupplied(){
    if (supplier)
       return true;
    return false; 
}

bool Cells::event(){
    randNum = rand() % 9 + 1;
    
    //return false if unable to conduct operations
    if(!leader || supplies < 33 || members < 3 || randNum < 8) {
        //if unable to conduct ops, and logistics available, then resupply
        if(supplies < 33 && isSupplied())
            supplies += 10;        
        //if (isSupplied())
            //supplies += 10;
        return false;
    }

    supplies -= 30;
    return true;
}
