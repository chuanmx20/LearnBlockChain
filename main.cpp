#include <iostream>

#include "BlockChain/Blockchain.h"
#include "POW/ProofOfWork.h"
#include "leveldb/db.h"

int main() {
    Blockchain chain;
//    chain.AddBlock("Trans 1 BTC to CMX");
//    std::cout << chain.GetEndHash();
    Block block("nothing but just test", "");
    std::ostringstream os;
    boost::archive::binary_oarchive oa(os);
    oa << block;
    std::cout << " " << os.str();
    return 0;
}
