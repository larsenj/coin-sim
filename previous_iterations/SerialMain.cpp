/*
 * Name: ThreadCells
 * Author: Jon Larsen
 * Description:
 *
 */


 


//#include "Cells.h"
#include <stdio.h>
#include <iostream>
#include "Province.h"

using namespace std; 

int main(){
    
    int numProvinces;
    
    //initialize the array of provinces
    cout << "Enter the number of provinces: ";
    cin >> numProvinces;
    Province** theater = new Province*[numProvinces];

    std::string provinceName;
    int numCells;

    //populate the theater
    for (int i = 0; i < numProvinces; i++){
        cin.ignore(10, '\n'); //deal with the C++ trailing endline problem
        cout << "Enter the name of province #" << i+1 << " : ";
        getline(cin, provinceName);
        cout << "How many cells estimated in " << provinceName << "? ";
        cin >> numCells;

        theater[i] = new Province(provinceName, numCells);
    }

    //loop for SIGACTS
    char goAgain;
    do {

        //set up multithreading for this loop
        for (int i = 0; i < numProvinces; i++){
            theater[i]->weekEvents();
        }

        for (int j = 0; j < numProvinces; j++)
            theater[j]->weekRollup();

        cout << "\nSummary:" << endl;
        for (int k = 0; k < numProvinces; k++)
            cout << "\t" << theater[k]->name << " had " << theater[k]->getWeekCount() << " SIGACTS." << endl;

        cout << "Run another week?(y/n) ";
        cin >> goAgain;
    } while (goAgain == 'y');

}//end main
