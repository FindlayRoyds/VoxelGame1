//
//  event.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 3/08/23.
//

#ifndef event_hpp
#define event_hpp

#include <stdio.h>
#include <any>
#include <string>

class Server;
class Client;

class event
{
public:
    inline static bool isServer;
    inline static Server* server;
    inline static Client* client;
    static void processEvent(std::any eventData);
    static void setServer(Server* serverP) {
        isServer = true;
        server = serverP;
    }
    static void setClient(Client* clientP) {
        isServer = false;
        client = clientP;
    }
    enum eventType {
        connectionRequest,
        playerAdded
    };
    struct eventDataWrapper {
        eventType eventName;
        const char* eventData;
    };
protected:
    
};

//Server* event::server;
//Client* event::client;
//bool event::isServer;

#endif /* event_hpp */
