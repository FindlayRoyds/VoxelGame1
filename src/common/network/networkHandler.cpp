//
//  enetWrapper.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 1/07/23.
//

#include "networkHandler.hpp"

NetworkHandler::NetworkHandler(bool isServer)
{
    address.port = 7776;
    
    if (isServer) {
        address.host = ENET_HOST_ANY;
        host = enet_host_create(&address, 32, 1, 0, 0);
    } else {
        host = enet_host_create(NULL, 1, 1, 0, 0);
        enet_address_set_host(&address, "127.0.0.1");
    }
    
    if (host == NULL) {
        fprintf(stderr, "An error occurred while trying to create an ENet server host.\n");
        exit(EXIT_FAILURE);
    }
    
    if (!isServer) {
        ENetEvent event;
        
        server = enet_host_connect(host, &address, 1, 0);
        if (server == NULL) {
            std::cout << "Connected to server peer failed" << std::endl;
        }
        
        if (enet_host_service(host, &event, 5000) > 0
            && event.type == ENET_EVENT_TYPE_CONNECT) {
            puts("connection succeeded");
        } else {
            enet_peer_reset(server);
            puts("connection failed");
        }
    }
}


std::list<ENetEvent> NetworkHandler::PollEvent()
{
    std::list<ENetEvent> events;
    ENetEvent* event = new ENetEvent;
    while (enet_host_service(host, event, 0) > 0) {
        events.push_back(*event);
        event = new ENetEvent;
    }
    return events;
}

ENetPeer* NetworkHandler::getServer()
{
    return this -> server;
}
