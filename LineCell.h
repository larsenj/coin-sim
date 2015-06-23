#ifndef LINECELL_H
#define LINECELL_H

#include "Cells.h"

class LineCell:public Cells {
    private:
        int supplies;
        bool leader;
        bool supplier;

    public:
        LineCell();
        LineCell(int, int, int, int, bool, bool);
        inline bool hasLeader() { return leader; }
        inline bool setLeader(bool ldr) { leader = ldr; }
        inline bool isSupplied() { return supplier; }
        inline bool setSupplied(bool sup) { supplier = sup; }
        ~LineCell();
};

#endif
