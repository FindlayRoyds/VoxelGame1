//
//  eventHandler.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 5/07/23.
//

#include "eventHandler.hpp"
#include "server.hpp"
#include "client.hpp"

EventHandler::EventHandler(Server* server)
: networkHandler(true)
{
    isServer = true;
    this -> server = server;
}

EventHandler::EventHandler(Client* client)
: networkHandler(false)
{
    isServer = false;
    this -> client = client;
}

void EventHandler::pollEvents()
{
    for (auto const& event : networkHandler.PollEvent()) {
        switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                connectionRequest(event.peer);
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                break;
            case ENET_EVENT_TYPE_NONE:
                break;
        }
    }
}
