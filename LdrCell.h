/*
    LdrCell.h
    Leadership provides coordination for all subordinate cell activity and 
    with higher elements.
*/

#ifndef LDRCELL_H
#define LDRCELL_H

#include "Cell.h"

class LdrCell:public Cell {
    private:
        int supplies;
        bool leader;
        bool supplier;

    public:
        LdrCell();
        LdrCell(int, int, int, int, bool, bool);
        inline bool hasLeader() { return leader; }
        inline bool setLeader(bool ldr) { leader = ldr; }
        inline bool isSupplied() { return supplier; }
        inline bool setSupplied(bool sup) { supplier = sup; }
};

#endif
