//
//  host.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 1/07/23.
//

#ifndef networkHandler_hpp
#define networkHandler_hpp

#include <stdio.h>
#include <iostream>
#include <enet/enet.h>
#include <list>

class NetworkHandler {
public:
    NetworkHandler(bool isServer);
    std::list<ENetEvent> PollEvent();
    ENetPeer* getServer();
private:
    ENetAddress address;
    ENetHost* host;
    ENetPeer* server = nullptr;
};

#endif /* networkHandler_hpp */
