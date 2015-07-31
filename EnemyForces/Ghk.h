/*
   Ghk.h 
   Base class for ef hierarchy. Level depends on what the vector holds.
*/
#ifndef GHK_H
#define GHK_H

#include <vector>
#include <memory>
#include "CellWrapper.h"

template <typename T>
class Ghk {
    protected:
        int ID;
        int wEvents;
        int daySIG[7];
        std::vector<T*> GhkVector; //vector to hold next level down
        std::vector<Cell*> GhkHQ; //holds HQ and staff cells

    public:
        Ghk(){}
        Ghk(int);//ID
        //void buildHQ(int);
        inline int getCellID(int index) {return GhkVector[index]->ID;}
        inline int getHQID(int index) {
            int tempID = ID;
            return tempID;}
        inline int getDaySig(int day) { return daySIG[day]; }
        inline int getID() { return ID; }
        inline int getWeekEvents() { return wEvents; }
        //~Ghk();
};

#endif
