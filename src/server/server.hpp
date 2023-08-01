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
#include <thread>
#include <chrono>

#include "eventHandler.hpp"

class Server
{
public:
    Server();
    void addPlayer();
};

#endif /* server_hpp */
