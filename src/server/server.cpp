//
//  server.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 3/07/23.
//

#include "server.hpp"

Server::Server()
: world()
{
    EventHandler eventHandler(this);
    
    puts("server initialised");
    
    while (true) {
        eventHandler.pollEvents();
    }
}

void Server::addPlayer(ENetPeer* peer)
{
    unsigned int newPlayerID = ++maxPlayerID;
    Player newPlayer;
    players[newPlayerID] = newPlayer;
    peers[newPlayerID] = peer;
    playerIDs[peer] = newPlayerID;
    
    for (auto& otherPeer: peers) {
        PlayerAdded::eventDataStruct eventData;
        eventData.playerID = newPlayerID;
        eventData.isLocalPlayer = otherPeer.second == peer;
        EventHandler::sendEvent(otherPeer.second, Event::eventType::playerAdded, eventData);
    }
}


void Server::removePlayer(ENetPeer* peer)
{
    unsigned int playerID = playerIDs[peer];
    players.erase(playerID);
    peers.erase(playerID);
    playerIDs.erase(peer);
    
    for (auto& otherPeer: peers) {
        PlayerLeaving::eventDataStruct eventData;
        eventData.playerID = playerID;
        EventHandler::sendEvent(otherPeer.second, Event::eventType::playerLeaving, eventData);
    }
}
