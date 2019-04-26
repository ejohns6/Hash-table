/**************************************************************
** File:    secondaryHashTable.h
** Project: CMSC 341 Project 5, Spring 2016
** Author:  Erich Johnson
** Date:    5/10/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   This file is the header which creates the perfect hash table
**
**************************************************************/
#ifndef SECONDARYHASHTABLE_H_INCLUDED
#define SECONDARYHASHTABLE_H_INCLUDED

#include <vector>
#include "Node.h"

class secondaryHashTable
    {
    public:
        Node* m_postPerfect;

        //input: N/A
        //output: N/A
        //Descriptaion: creates an intitilized object
        secondaryHashTable();

        //input: N/A
        //output: N/A
        //Descriptaion: deconstructs an object
        ~secondaryHashTable();

        //input: info that was parsed
        //output: N/A
        //Descriptaion: pushes backs the info into a vector
        void pushBackPRE(std::string cityNameStateName, std::string latitude, std::string longitude);

        //it gets the amount of cities in the class
        unsigned long long getAmountInSecondary();

        //gets the amount of slots needed
        unsigned long long getSlotsInSecondary();

        //input: N/A
        //output: N/A
        //Descriptaion: creates the correct secondary hash table
        void finishSecondary();


        //input: city name and state name
        //output: the slot number
        //Descriptaion: calculates the correct slot to put the city into
        int gFunctionHfunction(std::string cityNameStateName);

        //input: N/A
        //output: N/A
        //Descriptaion: recalculates a b c to the correct seed
        void recalibration();

        //input: N/A
        //output: N/A
        //Descriptaion: prints the data in alphabetic order
        void print();

        //input: cities name
        //output: city name and location
        //Descriptaion: finds the cities location
        std::string searching(std::string cityNameStateName);

        //input: N/A
        //output: N/A
        //Descriptaion: gets the seed
        unsigned int getSeed();

    private:
        std::vector<Node*> m_prePerfect;

        int m_amountInSecondary;

        unsigned int m_seed;

        unsigned long long Prime1;
        unsigned long long Prime2;
        unsigned long long _a;
        unsigned long long _b;
        unsigned long long _c;

        unsigned long long numberOfCollisions;




};

#endif // SECONDARYHASHTABLE_H_INCLUDED
