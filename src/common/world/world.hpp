//
//  world.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 11/08/23.
//

#ifndef world_hpp
#define world_hpp

#include <stdio.h>

#include "chunkManager.hpp"

class World
{
public:
    World();
private:
    ChunkManager chunkManager;
};

#endif /* world_hpp */
