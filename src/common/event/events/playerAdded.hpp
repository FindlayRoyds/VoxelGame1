#ifndef playerAdded_hpp
#define playerAdded_hpp

#include <stdio.h>
#include <string>
#include <any>

#include "event.hpp"

class playerAdded: public event
{
public:
    
    struct eventDataStruct {
        unsigned int playerID;
        bool isLocalPlayer;
        int test = 12;
    };
    static void processEvent(eventDataStruct eventData);
};

#endif
