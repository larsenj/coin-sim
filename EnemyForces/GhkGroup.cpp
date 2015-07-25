/*
    GhkGroup.cpp
*/

#include <vector>
#include <iostream>
#include <memory>
#include "GhkGroup.h"
#include "../EntityManager.h"

/*void GhkGroup::registerCell(Cell* x, bool lineVector){
    EntityMgr->RegisterEntity(x);
    (lineVector) ? GhkVector.push_back(x) : GhkHQ.push_back(x);
}*/

GhkGroup::GhkGroup(int parentID, int childNum){
    ID = parentID + (childNum * 100); //so look for the X's in 00700XX00
    
    /*
    LineCell* L1(new LineCell(ID+1, 10));
    registerCell(L1, true);
    LineCell* L2(new LineCell(ID+2, 10));
    registerCell(L2, true);
    LineCell* L3(new LineCell(ID+3, 10));
    registerCell(L3, true);
    */

    //create 3 line cells
    for (int i = 1; i < 4; i++){
        GhkVector.emplace_back(new LineCell(ID+i, 10, ID+6));
        EntityMgr->RegisterEntity(GhkVector.back());
    }

    //create HQ and staff element
    buildHQ(ID);    

/*    
    std::cout << "testing stuff" <<std::endl;
//    std::cout << "L1 hasLeader is " << L1->hasLeader() << std::endl;
    std::cout << "[0] type is " << GhkVector[0]->getType() << std::endl;
    std::cout << "GhkVector[0] hasLeader is " << GhkVector[0]->hasLeader() << std::endl;
//    std::cout << "L1 address = " << L1 << std::endl;
    std::cout << "[0] address = " << GhkVector[0] << std::endl;
//    L1->setLeader(false);
//    std::cout << "L1 hasLeader is " << L1->hasLeader() << std::endl;
//    std::cout << "L1 supplies = " << L1->getSupplies() << std::endl;
    std::cout << "[0] supplies = " << GhkVector[0]->getSupplies() << std::endl;
*/

}


void GhkGroup::buildHQ(int ID){
    int i = GhkVector.size() + 1;
    GhkHQ.emplace_back(new LogCell(ID + i, 2)); //add stics
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
