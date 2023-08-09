//
//  server.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 3/07/23.
//

#ifndef server_hpp
#define server_hpp

#include <stdio.h>
#include <enet/enet.h>
#include <unordered_map>

#include "eventHandler.hpp"
#include "event.hpp"
#include "playerAdded.hpp"
#include "player.hpp"

class Server
{
public:
    Server();
    void addPlayer(ENetPeer* peer);
    void removePlayer(ENetPeer* peer);
private:
    std::unordered_map<unsigned int, ENetPeer*> peers;
    std::unordered_map<unsigned int, Player> players;
    std::unordered_map<ENetPeer*, unsigned int> playerIDs;
    unsigned int maxPlayerID = 0;
};

#endif /* server_hpp */
