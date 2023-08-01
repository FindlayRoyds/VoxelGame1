//
//  connectionRequest.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 1/08/23.
//

#include <stdio.h>
#include "eventHandler.hpp"
#include "server.hpp"

void EventHandler::connectionRequest(ENetPeer*)
{
    puts("a new client was connected");
    server -> addPlayer();
}
