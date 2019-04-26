/**************************************************************
** File:    secondaryHashTable.cpp
** Project: CMSC 341 Project 5, Spring 2016
** Author:  Erich Johnson
** Date:    5/10/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   This file does what was stated in the header
**
**************************************************************/
#include <stdlib.h>
#include <iostream>
#include <string>

#include "secondaryHashTable.h"

secondaryHashTable::secondaryHashTable(){
    numberOfCollisions = 0;
    m_seed = 0;
    Prime1 = 16890581;
    Prime2 = 17027399;
}



secondaryHashTable::~secondaryHashTable(){
    //deletes prePerfect info which is vector in oder that came in
    for(int i = 0; i < m_amountInSecondary; i++){
        delete m_prePerfect[i];
    }
    //delete the hash table
    delete [] m_postPerfect;

}

void secondaryHashTable::pushBackPRE(std::string cityNameStateName, std::string latitude, std::string longitude){
    //inserts the data to the back of the prePerfect
    Node* temp = new Node(cityNameStateName, latitude, longitude);
    m_prePerfect.push_back(temp);

}

unsigned long long secondaryHashTable::getAmountInSecondary(){
    return(m_amountInSecondary);
}

unsigned long long secondaryHashTable::getSlotsInSecondary(){
    return(m_amountInSecondary*m_amountInSecondary);
}

void secondaryHashTable::finishSecondary(){
    m_amountInSecondary = m_prePerfect.size();

    Node* temp_postPerfect;
    bool noColisions;
    do{
        //makes hash table the amount in secondary squared
        temp_postPerfect = new Node[m_amountInSecondary*m_amountInSecondary];
        //calculates a, b, and c
        recalibration();
        noColisions = true;
        for(int i = 0; i < m_amountInSecondary; i++){
            //calculates the slot location
            unsigned int x;
            x = gFunctionHfunction(m_prePerfect[i]->m_cityNameStateName);
            //checks to see slot is empties
            if(temp_postPerfect[x].m_isEmpty == false){
                //makes sure will jump out of for loop
                i += m_amountInSecondary;
                noColisions = false;
                //deletes the hash table so to be able to remake without leak
                delete [] temp_postPerfect;
            }else{
                //set x slot at the node
                temp_postPerfect[x] = *m_prePerfect[i];
            }
        }
        if(noColisions == false){
            //increases seed by 1 if there was a colision
            m_seed++;
        }
        //goes until there is not a colision
    }while(noColisions == false);
    //sets postPerfect to the temp which is now a perfect hash
    m_postPerfect = temp_postPerfect;
}


int secondaryHashTable::gFunctionHfunction(std::string cityNameStateName){



    //THE G FUNCTION
    unsigned long long g = 0;
    for(unsigned int i = 0; i < cityNameStateName.length(); i++){
        g = ((g * _c) + cityNameStateName[i]) % Prime1;
    }
    //THE H FUNCTION

    unsigned long long x = (_a * g + _b) % Prime2;
    x = x % getSlotsInSecondary();
    return(x);
}


void secondaryHashTable::recalibration(){
    //caluclates a,b, and c
    srand(m_seed);
    _c = (rand() % Prime1 + 1);
    _a = (rand() % Prime2 + 1);
    _b = (rand() % Prime2);
}

void secondaryHashTable::print(){
    //prints in abc order
    for(unsigned int i = 0; i < getAmountInSecondary(); i++){
        std::cout << m_prePerfect[i]->m_cityNameStateName << " (" << m_prePerfect[i]->m_latitude << " " << m_prePerfect[i]->m_longitude << ")" << std::endl;
    }
}

std::string secondaryHashTable::searching(std::string cityNameStateName){
    //gets slot that the string would be placed in
    int x;
    std::string toBeReturned;
    x = gFunctionHfunction(cityNameStateName);
    //checks to see if string is there and if it matches
    if(m_postPerfect[x].m_isEmpty == false and m_postPerfect[x].m_cityNameStateName == cityNameStateName){
        toBeReturned = m_postPerfect[x].m_cityNameStateName + " (" + m_postPerfect[x].m_latitude + " " + m_postPerfect[x].m_longitude + ")\n";
        return(toBeReturned);
    }else{
        //returns N/A
         return("N/A");
    }
}

unsigned int secondaryHashTable::getSeed(){
    //gets the seed
    return(m_seed);
}



