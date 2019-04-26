#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <vector>
#include <iostream>


struct Node
{


    std::string m_cityNameStateName;
    std::string m_latitude;
    std::string m_longitude;
    bool m_isEmpty;
    unsigned int m_timesNeedToReHash;

    //input: N/A
    //output: N/A
    //Descriptaion: sets isEmpty to true
    Node(){
        m_isEmpty = true;


    }

    //input: city name state name, lat and long
    //output: N/A
    //Descriptaion: creates a node to the given info
    Node(std::string cityNameStateName, std::string latitude, std::string longitude)
    :m_cityNameStateName(cityNameStateName), m_latitude(latitude), m_longitude(longitude), m_isEmpty(false)
    {

    }


    //input: N/A
    //output: N/A
    //Descriptaion: deconstructs
    ~Node(){

    }


};
#endif // NODE_H_INCLUDED
