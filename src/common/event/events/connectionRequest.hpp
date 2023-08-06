#ifndef connectionRequest_hpp
#define connectionRequest_hpp

#include <stdio.h>
#include <enet/enet.h>

#include "eventHandler.hpp"
#include "server.hpp"
#include "event.hpp"

class ConnectionRequest: public event
{
public:
    struct eventDataStruct {
        ENetPeer* peer;
        std::string test;
    };
    static void process(eventDataStruct eventData);
};


#endif /* event_hpp */
