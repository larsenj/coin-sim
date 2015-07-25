/*
 *  Cell.h
 *  Base class for all cells.
 *
 */

#ifndef CELL_H
#define CELL_H

#include<string>

enum CellType { line, ldr, log, sct, med };

class Cell {
    protected:
        int ID;
        int members;
        int randNum;
        CellType cType;
        int power;
        int wCount = 0;
        int higherID;
        bool isAlive;

    public:
        Cell();
        Cell(int);
        Cell(int, CellType, int, int);//name,type,members,pwr
        Cell(int, CellType, int, int, int);//name,type,members,pwr,higher
        bool event(int);
        const char* cellName[5] = { "line", "ldr", "log", "scout", "med" };
        virtual bool HandleMessage(){};
        ~Cell();

        /*-----Getters and Setters -----*/
        inline CellType getCellType() { return cType;}
        std::string getType(); 
        inline void setIsAlive(bool n) { isAlive = n; }
        inline bool getIsAlive() { return isAlive; }
        inline void setHigherID(int n) { higherID = n; }
        inline int getHigherID(int n) { return higherID; }
        inline int getWeekCount() { return wCount; }
        inline int getPower() { return power; }
        inline int getID() { return ID; }
        //virtual functions below added to prevent "slicing" in vector<Cell*>
        virtual bool hasLeader(){}; 
        virtual void setLeader(){}; 
        virtual bool isSupplied(){}; 
        virtual void setSupplied(){}; 
        virtual int getSupplies(){};
};

#endif
