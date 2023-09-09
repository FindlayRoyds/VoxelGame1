//
//  chunkManager.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 15/08/23.
//

#include "chunkManager.hpp"

ChunkManager::ChunkManager() {
    generateChunk(glm::ivec3(0, 0, 0));
    Chunk* testChunk = getChunk(glm::ivec3(0, 0, 0));
    std::cout << testChunk->getBlock(glm::ivec3(1, 2, 3))->getName() << std::endl;
}

Chunk* ChunkManager::getChunk(glm::ivec3 chunkPosition) {
    if (!isChunkGenerated(chunkPosition)) {
        generateChunk(chunkPosition);
    }
    
    return chunkMap[chunkPosition];
}

void ChunkManager::generateChunk(glm::ivec3 chunkPosition) {
    if (isChunkGenerated(chunkPosition)) {return;}
    
    chunkMap[chunkPosition] = new Chunk(chunkPosition);
}

bool ChunkManager::isChunkGenerated(glm::ivec3 chunkPosition) {
    return !(chunkMap.find(chunkPosition) == chunkMap.end());
}
