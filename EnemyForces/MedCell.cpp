/*
    MedCell.cpp
    Medical support, will not be dedicated EF at lower levels
*/

#include <iostream>
#include "MedCell.h"

MedCell::MedCell(int n, int pwr):Cell(n, med, 3, pwr), supplies(100){}

MedCell::MedCell(int n, int pwr, int higher):Cell(n, med, 3, pwr, higher), supplies(100){}


