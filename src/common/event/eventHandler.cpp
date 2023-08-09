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
    Event::setServer(server);
}

EventHandler::EventHandler(Client* client)
: networkHandler(false)
{
    isServer = false;
    this -> client = client;
    Event::setClient(client);
}

void EventHandler::pollEvents()
{
    for (auto const& event : networkHandler.PollEvent()) {
        switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT: {
                PeerConnected::eventDataStruct eventData;
                eventData.peer = event.peer;
                PeerConnected::process(eventData);
                break;
            }
            case ENET_EVENT_TYPE_RECEIVE: {
                enet_uint8* rawData = event.packet->data;
                uint8_t typeNum;
                memcpy(&typeNum, rawData, sizeof(typeNum));
                
                switch (typeNum) {
                    case Event::eventType::connectionRequest: {
                        break;
                    }
                    case Event::eventType::playerAdded: {
                        PlayerAdded::eventDataStruct eventData;
                        memcpy(&eventData, rawData+1, sizeof(eventData));
                        PlayerAdded::process(eventData);
                        break;
                    }
                    case Event::eventType::playerLeaving: {
                        PlayerLeaving::eventDataStruct eventData;
                        memcpy(&eventData, rawData+1, sizeof(eventData));
                        PlayerLeaving::process(eventData);
                    }
                }
                break;
            }
            case ENET_EVENT_TYPE_DISCONNECT:
                PeerDisconnected::eventDataStruct eventData;
                eventData.peer = event.peer;
                PeerDisconnected::process(eventData);
                break;
            case ENET_EVENT_TYPE_NONE:
                break;
        }
    }
}


