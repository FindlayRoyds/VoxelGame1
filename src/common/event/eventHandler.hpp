//
//  eventHandler.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 5/07/23.
//

#ifndef eventHandler_hpp
#define eventHandler_hpp

#include <stdio.h>
#include <map>
#include <json/json.hpp>

#include "event.hpp"
#include "events/peerConnected.hpp"
#include "events/peerDisconnected.hpp"
#include "events/playerAdded.hpp"
#include "events/playerLeaving.hpp"

#include "networkHandler.hpp"

// forward declaration to allow event handler access to server and client instance
class Server;
class Client;

class EventHandler
{
public:
    EventHandler(Server* server);
    EventHandler(Client* client);
    template <typename T>
    static void sendEvent(ENetPeer* peer, Event::eventType eventType, T eventData) {
        uint8_t typeNum = eventType;
        char* packetData = new char[sizeof(eventData) + sizeof(typeNum)];
        
        memcpy(packetData + sizeof(typeNum), &eventData, sizeof(eventData));
        memcpy(packetData, &typeNum, sizeof(typeNum));
        
        ENetPacket * packet = enet_packet_create (packetData,
                                                  sizeof (packetData) + 1,
                                                  ENET_PACKET_FLAG_RELIABLE);
        enet_peer_send(peer, 0, packet);
    }
    void pollEvents();
private:
    bool isServer;
    NetworkHandler networkHandler;
    union {
        Server* server;
        Client* client;
    };
};

#endif /* eventHandler_hpp */
