/**
    LineCell.cpp
    This is your basic frontline cell. Currently it will be used
    for all SIGACTS
*/
#include <iostream>
#include "LineCell.h"

LineCell::LineCell(int n, int pwr):Cell(n, line, 5, pwr), supplies(100), leader(true), supplier(true){std::cout<<"Creating LineCell " << n << std::endl;}



