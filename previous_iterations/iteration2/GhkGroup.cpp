/*
    GhkGroup.cpp
*/

#include "GhkGroup.h"
#include <vector>
#include <iostream>

GhkGroup::GhkGroup(int parentID, int childNum){
    ID = parentID + (childNum * 100); //so look for the X's in 00700XX00
    for (int i = 1; i < 4; i++)
        GhkVector.emplace_back(new LineCell(ID+i, 5, 10, 100, true, true));
}

int GhkGroup::getCellID(int index){
    return GhkVector[index]->getID();
}

int GhkGroup::dayEvents(){
    int count = 0;
    int maxV = GhkVector.size();
    for (int i = 0; i < maxV; i++)
        if(GhkVector[i]->event(8)) //hardcoding 8 as max for now
            count++;
    /*
    //Group level hq element NYI
    int maxH = GhkHQ.size();
    for (int j = 0; j < maxH; j++){
        if(GhkHQ[j]->event(8)) //hardcoding 8 as max for now 
            count++;
    }
    */
    return count;
}

int GhkGroup::weekEvents(){
    std::cout << "\tWeek events for Group " << ID << std::endl;
    wEvents = 0;
    for (int i = 0; i < 7; i++)
    {
        std::cout << "\t\tDay " << i+1 << std::endl;    
        wEvents += dayEvents();
    }
    return wEvents;
}


GhkGroup::~GhkGroup(){
    std::cout << "Deleting GhkGroup " << getID() << std::endl;
}
