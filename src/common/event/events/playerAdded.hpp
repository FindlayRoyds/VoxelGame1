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
        std::string name;
    };
    static void processEvent(eventDataStruct eventData);
};

#endif
