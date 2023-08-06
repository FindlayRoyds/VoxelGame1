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
#include "events/connectionRequest.hpp"
#include "events/playerAdded.hpp"

#include "networkHandler.hpp"

// forward declaration to allow event handler access to server and client instance
class Server;
class Client;

class EventHandler
{
public:
    EventHandler(Server* server);
    EventHandler(Client* client);
    static void sendEvent(ENetPeer* peer, event::eventType eventName, std::any eventData);
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
