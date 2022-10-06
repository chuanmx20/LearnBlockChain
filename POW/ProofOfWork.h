//
// Created by 钏茗喜 on 2022/10/5.
//

#ifndef LEARNBLOCKCHAIN_PROOFOFWORK_H
#define LEARNBLOCKCHAIN_PROOFOFWORK_H

#include "../Utils/hex2bigint.h"
#include "../Utils/picosha2.h"
#include "../Utils/BigInt.h"

#ifndef TARGET_BIT
#define TARGET_BIT 24
#endif

class ProofOfWork {
private:
    int timestamp;
    std::string prevHash;
    std::string data;
    BigInt target;
public:
    ProofOfWork() = delete;
    ProofOfWork(int, std::string, std::string, int = TARGET_BIT);
    std::string PrepareData(unsigned int nonce);
    std::pair<int, std::string> Run();

};


#endif //LEARNBLOCKCHAIN_PROOFOFWORK_H
