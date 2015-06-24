/*
    MedCell.h
    Medical support, will not be dedicated EF at lower levels
*/

#ifndef MEDCELL_H
#define MEDCELL_H

#include "Cells.h"

class MedCell:public Cells {
    private:
        int supplies; //keep this in for use later
        //bool leader;  no leaders at lower levels
        //bool supplier; not supplied by EF at lower levels 

    public:
        MedCell();
        MedCell(int, int, int, int);
        //inline bool hasLeader() { return leader; }
        //inline bool setLeader(bool ldr) { leader = ldr; }
        //inline bool isSupplied() { return supplier; }
        //inline bool setSupplied(bool sup) { supplier = sup; }
        ~MedCell();
};

#endif
