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
                event::eventDataWrapper wrappedEventData;
                memcpy(&wrappedEventData, rawData, sizeof(wrappedEventData));
                std::cout << wrappedEventData.eventName << std::endl;
                switch (wrappedEventData.eventName) {
                    case event::eventType::connectionRequest: {
                        break;
                    }
                    case event::eventType::playerAdded: {
                        /*playerAdded::eventDataStruct eventData;
                        memcpy(&eventData, wrappedEventData.eventData, sizeof(*wrappedEventData.eventData));
                        std::cout << sizeof(eventData) << std::endl;*/
                        playerAdded::eventDataStruct eventData = std::any_cast<playerAdded::eventDataStruct>(wrappedEventData.eventData);
                        playerAdded::processEvent(eventData);
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

void EventHandler::sendEvent(ENetPeer* peer, event::eventType eventName, std::any eventData)
{
    event::eventDataWrapper  wrappedPacketData;
    wrappedPacketData.eventName = eventName;
    wrappedPacketData.eventData = eventData;
    
    const void* newData[sizeof(wrappedPacketData)];
    memcpy(&newData, &wrappedPacketData, sizeof(event::eventDataWrapper));
    
    ENetPacket * packet = enet_packet_create (newData,
                                              sizeof (newData) + 1,
                                              ENET_PACKET_FLAG_RELIABLE);
    enet_peer_send(peer, 0, packet);
}
