//
// Created by 钏茗喜 on 2022/10/5.
//

#include "Blockchain.h"

void Blockchain::AddBlock(const std::string& data) {
    Block newBlock = Block(data, blocks.size() == 0 ? "" : blocks[blocks.size()-1].GetHash());
    blocks.emplace_back(newBlock);
    leveldb::DB* db;
    leveldb::Options options;
//    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, DBFileName, &db);
    assert(status.ok());

    std::ostringstream os;
    boost::archive::binary_oarchive oa(os);
    oa << newBlock;

    leveldb::WriteBatch batch;
    batch.Put(newBlock.GetHash(), os.str());

    /// store [hash :  block_serial] in database when new block created
    if (status.ok())
        status = db->Write(leveldb::WriteOptions(), &batch);
    delete db;
}

std::vector<Block> Blockchain::GetBlocks() {
    return std::vector<Block>(blocks);
}

std::string Blockchain::GetEndHash() {
    return blocks[blocks.size() - 1].GetHash();
}

Blockchain::Blockchain(const std::string & _dbFileName) {
    DBFileName = _dbFileName;
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, _dbFileName, &db);

    leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
    std::cout << it->Valid() << std::endl;
    if (it->Valid()) {
        /// current database might contains blocks
        for (;it->Valid();it->Next()) {
            std::cout << it->value().ToString() << std::endl;
            /// create the whole block chain from database
            try {
                blocks.emplace_back(Block::Deserialize(it->value().ToString()));
            } catch (std::exception &e) {
                throw e;
            }
        }
        delete db;
    } else {
        delete db;
        /// current database is empty
        AddBlock("Genesis Block");
    }
}
