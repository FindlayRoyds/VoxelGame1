//
//  peerConnected.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 9/08/23.
//

#include "peerDisconnected.hpp"

void PeerDisconnected::process(PeerDisconnected::eventDataStruct eventData) {
    server -> removePlayer(eventData.peer);
}
