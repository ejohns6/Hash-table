/**************************************************************
** File:    mainHashTable.h
** Project: CMSC 341 Project 5, Spring 2016
** Author:  Erich Johnson
** Date:    5/10/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   This file is the header which creates the main hash table
**
**************************************************************/
#ifndef MAINHASHTABLE_H_INCLUDED
#define MAINHASHTABLE_H_INCLUDED

#include "secondaryHashTable.h"

class mainHashTable
    {
    public:

        //should never be used
        mainHashTable();

        //input:the amount of data going to input
        //output:an initialized hash table with n size and the a, b, and c will be made
        //Descriptaion: initialized hash table with n size and the a, b, and c will be made
        mainHashTable(int _size);

        //input:N/A
        //output:N/A
        //Descriptaion: deconstructs the mainHashTable
        ~mainHashTable();

        //input:the parced data
        //output: N/A
        //Descriptaion: inserts the data into the right slot
        void insertCity(std::string cityNameStateName, std::string latitude, std::string longitude);

        //input: N/A
        //output: N/A
        //Descriptaion: prints the data that was required from the sample output
        void print();

        //input: N/A
        //output: N/A
        //Descriptaion: finalizes each secondary hash table
        void finish();

        //input: string
        //output: places name, key, and location
        //Descriptaion: finds the location with only two disk access
        std::string searching(std::string cityNameStateName);
    private:
        secondaryHashTable* m_secondaryHashTable;
        int m_size;

        unsigned long long Prime1;
        unsigned long long Prime2;
        unsigned long long _a;
        unsigned long long _b;
        unsigned long long _c;




};

#endif // MAINHASHTABLE_H_INCLUDED
