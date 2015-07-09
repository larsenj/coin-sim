#ifndef CELLS_H
#define CELLS_H

class Cells {
    private:
        int cellNumber;
        int members;
        int supplies;
        bool leader;
        bool supplier;
        int randNum;
    public:
        Cells();
        Cells(int);
        Cells(int, int, int);
        bool hasLeadership();
        bool isSupplied();
        bool event();
};

#endif
