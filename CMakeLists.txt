cmake_minimum_required(VERSION 3.17)
project(LearnBlockChain)

set(CMAKE_CXX_STANDARD 14)
set(BOOST_MIN_VERSION "1.67.0")
find_package(Boost ${BOOST_MIN_VERSION} COMPONENTS serialization)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Fatal error: Boost (version >= ${BOOST_MIN_VERSION}) required.\n")
endif()
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARY_DIRS}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")
# Boost
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

include_directories(Utils)
add_definitions(-DTARGET_BIT=6)

include_directories(/usr/local/include)

add_executable(LearnBlockChain main.cpp Block/Block.cpp Block/Block.h BlockChain/Blockchain.cpp BlockChain/Blockchain.h POW/ProofOfWork.cpp Utils/BigInt.cpp Utils/BigInt.h Utils/hex2bigint.cpp Utils/hex2bigint.h)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})