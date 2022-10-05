cmake_minimum_required(VERSION 3.17)
project(LearnBlockChain)

set(CMAKE_CXX_STANDARD 14)
include_directories(Utils)
add_executable(LearnBlockChain main.cpp Block/Block.cpp Block/Block.h BlockChain/Blockchain.cpp BlockChain/Blockchain.h)