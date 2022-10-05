//
// Created by 钏茗喜 on 2022/10/5.
//

#include "Blockchain.h"

Blockchain::Blockchain() {
    blocks.emplace_back(Block("Genesis Block", std::string()));
}

void Blockchain::AddBlock(const std::string& data) {
    Block& prevBlock = blocks[blocks.size() - 1];
    Block newBlock = Block(data, prevBlock.GetHash());
    blocks.emplace_back(newBlock);
}

std::vector<Block> Blockchain::GetBlocks() {
    return std::vector<Block>(blocks);
}
