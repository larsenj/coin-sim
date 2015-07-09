/*
    GhkCo.cpp
*/

#include "GhkCo.h"
#include <vector>
#include <iostream>

GhkCo::GhkCo(int parentID, int childNum){
    ID = parentID + (childNum * 10000); //so look for X's in 007XX0000
    int i = 1;
    for (; i < 4; i++)
        GhkVector.emplace_back(new GhkGroup(ID, i));
    GhkHQ.emplace_back(new LdrCell(ID + i, 5, 3, 100, true, true)); //add leadership
    i++; 
    GhkHQ.emplace_back(new SctCell(ID + i, 5, 2)); //add scouts
    i++; 
    GhkHQ.emplace_back(new LogCell(ID + i, 5, 2, 100, true, true)); //add logistics
    i++; 
    GhkHQ.emplace_back(new MedCell(ID + i, 5, 1, 100)); //add medical
}

void GhkCo::printMemberIDs(){
    std::cout << "Groups:" << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << GhkVector[i]->getID() << std::endl;
    std::cout << "HQ:" << std::endl; 
    for (int i = 0; i < 4; i++)
        std::cout << GhkHQ[i]->getType() << " " << GhkHQ[i]->getID() << std::endl;
}

int GhkCo::weekEvents(){
    std::cout << "Week events for Company " << ID << std::endl;
    wEvents = 0;
    int maxV = GhkVector.size();
    for(int i = 0; i < maxV; i++)
        wEvents += GhkVector[i]->weekEvents();
    int maxH = GhkHQ.size();
    for(int j = 0; j < 7; j++){
        std::cout << "\tCompany HQ elements day " << j+1 << std::endl;
        for (int k = 0; k < maxH; k++)
            if(GhkHQ[k]->event(8)) //hardcoding 8 as max for now
                wEvents++;
    }
    return wEvents; 
}

GhkCo::~GhkCo(){
    std::cout << "Deleting GhkCo " << getID() << std::endl;
}
