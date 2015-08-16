/*
    GhkGroup.cpp
*/

#include <vector>
#include <iostream>
#include <memory>
#include "GhkGroup.h"
#include "../EntityManager.h"


GhkGroup::GhkGroup(int parentID, int childNum){
    ID = parentID + (childNum * 100); //so look for the X's in 00700XX00
    
    //create 3 line cells
    for (int i = 1; i < 4; i++){
        GhkVector.emplace_back(new LineCell(ID+i, 10, ID+6));
        EntityMgr->RegisterEntity(GhkVector.back());
    }

    //create HQ and staff element
    buildHQ(ID);    

    //ensure Leader Cell is tracking all its people
    if(GhkHQ[2]->getCellType() == ldr)
        GhkHQ[2]->buildLdrC2(GhkVector, GhkHQ);
}


void GhkGroup::buildHQ(int ID){
    int i = GhkVector.size() + 1;
    int ldrID = ID+6;
    GhkHQ.emplace_back(new LogCell(ID + i, 2, ldrID)); //add logistics
    EntityMgr->RegisterEntity(GhkHQ.back());
    i++; 
    GhkHQ.emplace_back(new SctCell(ID + i, 2)); //add scouts
    EntityMgr->RegisterEntity(GhkHQ.back());
    i++; 
    GhkHQ.emplace_back(new LdrCell(ID + i, 3)); //add leadership
    EntityMgr->RegisterEntity(GhkHQ.back());
    i++; 
    GhkHQ.emplace_back(new MedCell(ID + i, 1)); //add medical
    EntityMgr->RegisterEntity(GhkHQ.back());
}

/*
int GhkGroup::getCellID(int index){
    return GhkVector[index]->getID();
}
*/

int GhkGroup::dayEvents(){
    int count = 0;
    int maxV = GhkVector.size();
    for (int i = 0; i < maxV; i++)
        if(GhkVector[i]->event(8)) //hardcoding 8 as max for now
            count++;
    
    //Group level hq element NYI
    int maxH = GhkHQ.size();
    for (int j = 0; j < maxH; j++){
        if(GhkHQ[j]->event(8)) //hardcoding 8 as max for now 
            count++;
    }
    
    return count;
}

int GhkGroup::weekEvents(){
    std::cout << "\tWeek events for Group " << ID << std::endl;
    wEvents = 0;
    for (int i = 0; i < 7; i++)
    {
        std::cout << "\t\tDay " << i+1 << std::endl;    
        daySIG[i] = dayEvents();
        wEvents += daySIG[i];
    }
    return wEvents;
}

GhkGroup::~GhkGroup(){
    std::cout << "Deleting GhkGroup " << getID() << std::endl;
    for (int i = 0; i < GhkVector.size(); i++){
        delete GhkVector[i]; 
    }
    for (int i = 0; i < GhkHQ.size(); i++){
        delete GhkHQ[i]; 
    }
}
