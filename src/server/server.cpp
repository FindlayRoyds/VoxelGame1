//
//  server.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 3/07/23.
//

#include "server.hpp"

void Server::run() {
    EventHandler eventHandler(true); 
    NetworkHandler networkHandler(true);
    
    ENetPeer* client = nullptr;
    bool connectedToClient = false;
    
    int i = 0;
    while (true) {
        for (auto const& event : networkHandler.PollEvent()) {
            switch (event.type) {
                case ENET_EVENT_TYPE_CONNECT:
                    std::cout << "A new client connected" << std::endl;
                    client = event.peer;
                    connectedToClient = true;
                    break;
                case ENET_EVENT_TYPE_RECEIVE:
                    std::cout << "A packet was recieved" << std::endl;
                    break;
                case ENET_EVENT_TYPE_DISCONNECT:
                    std::cout << "A peer was disconnected" << std::endl;
                    break;
                case ENET_EVENT_TYPE_NONE:
                    std::cout << "None type event recieved" << std::endl;
                    break;
            }
        }
        
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
