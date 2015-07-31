/*
 * Name: EFOrg
 * Author: Jon Larsen
 * Description: The purpose of this iteration is to test creating the line and
 *              block hierarchy of forces
 */

#include <vector>
#include <thread>
#include <cstdlib>
#include <iostream>
#include "Province.h"

//using namespace std; 

void provinceEvents(Province* P);
int validInput();
void printSummary(int num, Province** theater);

int main(int argc, char* argv[]){
    
    
    //check for correct usage
    if (argc != 2) {
        std::cerr << "Usage: Coin [number of threads]\n";
        return 1;
    }

    //initialize the array of provinces
    std::cout << "Enter the number of provinces: ";
    int numProvinces = validInput();

    Province** theater = new Province*[numProvinces];

    std::string provinceName;
    int numDistricts;

    //populate the theater
    for (int i = 0; i < numProvinces; i++){
        std::cin.ignore(10, '\n'); //deal with the C++ trailing endline problem
        std::cout << "Enter the name of province #" << i+1 << " : ";
        getline(std::cin, provinceName);
        std::cout << "How many districts in " << provinceName << "? ";
        numDistricts = validInput();

        theater[i] = new Province(provinceName, i+1, numDistricts);
    }

    //loop for SIGACTS
    int numThreads = atoi(argv[1]);
    char goAgain;
    do {

        //code without multithreading
        /*for (int i = 0; i < numProvinces; i++){
            theater[i]->weekEvents();
        }*/
        
        
        if(numThreads >= numProvinces) {
            std::vector<std::thread> threads;
            for (int i = 0; i < numProvinces; i++)
                threads.push_back(std::thread(provinceEvents, theater[i]));
            for(auto& thread : threads)
                thread.join();  
        } 
        else {
            //if (numProvinces % numThreads == 0) {
            for(int i = 0; i < numProvinces;){
            std::vector<std::thread> threads;
                for (int t = 0; t < numThreads && i < numProvinces; t++){
                    threads.push_back(std::thread(provinceEvents, theater[i]));
                    i++;
                }//t
                for(auto& thread : threads)
                    thread.join();  
            }//i
        }

        for (int j = 0; j < numProvinces; j++)
            theater[j]->weekEvents();

        printSummary(numProvinces, theater);

        std::cout << "Run another week?(y/n) ";
        std::cin >> goAgain;
    } while (goAgain == 'y');

}//end main

void provinceEvents(Province* P){
    P->weekEvents();
}

void printSummary(int num, Province** theater){
    std::cout << "\nSummary:" << std::endl;
    for (int k = 0; k < num; k++)
        std::cout << "\t" << theater[k]->getName() << " had " << 
            theater[k]->getWeekCount() << " SIGACTS." << std::endl;
}

int validInput(){
    int x;
    std::cin >> x;
    while(std::cin.fail() || x <= 0){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "You must enter a positive number: ";
        std::cin >> x;
    }
    return x;
}
