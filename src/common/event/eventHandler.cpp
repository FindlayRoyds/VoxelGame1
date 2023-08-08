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
    event::setServer(server);
}

EventHandler::EventHandler(Client* client)
: networkHandler(false)
{
    isServer = false;
    this -> client = client;
    event::setClient(client);
}

void EventHandler::pollEvents()
{
    for (auto const& event : networkHandler.PollEvent()) {
        switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT: {
                ConnectionRequest::eventDataStruct eventData;
                eventData.peer = event.peer;
                eventData.test = "hello";
                ConnectionRequest::process(eventData);
                break;
            }
            case ENET_EVENT_TYPE_RECEIVE: {
                enet_uint8* rawData = event.packet->data;
                uint8_t typeNum;
                memcpy(&typeNum, rawData, sizeof(typeNum));
                
                switch (typeNum) {
                    case event::eventType::connectionRequest: {
                        break;
                    }
                    case event::eventType::playerAdded: {
                        playerAdded::eventDataStruct eventData;
                        memcpy(&eventData, rawData+1, sizeof(eventData));
                        std::cout << eventData.playerID << std::endl;
                        playerAdded::processEvent(eventData);
                        break;
                    }
                    case event::eventType::playerLeaving: {
                        break;
                    }
                }
                break;
            }
            case ENET_EVENT_TYPE_DISCONNECT:
                break;
            case ENET_EVENT_TYPE_NONE:
                break;
        }
    }
}


