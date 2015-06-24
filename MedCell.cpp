/*
    MedCell.cpp
    Medical support, will not be dedicated EF at lower levels
*/

#include <iostream>
#include "MedCell.h"

MedCell::MedCell(int n, int num, int pwr, int stock):Cells(n, med, num, pwr), supplies(stock){}

MedCell::~MedCell(){
        std::cout << "Deleting "  << cellName[med] << " cell " << getID() << std::endl;
    }


