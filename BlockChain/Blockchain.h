//
// Created by 钏茗喜 on 2022/10/5.
//

#ifndef LEARNBLOCKCHAIN_BLOCKCHAIN_H
#define LEARNBLOCKCHAIN_BLOCKCHAIN_H

#include <vector>
#include <assert.h>

#include "../Block/Block.h"
#include "leveldb/db.h"
#include "leveldb/write_batch.h"

class Blockchain {
    std::vector<Block> blocks;
    std::string DBFileName;
public:
    Blockchain() = delete;
    Blockchain(const std::string& dbFileName);
    std::vector<Block> GetBlocks();
    void AddBlock(const std::string& data);
    std::string GetEndHash();
};
#endif //LEARNBLOCKCHAIN_BLOCKCHAIN_H
