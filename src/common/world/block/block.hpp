//
//  block.hpp
//  VoxelGame1
//
//  Created by Findlay Royds on 30/06/23.
//

#ifndef block_hpp
#define block_hpp

#include <stdio.h>
#include <string>

class Block
{
public:
    Block(u_int8_t blockID);
    u_int8_t getID();
    std::string getName();
private:
    u_int8_t blockID;
    struct blockInfo {
        u_int8_t id;
        std::string name;
    };
    static const blockInfo blockInfos[];
};

#endif /* block_hpp */
