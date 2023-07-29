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

#include "event.hpp"

class EventHandler {
public:
    EventHandler(bool isServer);
    void pollEvents();
private:
    bool isServer;
    std::unordered_map<std::string, Event> eventMap;
};

#endif /* eventHandler_hpp */
