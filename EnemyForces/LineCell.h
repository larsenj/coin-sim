#ifndef LINECELL_H
#define LINECELL_H

#include "Cell.h"
#include <iostream>

class LineCell:public Cell {
    private:
        int supplies;
        bool leader;
        bool supplier;
    public:
        LineCell();
        LineCell(int, int);
        inline bool hasLeader() { return leader; }
        inline bool setLeader(bool ldr) { leader = ldr; }
        inline bool isSupplied() { return supplier; }
        inline bool setSupplied(bool sup) { supplier = sup; }
        inline int getSupplies() { return supplies; }
};

#endif
