//
//  connectionRequest.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 1/08/23.
//

#include "connectionRequest.hpp"

void ConnectionRequest::process(eventDataStruct eventData) {
    playerAdded::eventDataStruct newEventData;
    newEventData.name = "bob";
    EventHandler::sendEvent(eventData.peer, event::eventType::playerAdded, newEventData);
}

