//
//  chunk.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 18/08/23.
//

#ifndef chunk_hpp
#define chunk_hpp

#include <stdio.h>
#include <iostream>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include "block.hpp"
#include "air.hpp"
#include "dirt.hpp"

class Chunk {
public:
    Chunk(glm::ivec3 position);
    void printPosition();
    Block* getBlock(glm::ivec3 position);
private:
    int getBlockIndexFromPosition(glm::ivec3 position);
    glm::ivec3 getBlockPositionFromIndex(int blockIndex);
    
    glm::ivec3 position;
    Block* blocks[32*32*32];
};

#endif /* chunk_hpp */
