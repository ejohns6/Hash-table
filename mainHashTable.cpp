/**************************************************************
** File:    mainHashTable.cpp
** Project: CMSC 341 Project 5, Spring 2016
** Author:  Erich Johnson
** Date:    5/10/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   This file does what was described in the header
**
**************************************************************/
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>


#include "mainHashTable.h"

//does nothing
mainHashTable::mainHashTable(){

}

//does what it say in the header
mainHashTable::mainHashTable(int _size){
    m_secondaryHashTable = new secondaryHashTable[_size];
    m_size = _size;
    Prime1 = 16890581;
    Prime2 = 17027399;
    srand(0);
    //sets c, a, and b in the way was described in the proj description
    _c = rand() % Prime1 + 1;
    _a = rand() % Prime2 + 1;
    _b = rand() % Prime2;
}

mainHashTable::~mainHashTable(){
    //deletes the array of secondary Hash tables
    delete [] m_secondaryHashTable;
}

void mainHashTable::insertCity(std::string cityNameStateName, std::string latitude, std::string longitude){
    //THE G FUNCTION
    unsigned long long g = 0;
    for(unsigned int i = 0; i < cityNameStateName.size(); i++){
        g = (g*_c)/* % Prime1*/;
        g = (g + cityNameStateName[i]) % Prime1;
    }


    //THE H FUNCTION
    unsigned long long Prime2 = 17027399;
    unsigned long long x = (_a * g + _b) % Prime2;
    x = x % m_size;
    //pushes in the x loction of the array
    m_secondaryHashTable[x].pushBackPRE(cityNameStateName, latitude, longitude);


}



void mainHashTable::print(){
    //prints as stated in the proj description
    std::cout << "\np1:" << Prime1 << std::endl;
    std::cout << "p2:" << Prime2 << std::endl;
    std::cout << "a:" << _a << std::endl;
    std::cout << "b:" << _b << std::endl;
    std::cout << "c:" << _c << std::endl;
    std::cout << "\n" << std::endl;

    int amountOfSecondaryHash = 0;
    int amountWith0 = 0;
    int amountWith1 = 0;
    int amountWith2 = 0;
    int amountWith3 = 0;
    int amountWith4 = 0;
    int amountWith5 = 0;
    int amountWith6 = 0;
    int amountWith7 = 0;
    int amountWith8 = 0;
    int amountWith9 = 0;
    int amountWithMoreThan9 = 0;
    int SlotWithMostCollisions = 0;
    for(int i = 0; i < m_size; i++){
            if(m_secondaryHashTable[i].getAmountInSecondary() == 0){
                amountWith0++;
            }else if(m_secondaryHashTable[i].getAmountInSecondary() == 1){
                amountWith1++;
            }else if(m_secondaryHashTable[i].getAmountInSecondary() == 2){
                amountWith2++;
            }else if(m_secondaryHashTable[i].getAmountInSecondary() == 3){
                amountWith3++;
            }else if(m_secondaryHashTable[i].getAmountInSecondary() == 4){
                amountWith4++;
            }else if(m_secondaryHashTable[i].getAmountInSecondary() == 5){
                amountWith5++;
            }else if(m_secondaryHashTable[i].getAmountInSecondary() == 6){
                amountWith6++;
            }else if(m_secondaryHashTable[i].getAmountInSecondary() == 7){
                amountWith7++;
            }else if(m_secondaryHashTable[i].getAmountInSecondary() == 8){
                amountWith8++;
            }else if(m_secondaryHashTable[i].getAmountInSecondary() == 9){
                amountWith9++;
            }else{
                amountWithMoreThan9++;
            }
            if(m_secondaryHashTable[i].getAmountInSecondary() > 0){
                amountOfSecondaryHash++;
            }
            if(m_secondaryHashTable[SlotWithMostCollisions].getAmountInSecondary() < m_secondaryHashTable[i].getAmountInSecondary()){
                SlotWithMostCollisions = i;
            }
    }
    std::cout << "number of cities: " << m_size << std::endl;
    std::cout << "maximum collisions: " << m_secondaryHashTable[SlotWithMostCollisions].getAmountInSecondary() << std::endl;
    std::cout << "# primary slots with 0 cities: " << amountWith0 << std::endl;
    std::cout << "# primary slots with 1 cities: " << amountWith1 << std::endl;
    std::cout << "# primary slots with 2 cities: " << amountWith2 << std::endl;
    std::cout << "# primary slots with 3 cities: " << amountWith3 << std::endl;
    std::cout << "# primary slots with 4 cities: " << amountWith4 << std::endl;
    std::cout << "# primary slots with 5 cities: " << amountWith5 << std::endl;
    std::cout << "# primary slots with 6 cities: " << amountWith6 << std::endl;
    std::cout << "# primary slots with 7 cities: " << amountWith7 << std::endl;
    std::cout << "# primary slots with 8 cities: " << amountWith8 << std::endl;
    std::cout << "# primary slots with 9 cities: " << amountWith9 << std::endl;
    std::cout << "** cities in the slot with most collisions **" << std::endl;
    m_secondaryHashTable[SlotWithMostCollisions].print();

    int oneTriedToHash = 0;
    int twoTriedToHash = 0;
    int threeTriedToHash = 0;
    int fourTriedToHash = 0;
    int fiveTriedToHash = 0;
    int sixTriedToHash = 0;
    int sevenTriedToHash = 0;
    int eightTriedToHash = 0;
    int nineTriedToHash = 0;
    int tenTriedToHash = 0;
    //int moreThenTentried = 0;
    int a = 0;
    int amountOfSecondaryHashTablesWithMoreThanOneItem = amountWith2  + amountWith3 + amountWith4 + amountWith5 + amountWith6 + amountWith7 + amountWith8 + amountWith9 + amountWithMoreThan9;
    float averageHashFunctionsTried = 0;
    for(int i = 0; i < m_size; i++){
        if(m_secondaryHashTable[i].getAmountInSecondary() > 1){
            unsigned long long amountOfxHashFunctionsForCurrentTable = m_secondaryHashTable[i].getSeed();
            if(amountOfxHashFunctionsForCurrentTable == 0){
                oneTriedToHash++;
            }else if(amountOfxHashFunctionsForCurrentTable == 1){
                twoTriedToHash++;
            }else if(amountOfxHashFunctionsForCurrentTable == 2){
                threeTriedToHash++;
            }else if(amountOfxHashFunctionsForCurrentTable == 3){
                fourTriedToHash++;
            }else if(amountOfxHashFunctionsForCurrentTable == 4){
                fiveTriedToHash++;
            }else if(amountOfxHashFunctionsForCurrentTable == 5){
                sixTriedToHash++;
            }else if(amountOfxHashFunctionsForCurrentTable == 6){
                sevenTriedToHash++;
            }else if(amountOfxHashFunctionsForCurrentTable == 7){
                eightTriedToHash++;
            }else if(amountOfxHashFunctionsForCurrentTable == 8){
                nineTriedToHash++;
            }else if(amountOfxHashFunctionsForCurrentTable == 9){
                tenTriedToHash++;
            }//else{
              //  moreThenTentried++;
            //}
            averageHashFunctionsTried += amountOfxHashFunctionsForCurrentTable+1;
            a++;
        }
    }
    averageHashFunctionsTried = averageHashFunctionsTried/amountOfSecondaryHashTablesWithMoreThanOneItem;
    std::cout << "# secondary hash tables trying 1 hash functions: " << oneTriedToHash << std::endl;
    std::cout << "# secondary hash tables trying 2 hash functions: " << twoTriedToHash << std::endl;
    std::cout << "# secondary hash tables trying 3 hash functions: " << threeTriedToHash << std::endl;
    std::cout << "# secondary hash tables trying 4 hash functions: " << fourTriedToHash << std::endl;
    std::cout << "# secondary hash tables trying 5 hash functions: " << fiveTriedToHash << std::endl;
    std::cout << "# secondary hash tables trying 6 hash functions: " << sixTriedToHash << std::endl;
    std::cout << "# secondary hash tables trying 7 hash functions: " << sevenTriedToHash << std::endl;
    std::cout << "# secondary hash tables trying 8 hash functions: " << eightTriedToHash << std::endl;
    std::cout << "# secondary hash tables trying 9 hash functions: " << nineTriedToHash << std::endl;
    std::cout << "# secondary hash tables trying 10 hash functions: " << tenTriedToHash << std::endl;
    //std::cout << "# secondary hash tables trying 10+ hash functions: " << moreThenTentried << std::endl;
    std::cout << "number of secondary hash tables with more than one item: " << amountOfSecondaryHashTablesWithMoreThanOneItem << std::endl;
    std::cout << "avreage # of hash functions tried: " << averageHashFunctionsTried << std::endl;
}

void mainHashTable::finish(){
    //calls the finilazation of each secondary hash table
   for(int i = 0; i < m_size; i++){
        m_secondaryHashTable[i].finishSecondary();
    }
}

std::string mainHashTable::searching(std::string cityNameStateName){
    //THE G FUNCTION
    unsigned long long g = 0;
    for(unsigned int i = 0; i < cityNameStateName.size(); i++){
        g = (g*_c)/* % Prime1*/;
        g = (g + cityNameStateName[i]) % Prime1;
    }
    //THE H FUNCTION
    unsigned long long x = (_a * g + _b) % Prime2;
    x = x % m_size;
    //finds the slot that is wanted from the search and checks to see if secondary hash table is empty
    if(m_secondaryHashTable[x].getAmountInSecondary() > 0){
        //std::cout << "city details: Key = " << x << std::endl;
        std::string key = "city details: Key = ";
        std::stringstream convert;
        convert << x;
        key += convert.str() + "\n";
        std::string location = m_secondaryHashTable[x].searching(cityNameStateName);
        if(location == "N/A"){
            key = location;
        }else{
            key += location;
        }
        return(key);
    }else{
        return("N/A");
    }

}
