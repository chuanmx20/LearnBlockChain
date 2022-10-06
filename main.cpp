#include <iostream>

#include "BlockChain/Blockchain.h"
#include "POW/ProofOfWork.h"
#include "leveldb/db.h"

int main() {
    Blockchain chain;
    chain.AddBlock("Trans 1 BTC to CMX");
    std::cout << chain.GetEndHash();
    return 0;
}
