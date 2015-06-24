/*
    LdrCell.cpp
    Leadership provides coordination for all subordinate cell activity and 
    with higher elements.
*/
#include <iostream>
#include "LdrCell.h"

LdrCell::LdrCell(int n, int num, int pwr, int stock, bool lead, bool sup):Cells(n, ldr, num, pwr), supplies(stock), leader(lead), supplier(sup){}

LdrCell::~LdrCell(){
        std::cout << "Deleting "  << cellName[ldr] << " cell " << getID() << std::endl;
    }


