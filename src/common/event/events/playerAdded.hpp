#ifndef playerAdded_hpp
#define playerAdded_hpp

#include <stdio.h>
#include <string>
#include <any>

#include "event.hpp"

class PlayerAdded: public Event
{
public:
    
    struct eventDataStruct {
        unsigned int playerID;
        bool isLocalPlayer;
    };
    static void process(eventDataStruct eventData);
};

#endif
