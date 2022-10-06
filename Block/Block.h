//
// Created by 钏茗喜 on 2022/10/5.
//

#ifndef LEARNBLOCKCHAIN_BLOCK_H
#define LEARNBLOCKCHAIN_BLOCK_H


#include <cstdint>
#include <string>
#include <ctime>
#include <cstdlib>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/string.hpp>

#include "picosha2.h"
#include "../POW/ProofOfWork.h"

class Block {
    int64_t timestamp;
    std::string data;
    std::string prevBlockHash;
    int nonce;
    std::string hash;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int& version) {
        ar & std::to_string(timestamp);
        ar & prevBlockHash;
        ar & data;
        ar & hash;
    }
public:
    Block() = delete;
    Block(std::string _data, std::string _prevBlockHash);
    std::string GetHash();
    std::string GetPrevBlock();
    std::string GetData();
    int64_t GetTime();
    std::string to_string();
};


#endif //LEARNBLOCKCHAIN_BLOCK_H
