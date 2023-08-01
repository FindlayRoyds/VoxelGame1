//
//  server.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 3/07/23.
//

#include "server.hpp"

Server::Server()
: eventHandler(this)
{
    
}

void Server::run()
{
    ENetPeer* client = nullptr;
    bool connectedToClient = false;
    
    int i = 0;
    while (true) {
        eventHandler.pollEvents();
        
        if (connectedToClient) {
            //std::string m = "packet" + std::to_string(i);
            int m = i;
            ENetPacket * packet = enet_packet_create (&m,
                                                      sizeof (m) + 1,
                                                      ENET_PACKET_FLAG_RELIABLE);
            enet_peer_send (client, 0, packet);
            i++;
        }
    }
}

void Server::addPlayer()
{
    puts("pretty good");
}
