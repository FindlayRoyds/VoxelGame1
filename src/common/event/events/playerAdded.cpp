//
//  playerAdded.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 1/08/23.
//

#include "playerAdded.hpp"

#include <iostream>
#include <stdio.h>
#include <string>
#include <any>

#include "event.hpp"

void PlayerAdded::process(eventDataStruct eventData)
{
    if (!eventData.isLocalPlayer) {
        std::cout << "player with ID " << eventData.playerID << " has joined the game" << std::endl;
    } else {
        std::cout << "player ID: " << eventData.playerID << std::endl;
    }
}
