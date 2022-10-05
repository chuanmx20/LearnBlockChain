//
// Created by 钏茗喜 on 2022/10/5.
//

#ifndef LEARNBLOCKCHAIN_BLOCKCHAIN_H
#define LEARNBLOCKCHAIN_BLOCKCHAIN_H

#include <vector>

#include "../Block/Block.h"

class Blockchain {
    std::vector<Block> blocks;
public:
    Blockchain();
    std::vector<Block> GetBlocks();
    void AddBlock(const std::string& data);
};


#endif //LEARNBLOCKCHAIN_BLOCKCHAIN_H
