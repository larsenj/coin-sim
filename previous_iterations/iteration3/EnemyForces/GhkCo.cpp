/*
    GhkCo.cpp
*/

#include <vector>
#include <iostream>
#include "GhkCo.h"
#include "../EntityManager.h"

GhkCo::GhkCo(int parentID, int childNum){
    ID = parentID + (childNum * 10000); //so look for X's in 007XX0000
    for (int i = 1; i < 4; i++)
        GhkVector.emplace_back(new GhkGroup(ID, i));
    buildHQ(ID);
}

void GhkCo::printMemberIDs(){
    std::cout << "Groups:" << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << GhkVector[i]->getID() << std::endl;
    std::cout << "HQ:" << std::endl; 
    for (int i = 0; i < 4; i++)
        std::cout << GhkHQ[i]->getType() << " " << GhkHQ[i]->getID() << std::endl;
}

//call each cell's dayEvents() 7 times, storing results in an array
int GhkCo::weekEvents(){
    std::cout << "Week events for Company " << ID << std::endl;
    wEvents = 0;
    int maxV = GhkVector.size();

    //calculate week events from subordinate units
    for(int i = 0; i < maxV; i++)
        wEvents += GhkVector[i]->weekEvents();
    int maxH = GhkHQ.size();
    
    //calculate week events from HQ & staff element
    for(int j = 0; j < 7; j++){
        std::cout << "\tCompany HQ elements day " << j+1 << std::endl;
        for (int k = 0; k < maxH; k++)
            if(GhkHQ[k]->event(8)) { //hardcoding 8 as max for now
                wEvents++;
                daySIG[j]++;
        }
    }
    return wEvents; 
}

//build the HQ and staff element into the GhkHQ vector, and register with EM
void GhkCo::buildHQ(int ID){
    int i = GhkVector.size() + 1;
    int ldrID = ID+6;
    GhkHQ.emplace_back(new LogCell(ID + i, 2, ldrID)); //add logistics
    EntityMgr->RegisterEntity(GhkHQ.back());
    i++; 
    GhkHQ.emplace_back(new SctCell(ID + i, 2, ldrID)); //add scouts
    EntityMgr->RegisterEntity(GhkHQ.back());
    i++; 
    GhkHQ.emplace_back(new LdrCell(ID + i, 3)); //add leadership
    EntityMgr->RegisterEntity(GhkHQ.back());
    i++; 
    GhkHQ.emplace_back(new MedCell(ID + i, 1, ldrID)); //add medical
    EntityMgr->RegisterEntity(GhkHQ.back());

    //create the Co Ldr's list of staff and subordinate leaders
    if(GhkHQ[2]->getCellType() == ldr){
        //create a temporary vector of subordinate ldr cells
        int gvSize = GhkVector.size();
        std::vector<Cell*> GhkTmp(gvSize);
        int tmpID;
        for (int j = 0; j < gvSize; j++){
            tmpID = GhkVector[j]->getHQID(2);
            GhkTmp[j] = EntityMgr->GetEntityFromID(tmpID);            
        }
        //pass in temp vector and hq vector to build function
        GhkHQ[2]->buildLdrC2(GhkTmp, GhkHQ);
    } 

}

    
GhkCo::~GhkCo(){
    std::cout << "Deleting GhkCo " << getID() << std::endl;
}
