//
// Created by 钏茗喜 on 2022/10/5.
//

#include "ProofOfWork.h"

ProofOfWork::ProofOfWork(int _timestamp, std::string _prevHash, std::string _data, int targetBit) {
    target = 1;
    for (int i = 0; i < 256-targetBit; ++i)
        target *= 2;
    timestamp = _timestamp;
    prevHash = _prevHash;
    data = _data;
}

std::string ProofOfWork::PrepareData(unsigned int nonce) {
    char nonceStr[8] = {0};
    sprintf(nonceStr, "%X", nonce);
    std::string data = prevHash + data + std::to_string(timestamp) + std::string(nonceStr);
    return data;
}

std::pair<int, std::string> ProofOfWork::Run() {
    BigInt hashInt;

    std::string hashStr;

    unsigned int maxNonce = 1;
#ifdef MAX_NONCE
    maxNonce = MAX_NONCE;
#else
    maxNonce <<= 31;
#endif
    unsigned int i = 0;
    for (; i < maxNonce; ++i)
    {
        picosha2::hash256_hex_string(PrepareData(i), hashStr);
        hashInt = FromHex(hashStr);
        if (hashInt <= target)
            break;
    }
    return std::pair<int, std::string>(i, hashStr);
}
