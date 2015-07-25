/*
    SctCell.h
    Scout cell. At lower levels will not be dedicated EF.    
*/

#ifndef SCTCELL_H
#define SCTCELL_H

#include "Cell.h"

class SctCell:public Cell {
    private:
        int supplies;
        //bool leader; No "leader" at lower levels
        //bool supplier; Not supplied by EF at lower levels

    public:
        SctCell();
        SctCell(int, int);
        //inline bool hasLeader() { return leader; }
        //inline bool setLeader(bool ldr) { leader = ldr; }
        //inline bool isSupplied() { return supplier; }
        //inline bool setSupplied(bool sup) { supplier = sup; }
};

#endif
