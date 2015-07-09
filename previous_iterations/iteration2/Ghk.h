/*
   Ghk.h 
   Base class for ef hierarchy. Level depends on what the vector holds.
*/
#ifndef GHK_H
#define GHK_H

#include <vector>
#include "CellWrapper.h"
#include <memory>

template <typename T>
class Ghk {
    protected:
        int ID;
        int wEvents;
        std::vector<std::unique_ptr<T>> GhkVector; //vector to hold next level down
        std::vector<std::unique_ptr<Cell>> GhkHQ; //holds HQ and staff cells

    public:
        Ghk(){}
        Ghk(int);//ID
        inline int getID() { return ID; }
        inline int getWeekEvents() { return wEvents; }
        //~Ghk();
};

#endif
