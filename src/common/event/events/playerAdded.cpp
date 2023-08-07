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

void playerAdded::processEvent(eventDataStruct eventData)
{
    std::cout << "player " + eventData.name + " has joined the game" << std::endl;
}
