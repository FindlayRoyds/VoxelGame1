//
//  server.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 3/07/23.
//

#include "server.hpp"

Server::Server()
{
    EventHandler eventHandler(this);
    while (true) {
        eventHandler.pollEvents();
    }
}

void Server::addPlayer(ENetPeer* peer)
{
    unsigned int newPlayerID = ++maxPlayerID;
    //std::cout << "a player joined with playerID " << newPlayerID << std::endl;
    Player newPlayer;
    players[newPlayerID] = newPlayer;
    peers[newPlayerID] = peer;
    
    std::cout << newPlayerID << std::endl;
    
    for (auto& otherPeer: peers) {
        playerAdded::eventDataStruct eventData;
        eventData.playerID = newPlayerID;
        eventData.isLocalPlayer = otherPeer.second == peer;
        EventHandler::sendEvent(otherPeer.second, event::eventType::playerAdded, eventData);
    }
}
