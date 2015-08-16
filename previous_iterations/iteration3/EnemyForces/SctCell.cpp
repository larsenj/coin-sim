/*
    SctCell.cpp
    Scout cell. At lower levels will not be dedicated EF.    
*/

#include <iostream>
#include "SctCell.h"

SctCell::SctCell(int n, int pwr):Cell(n, sct, 3, pwr){}

SctCell::SctCell(int n, int pwr, int higher):Cell(n, sct, 3, pwr, higher){}


