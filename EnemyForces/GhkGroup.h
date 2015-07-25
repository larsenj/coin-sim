/*
    GhkGroup.h
    Level that operates at lower then the district level - village-ish level. 
    Has an HQ/staff, though they are commonly just representative of civilian 
    infrastructure(and not implemented here)
*/

#ifndef GHKGROUP_H
#define GHKGROUP_H

#include "Ghk.h"

class GhkGroup : public Ghk<Cell> {
    private:
    
    public:
        //GhkGroup();
        GhkGroup(int, int); //parentID, childNum
        int getCellID(int);
        int dayEvents();
        int weekEvents();
        void buildHQ(int);
        //void registerCell(Cell*, bool);    
        ~GhkGroup();
};

#endif
