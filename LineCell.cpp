/**
    LineCell.cpp
    This is your basic frontline cell. Currently it will be used
    for all SIGACTS
*/
#include <iostream>
#include "LineCell.h"

LineCell::LineCell(int n, int num, int pwr, int stock, bool lead, bool sup):Cells(n, line, num, pwr), supplies(stock), leader(lead), supplier(sup){}

LineCell::~LineCell(){
        std::cout << "Deleting "  << cellName[line] << " cell " << getID() << std::endl;
    }


