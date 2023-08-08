//
//  playerLeaving.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 7/08/23.
//

#include "playerLeaving.hpp"

#include <iostream>

void PlayerLeaving::process(eventDataStruct eventData)
{
    std::cout << "player with ID " << eventData.playerID << " has left the game" << std::endl;
}
