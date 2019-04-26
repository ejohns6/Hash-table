/**************************************************************
** File:    Project5.cpp
** Project: CMSC 341 Project 5, Spring 2016
** Author:  Erich Johnson
** Date:    5/10/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   This file is the driver it takes in information and
**   makes a perfect hash table
**
**************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
using namespace std;

#include "mainHashTable.h"

string const SEARCH_FOR_CITY = "Ringgold, GA";//data to check if can retrive data

int main(int argc, char *argv[])
{


    int sizeOfMainHash = 0;//keeps track of how many data are sparced
    string filename;//file name of file with data

    if(argc == 2){//checks too see if input has a file
      filename = argv[1];
    }else{
      cout << "Not enough command line arguments." << endl;
      return 0;
    }

    ifstream file(filename.c_str());

    vector<string> cityNameStateName;
    vector<string> latitudeVector;
    vector<string> longitudeVector;

    if(file.is_open()){//checks to see if file is there
        string line;
        string latitude;
        string longitude;

        while(getline(file, line)){//parses the table
            cityNameStateName.push_back(line.c_str());
            sizeOfMainHash++;
            getline(file, line);
            stringstream onLine(line);
            onLine >> latitude >> longitude;
            latitudeVector.push_back((latitude.c_str()));
            longitudeVector.push_back((longitude.c_str()));
        }
    }else{
        cout << "File was not opened." << endl;
        return 0;
    }

    mainHashTable mainHash(sizeOfMainHash);//inputs data to main has table
    for(unsigned int i = 0; i < cityNameStateName.size(); i++){
        mainHash.insertCity(cityNameStateName[i], latitudeVector[i], longitudeVector[i]);
    }
    mainHash.finish();//finalizes the secondary hash tables
    mainHash.print(); //prints the requested info
    cout << mainHash.searching(SEARCH_FOR_CITY) << std::endl;//retrives the infomation to see if it was stored correctly

    file.close();//closes the file

    return 0;
}
