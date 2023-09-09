//
//  chunkManager.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 15/08/23.
//

#ifndef chunkManager_hpp
#define chunkManager_hpp

#include <stdio.h>
#include <unordered_map>
#include <map>
#include <tuple>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/hash.hpp"

#include "tupleHash.hpp"
#include "chunk.hpp"

class ChunkManager
{
public:
    ChunkManager();
    Chunk* getChunk(glm::ivec3);
private:
    void generateChunk(glm::ivec3);
    bool isChunkGenerated(glm::ivec3);
    
    std::unordered_map<glm::ivec3, Chunk*> chunkMap;
};

#endif /* chunkManager_hpp */
