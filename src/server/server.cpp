//
//  server.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 3/07/23.
//

#include "server.hpp"

Server::Server()
{
    EventHandler eventHandler(this);
    ENetPeer* client = nullptr;
    bool connectedToClient = false;
    
    int i = 0;
    while (true) {
        eventHandler.pollEvents();
    }
}

void Server::addPlayer()
{
    puts("pretty good");
}
