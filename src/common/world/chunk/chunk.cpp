//
//  chunk.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 18/08/23.
//

#include "chunk.hpp"

Chunk::Chunk(glm::ivec3 position)
:position()
{
    this->position = position;
    for (int i = 0; i < 32*32*32; i++) {
        Block* newBlock = new Block(i % 2);
        blocks[i] = newBlock;
    }
}

void Chunk::printPosition() {
    std::cout << glm::to_string(position) << std::endl;
}

Block* Chunk::getBlock(glm::ivec3 position) {
    return blocks[getBlockIndexFromPosition(position)];
}

int Chunk::getBlockIndexFromPosition(glm::ivec3 position) {
    return position.x + position.y * 32 + position.z * 32 * 32;
}
