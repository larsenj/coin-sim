/*
    SctCell.cpp
    Scout cell. At lower levels will not be dedicated EF.    
*/

#include <iostream>
#include "SctCell.h"

SctCell::SctCell(int n, int num, int pwr):Cells(n, sct, num, pwr){}

SctCell::~SctCell(){
        std::cout << "Deleting "  << cellName[sct] << " cell " << getID() << std::endl;
    }


