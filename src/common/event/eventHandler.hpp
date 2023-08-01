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

#include "networkHandler.hpp"

// forward declaration to allow event handler access to server and client instance
class Server;
class Client;

class EventHandler
{
public:
    EventHandler(Server* server);
    EventHandler(Client* client);
    
    void pollEvents();
private:
    bool isServer;
    NetworkHandler networkHandler;
    union {
        Server* server;
        Client* client;
    };
    // --- events --- //
    
    void connectionRequest(ENetPeer*);
};

#endif /* eventHandler_hpp */
