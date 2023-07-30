//
//  connectionRequest.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 31/07/23.
//

#include <stdio.h>
#include "../event.hpp"

class ConnectionRequest: public Event {
public:
    ConnectionRequest() {
        //eventName = "connectionRequest";
    }
    void process(nlohmann::json eventData) {
        
    }
};
