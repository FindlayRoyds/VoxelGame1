#ifndef peerConnection_hpp
#define peerConnection_hpp

#include <stdio.h>
#include <enet/enet.h>

#include "eventHandler.hpp"
#include "server.hpp"
#include "event.hpp"

class PeerConnected: public Event
{
public:
    struct eventDataStruct {
        ENetPeer* peer;
    };
    static void process(eventDataStruct eventData);
};


#endif /* event_hpp */
