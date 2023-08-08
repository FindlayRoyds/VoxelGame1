//
//  playerLeaving.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 7/08/23.
//

#ifndef playerLeaving_hpp
#define playerLeaving_hpp

#include <stdio.h>

#include "event.hpp"

class PlayerLeaving {
public:
    struct eventDataStruct {
        event::eventType eventType = event::eventType::playerLeaving;
        unsigned int playerID;
    };
    void process(eventDataStruct eventData);
};

#endif /* playerLeaving_hpp */
