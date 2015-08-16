/*
    GhkCo.h
    A Ghk Company operates at the distric level. It will have 3 groups and a 
    HQ/staff element. Staff elements may still be just coopted infrastructure.
*/

#ifndef GHKCO_H
#define GHKCO_H

#include "GhkGroup.h"

class GhkCo : public Ghk<GhkGroup> {
    private:

    public:
        GhkCo(int, int); //parentID, childNum
        void printMemberIDs();
        int weekEvents();
        void buildHQ(int);
        ~GhkCo();
};

#endif
