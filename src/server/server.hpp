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

#include "../common/network/networkHandler.hpp"
#include "../common/event/eventHandler.hpp"

class Server {
public:
    void run();
};

#endif /* server_hpp */
