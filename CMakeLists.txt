cmake_minimum_required(VERSION 3.17)
project(LearnBlockChain)

set(CMAKE_CXX_STANDARD 14)
include_directories(Utils)
add_definitions(-DTARGET_BIT=6)

include_directories(/usr/local/include)
add_executable(LearnBlockChain main.cpp Block/Block.cpp Block/Block.h BlockChain/Blockchain.cpp BlockChain/Blockchain.h POW/ProofOfWork.cpp Utils/BigInt.cpp Utils/BigInt.h Utils/hex2bigint.cpp Utils/hex2bigint.h)