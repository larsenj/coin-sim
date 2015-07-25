/*
    LdrCell.cpp
    Leadership provides coordination for all subordinate cell activity and 
    with higher elements.
*/
#include <iostream>
#include "LdrCell.h"

LdrCell::LdrCell(int n, int pwr):Cell(n, ldr, 5, pwr), supplies(100), leader(true), supplier(true){}



