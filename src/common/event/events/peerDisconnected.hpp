//
//  peerDisconnected.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 9/08/23.
//

#ifndef peerDisconnected_hpp
#define peerDisconnected_hpp

#include <stdio.h>
#include <enet/enet.h>

#include "event.hpp"
#include "server.hpp"

class PeerDisconnected: public Event
{
public:
    struct eventDataStruct {
        ENetPeer* peer;
    };
    static void process(eventDataStruct eventData);
};

#endif /* peerDisconnected_hpp */
