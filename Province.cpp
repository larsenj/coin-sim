/*
    Province.cpp
*/
#include "Province.h"
#include <string>
#include <vector>

Province::Province(std::string pName) : name(pName) {}//end constructor

Province::Province(std::string pName, int pID, int groups){
    name = pName;
    ID = pID * 10000000; 
    int eID = ID + 7000000;//using 7 to denote ef (FF will be something else)
    stability = 50;
    //populate ef vector
    for(int i = 0; i < groups; i++){
        efVector.emplace_back(new GhkCo(eID, i+1));    
    }
}//end constructor

Province::Province(std::string pName, int pID, int groups, int stab):
    name(pName), ID(pID * 10000000), stability(stab){
    int eID = ID + 7000000;//using 7 to denote ef (FF will be something else)
    //populate ef vector
    for(int i = 0; i < groups; i++){
        efVector.emplace_back(new GhkCo(eID, i+1));    
    }
}//end constructor

//run the week, determining how many SIGACTS happened
void Province::weekEvents(){
    wCount = 0;
    int num = efVector.size();

    //count SIGACTS for the week
    for (int i = 0; i < num; i++){    
        wCount += efVector[i]->weekEvents();
    }
}//end weekEvents
