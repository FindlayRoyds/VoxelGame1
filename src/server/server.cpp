//
//  server.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 3/07/23.
//

#include "server.hpp"

void Server::run() {
    EventHandler eventHandler(true);
    
    ENetPeer* client = nullptr;
    bool connectedToClient = false;
    
    int i = 0;
    while (true) {
        eventHandler.pollEvents();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
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
