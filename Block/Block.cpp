//
// Created by 钏茗喜 on 2022/10/5.
//

#include "Block.h"

Block::Block(std::string _data, std::string _prevBlockHash) {
    timestamp = time(NULL);
    data = _data;
    prevBlockHash = _prevBlockHash;
    std::string header = _prevBlockHash + _data + std::to_string(timestamp);
    picosha2::hash256_hex_string(header, hash);
}

std::string Block::GetHash() {
    return hash;
}

std::string Block::GetPrevBlock() {
    return prevBlockHash;
}

std::string Block::GetData() {
    return data;
}

int64_t Block::GetTime() {
    return timestamp;
}
