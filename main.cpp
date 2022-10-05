#include <iostream>
#include "picosha2.h"
#include <unistd.h>

#include "BlockChain/blockchain.h"
int main() {
    Blockchain chain;
    usleep(1000000);
    chain.AddBlock("Sent 1 BTC to Chuanmx");
    usleep(2000000);
    chain.AddBlock("sent 2 BTC to Xiahaotian");

    auto blocks = chain.GetBlocks();
    for (int i = 0; i < blocks.size(); ++i) {
        std::cout << "Time : " << blocks[i].GetTime() << "\n" << "Data : " << blocks[i].GetData() << "\n" << "Hash : " << blocks[i].GetHash() << "\n\n";
    }

    return 0;
}
