#include <iostream>

#include "BlockChain/Blockchain.h"
#include "POW/ProofOfWork.h"
#include "leveldb/db.h"

int main() {
    Blockchain chain("temp");
    chain.AddBlock("nothing just to test leveldb");
    return 0;
}
