#include <iostream>

#include "BlockChain/Blockchain.h"
#include "POW/ProofOfWork.h"
#include "leveldb/db.h"

int main() {
    Blockchain chain("testDB");
    chain.AddBlock("test1");
    for (auto i : chain.GetBlocks()) {
        printf("Tiimestamp : %lld, Data : %s, Hash : %s\n", i.GetTime(), i.GetData().c_str(), i.GetHash().c_str());
    }
    return 0;
}
