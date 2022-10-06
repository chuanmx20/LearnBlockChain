//
// Created by 钏茗喜 on 2022/10/5.
//

#include "Block.h"

Block::Block(std::string _data, std::string _prevBlockHash) {
    timestamp = time(NULL);
    data = _data;
    prevBlockHash = _prevBlockHash;

    ProofOfWork pow(timestamp, prevBlockHash, data);
    auto result = pow.Run();
    nonce = result.first;
    hash = result.second;
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

std::string Block::to_string() {
    std::ostringstream os;
    boost::archive::binary_oarchive oa(os);
    oa << *this;
    return os.str();
}

template<class Archive>
void Block::serialize(Archive &ar, const unsigned int &version) {
    ar & timestamp;
    ar & prevBlockHash;
    ar & data;
    ar & hash;
}

Block Block::Deserialize(std::string str) {
    Block ret("", "");
    std::istringstream is(str);
    boost::archive::binary_iarchive ia(is);
    ia >> ret;
    return reinterpret_cast<Block &&>(ret);
}
