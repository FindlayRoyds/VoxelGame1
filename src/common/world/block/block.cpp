//
//  block.cpp
//  VoxelGame1
//
//  Created by Findlay Royds on 30/06/23.
//

#include "block.hpp"

const Block::blockInfo Block::blockInfos[] = {
    {0, "air"},
    {1, "dirt"}
};

Block::Block(u_int8_t blockID) {
    this->blockID = blockID;
}

u_int8_t Block::getID() {
    return blockID;
}

std::string Block::getName() {
    return blockInfos[getID()].name;
}

