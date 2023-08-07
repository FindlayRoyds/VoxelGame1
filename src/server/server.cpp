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
    while (true) {
        eventHandler.pollEvents();
    }
}

void Server::addPlayer(ENetPeer* peer)
{
    puts("joined");
}
